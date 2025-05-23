//
// Created by jose-b-reis on 5/22/25.
//

#ifndef CHAIN_H
#define CHAIN_H
#include "Command.hpp"
#include <vector>
#include <string>
#include <set>

namespace prog {
class Chain : public Command {
public:
    Chain(const std::vector<std::string>& scrims, std::set<std::string> call_stack = {});
    Image* apply(Image* img) override;
private:
    std::vector<std::string> scrim_files;
    std::set<std::string> call_stack;
};
}

#endif //CHAIN_H
