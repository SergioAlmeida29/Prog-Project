#ifndef PROJECT_FILL_HPP
#define PROJECT_FILL_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class Fill : public Command {
        public:
            Fill(int x, int y, int w, int h, const Color& color) 
                : Command("fill"), x(x), y(y), w(w), h(h), color(color) {}
            Image* apply(Image* img) override;
        private:
            int x, y, w, h;
            Color color;
        };
    }
}
#endif
