#include <iostream>

// credit card validation
// 6011000990139424

//luhn algorithm
//1. double every second digit from right to left. 
//If doubling of a digit results in a two-digit number, add up the two digits to get a single-digit number.
//2. Add all single digit numbers from step 1.
//3. Add all digits in the odd places from right to left in the card number.
//4. Sum the results from steps 2 & 3.
//5. If the result from step 4 is divisible by 10, the card number is valid; otherwise, it is invalid.

// 6011 0009 9013 9424 // card number
// 122 00 182 184 // double every second digit, mean 6 1  0 0  9 1  9 2 > 6*2=12 1*2=2 0*2=0 0*2=0 9*2=18 1*2=2 9*2=18 2*2=4 
// 1+2+2+0+0+1+8+2+1+8+4 = 29 // sum of all single digit numbers from step 1
// 0 1  0 9  0 3  4 4 // sum of all digits in the odd places from right to left in the card number
// 0+1+0+9+0+3+4+4 = 21
// 29 + 21 = 50
// 50 % 10 = 0 = valid

int getDigit(const int number);
int sumOddDigits(const std::string cardNumber);
int sumEvenDigits(const std::string cardNumber);

int main() {
    std::string cardNumber;
    int result=0;

    std::cout << "Enter credit card numbers: ";
    std::cin >> cardNumber;

    result = sumEvenDigits(cardNumber) + sumOddDigits(cardNumber);

    if (result % 10 == 0){
        std::cout << "Valid card number" << std::endl;
        std::cout << "card number: " << cardNumber << std::endl;
    } else {
        std::cout << "Invalid card number" << std::endl;
        std::cout << "card number: " << cardNumber << std::endl;
    }

    return 0;
}

int getDigit(const int number){
    // 18 % 10 + ( 18 / 10 % 10) = 8 + 1 = 9
    return number % 10 + (number / 10 % 10); // return the sum of the two digits
}
int sumOddDigits(const std::string cardNumber){
    int sum = 0;
    for (int i = cardNumber.size() - 1; i >= 0; i -= 2){ // sum all digits in the odd places from right to left
        sum += cardNumber[i] - '0';
    }
    return 0;
}
int sumEvenDigits(const std::string cardNumber){
    int sum = 0;
    for (int i = cardNumber.size() - 2; i >= 0; i -= 2){ // double every second digit from right to left
        sum += getDigit((cardNumber[i] - '0' ) * 2);
    }
    return sum;
}
