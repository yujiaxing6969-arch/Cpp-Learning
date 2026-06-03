#include <iostream>
#include <cstring>
class Student{
private:
    char *name;
public:
    Student(const char* newname = "Tom"){
        name = new char[strlen(newname) +1];
        strcpy(name,newname);
        std::cout << "普通构造函数\n";
    }
    // Student(const Student &other){
    //     name = new char[strlen(other.name) + 1];
    //     strcpy(name, other.name);
    //     std::cout << "拷贝构造函数\n";
    // }
    Student(const Student& other):name(other.name){
        std::cout << "浅拷贝构造\n";
    }
    ~Student(){
        delete[] name;
        std::cout <<"析构函数\n";
    }
    void setName(const char *newName){
        delete[] name;
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }
    void print() const{
        std::cout << "Name: "<<name <<std::endl;
    }
};
int main(){
    Student s1("Tom");
    Student s2 = s1;
    s1.print();
    s2.print();

    s2.setName("Apple");
    s1.print();
    s2.print();
    return 0;
}