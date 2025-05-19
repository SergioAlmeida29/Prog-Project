#include "Command/RotateLeft.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
namespace command {
    Image* RotateLeft::apply(Image* img) {
        Image* new_img = new Image(img->height(), img->width());
        
        for(int x = 0; x < img->width(); x++) {
            for(int y = 0; y < img->height(); y++) {
                new_img->at(y, img->width()-1-x) = img->at(x, y);
            }
        }
        
        delete img;
        return new_img;
    }
} // namespace command
} // namespace prog
