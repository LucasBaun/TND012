/**************************************************************************
 Author: 
 Course: tnd012, lab3, exercise 2
************************************************************************* */

#include <iostream>
#include <format>

int main() {

	//Add Variables

	double fprice;
	double lprice;
	double pricestep;
	double taxp;
	double tax;
	double priceaddtax;
	int check = 0;

	//Ask and parameters
	do {
	std::cout << "Enter first price: ";
	std::cin >> fprice;
	std::cout << "Enter last price: ";
	std::cin >> lprice;
	std::cout << "Enter price step: ";
	std::cin >> pricestep;
	std::cout << "Enter tax percentage: ";
	std::cin >> taxp;
	

		if (fprice <= 0 || lprice <= 0 || taxp <= 0 || pricestep < 0 || fprice > lprice) {

			std::cout << "Invalid user input\n";
		}
		else {
			check++;
		}
	} while (check == 0);
	
	std::cout << "\nPrice tax fee\t" << "\ttax\t" << "\tPrice with tax\t\n";
	std::cout << std::format("{:=<48}", "") << "\n";
	
	taxp = taxp / 100;

	while (fprice <= lprice) {

		
		tax = fprice * taxp;
		priceaddtax = tax + fprice;
		std::cout << std::format("{:13.2f}",fprice) << " " << std::format("{:15.2f}",tax) << " " << std::format("{:17.2f}",priceaddtax) << "\n";
		fprice += pricestep;

	}

}