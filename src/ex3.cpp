#include <iostream>
#include "MyCollection.hpp"

int main() {
    MyCollection<int> c1(10);
    c1.insert_end(1);
    c1.print();
    return 0;
}