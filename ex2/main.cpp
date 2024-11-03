#include <iostream>
/**
 * @brief this is the main function that will be executed when the program is run 
 * 
 * @return int the return value of the program
 */

int main() {
    int x =10;
    int y = x++; // y=10, x=11
    int z = ++x; // z=12, x=12
    std::cout << x;
    std::cout << y;
    std::cout << z;
    int f = (1 + 2) * 3; 
    std::cout << f << std::endl;
    double g = (x + y) / (z + 1.2);
    std::cout << g << std::endl;
    //read an integer from the keyboard
    int a = 05 ;
    std::cin >> a;
    //print the integer
    std::cout << "int: " << a << std::endl;
    a = a + 1;
    std :: cout << "the number now is " << a << std::endl;
    return 0;
    }
    