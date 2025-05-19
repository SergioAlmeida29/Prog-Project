#include "Command/Crop.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
namespace command {
    Image* Crop::apply(Image* img) {
        Image* new_img = new Image(w, h);
        
        for(int i = 0; i < w && (i + x) < img->width(); i++) {
            for(int j = 0; j < h && (j + y) < img->height(); j++) {
                if((i + x) >= 0 && (j + y) >= 0) {
                    new_img->at(i, j) = img->at(i + x, j + y);
                }
            }
        }
        
        delete img;
        return new_img;
    }
} // namespace command
} // namespace prog
