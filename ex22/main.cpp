#include <iostream>

//rock-paper-scissors game from r/p/s 

char get_user_choice() {
    char choice;
    std::cout << "Enter your choice (r/p/s): ";
    std::cin >> choice;
    return choice;
}

char get_computer_choice() {
    return 'r';
}

void print_winner(char user, char computer) {
    if (user == computer) {
        std::cout << "It's a tie!\n";
    } else if ((user == 'r' && computer == 's') ||
               (user == 'p' && computer == 'r') ||
               (user == 's' && computer == 'p')) {
        std::cout << "You win!\n";
    } else {
        std::cout << "You lose!\n";
    }
}

//add play again function
bool play_again() {
    char choice;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> choice;
    return choice == 'y';
}

//add win count and lose count 
int main() {
    int win_count = 0;
    int lose_count = 0;
    do {
        char user = get_user_choice();
        char computer = get_computer_choice();
        print_winner(user, computer);
        if (user == computer) {
            // do nothing
        } else if ((user == 'r' && computer == 's') ||
                   (user == 'p' && computer == 'r') ||
                   (user == 's' && computer == 'p')) {
            win_count++;
        } else {
            lose_count++;
        }
    } while (play_again());
    std::cout << "You won " << win_count << " times and lost " << lose_count << " times.\n";
    return 0;
}