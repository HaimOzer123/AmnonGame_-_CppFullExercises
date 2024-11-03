#include <iostream>
#include <vector>

// //typedef std::vector<std::pair<std::string, int>> pairlist_t;
// typedef std::string text_t;
// typedef int number_t;
using number_t = int;
using text_t = std::string;

int main () { 
    
    text_t text = "Hello World!";
    std::cout << text << '\n';
    number_t number = 42;
    std::cout << number << '\n';
    
    return 0;
}