#ifndef PROJECT_CHAIN_HPP
#define PROJECT_CHAIN_HPP

#include "Command.hpp"
#include <vector>
#include <string>
#include <unordered_set>

namespace prog {
    namespace command {

        class Chain : public Command {
        public:

            Chain(const std::vector<std::string>& scrims);


            ~Chain() override = default;

            Image *apply(Image *img) override;

            std::string toString() const override;
        private:
            std::vector<std::string> scrims_;   /**< List of scrim script file names. */

            static std::unordered_set<std::string> stack_;


            static Image* runScrim(const std::string& scrim, Image* img);
        };
    }
}

#endif