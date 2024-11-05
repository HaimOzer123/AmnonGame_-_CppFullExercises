#include <iostream>

int main() {
    //pointers are variables that store the memory address of another variable
    // & = address of operator
    // * = dereference operator

    std::string name = "Haim";
    int age = 30;
    double weight = 80.5;
    std::string freePizzas[5] = {"pizza1","pizza2","pizza3","pizza4","pizza5"};
    
    std::string *pName = &name; // pName is a pointer to a string
    int *pAge = &age; // pAge is a pointer to an int
    double *pWeight = &weight; // pWeight is a pointer to a double

    std::string *pFreePizzas = freePizzas; // pFreePizzas is a pointer to an array of strings

    std::cout << "*******************Pointers*******************" << '\n';
    std::cout << *pName << '\n';
    std::cout << *pAge << '\n';
    std::cout << *pWeight << '\n';
    std::cout << *pFreePizzas << '\n';

    std::cout << "*****************|Null pointer|****************" << '\n';

    //Null value and Null pointer

    int *pointer = nullptr; // pointer is a null pointer
   // int *pointer2 = NULL; // pointer2 is a null pointer
    //what the diff between nullptr and NULL?
    //nullptr is a keyword introduced in C++11 to represent a null pointer.
    //NULL is a macro defined in several headers of the C and C++ Standard Library to represent a null pointer.

    int x = 123;

    pointer = &x; // pointer now points to x

    if (pointer == nullptr){
        std::cout << "address was not assigned" << '\n';
        std::cout << "address: " << pointer << '\n';
    } else {
        std::cout << "address was assigned" << '\n';
        std::cout << "address: " << pointer << '\n';
    }


}