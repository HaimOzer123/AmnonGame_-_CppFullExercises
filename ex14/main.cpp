#include <iostream> 

int main(){
    int grade = 75;
    grade >= 60 ? std::cout << "you pass" : std::cout << "you fail";

    int number = 9;
    number % 2 == 1 ? std::cout << "odd" : std::cout << "even";

    bool houngy = true;
    houngy ? std::cout << "houngy" : std::cout << "not houngry";
    return 0;
    
}