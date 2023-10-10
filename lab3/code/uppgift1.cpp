/**************************************************************************
 Author: 
 Course: tnd012, lab3, exercise 1
************************************************************************* */


#include <iostream>
#include <format>

int main() {


	int ticket;
	int total_price = 0;
	int age;

	//Ask how many tickets

	std::cout << "Welcome to our Football Arena\n";
	std::cout << std::format("{:-<29}","");

	do
	{
		std::cout << std::endl << "Number of tickets : ";
		std::cin >> ticket;
		if (ticket <= 0)
		{
			std::cout << "Invalid number of tickets!\n";
		}

	} while (ticket <=0);

	int ticket_count = 1;

	do
	{
		
		std::cout << "Enter age for person " << ticket_count << ": ";
		std::cin >> age;

		if (age < 8 && age > 0)
		{
			ticket_count++;

		}
		else if (age >= 8 && age < 15)
		{
			total_price += 30;
			ticket_count++;
		}
		else if (age >= 15)
		{
			total_price += 80;
			ticket_count++;
		}
		else 
		{
			std::cout << "\nInvalid age try again\n";
		}
		
	} while (ticket_count <= ticket); //hur många gånger ska den upprepas?

	std::cout << "Total price = " << total_price << "\n";


}