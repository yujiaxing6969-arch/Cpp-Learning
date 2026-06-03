#include <iostream>

class Student{
private:
    char *name;
public:
    Student(): name("Tom") {
        std::cout <<"constrtucted success!"<<std::endl;
    }

    Student(char * name): name(name){
        std::cout <<"constructed with value success!"<<std::endl;
    }

    Student(const Student & other):name(other.name){
        std::cout<<"constructed with other success!"<<std::endl;
    }
    ~Student(){
        std::cout<<"deconstructed success!"<<std::endl;
    }
    void setName(const char *newName) {
        *this->name  = *newName; 
    }
    void print() const {
        std::cout << "Name :"<< name<<std::endl;
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