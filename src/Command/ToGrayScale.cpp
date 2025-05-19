#include "Command/ToGrayScale.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
namespace command {
    Image* ToGrayScale::apply(Image* img) {
        for(int x = 0; x < img->width(); x++) {
            for(int y = 0; y < img->height(); y++) {
                Color& pixel = img->at(x,y);
                int gray = (pixel.red() + pixel.green() + pixel.blue()) / 3;
                pixel.red() = gray;
                pixel.green() = gray;
                pixel.blue() = gray;
            }
        }
        return img;
    }
} // namespace command
} // namespace prog
