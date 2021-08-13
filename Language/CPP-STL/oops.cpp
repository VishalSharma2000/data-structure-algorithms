#include <bits/stdc++.h>

/* Class actually does not represent a data it's actually represent a blueprint of an actual entity
So, when we want to create an employee we can use this blue print to use it as a model. */

/* 
    Access Modifiers 
        public => accessible outside the class
        private => accessible only inside the class
        protected => in between private and public, has some rules of accessibility
*/

/*
Pillars of Object Oriented Programming
1) Encapsulation => keeping all related variables and functions at one place
2) Abstraction => showing only that much data to the outer world as much they want
3) Inheritance => inheriting the attributes and behaviour of the parent child
4) Polymorphism => method overriding and method over loading
*/

/* 
  Abstract class vs abstraction

  abstract class is basically a class with abstract function (is a function with no body) whereas abstraction is the concept of the oops
  where we show only necessary data to the outer world

  need for creating abstract class ?
  abstract class can be thought as kind of necessary functions can should be implemented when a particular object is created. Basically we are forcing the object to give defination of this necessary functions

  for eg:
  when a new employee is created then we can make an abstrac class having fucntion declaration of department, branch, project like below

  class AbstractEmployee {
    virtual void defineDepartment() = 0;
    virtual void defineBranch() = 0;
    virtual void defineProject() = 0;
  };

  class Employee : AbstractEmployee {
  public:  
    void defineDepartment() {

    }

    void defineBranch () {

    }

    void defineProject () {

    }
  };
 */

class Employee {
    // members are attributes and behaviours
    // attributes are basically variables and behaviours are functions 
    public:
        string name, companyName;
        int age;
    
        Employee(string name, string companyName, int age) {
            this->name = name;
            this->companyName = companyName;
            this->age = age;
        }
    
        void introduce() {
            cout << name + " " + companyName + " " + to_string(age) << endl;
        }
};

int main() {
    Employee e1 = Employee("Vishal Sharma", "Publicis Sapient", 21);
    Employee *e2 = new Employee("Gaurav Sharma", "Jagdish Enterprises", 10);
    e1.introduce();
    e2->introduce();
}