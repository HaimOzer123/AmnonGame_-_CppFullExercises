#include <iostream>

//constructor example

class Student{
    public:
        std::string name;
        int age;
        double gpa;

    Student (std::string name, int age, double gpa){
        this -> name = name;
        this -> age = age;
        this -> gpa = gpa;
    }
};

int main(){
    Student student1("Spongebob", 21, 3.6);
    Student student2("Pam", 22, 3.8);

    std :: cout <<"name "<< student1.name << '\n';
    std :: cout <<"age "<< student1.age << '\n';
    std :: cout <<"gpa "<< student1.gpa << '\n';
    std :: cout <<"name "<< student2.name << '\n';
    std :: cout <<"age "<< student2.age << '\n';
    std :: cout <<"gpa "<< student2.gpa << '\n';
    return 0;
}