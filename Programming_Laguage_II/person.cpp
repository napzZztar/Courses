#include <iostream>
using namespace std;


class Person{
    private: 
        string name;
        int age;
        string dob;

    public:
        void setName(string name){
            this->name = name;
        }

        void setAge(int age){
            this->age = age;
        }

        void setDob(string dob){
            this->dob = dob;
        }

        void getName(){
            cout<<this->name<<endl;
        }

        void getAge(){
            cout<<this->age<<endl;
        }

        void getDob(){
            cout<<this->dob<<endl;
        }

        void display(){
            cout<<this->name<<endl;
            cout<<this->age<<endl;
            cout<<this->dob<<endl;
        }
};

int main(){
    Person person;

    person.setName("You know who");
    person.setAge(19999);
    person.setDob("12-30-1111");

    person.display();

    return 0;
}
