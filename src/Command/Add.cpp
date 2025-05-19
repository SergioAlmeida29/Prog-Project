#include "Command/Add.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include "PNG.hpp"

namespace prog {
namespace command {
    Image* Add::apply(Image* img) {
        Image* source = loadFromPNG(filename);
        if (!source) return img;

        for(int i = 0; i < source->width(); i++) {
            for(int j = 0; j < source->height(); j++) {
                Color& pixel = source->at(i, j);
                if(pixel.red() != neutral.red() || 
                   pixel.green() != neutral.green() || 
                   pixel.blue() != neutral.blue()) {
                    
                    int dest_x = x + i;
                    int dest_y = y + j;
                    if(dest_x >= 0 && dest_x < img->width() && 
                       dest_y >= 0 && dest_y < img->height()) {
                        img->at(dest_x, dest_y) = pixel;
                    }
                }
            }
        }

        delete source;
        return img;
    }
} // namespace command
} // namespace prog
