// Copyright 2025 Mikhail Ibrahim
// Date: Mar 6, 2025
// Description: A C++ program that calculates the area and perimeter of an
// ellipse, including an approximation for the perimeter based on user input
// for the major and minor axes.

#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

double calculate_area(double a, double b) {
    return M_PI * a * b;
}

double calculate_perimeter(double a, double b) {
    double h = std::pow(a - b, 2) / std::pow(a + b, 2);
    return M_PI * (a + b) * (1 + (3 * h) / (10 + std::sqrt(4 - 3 * h)));
}

double get_positive_float(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail() || value <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a positive number.\n";
        } else {
            return value;
        }
    }
}

void run_test_cases() {
    struct TestCase {
        double a, b;
    };

    TestCase test_cases[] = {
        {5, 3}, {10, 6}, {7, 7}, {3, 2}, {15, 10}, {20, 5}};

    for (int i = 0; i < 6; ++i) {
        double a = test_cases[i].a;
        double b = test_cases[i].b;
        double area = calculate_area(a, b);
        double perimeter = calculate_perimeter(a, b);

        std::cout << "Test Case " << (i + 1) << ": a=" << a
                  << ", b=" << b << "\n"
                  << "Area: " << std::fixed << std::setprecision(2)
                  << area << " square units\n"
                  << "Perimeter (approx): " << std::fixed
                  << std::setprecision(2) << perimeter << " units\n\n";
    }
}

int main() {
    std::cout << "Welcome to the Ellipse Calculator!\n\n";
    run_test_cases();

    while (true) {
        double a = get_positive_float(
            "Enter the length of the major axis (a): ");
        double b = get_positive_float(
            "Enter the length of the minor axis (b): ");
        double area = calculate_area(a, b);
        double perimeter = calculate_perimeter(a, b);

        std::cout << "\nEllipse with axes a=" << a << " and b=" << b << ":\n";
        std::cout << "Area: " << std::fixed << std::setprecision(2)
                  << area << " square units\n";
        std::cout << "Perimeter (approx): " << std::fixed
                  << std::setprecision(2) << perimeter << " units\n\n";

        std::string another;
        std::cout << "Do you want to calculate for another ellipse? (yes/no): ";
        std::cin >> another;

        if (another != "yes") {
            break;
        }
    }

    return 0;
}
