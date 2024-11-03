#include <iostream>

int main(){
    double temp;
    char unit;

    std::cout << "***** Temperature Converter *****" << std::endl;
    std::cout << "Enter the temperature: ";
    std::cin >> temp;
    std::cout << "F= Fahrenheit, C= Celsius" << std::endl;
    std::cout << "Enter the unit (F/C): ";
    std::cin >> unit;

    if (unit == 'F' || unit == 'f'){
        std::cout << "Temperature in Celsius: ";
        temp = (temp - 32) * 5 / 9; 
        std::cout << temp << std::endl;
    } else if (unit == 'C' || unit == 'c'){
        std::cout << "Temperature in Fahrenheit: ";
        temp = (temp * 9 / 5) + 32;
        std::cout << temp << std::endl;
    } else {
        std::cout << "Invalid unit" << std::endl;
    }
    std::cout << "***** Thank you! *****" << std::endl;
}