#include <iostream>

//object oriented programming in c++ exsercise
//object oriented programming is a programming paradigm that uses objects to design applications and computer programs
//objects are instances of classes that can interact with one another to design applications and computer programs
//classes are blueprints that define the properties and behaviors of objects
//properties are the attributes of objects
//behaviors are the actions that objects can perform
//encapsulation is the bundling of data and methods that operate on the data into a single unit
//inheritance is the mechanism that allows one class to inherit properties and behaviors from another class
//polymorphism is the ability of objects to take on different forms

class Humen{
    public:
        std::string name;
        int age;
        std::string occupation;

        void eat(){
            std::cout << name << " is eating \n";
        }
        void sleep(){
            std::cout << name << " is sleeping \n";
        }
        void work(){
            std::cout << name << " is working \n";
        }
};

class Car{
    int speed;
    int weight;

    public:
        std::string make;
        std::string model;
        int year;
        std :: string color;

        void accelerate(){
            std::cout << "The car is accelerating \n";
        }
        void brake(){
            std::cout << "The car is braking \n";
        }
};

int main(){
    Humen h1;
    h1.name = "John";
    h1.age = 20;
    h1.occupation = "student";

    Humen h2;
    h2.name = "Jane";
    h2.age = 21;
    h2.occupation = "teacher";

    Humen h3;
    h3.name = "Jack";
    h3.age = 22;
    h3.occupation = "doctor";
 
    h1.eat();
    h2.sleep();
    h3.work();

    std :: cout << "********************************************" << '\n';
    std :: cout << "Name: " << h1.name << "|"<< h2.name << "|" << h3.name << '\n';
    std :: cout << "Age: " << h1.age << "|"<< h2.age << "|" << h3.age << '\n';
    std :: cout << "Occupation: " << h1.occupation << "|"<< h2.occupation << "|" << h3.occupation << '\n';
    std :: cout << "********************************************" << '\n';

    Car c1;
    c1.make = "Toyota";
    c1.model = "Corolla";
    c1.year = 2021;
    c1.color = "black";
    c1.accelerate();
    c1.brake();

    std :: cout << "********************************************" << '\n';
    std :: cout << "Make: " << c1.make << '\n';
    std :: cout << "Model: " << c1.model << '\n';
    std :: cout << "Year: " << c1.year << '\n';
    std :: cout << "Color: " << c1.color << '\n';
    std :: cout << "********************************************" << '\n';
    
    return 0;
}