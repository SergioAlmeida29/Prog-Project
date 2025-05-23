#ifndef RESIZE_HPP
#define RESIZE_HPP

#include "Command.hpp"
#include <string>

namespace prog::command {
    class Resize : public Command {
    public:
        Resize(int x, int y, int w, int h);
        ~Resize();

        Image *apply(Image *img) override;
        std::string toString() const override;

    private:
        int m_x, m_y;
        int m_w, m_h;
    };
}

#endif //RESIZE_HPP