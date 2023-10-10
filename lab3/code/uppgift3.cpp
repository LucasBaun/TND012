/**************************************************************************
 Author: 
 Course: tnd012, lab3, exercise 3
************************************************************************* */

/*
 * Tax: 25
 * Products prices:
 * 10 12.5 13 8.5 1120 155 200 220 44 150 112 75 109 80 2300 157 66 47 449 154 STOP
 */



#include <iostream>
#include <iomanip>
#include <cmath>
#include <format>
#include <vector>

int main()
{


    //adding variables
    double first_price, last_price, price_step, tax_percentage, tax, price_with_tax;

    std::cout << "Enter tax: "; //printa uten fråga
    std::cin >> tax_percentage; // få in vad tax är
    tax_percentage = tax_percentage / 100; //gör den till decimaler så vi kan gångra in den sedan.


    std::cout << "Enter Product price: "; //frågar användare om inputs på produkter 
    std::vector<double> products;  // tom vektor som vi sedan fyller på

    while (std::cin >> first_price) { //whileloop som kollar när användaren skriver något annat än nummer
        products.push_back(first_price); // lägger till "first_price som användaren skriver in till vektorn
    }

    if (products.empty() == false) {  //Har användaren lagt till produkter?



        std::cout << std::endl << "Price tax free" << std::setw(10) << "Tax" << std::setw(25) << "price with tax" << std::endl; //printar ut simpel text


        for (double price : products) { //for loop som skapar en double för lika många produkter vi har lagt till.
            tax = price * tax_percentage; //räknar ut vad tax kostar
            price_with_tax = price + tax; //räknar ut vad totala priset blir
            std::cout << std::fixed << std::setprecision(2); //sätter decimal till 2
            std::cout << std::endl << price << std::setw(10) << tax << std::setw(25) << price_with_tax << std::endl; //printar ut resultatet

        }

    }
    else {
        std::cout << "No products prices provided!!\n";
    }

}
