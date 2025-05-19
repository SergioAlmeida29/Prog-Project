#ifndef PROJECT_SCALEUP_HPP
#define PROJECT_SCALEUP_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class ScaleUp : public Command {
        public:
            ScaleUp(int x, int y) : Command("scaleup"), x_factor(x), y_factor(y) {}
            Image* apply(Image* img) override;
        private:
            int x_factor, y_factor;
        };
    }
}
#endif
