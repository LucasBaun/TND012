/*
 * =============================================================
 * TND012: lab 6
 * Authors:
 * =============================================================
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <format>
#include <algorithm>



struct date {
    int year = 0;
    int month = 0;
    int day = 0;
    
};


struct product_sale {
    std::string code;
    date tog_data;
    int sale = 0;
    bool samma = false;
};

date read_date(std::ifstream& is) {
    date d;
    //is >> '-';
    is >> d.year;    
    is >> d.month;    
    is >> d.day;
    
    return d;
}

// Read a product sale from stream is
product_sale read_sale(std::ifstream& is) {
    product_sale p;    
    
    is >> p.code;
    is >> p.tog_data.year;    
    is >> p.tog_data.month;
    p.tog_data.month = abs(p.tog_data.month);
    is >> p.tog_data.day;
    p.tog_data.day = abs(p.tog_data.day);
    is >> p.sale;
    return p;
}

std::vector<product_sale> read_sales_file(std::ifstream& is) {    
    std::vector<product_sale> temp;          
    
    product_sale c = read_sale(is);  
    
    while (is) {        
        temp.push_back(c);
        c = read_sale(is);
    }
    return temp;
}

void display(std::vector<product_sale> V, std::ofstream& os, int k) {    
 
    std::string code = "Code";
	std::string d = "Date";
	std::string u = "Units Sold";

    
    os << std::format("{:15}{:15}{:15}", code, d, u) << "\n";
    int counter = 0;
    for (product_sale p : V) {
        counter += 1;
        if (counter > k) {
            break;
        }
        os << std::format("{}{:10}-{:02}-{:02}{:10}", p.code, p.tog_data.year, p.tog_data.month, p.tog_data.day, p.sale);
        if (p.samma) {
            os << "^^\n";
        }
        else {
            os << "\n";
        }
    }    
}


std::vector<product_sale> sort(std::vector<product_sale>& V) {
    std::vector <product_sale> newvector;

    for (int pass = 1; pass < std::ssize(V); ++pass) {
        for (int i = 0; i < std::ssize(V) - 1; ++i) {
            if (V[i].sale > V[i + 1].sale) {    //kollar om v[1] är större än v[2]
                std::swap(V[i], V[i + 1]);      //byt plats

            }
            else if (V[i].sale == V[i + 1].sale) {  //om v[1] !> v[2] kolla om dom är lika
                int date1 = (V[i].tog_data.year * 10000) + (V[i].tog_data.month * 100) + (V[i].tog_data.day);
                int date2 = (V[i+1].tog_data.year * 10000) + (V[i+1].tog_data.month * 100) + (V[i+1].tog_data.day);
                //Vi skapar två ints med hela datumen för att slippa göra massa if, else if

                if (date1 > date2) {            //är v[1] datum > v[2] datum
                    std::swap(V[i], V[i + 1]);  //byt plats
                   
                }
                else if (date1 == date2) {      //är v[1] datum !> v[2] datum kolla om dom är lika
                    std::string code1 = V[i].code;
                    std::string code2 = V[i + 1].code;                    

                    int counter = -1;
                    do {
                        counter += 1;
                        if (int(code1[counter]) > int(code2[counter])){
							std::swap(V[i], V[i + 1]);  //byt plats
                        }
                    } while (int(code1[counter]) == int(code2[counter]));                  
                }
            }            
        }
    }
    newvector = V;
    return newvector;
}
void namecheck(std::vector<product_sale>& N) {
    for (int pass = std::ssize(N) - 1; pass >= 1; --pass) {
        for (int varv = pass - 1; varv >= 0; --varv) {
            if (N[pass].code == N[varv].code) {
                N[pass].samma = true;
            }
        }
    }
}
    

int main() {
    std::cout << "Enter k: ";
    int k;
    std::cin >> k;

    std::string path = "C:/Users/Linus/OneDrive/Skrivbord/Lab6/code/"; // Replace this path, if needed

    std::cout << "Enter name of product sales file: ";
    std::string input_file_name;
    std::cin >> input_file_name; //Test if bad state 1
    std::ifstream sales_file(path + input_file_name);

    std::cout << "Enter name of top-k sales file: ";
    std::string output_file_name;
    std::cin >> output_file_name; // Test if in bad state 2
    std::ofstream top_sold_file(path + output_file_name);

    if (!sales_file || !top_sold_file) { //Testing if in bad state 1, 2
        std::cout << "File error!!\n";
        return 0;
    }
    std::vector<product_sale> salevector;
    salevector = read_sales_file(sales_file);
    std::vector<product_sale> sortedv = sort(salevector);
    namecheck(sortedv);   

    display(sortedv, top_sold_file, k);    
}



