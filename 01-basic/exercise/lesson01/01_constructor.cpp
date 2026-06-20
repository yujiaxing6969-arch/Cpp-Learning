#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int age;

public:
   Student() : name("noname"), age(18){
    std::cout <<"默认构造函数\n";
   }

   Student(const std::string &newstring):
    name(newstring), age(18){
        std::cout<<"只传名字的构造\n";
    }

    Student(int newAge):name("noname"),age(newAge){
        std::cout<<"只传年龄的构造\n";
    }
    Student(const std::string &newstring, int newAge):
    name(newstring), age(newAge){
        std::cout<<"普通构造\n";
    }

    ~Student(){
        std::cout<<"析构函数: "<<name<<"\n";
    }

    void print() const {
        std::cout << "Name: " << name << " Age: " << age << '\n';
    }
};

int main() {
    Student s1;
    s1.print();

    Student s2("Tom", 20);
    s2.print();

    Student s3("Jerry");
    s3.print();

    Student s4(25);
    s4.print();

    Student s5{"Alice", 30};
    s5.print();

    Student s6{"Bob"};
    s6.print();

    Student s7{40};
    s7.print();
    return 0;
}
