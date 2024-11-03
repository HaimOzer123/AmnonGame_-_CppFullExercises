#include <iostream>

int main () {
    int a = 1;
    int b = 2;
    std::cout << "first a="<< a << std::endl;
    std::cout << "first b="<< b << std::endl; 
    int temp = a;
    a = b;
    b = temp;

    std::cout << "a="<< a << std::endl;
    std::cout << "b="<< b << std::endl;
        
    return 0;
}