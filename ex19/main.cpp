#include <iostream> 

// void happyBirthday(){
//     std::cout << "Happy Birthday to you!\n""Happy Birthday to you!\n" "Happy Birthday to you!\n" "Happy Birthday to you!\n" << std::endl;
// }

//declaring a function
void happyBirthday(std::string name, int age);

int main(){
    std::string name = "Haim";
    int age = 20;

    happyBirthday(name, age);
        return 0;
}

//defining a function
void happyBirthday(std::string name, int age){
    std::cout << "Happy Birthday to you!\n";
    std::cout<< "Happy Birthday dear " << name << "!\n";
    std::cout<< "Happy Birthday to you!\n" << std::endl;
    std::cout <<"\n" "\n" "You are now " << age << " years old!" "\n" "\n" "____________GZ___________" << std::endl;

}
