#include "Command/Replace.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
namespace command {
    Image* Replace::apply(Image* img) {
        for(int x = 0; x < img->width(); x++) {
            for(int y = 0; y < img->height(); y++) {
                Color& pixel = img->at(x, y);
                if(pixel.red() == old_color.red() && 
                   pixel.green() == old_color.green() && 
                   pixel.blue() == old_color.blue()) {
                    pixel = new_color;
                }
            }
        }
        return img;
    }
} // namespace command
} // namespace prog
