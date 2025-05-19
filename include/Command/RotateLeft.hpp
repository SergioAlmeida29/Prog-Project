#ifndef PROJECT_ROTATELEFT_HPP
#define PROJECT_ROTATELEFT_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class RotateLeft : public Command {
        public:
            RotateLeft() : Command("rotate_left") {}
            Image* apply(Image* img) override;
        };
    }
}
#endif
