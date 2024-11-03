#include <iostream> 

int main () {
    int soda_count = 5;
    int cola_count = 5;
    int coffee_count = 5;

    int selected_drink = 0;
    while (true){
    std::cout << "Please select a drink: \n" "1 for soda\n" "2 for cola\n" "3 for coffee\n" "4 for maintenance\n" "5 for quit" << std::endl;
    std::cin >> selected_drink;
    std::cout << "You selected: " << selected_drink << std::endl;


        if (selected_drink == 1) {
            if (soda_count > 0) {
                soda_count--;
                std::cout << "Enjoy your soda!" << std::endl;
                std::cout << "Soda count: " << soda_count << std::endl;
            } else {
                std::cout << "Sorry, we are out of soda." << std::endl;
            }
        } else if (selected_drink == 2) {
            if (cola_count > 0) {
                cola_count--;
                std::cout << "Enjoy your cola!" << std::endl;
                std::cout << "Cola count: " << cola_count << std::endl;
            } else {
                std::cout << "Sorry, we are out of cola." << std::endl;
            }
        } else if (selected_drink == 3) {
            if (coffee_count > 0) {
                coffee_count--;
                std::cout << "Enjoy your coffee!" << std::endl;
                std::cout << "Coffee count: " << coffee_count << std::endl;
            } else {
                std::cout << "Sorry, we are out of coffee." << std::endl;
            }
        } else if (selected_drink == 4) {
            // show the drink counts and make a manue to refill the drinks
            std::cout << "Soda count: " << soda_count << std::endl;
            std::cout << "Cola count: " << cola_count << std::endl;
            std::cout << "Coffee count: " << coffee_count << std::endl;
            std::cout << "Please select a drink to refill:\n" "1 for soda\n" "2 for cola\n" "3 for coffee" << std::endl;
            std::cin >> selected_drink;
            if (selected_drink == 1) {
                soda_count += 5; // refill 5 drinks
                std::cout << "Soda count: " << soda_count << std::endl;
            } else if (selected_drink == 2) {
                cola_count += 5; // refill 5 drinks
                std::cout << "Cola count: " << cola_count << std::endl;
            } else if (selected_drink == 3) {
                coffee_count += 5; // refill 5 drinks
                std::cout << "Coffee count: " << coffee_count << std::endl;
            } else {
                std::cout << "Invalid selection." << std::endl;
            }
        }
        else if (selected_drink == 5) {
            std::cout << "Soda count: " << soda_count << std::endl;
            std::cout << "Cola count: " << cola_count << std::endl;
            std::cout << "Coffee count: " << coffee_count << std::endl;
            std::cout << "\n\nGoodbye!" << std::endl;
            break;
        }
        else {
            std::cout << "Invalid selection." << std::endl;
        }
    }
}