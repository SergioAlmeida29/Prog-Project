#include "Command/Move.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
namespace command {
    Image* Move::apply(Image* img) {
        Image* temp = new Image(img->width(), img->height());
        
        // Fill with white (default color)
        for(int i = 0; i < img->width(); i++) {
            for(int j = 0; j < img->height(); j++) {
                temp->at(i, j) = Color(255, 255, 255);
            }
        }
        
        // Copy pixels to new positions if they're in bounds
        for(int i = 0; i < img->width(); i++) {
            for(int j = 0; j < img->height(); j++) {
                int new_x = i + x;
                int new_y = j + y;
                
                if(new_x >= 0 && new_x < img->width() && 
                   new_y >= 0 && new_y < img->height()) {
                    temp->at(new_x, new_y) = img->at(i, j);
                }
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
