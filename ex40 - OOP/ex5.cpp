#include <iostream>

class AbstractEmployee {
public:
    virtual void AskForPromotion() = 0;
};

class Employee : public AbstractEmployee {
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
    virtual void Work() { 
        std::cout << name << " is checking email, task backlog" << std::endl;
    }
};

class Developer : public Employee {
public:
    std::string favProgrammingLanguage;
    Developer(std::string Name, std::string Company, int Age, std::string FavProgrammingLanguage)
        : Employee(Name, Company, Age) {
        favProgrammingLanguage = FavProgrammingLanguage;
    }
    void FixBug() {
        std::cout << getName() << " fixed bug using " << favProgrammingLanguage << std::endl;
    }
    void Work() override { 
        std::cout << getName() << " is writing " << favProgrammingLanguage << " code" << std::endl;
    }
};

class Teacher : public Employee {
public:
    std::string subject;
    Teacher(std::string Name, std::string Company, int Age, std::string Subject)
        : Employee(Name, Company, Age) {
        subject = Subject;
    }
    void PrepareLesson() {
        std::cout << getName() << " is preparing " << subject << " lesson" << std::endl;
    }
    void Work() override { 
        std::cout << getName() << " is teaching " << subject << std::endl;
    }
};

int main() {
    Developer d("Saldina", "YT-CodeBeauty", 25, "C++");
    Teacher t("Jack", "Cool School", 35, "History");

    Employee* e1 = &d;
    Employee* e2 = &t;

    e1->Work();
    e2->Work();

    d.FixBug();
    d.AskForPromotion();
    t.PrepareLesson();
    t.AskForPromotion();
    
    return 0;
}
