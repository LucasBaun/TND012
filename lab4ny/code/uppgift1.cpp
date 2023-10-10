/*
 * TND012, Lab4: program to find prime numbers
 * Author:
 *
 */

#include <iostream>
#include <format>
#include <vector>

// ADD any needed functions here


void menu() {
    // Display the menu
    std::cout << std::format("{:=<16}", "");
    std::cout << "\n1. Test Prime\n2. Next Prime\n3. Previous Prime\n4. Display Primes\n5. Exit\n";
    std::cout << std::format("{:=<16}", "");   
    std::cout << "\nYour choice? ";   
    return;    
}

bool prime_test(int t_prime) {
    bool prime = true;
    if (t_prime <= 1) {
        prime = false;
    }
    for (int checkp = 2; checkp <= (t_prime / 2); ++checkp) {
        if (t_prime % checkp == 0) {
            prime = false;
        }
    }
    return prime;
}

int nextprime(int nextprime) {
    // Testa prime. Om inte prime så startar loopen om

    bool test;
    for (int i = nextprime + 1; test = true; ++i) {
        test = prime_test(i);
        if (test == true) {
            return i;           
        }      
    }
    return 1;
}

int prev_prime(int x) {
    bool y;
    for (int i = x - 1; y = true; --i) {
        y = prime_test(i);
        if (y)
        {
            return i;
        }
    }
    
}

std::vector<int> display_primes(int a, int b) {
    std::vector<int> x;
    int y = a;
    int t = b;
    for (int n = y; y <= t; ++n) {
        bool prime = prime_test(n);
        if (prime) {
            x.push_back(n);
        }

    }
    return x;
}

void display_sequence(const std::vector<int>& y) {
    for (int e : y) {
        std::cout << e << " ";
    }
}


int main() {
    constexpr int exit = 5;

    int option = exit;

    do {
        // Display the menu
        menu();
        std::cin >> option;
        int prime1;
        int t_prime;
        


        switch (option) {
        case 1:            
            std::cout << "\nEnter prime number: ";
            std::cin >> prime1;
            bool prime;
            prime = prime_test(prime1);
            if (prime) {
                std::cout << prime1 << " is a prime. " << "\n\n";
            } else {
                std::cout << prime1 << " is not a prime." << "\n\n";
            }
            break;
        case 2:
            //Fråga Prime            
            bool test1;
            std::cout << "Enter prime nr: ";
            std::cin >> t_prime;
            test1 = prime_test(t_prime);
            if (test1 == false) {
                std::cout << "not prime.";
                break;
            }           
            std::cout << "Next prime nr: " << nextprime(t_prime) << "\n\n";               
            break;
        case 3:
            std::cout << "\nEnter prime number: ";
            std::cin >> t_prime;
            bool prime3;
            prime3 = prime_test(t_prime);
            if (prime3) {
                int test2 = prev_prime(t_prime);
                std::cout << "prev prime is: " << test2 << std::endl;
            } else {
                std::cout << "you did not enter a prime number, please use the `check prime` option to find a prime number." << std::endl;
            }
            break;
        case 4:
            int a, b;
            //std::vector<int> list;
            std::cout << "Enter interval [a,b]? ";
            std::cin >> a >> b;
            std::vector<int> list = display_primes(a, b);
            std::cout << "Prime numbers: ";
            display_sequence(list);
            
            break;

        }

       
        

        // Read user option

        // Handle user option -- switch-statement can be useful here

    } while (option != exit);
}




