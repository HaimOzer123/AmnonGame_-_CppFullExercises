#include <iostream>

int main(){
    int num;
    int guess;
    int tries = 0;

    srand(time(NULL));
    num = (rand() % 100) + 1;
    std::cout<<"**********Welcome to the Number Guessing Game**********"<<std::endl;
    
    do{
        std::cout << "Guess a number between 1 and 100: ";
        std::cin >> guess;
        tries++;

        if(guess > num){
            std::cout << "Too high!" << std::endl;
        } else if (guess < num){
            std::cout << "Too low!" << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number in " << tries << " tries." << std::endl;
            std::cout << "The number was: " << num << std::endl;
        }
    } while (guess != num);

    std::cout << "***** Thanks for playing! *******" << std::endl;
    
}