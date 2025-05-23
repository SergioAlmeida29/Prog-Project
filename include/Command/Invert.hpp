#ifndef PROJECT_INVERT_HPP
#define PROJECT_INVERT_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class Invert : public Command {
        public:
            Invert() : Command("invert") {}
            Image* apply(Image* img) override;
        };
    }
}
#endif
