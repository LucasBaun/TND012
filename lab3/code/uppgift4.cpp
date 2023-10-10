/**************************************************************************
 Author: 
 Course: tnd012, lab3, exercise 4
************************************************************************* */


#include <iostream>


int main() {
	


		for (int a = 0; a <= 9; ++a) {			
	
			for (int b = 0; b <= 9; ++b) {						

				for (int c = 0; c <= 9; ++c) {

					if (a == b || a == c || b == c) {

					}
					else {
						std::cout << "A = " << a << "\tB = " << b << "\tC = " << c << "\n";
						if ((a * 10 + a + b * 10 + b + c * 10 + c) == a * 100 + b * 10 + c)
							std::cout << "\nAA + BB + CC = ABC, solution: " << "A = " << a << "\tB = " << b << "\tC = " << c << "\n";
					}
				} std::cout << "\n";
			}			
		}
	
		


}