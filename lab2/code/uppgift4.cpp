/*
 * TND012, Lab2: exercise 4
 * Author:
 *
 */

#include <iostream>

int main() {
    // ADD CODE

    int dh_time;
    int dm_time;
    int fh_time;
    int fm_time;


    std::cout << "Departure time hour = ";
    std::cin >> dh_time;
    std::cout << "Departure time minutes = ";
    std::cin >> dm_time;

    std::cout << "How long will the flight be? Hours = ";
    std::cin >> fh_time;
    std::cin >> fm_time;


    if (dh_time > 23|| fh_time > 23 || dm_time > 59 || fm_time > 59){
        std::cout << "Invalid time frame";

    }

    else {}



}
