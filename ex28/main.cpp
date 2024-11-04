#include <iostream>

// memory address example

int main(){
    int a = 10;
    int b = 20;
    int c = 30;

    std::cout << "a: " << a << " address: " << &a << std::endl;
    std::cout << "b: " << b << " address: " << &b << std::endl;
    std::cout << "c: " << c << " address: " << &c << std::endl;

    //how to control the memory address
    int *ptr = &a;
    std::cout << "ptr: " << ptr << " value: " << *ptr << std::endl;

    return 0;
}