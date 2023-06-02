#include <iostream>

// Function to calculate the number of chocolate bars and leftover coupons
std::pair<int, int> calculate_chocolate_bars(int dollars) {
    int chocolate_bars = dollars;
    int coupons = chocolate_bars;

    // Calculate the number of chocolate bars and leftover coupons
    while (coupons >= 7) {
        // Calculate additional chocolate bars that can be obtained with the coupons
        int new_chocolate_bars = coupons / 7;
        // Update the total chocolate bars count
        chocolate_bars += new_chocolate_bars;
        // Calculate the leftover coupons after purchasing additional chocolate bars
        int leftover_coupons = coupons % 7 + new_chocolate_bars;
        // Update the coupon count with the leftover coupons
        coupons = leftover_coupons;
    }

    // Return the number of chocolate bars and leftover coupons as a pair
    return std::make_pair(chocolate_bars, coupons);
}

int main() {
    bool repeat = true;

    while (repeat) {
        double dollars;

        while (true) {
            // Prompt the user for the amount they want to spend on chocolates
            std::cout << "How much would you like to spend on chocolates? ";

            // Input validation: Check if the input is a non-negative whole number
            if (std::cin >> dollars && dollars >= 0 && dollars == static_cast<int>(dollars)) {
                break;
            }
            else {
                std::cout << "Error: Please enter a non-negative whole number." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }

        // Calculate the number of chocolate bars and leftover coupons based on the user's input
        std::pair<int, int> result = calculate_chocolate_bars(static_cast<int>(dollars));
        int bars = result.first;
        int coupons = result.second;

        // Display the result to the user
        std::cout << "You can buy " << bars << " chocolates" << std::endl;
        std::cout << "You will have " << coupons << " leftover coupons" << std::endl;

        while (true) {
            std::string choice;
            // Ask the user if they want to repeat the program
            std::cout << "Would you like to use this program again? (y/n) ";
            std::cin >> choice;

            // Input validation: Check if the choice is 'y' or 'Y' for yes, 'n' or 'N' for no
            if (choice == "y" || choice == "Y") {
                break;
            }
            else if (choice == "n" || choice == "N") {
                std::cout << "Thank you! Have a great day!" << std::endl;
                repeat = false;
                break;
            }
            else {
                std::cout << "Error: Invalid input. Please enter 'y' or 'n'." << std::endl;
            }
        }
    }

    return 0;
}

