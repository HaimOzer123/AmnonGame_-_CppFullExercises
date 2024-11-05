#include <iostream>

//pass structs as template arguments

struct student {
    std::string name;
    int age;
    bool enrolled;
    double gpa;
};

void print_student(student &s);

int main(){

    student s1 = {"John", 20, true, 3.5};
    student s2 = {"Jane", 21, false, 3.8};
    student s3 = {"Jack", 22, true, 3.9};

    print_student(s1);
    print_student(s2);
    print_student(s3);

    return 0;
}

void print_student(student &s){
    std::cout << "Name: " << s.name << '\n';
    std::cout << "Age: " << s.age << '\n';
    std::cout << "Enrolled: " << s.enrolled << '\n';
    std::cout << "GPA: " << s.gpa << '\n';
    std::cout << "address of s: " << &s << '\n';
    std::cout << "********************************************" << '\n';
}

