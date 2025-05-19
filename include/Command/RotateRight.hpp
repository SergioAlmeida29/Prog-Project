#ifndef PROJECT_ROTATERIGHT_HPP
#define PROJECT_ROTATERIGHT_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class RotateRight : public Command {
        public:
            RotateRight() : Command("rotate_right") {}
            Image* apply(Image* img) override;
        };
    }
}
#endif
