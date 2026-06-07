#include <iostream>
#include <string>
#include <utility>

class Student {
private:
    std::string name;
    int age;

public:
    explicit Student(std::string newName, const int newAge)
        : name(std::move(newName)),age(newAge) {
        std::cout << "普通构造\n";
    }

    void setName(std::string newName) {
        name = std::move(newName);
    }

    void print() const {
        std::cout << "Name: " << name << '\n'
        << "Age: " << age << "\n";
    }
};

Student createStudent() {
    Student temp("Alice",10);
    return temp;
}

int main() {
    Student a("Tom", 20);
    
    Student d = std::move(a);
    a.print();
    d.print();
    return 0;
}

/*
今日练习：Rule of Zero

1. 先运行这个文件，观察：我们没有写析构、拷贝构造、拷贝赋值、
   移动构造、移动赋值，代码仍然能正确工作。

2. 思考：
   char* 版本必须手写 Rule of Five，是因为 Student 自己直接管理堆内存。
   string 版本不需要手写这些函数，是因为 std::string 已经自己管理资源。

3. 动手改：
   给 Student 增加一个 int age 成员。
   要求：
   - 构造函数可以同时传入 name 和 age
   - print 同时输出 name 和 age
   - main 中创建几个对象测试拷贝和赋值

4. 小问题：
   Student e = std::move(a); 之后，a 还能不能 print？
   可以，但 a 的 name 处于“有效但未指定”的状态，不要依赖它的具体内容。
*/
