#include <iostream>

int main(){
    //dynamic memory example and exsercise

    int *pNum = NULL;

    pNum = new int; //allocate memory for an int variable on the heap and store the address in pNum

    *pNum = 21; //store 21 in the memory location pNum points to

    std ::cout <<"value:" << *pNum << '\n';
    std ::cout << "adreess" <<pNum << '\n';
    
    delete pNum; //deallocate the memory

    char *pGrade = NULL;
    int size;
    std::cout << "how many grades do you want to enter?";
    std::cin >> size;

    pGrade = new char[size];

    for (int i = 0; i < size;i++){
        std::cout << "Enter grade" << i + 1 << ":";
        std::cin >> pGrade[i];
    }

    std::cout << "grades:";
    for (int i = 0; i < size; i++){
        std::cout << pGrade[i] << " | ";
    }

        return 0;
}