#include "MyCollection.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {

    std::srand(std::time(nullptr)); // use current time as seed for random generator

    MyCollection<int> c1(10);
    c1.insert_end(1);
    // c1.print();

    init<int>(c1, 13, 0, 10);
    // init(c1, 5, 0, 10);
    // c1.print();
    std::cout << c1;

    return 0;
}