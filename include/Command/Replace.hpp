#ifndef PROJECT_REPLACE_HPP
#define PROJECT_REPLACE_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class Replace : public Command {
        public:
            Replace(const Color& old_color, const Color& new_color) 
                : Command("replace"), old_color(old_color), new_color(new_color) {}
            Image* apply(Image* img) override;
        private:
            Color old_color;
            Color new_color;
        };
    }
}
#endif
