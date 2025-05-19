#ifndef PROJECT_ADD_HPP
#define PROJECT_ADD_HPP

#include "Command.hpp"
#include <string>

namespace prog {
    namespace command {
        class Add : public Command {
        public:
            Add(const std::string& filename, const Color& neutral, int x, int y) 
                : Command("add"), filename(filename), neutral(neutral), x(x), y(y) {}
            Image* apply(Image* img) override;
        private:
            std::string filename;
            Color neutral;
            int x, y;
        };
    }
}
#endif
