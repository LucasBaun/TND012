/*
 * TND012, Lab5
 * Author: Lucba332, lihen669
 *
 */

/*Test data 1
country X: 50 50 100 250 100 50 100 85 100 180 10 100 -1
Sweden:    70 78 170 250 105 90 120 96 160 250 18 150 -1
*/

/*Test data 2
country X: 50 50 100 250 100 50 100 85 100 180 10 100 50 50 120 120 50 77 -1
Sweden:    70 78 170 250 105 90 120 96 160 250 18 150 65 60 190 147 90 90 -1
*/

/*Test data 3
country X: 50 50 100 250 100 50 -1
Sweden:    70 78 170 250 105 90 120 96 160 250 18 150 -1
*/

/*Test data 4
country X: 50 50 100 250 100 50 -1
Sweden:    70 78 170 250 105 90 -1
*/

// Try also your code with other test data

#include <iostream>
#include <vector>


//Function read input and return into vector
std::vector<int> read_seq() {
    std::vector<int> V; // empty vector

    int value; // read values into this variable
    while (std::cin >> value && value > 0) { // read until a non-positive number  is entered
        //uträkning = value
        V.push_back(value); // add value to the end of V
    }
    return V; // return the vector with the list of values read
}

//Function calculate difference between countries return in vector
std::vector<int> difference(std::vector<int> V1, std::vector<int> V2) {
    std::vector<int> V3(std::ssize(V1), 0);
    for (int pass = 0; pass < std::ssize(V1); ++pass) { 
        V3[pass] = V2[pass] - V1[pass];
    }
    return V3;
}

//Functions calls functions difference and converts to amount stars
std::vector<int> count_stars(std::vector<int> V3) {
    std::vector<int> temp_stars(std::ssize(V3), 0);
    for (int pass = 0; pass < std::ssize(V3); ++pass) {
        double stars = 10.00;        
		temp_stars[pass] = static_cast<int>(std::round((V3[pass] / stars))); // Used static_cast because we use an double and then convert in to a int

    }
    return temp_stars;
}
//Function prints out
void create_histogram(std::vector<char> A, std::vector<int> stars) {
	if (std::ssize(stars) >= std::ssize(A)) {
		long long int a = std::ssize(stars) - std::ssize(A);
		for (int pass = 0; pass < a; ++pass) {
			A.push_back(A[pass]);
		}

		for (int pass = 0; pass < std::ssize(A); ++pass) {
			std::cout << A[pass] << " ";
			for (int varv = 0; varv < stars[pass]; ++varv) {
				std::cout << "*";
			}
			std::cout << "\n";
		}
	}
	else {
		std::cout << "Not enough months";
	}
}

int main() {
    
    std::cout << "Enter data for country X:\t";
    std::vector<int> country_X = read_seq();
    std::cout << "\nEnter data for Sweden:\t\t";
    std::vector<int> Sweden = read_seq();   
    std::vector<char> Months = {'J', 'F', 'M', 'A', 'M', 'J', 'J', 'A', 'S', 'O', 'N', 'D' };

    if (std::ssize(country_X) == std::ssize(Sweden)) {

		std::vector<int> calc_V3;
        calc_V3 = difference(country_X, Sweden); 
		std::vector<int> calc_count_stars;
		calc_count_stars = count_stars(calc_V3);
        create_histogram(Months, calc_count_stars);
        
    } else {
        std::cout << "Invalid input!!\n";
    }
}
