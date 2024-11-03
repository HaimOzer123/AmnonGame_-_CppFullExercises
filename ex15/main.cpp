#include <iostream> 

int main(){
    int temp;

    std::cout << "Enter the temperature: ";
    std::cin >> temp;

    if (temp > 0 && temp < 100){
        std::cout << "The water is liquid" << std::endl;
    } else if (temp <= 0){
        std::cout << "The water is solid" << std::endl;
    } else {
        std::cout << "The water is gas" << std::endl;
    }

    bool sunny = true;
    if (sunny){
        std::cout << "It is sunny" << std::endl;
    } else {
        std::cout << "It is not sunny" << std::endl;
    }
}