#include "Image.hpp"

namespace prog {
    Image::Image(int w, int h, const Color &fill) : w(w), h(h){
      pixels.resize(w * h,  fill);
    }

    Image::~Image() {
    }

    int Image::width() const {
        return w;
    }

    int Image::height() const {
        return h;
    }

    Color &Image::at(int x, int y) {
        return pixels[y * w + x];
    }

    const Color &Image::at(int x, int y) const {
        return pixels[y * w + x];
    }
}
