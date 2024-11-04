#include <iostream>

int main () {
    int students = 20;

    //students = students + 1; will add 1 to the value of students
    // students += 1;  // will add 1 to the value of students
    // students ++; // will add 1 to the value of students

    // students = students - 2; // will subtract 2 from the value of students
    // students -= 2; // will subtract 2 from the value of students
    // students --; // will subtract 1 from the value of students

    // students = students * 2; // will multiply the value of students by 2
    // students *= 2; // will multiply the value of students by 2

    // students = students / 2; // will divide the value of students by 2
    // students /= 2; // will divide the value of students by 2

    // students = students % 2; // will give the remainder of the division of students by 2
    //using to check even or odd numbers

    int students2 = 10 - 5 * 2 + 3 / 2 % 2; // 10 - 10 + 1 = 1
    int students3 = 10 - (5 * 2 + 3) / 2 % 2; // 10 - 13 / 2 % 2 = 10 - 6 % 2 = 10 - 0 = 10
    int students4 = 10 - 5 * (2 + 3) / 2 % 2; // 10 - 5 * 5 / 2 % 2 = 10 - 25 / 2 % 2 = 10 - 12 % 2 = 10 - 0 = 10
    // int students5 = 10 - 5 * 2 + 3 / (2 % 2); // 10 - 10 + 3 / 0 = 10 - 10 + 0 = 0
    int students6 = 10 - 5 * 2 + 3 / 2 % (2); // 10 - 10 + 3 / 2 % 2 = 10 - 10 + 1 = 1
    int students7 = 10 - 5 * 2 + 3 / 2 % 2; // 10 - 10 + 3 / 2 % 2 = 10 - 10 + 1 = 1

    std::cout << students << '\n';
    std::cout << students2 << '\n';
    std::cout << students3 << '\n';
    std::cout << students4 << '\n';
    // std::cout << students5 << '\n';
    std::cout << students6 << '\n';
    std::cout << students7 << '\n';

    return 0;
    }   