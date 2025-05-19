#include "Command/ScaleUp.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
namespace command {
    Image* ScaleUp::apply(Image* img) {
        int new_width = img->width() * x_factor;
        int new_height = img->height() * y_factor;
        Image* new_img = new Image(new_width, new_height);
        
        // Each pixel from original image becomes a rectangle of pixels
        for(int y = 0; y < img->height(); y++) {
            for(int x = 0; x < img->width(); x++) {
                Color pixel = img->at(x, y);
                
                // Fill the rectangle for this pixel
                for(int dy = 0; dy < y_factor; dy++) {
                    for(int dx = 0; dx < x_factor; dx++) {
                        new_img->at(x * x_factor + dx, y * y_factor + dy) = pixel;
                    }
                }
            }
        }
        
        delete img;
        return new_img;
    }
} // namespace command
} // namespace prog
