#include "MyCollection.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <typeinfo>
#include <vector>

/* A function to test the MyCollection functions */
template <class T>
void testFunctions(int size, T min_value, T max_value) {
    MyCollection<T> c(size);
    MyCollection<T> res(size);
    init<T>(c, size, min_value, max_value);
    apply_fact<T>(c, res);

    std::cout << "--- Testing type : " << typeid(T).name() << " --- \n";
    std::cout << "Init: ";
    std::cout << c;
    std::cout << "Factorial: ";
    std::cout << res;
}

/* A function to test the same functions with the vector containter */
template <class T>
void testVectorFunctions(int size, T min_value, T max_value) {
    std::vector<T> c;
    std::vector<T> res;
    vector_init<T>(c, size, min_value, max_value);
    vector_apply_fact<T>(c, res);

    std::cout << "--- Testing type : " << typeid(T).name() << " --- \n";
    std::cout << "Init: ";
    for (const auto &elem : c)
        std::cout << elem << ' ';
    std::cout << "\nFactorial: ";
    for (const auto &elem : res)
        std::cout << elem << ' ';
    std::cout << "\n";
}

int main() {

    std::srand(std::time(nullptr)); // use current time as seed for random generator

    unsigned size{10};

    std::cout << "\n *** Testing MyCollection versions *** \n\n";
    testFunctions<short>(size, 0, 7);
    testFunctions<int>(size, 0, 12);
    testFunctions<long>(size, 0, 16);
    testFunctions<long long>(size, 0, 16);

    std::cout << "\n *** Testing vector versions *** \n\n";
    testVectorFunctions<short>(size, 0, 7);
    testVectorFunctions<int>(size, 0, 12);
    testVectorFunctions<long>(size, 0, 16);
    testVectorFunctions<long long>(size, 0, 16);

    return 0;
}