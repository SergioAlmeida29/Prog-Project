#include "Command/Fill.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
namespace command {
    Image* Fill::apply(Image* img) {
        for(int i = x; i < x + w && i < img->width(); i++) {
            for(int j = y; j < y + h && j < img->height(); j++) {
                if(i >= 0 && j >= 0) {
                    img->at(i, j) = color;
                }
            }
        }
        return img;
    }
} // namespace command
} // namespace prog
