#include <iostream>

class Employee{
public:
    std::string name;
    std::string company;
    int age;

    void IntroduceYourself(){
        std::cout << "\n" << "Name - " << name << "\n";
        std::cout << "Company - " << company << "\n";
        std::cout << "Age - " << age << "\n";
    }

    Employee(std::string name, std::string company, int age){
        this -> name = name;
        this -> company = company;
        this -> age = age;

    }
};

int main(){
    
    Employee e1=Employee("Saldina", "YT-CodeBeauty", 22);
    // e1.name = "hololololololololo";
    // e1.age = 21;
    // e1.company = "ololololololololo";
    Employee e2=Employee("Dick", "YT", 22);
    // e2.name = "Saldina";
    // e2.age = 22;
    // e2.company = "Youtube"; 

    e1.IntroduceYourself();
    e2.IntroduceYourself();
}