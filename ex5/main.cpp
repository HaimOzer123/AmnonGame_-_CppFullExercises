#include <iostream>

int main(){
    //int (integer) - 4 bytes - used to store whole numbers
    int x = 5;

    //float - 4 bytes - used to store decimal numbers
    float y = 3.14;

    //double - 8 bytes - used to store decimal numbers
    double y = 3.14;

    //char - 1 byte - used to store single characters
    char z = 'a';

    //bool - 1 byte - used to store true or false
    bool w = true;
    bool v = false;

    //string - used to store text - it is not a built-in data type
    std::string s = "Hello, World!";
    std::string t = "Hello, World!";

    //array - used to store multiple values of the same type
    int arr[5] = {1, 2, 3, 4, 5};
    float arr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char arr[5] = {'a', 'b', 'c', 'd', 'e'};
    bool arr[5] = {true, false, true, false, true};
    double arr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

    //auto - used to automatically determine the data type
    auto a = 5;
    auto b = 3.14;
    auto c = 'a';
    auto d = true;
    auto e = "Hello, World!";
    auto f = {1, 2, 3, 4, 5};

    //const - used to define constants - the value cannot be changed after initialization -like read-only variables
    const int g = 5;
    const float h = 3.14;
    const char i = 'a';
    const bool j = true;
    const std::string k = "Hello, World!";
    const int arr[5] = {1, 2, 3, 4, 5};
    const float arr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    const char arr[5] = {'a', 'b', 'c', 'd', 'e'};
    const bool arr[5] = {true, false, true, false, true};
    const double arr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

    //costexpr - used to define constants that can be evaluated at compile time - the value cannot be changed after initialization
    constexpr int l = 5;
    constexpr float m = 3.14;
    constexpr char n = 'a';
    constexpr bool o = true;
    
    constexpr int arr[5] = {1, 2, 3, 4, 5};
    constexpr float arr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    constexpr char arr[5] = {'a', 'b', 'c', 'd', 'e'};
    constexpr bool arr[5] = {true, false, true, false, true};
    constexpr double arr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

    //pointer - used to store the memory address of a variable - used to access the value of a variable indirectly
    int p = 5;
    int *q = &p;

    //reference - used to create an alias for a variable - used to access the value of a variable directly
    int r = 5;
    int &s = r;

    //enum - used to define a set of named constants - the value of an enum variable must be one of the values in the enum list
    enum Color {RED, GREEN, BLUE};
    Color color = RED;

}