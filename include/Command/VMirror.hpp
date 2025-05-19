#ifndef PROJECT_VMIRROR_HPP
#define PROJECT_VMIRROR_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class VMirror : public Command {
        public:
            VMirror() : Command("v_mirror") {}
            Image* apply(Image* img) override;
        };
    }
}
#endif
