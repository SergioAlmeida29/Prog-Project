#include "Command/Slide.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
namespace command {
    Image* Slide::apply(Image* img) {
        Image* temp = new Image(img->width(), img->height());
        
        for(int i = 0; i < img->width(); i++) {
            for(int j = 0; j < img->height(); j++) {
                // Calculate new position with wrapping
                int new_x = (i + x) % img->width();
                if(new_x < 0) new_x += img->width();
                
                int new_y = (j + y) % img->height();
                if(new_y < 0) new_y += img->height();
                
                temp->at(new_x, new_y) = img->at(i, j);
            }
        }
        
        // Copy back to original image
        for(int i = 0; i < img->width(); i++) {
            for(int j = 0; j < img->height(); j++) {
                img->at(i, j) = temp->at(i, j);
            }
        }
        
        delete temp;
        return img;
    }
} // namespace command
} // namespace prog
