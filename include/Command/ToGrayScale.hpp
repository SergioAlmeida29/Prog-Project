#ifndef PROJECT_TOGRAYSCALE_HPP
#define PROJECT_TOGRAYSCALE_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class ToGrayScale : public Command {
        public:
            ToGrayScale() : Command("to_gray_scale") {}
            Image* apply(Image* img) override;
        };
    }
}
#endif
