#include <iostream>

void drawboard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main() {
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawboard(spaces);
    while (running){
    playerMove(spaces, player);
    drawboard(spaces);
        if (checkWinner(spaces, player, computer)){
        running = false;
        break;
    }
     else if (checkTie(spaces)){
        running = false;
        break;
    }
    computerMove(spaces, computer);
    drawboard(spaces);
        if (checkWinner(spaces, player, computer)){
        running = false;
        break;
     }
      else if (checkTie(spaces)){
        running = false;
        break;
    }
    }
    std :: cout << "Thanks for playing!" << '\n';
    return 0;
}

void drawboard(char *spaces){
    std::cout << '\n' << "     |     |     "<<'\n';
    std::cout << "  "<<spaces[0]<<"  |  "<<spaces[1]<<"  |  "<<spaces[2]<<"  "<<'\n';
    std::cout << "_____|_____|_____"<<'\n';
    std::cout << "     |     |     "<<'\n';
    std::cout << "  "<<spaces[3]<<"  |  "<<spaces[4]<<"  |  "<<spaces[5]<<"  "<<'\n';
    std::cout << "_____|_____|_____"<<'\n';
    std::cout << "     |     |     "<<'\n';
    std::cout << "  "<<spaces[6]<<"  |  "<<spaces[7]<<"  |  "<<spaces[8]<<"  "<<'\n';
    std::cout << "     |     |     "<<'\n' << '\n';
}
void playerMove(char *spaces, char player){
    int num;
    do{
        std::cout << "Enter a spot to place a mark (1-9): ";
        std::cin >> num;
        if (spaces[num-1] == ' '){
            spaces[num-1] = player;
            break;
        } else {
            std::cout << "Spot already taken. Try again." << '\n';
        }
    } while (!num > 0 || !num < 8);
}
void computerMove(char *spaces, char computer){
    int num;
    srand(time(0));

    while (true){
        num = rand() % 9;
        if (spaces[num] == ' '){
            spaces[num] = computer;
            break;
        }
    }
}
bool checkWinner(char *spaces, char player, char computer) {
    if ((spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]) ||
        (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]) ||
        (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]) ||
        (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]) ||
        (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]) ||
        (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]) ||
        (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]) ||
        (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6])) {
        if (spaces[0] == player || spaces[3] == player || spaces[6] == player || spaces[4] == player) {
            std::cout << "Player wins!" << '\n';
        } else {
            std::cout << "Computer wins!" << '\n';
        }
        return true;
    }
    return false;
}
bool checkTie(char *spaces) {
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false;  // There's at least one empty space, so no tie yet
        }
    }
    std::cout << "It's a tie!" << '\n';
    return true;  // All spaces are filled with no winner
}
