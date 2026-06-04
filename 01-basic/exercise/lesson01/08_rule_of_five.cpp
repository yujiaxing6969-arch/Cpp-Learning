#include <iostream>
#include <utility>
#include <string>
class Student{
private:
    std::string name;

public:
    Student():name("Tom"){
        std::cout<<"默认构造函数\n";
    }

    Student(std::string newName):name(newName){
        std::cout<<"普通构造函数\n";
    }

    void print(){
        std::cout <<"Name: "<<name<<std::endl;
    }
    
};


int main(){

    Student s1("Tom");
    Student s2 = s1;
    Student s3(std::move(s1));

    s2.print();
    s3.print();
    return 0;
}