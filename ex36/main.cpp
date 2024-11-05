#include <iostream> 

struct student {
    std::string name;
    int age;
    bool enrolled;
    double gpa;
    bool gender;
};

int main () {
    student s1 = {"John", 20, true, 3.5, true};
    student s2 = {"Jane", 21, false, 3.8, false};
    student s3 = {"Jack", 22, true, 3.9, true};

    std :: cout << "Name: " << s1.name << "|"<< s2.name << "|" << s3.name << '\n';
    std :: cout << "Age: " << s1.age << "|"<< s2.age << "|" << s3.age << '\n';
    std :: cout << "Enrolled: " << s1.enrolled << "|"<< s2.enrolled << "|" << s3.enrolled << '\n';
    std :: cout << "GPA: " << s1.gpa << "|"<< s2.gpa << "|" << s3.gpa << '\n';
    std :: cout << "********************************************" << '\n';
    return 0;
}