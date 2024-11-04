#include <iostream>

void swap(std::string &x, std::string &y){
    std::string temp;
    temp = x;
    x = y;
    y = temp;
}

int main(){
    std::string x = "Water";
    std::string y = "melon";
    std::string temp;

    temp = x;
    x = y;
    y = temp;
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';

    swap(x,y);

    std::cout << "After swap" << '\n';
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
    return 0;
}

