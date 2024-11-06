//inheritance example
#include <iostream>

class AbstractEmployee {
    virtual void AskForPromotion() = 0;
};

class Employee : AbstractEmployee {
private:
    std::string name;
    std::string company;
    int age;
public:
    void setName(std::string Name) {
        name = Name;
    }
    std::string getName() {
        return name;
    }
    void setCompany(std::string Company) {
        company = Company; 
    }
    std::string getCompany() {
        return company;
    }
    void setAge(int Age) {
        age = Age; 
    }
    int getAge() {
        return age;
    }
    void IntroduceYourself() {
        std::cout << "Name - " << name << std::endl;
        std::cout << "Company - " << company << std::endl;
        std::cout << "Age - " << age << std::endl;
    }
    Employee(std::string Name, std::string Company, int Age) {
        name = Name;      
        company = Company; 
        age = Age;         
    }
    void AskForPromotion() override {
        if (age >= 30)
            std::cout << name << " got promoted!" << std::endl;
        else
            std::cout << name << ", sorry no promotion for you!" << std::endl;
    }
};

class Developer :public Employee {
public:
    std::string favProgrammingLanguage;
    Developer(std::string Name, std::string Company, int Age, std::string FavProgrammingLanguage)
        : Employee(Name, Company, Age) {
        favProgrammingLanguage = FavProgrammingLanguage;
    }
    void FixBug() {
        std::cout << getName() << " fixed bug using " << favProgrammingLanguage << std::endl;
    }
};

class Teacher :public Employee {
public:
    std::string subject;
    void PrepareLesson() {
        std::cout << getName() << " is preparing " << subject << " lesson" << std::endl;
        std::cout << "Name - " << getName() << std::endl;
        std::cout << "Company - " << getCompany() << std::endl;
        std::cout << "Age - " << getAge() << std::endl;
    }
    Teacher(std::string Name, std::string Company, int Age, std::string Subject)
        : Employee(Name, Company, Age) {
        subject = Subject;
    }
};

int main() {
    Employee employee1 = Employee("Sara", "PornHub", 25);
    Employee employee2 = Employee("John", "Amazon", 35);

    Developer d = Developer("Saldina", "YT-CodeBeauty", 25, "C++");
    d.FixBug();
    d.AskForPromotion();

    Teacher t = Teacher("Jack", "Cool School", 35, "History");
    t.PrepareLesson();
    t.AskForPromotion();

    
    employee1.AskForPromotion();
    employee2.AskForPromotion();

    employee1.IntroduceYourself();
    employee2.IntroduceYourself();
    
    return 0;
}
