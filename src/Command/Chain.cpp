#include "Command/Chain.hpp"
#include "ScrimParser.hpp"
#include <iostream>

namespace prog {

Chain::Chain(const std::vector<std::string>& scrims, std::set<std::string> call_stack)
    : Command("chain"), scrim_files(scrims), call_stack(std::move(call_stack)) {}

Image* Chain::apply(Image* img) {
    Image* current = img;
    for (const auto& scrim_file : scrim_files) {
        if (call_stack.count(scrim_file)) {
            // Recursion detected, skip
            continue;
        }
        std::set<std::string> new_stack = call_stack;
        new_stack.insert(scrim_file);

        ScrimParser parser;
        Scrim* scrim = parser.parseScrim(scrim_file);
        if (!scrim) continue;

        // Filter out save, blank, open commands
        std::vector<Command*> filtered;
        for (auto* cmd : scrim->getCommands()) {
            std::string n = cmd->name();
            if (n == "save" || n == "blank" || n == "open") continue;
            filtered.push_back(cmd);
        }
        for (auto* cmd : filtered) {
            Image* next = cmd->apply(current);
            if (current != img) delete current;
            current = next;
        }
        delete scrim;
    }
    return current;
}

}