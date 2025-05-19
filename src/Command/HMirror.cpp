#include "Command/HMirror.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
namespace command {
    Image* HMirror::apply(Image* img) {
        for(int y = 0; y < img->height(); y++) {
            for(int x = 0; x < img->width()/2; x++) {
                Color temp = img->at(x, y);
                img->at(x, y) = img->at(img->width()-1-x, y);
                img->at(img->width()-1-x, y) = temp;
            }
        }
        return img;
    }
} // namespace command
} // namespace prog
