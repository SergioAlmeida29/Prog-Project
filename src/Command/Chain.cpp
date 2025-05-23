#include "Command/Chain.hpp"
#include "ScrimParser.hpp"
#include "Scrim.hpp"
#include "Logger.hpp"
#include <algorithm>
#include <sstream>

namespace prog {
    namespace command {

        std::unordered_set<std::string> Chain::stack_;

        Chain::Chain(const std::vector<std::string>& scrims) : Command("Chain"), scrims_(scrims) {}

        Image *Chain::apply(Image *img) {
            for(const auto& scrim : scrims_) {
                img = runScrim(scrim, img);
            }
            return img;
        }

        Image *Chain::runScrim(const std::string &scrim, Image *img) {

            if(!stack_.insert(scrim).second) {
                *Logger::out() << "Ignoring recursive chain to '" << scrim << "'\n";
                return img;
            }

            ScrimParser parser;
            Scrim* line = parser.parseScrim(scrim);
            if(!line) {
                *Logger::err() << "Failed to load scrim '" << scrim << "'\n";
                stack_.erase(scrim);
                return img;
            }

            for(Command* c : line->getCommands()) {
                std::string name = c->name();

                std::transform(name.begin(), name.end(), name.begin(), ::tolower);
                if(name == "blank" || name == "open" || name == "save") {
                    continue;
                }
                img = c->apply(img);
            }

            delete line;
            stack_.erase(scrim);
            return img;
        }

        std::string Chain::toString() const {
            std::ostringstream ss;
            ss << "chain";
            for (const auto& s : scrims_) ss << ' ' << s;
            ss << " end";
            return ss.str();
        }

    }
}