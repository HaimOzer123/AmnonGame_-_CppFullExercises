#include <iostream>
#include <string>

// abstract class example
class AbstractEmployee {
    virtual void AskForPromotion() = 0;
};

class Employee : public AbstractEmployee {  // public inheritance
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
        name = Name;      // Corrected assignment
        company = Company; // Corrected assignment
        age = Age;         // Corrected assignment
    }
    void AskForPromotion() override {
        if (age >= 30)
            std::cout << name << " got promoted!" << std::endl;
        else
            std::cout << name << ", sorry no promotion for you!" << std::endl;
    }
};

int main() {
    Employee employee1 = Employee("Saldina", "YT-CodeBeauty", 25);
    Employee employee2 = Employee("John", "Amazon", 35);

    employee1.AskForPromotion();
    employee2.AskForPromotion();

    return 0;
}
