#include "Command/VMirror.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
namespace command {
    Image* VMirror::apply(Image* img) {
        for(int x = 0; x < img->width(); x++) {
            for(int y = 0; y < img->height()/2; y++) {
                Color temp = img->at(x, y);
                img->at(x, y) = img->at(x, img->height()-1-y);
                img->at(x, img->height()-1-y) = temp;
            }
        }
        return img;
    }
} // namespace command
} // namespace prog
