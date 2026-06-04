#include <iostream>
#include <memory>

int main(){
    auto p1 = std::make_unique<int>(10);
    std::cout << *p1 << std::endl;

    auto p2 = std::move(p1);
    std::cout << *p2 << std::endl;

    if(p1 == nullptr){
        std::cout << "p1 为空\n";
    }
    return 0;
}