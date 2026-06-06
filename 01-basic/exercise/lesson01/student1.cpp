#include <iostream>
#include <cstring>
#include <utility>
class Student{
private:
    char * name;

public:
    Student(const char * newName){
        name = new char[strlen(newName) + 1];
        strcpy(name,newName);
        std::cout << "普通构造\n";
    }

    Student(const Student &other){
        if(other.name == nullptr){
            name = nullptr;
        }
        else{
            name = new char[strlen(other.name)+1];
            strcpy(name,other.name);
        }
        std::cout<<"拷贝构造\n";
        
    }

    Student & operator=(const  Student &other){
        if(this == &other){
            return *this;
        }
        if(other.name == nullptr){
            delete[] name;
            name = nullptr;
            return *this;
        }
        
        char *newName = new char[strlen(other.name)+1];
        strcpy(newName, other.name);
        delete[] name;
        name = newName;
        std::cout <<"拷贝赋值\n";
        return *this;
    }


    Student( Student&& other) noexcept{
        name = other.name;
        other.name = nullptr;
        std::cout <<"移动构造\n";
        
    }

    Student & operator= ( Student&& other) noexcept{
        if(this == &other){
            return *this;
        }
        delete[] name;
        name = other.name;
        other.name = nullptr;
        std::cout << "移动赋值\n";
        return *this;
    }

    ~Student(){
        delete[] name;
        std::cout <<"析构\n";
    }

    void print() const{
        if(name == nullptr){
            std::cout<< "Name: nullptr\n";
        }else{
            std::cout<< "Name: "<<name<<std::endl;
        }
    }
    void setName(const char *newName){
        delete[] name;
        name = new char[strlen(newName)+1];
        strcpy(name, newName);
    }
};

Student createStudent() {
    Student temp("Alice");
    return temp;
}
int main(){

    Student a("Tom");
    Student b = std::move(a);

    Student c("Jerry");
    c = a;

    Student d = a;

    a.print();
    b.print();
    c.print();
    d.print();
    return 0;
}