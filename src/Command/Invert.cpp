#include "Command/Invert.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {

    namespace command {
        Image* Invert::apply(Image* img) {
            for(int x = 0; x < img->width(); x++) {
                for(int y = 0; y < img->height(); y++) {
                    img->at(x,y).red() = 255 - img->at(x,y).red();
                    img->at(x,y).green() = 255 - img->at(x,y).green();
                    img->at(x,y).blue() = 255 - img->at(x,y).blue();
                }
            }
            return img;
        }
    }
}
