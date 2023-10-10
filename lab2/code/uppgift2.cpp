/*
 * TND012, Lab2: exercise 2
 * Author: lihen669
 *
 */

#include <iostream>
#include <cmath>
#include <format>

int main() {
    //Set value

   
    double b;
    double c;
    double root1;
    double root2;
    double x1;
    double x2;
    double rootcheck;

    //Ask for Constant b and c

    std::cout << "Coefficient b = ";
    std::cin >> b;
    std::cout << "Coefficient c = ";
    std::cin >> c;

    std::cout << "Calculating second degree roots...";

    //Check if sqrt is Complex or not

    rootcheck = (b / 2.0) * (b / 2.0) - c;

    if (rootcheck <= 0) {

        std::cout << "\nComplex roots!!!\n";
    }

    //Calculate roots
    else {
        root1 = -(b) / 2.0;
        root2 = std::sqrt((b / 2.0) * (b / 2.0) - c);

        x1 = root1 + root2;
        x2 = root1 - root2;
    //Print Answer in cout with only two decimals
        std::cout << std::format("\nFirst root = {:.2f}", x1); 
        std::cout << std::format("\nSecond root = {:.2f}", x2) << "\n";
    }
 



}
