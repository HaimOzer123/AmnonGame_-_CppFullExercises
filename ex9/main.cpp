#include <iostream>

int main(){
    // type conversion
    int correct = 8;
    int questions = 10;
    double score = correct / (double) questions * 100;  //using type conversion to get the correct score
    std::cout << "Your score is: " << score << "%" << '\n';
    return 0;

}