#include "Command/Resize.hpp"
#include "Command.hpp"
#include "Image.hpp"

using namespace prog;
using namespace std;

namespace prog::command {
    Resize::Resize( int x, int y, int w, int h) : Command("resize"), m_x(x), m_y(y), m_w(w), m_h(h) {}

    Resize::~Resize() {}

    Image* Resize::apply(Image* img) {
        Image* resized = new Image(m_w, m_h);

        for (int x = 0; x < m_w; x++) {
            for (int y = 0; y < m_h; y++) {
                int orig_x = m_x + x;
                int orig_y = m_y + y;

                if (orig_x >= 0 && orig_x < img->width() && orig_y >= 0 && orig_y < img->height()) {
                    resized->at(x,y) = img->at(orig_x, orig_y);
                }

            }
        }
        return resized;
    }
    string Resize::toString() const {
        return "resize";
    }
}