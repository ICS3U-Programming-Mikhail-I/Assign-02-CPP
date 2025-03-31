// Copyright 2025 Mikhail Ibrahim
// Date: Mar 30, 2025
// Description: A C++ program that calculates
// the area and perimeter of a regular
// octagon, based on user input for the side length and unit.

#include <cmath>
#include <iostream>
#include <string>

int main() {
    double side_length;
    std::string unit;

    // Prompt user for side length and unit input
    std::cout << "Enter the side length of the octagon: ";
    std::cin >> side_length;
    std::cout << "Enter the unit (m, cm, mm): ";
    std::cin >> unit;

    // Convert unit to lowercase
    for (size_t i = 0; i < unit.length(); ++i) {
        unit[i] = tolower(unit[i]);
    }

    // Convert side length to meters if needed
    if (unit == "cm") {
        side_length *= 0.01;  // Convert cm to meters
    } else if (unit == "mm") {
        side_length *= 0.001;  // Convert mm to meters
    } else if (unit != "m") {
        std::cout << "Unknown unit. Assuming meters." << std::endl;
    }

    // Constants
    const double PI = 3.141592653589793;

    // Calculate area and perimeter
    double area = 2 * (1 + std::sqrt(2)) * std::pow(side_length, 2);
    double perimeter = 8 * side_length;

    // Display results
    std::cout << "The area of the octagon is: "
              << round(area * 100.0) / 100.0 << " square meters" << std::endl;
    std::cout << "The perimeter of the octagon is: "
              << round(perimeter * 100.0) / 100.0 << " meters" << std::endl;

    // Closing greeting
    std::cout << "Thanks for using the Octagon Calculator! Have a great day!"
              << std::endl;

    return 0;
}
