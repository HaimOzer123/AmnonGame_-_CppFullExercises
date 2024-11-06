#include <iostream>

//Encapsulation example

class Employee{
    private:
        std::string name;
        std :: string company;
        int age;
    public:
        void setName(std::string name){
            name = name;
        }
        std::string getName(){
            return name;
        }
        void setCompany(std::string company){
            company = company;
        }
        std::string getCompany(){
            return company;
        }
        void setAge(int Age){
            Age = age;
         }
        int getAge(){
            return age;
        }
        void IntroduceYourself(){
            std::cout << "Name - " << name << std::endl;
            std::cout << "Company - " << company << std::endl;
            std::cout << "Age - " << age << std::endl;
        }
        Employee(std::string name, std::string company, int age){
            name = name;
            company = company;
            age = age;
        }
};

int main(){
    Employee employee1 = Employee("Saldina", "YT-CodeBeauty", 25);
    employee1.IntroduceYourself();
    Employee employee2 = Employee("John", "Amazon", 35);
    employee2.IntroduceYourself();

    employee1.setName("Saldina");
    employee1.setAge(35);
    std::cout << employee1.getName() << " is " << employee1.getAge() << " years old." << "\n";
    
    std::cout << "check IntroduceYourself() method after setting name and age" << "\n";
    employee1.IntroduceYourself();
    return 0;
    }