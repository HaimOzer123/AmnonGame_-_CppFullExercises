#include <iostream>

//recursion example

void walk(int steps);
void walk1(int steps);
int factorial(int num);


int main(){
    walk(5);
    walk1(5);
    std::cout << factorial(10) << '\n'; //3628800

    return 0;
}

void walk(int steps){
    if (steps > 0){
        std::cout << "steps remaining:" << steps << '\n';
        walk(steps - 1);
    }else{
        std::cout << "done walking" << '\n';
    }
}

void walk1(int steps){
    for (int i = steps; i > 0; i--){
        std::cout << "steps remaining:" << i << '\n';
    }
    std::cout << "done walking" << '\n';
}

int factorial(int num){
    if (num > 1){
        return num * factorial(num - 1);
    }
    else {
        return 1;
    }
}
