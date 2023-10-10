/*
 * TND012, Lab2: exercise 1
 * Author: lihen669
 *
 */

#include <iostream>
#include <iomanip>

int main() {

    //Welcome text
    std::cout << "Welcome to our Football Arena!\n------------------------------\n";

    //Give the age value and name
    int Age;


    //Enter input and text
    std::cout << "Enter Age: ";
    std::cin >> Age;

    //Parameters Age above 18 or more
    if (Age >= 18) {

        std::cout << "Price = 80 SEK\n";

    }
    //Parameters Age between 18 and 8
    else if (Age < 18; Age > 8) {

        std::cout << "Price = 30 SEK\n";

    }
    //Parameters Age younger than above
    else {

        std::cout << "Price = For Free\n";

    }

}
