#ifndef PROJECT_CHAIN_HPP
#define PROJECT_CHAIN_HPP

#include "Command.hpp"
#include <vector>
#include <string>
#include <unordered_set>

namespace prog {
    namespace command {
        /**
         * @brief Chain class that applies a series of scrims to an image.
         *
         * A Chain command executes a list of scrim files in order, applying their commands to the given image.
         * It inherits from the Command class and implements the apply method.
         */
        class Chain : public Command {
        public:
            /**
             * @brief Constructor for the Chain class with a vector of scrim file names.
             *
             * @param scrims A vector of strings representing the scrim files to be executed.
             */
            Chain(const std::vector<std::string>& scrims);

            /**
             * @brief Destructor for the Chain class.
             */
            ~Chain() override = default;

            /**
             * @brief Applies the chain of scrims to the given image.
             *
             * Iteratively loads and runs each scrim, skipping forbidden commands
             * like 'blank', 'open', or 'save'. Handles recursive protection.
             *
             * @param img A pointer to the Image object to which the scrims will be applied.
             * @return A pointer to the modified Image object.
             */
            Image *apply(Image *img) override;

            /**
             * @brief Returns a string representation of the Chain command.
             *
             * This method provides a string that describes the chain of scrims.
             *
             * @return A string representation of the Chain command.
             */
            std::string toString() const override;
        private:
            std::vector<std::string> scrims_;   /**< List of scrim script file names. */

            /**
            * @brief Static set used to detect and prevent recursive scrim calls.
            */
            static std::unordered_set<std::string> stack_;

            /**
            * @brief Helper method that runs a single scrim script on the image.
            *
            * @param scrim File name of the scrim script.
            * @param img Pointer to the image to apply the script to.
            * @return The image after the scrim has been applied.
            */
            static Image* runScrim(const std::string& scrim, Image* img);
        };
    }
}

#endif