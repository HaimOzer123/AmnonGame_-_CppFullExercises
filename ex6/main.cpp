#include <iostream>

namespace first{
    int x = 1;
    int y = 2;
}
namespace second{
    int x = 2;
    int y = 1;
}

int main(){
    const double pi = 3.14;
    std::cout << "The value of pi is: " << pi << std::endl;
    const int lightSpeed = 299792458;
    std::cout << "The speed of light is: " << lightSpeed << " m/s" << std::endl;
    const int gravity = 9.81;
    std::cout << "The acceleration due to gravity is: " << gravity << " m/s^2" << std::endl;

    int x = 0;
    std::cout << "The value of x is: " << x << std::endl;
    std::cout << "The value of x in the first namespace is: " << first::x << std::endl;
    std::cout << "The value of x in the second namespace is: " << second::x << std::endl;

    using namespace first;
    std::cout << "The value of y is: " << y << std::endl;
    std::cout << "The value of y in the second namespace is: " << second::y << std::endl;
    return 0;
}