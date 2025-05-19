#ifndef PROJECT_HMIRROR_HPP
#define PROJECT_HMIRROR_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class HMirror : public Command {
        public:
            HMirror() : Command("h_mirror") {}
            Image* apply(Image* img) override;
        };
    }
}
#endif
