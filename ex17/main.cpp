#include <iostream>

int main(){
    std::string name;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    
    if(name.empty()){
        std::cout << "You did not enter a name." << std::endl;
    } else if (name.length() > 10){
        std::cout << "Your name is too long." << std::endl;
    } else {
        std::cout << "Hello, " << name << "!" << std::endl;
    }

    name.append("@gmail.com");
    std::cout << "Your email is: " << name << std::endl;

}