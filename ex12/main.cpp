#include <iostream>

int main(){

    int age = 0;
    std::cout << "Enter your age: ";
    std::cin >> age;

    if (age < 18 && age > 0){
        std::cout << "You are a minor." << std::endl;
    } else if (age >= 18 && age < 65){
        std::cout << "You are an adult." << std::endl;
    } else if ( age <= 0){
        std::cout << "You are not born yet." << std::endl;
    } else if ( age > 120){
        std::cout << "You are dead." << std::endl;
    }
    else {
        std::cout << "You are a senior." << std::endl;
    }
}