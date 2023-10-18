#include "MyCollection.hpp"
#include "factorial.h"
#include <experimental/random>

template <class T>
void init(MyCollection<T> &c, int k, T min_value, T max_value) {
    for (int i = 0; i < k; i++)
        c.insert_end(std::experimental::randint(min_value, max_value)); // See https://en.cppreference.com/w/cpp/experimental/randint
}

template <class T>
void apply_fact(const MyCollection<T> &c, MyCollection<T> &res) {
    if (res.get_max_size() < c.get_size())
        throw std::range_error("Res is too small!");

    for (int i = 0; i < c.get_size(); i++)
        res.insert_end(factorial(c.get_elem(i)));
}

template <typename U>
std::ostream &operator<<(std::ostream &o, const MyCollection<U> &c) {
    o << "size : " << c.size << "\nmax_size : " << c.max_size << "\nElements: ";
    for (unsigned i = 0; i < c.size; i++)
        o << c.arr[i] << " ";
    o << "\n";
    return o;
}

template void init<int>(MyCollection<int> &, int, int, int);
// template void apply_fact<int>(MyCollection<int> &, MyCollection<int> &);
template std::ostream &operator<<(std::ostream &o, const MyCollection<int> &c);