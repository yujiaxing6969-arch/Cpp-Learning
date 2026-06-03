#include <iostream>

class Student
{
private:
    std::string name;
public:
    Student(const std::string& name):name(name)
    {
        std::cout << "普通构造函数\n";
    }
    Student(const Student& other): name(other.name)
    {
        std::cout<< "拷贝构造函数\n";
    }
    void print() const {
        std::cout << "Name: "<<name <<std::endl;
    }
    void setName(const std::string& name){
        this->name = name;
    }
};

int main()
{
    Student s1("Tom");

    Student s2 = s1;

    s2.setName("Jerry");
    s1.print();
    s2.print();

    return 0;
}