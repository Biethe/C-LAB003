#include "MyCollection.hpp"
#include <experimental/random>

template <class T>
int factorial(T n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

template <class T>
void init(MyCollection<T> &c, int k, T min_value, T max_value) {
    for (int i = 0; i < k; i++)
        c.insert_end(std::experimental::randint(min_value, max_value)); // See https://en.cppreference.com/w/cpp/experimental/randint
}

template <class T>
void apply_fact(const MyCollection<T> &c, MyCollection<T> &res) {
    if (res.get_max_size() < c.get_size())
        throw std::range_error("Res is too small!");

    for (unsigned i = 0; i < c.get_size(); i++)
        res.insert_end(factorial<T>(c.get_elem(i)));
}

template <typename U>
std::ostream &operator<<(std::ostream &o, const MyCollection<U> &c) {
    // o << "size : " << c.size << "\nmax_size : " << c.max_size << "\nElements: ";
    for (unsigned i = 0; i < c.size; i++)
        o << c.arr[i] << " ";
    o << "\n";
    return o;
}

/*******************
 * Vector Versions *
 *******************/

template <class T>
void vector_init(std::vector<T> &v, int k, T min_value, T max_value) {
    for (auto i = 0; i < k; i++)
        v.push_back(std::experimental::randint(min_value, max_value));
}

template <class T>
void vector_apply_fact(const std::vector<T> &c, std::vector<T> &res) {
    for (unsigned i = 0; i < c.size(); i++)
        res.push_back(factorial(c[i]));
}

template void init(MyCollection<short> &, int, short, short);
template void init(MyCollection<int> &, int, int, int);
template void init(MyCollection<long> &, int, long, long);
template void init(MyCollection<long long> &, int, long long, long long);
template void apply_fact(const MyCollection<short> &, MyCollection<short> &);
template void apply_fact(const MyCollection<int> &, MyCollection<int> &);
template void apply_fact(const MyCollection<long> &, MyCollection<long> &);
template void apply_fact(const MyCollection<long long> &, MyCollection<long long> &);
template std::ostream &operator<<(std::ostream &o, const MyCollection<short> &c);
template std::ostream &operator<<(std::ostream &o, const MyCollection<int> &c);
template std::ostream &operator<<(std::ostream &o, const MyCollection<long> &c);
template std::ostream &operator<<(std::ostream &o, const MyCollection<long long> &c);

template void vector_init(std::vector<short> &, int, short, short);
template void vector_init(std::vector<int> &, int, int, int);
template void vector_init(std::vector<long> &, int, long, long);
template void vector_init(std::vector<long long> &, int, long long, long long);
template void vector_apply_fact(const std::vector<short> &, std::vector<short> &);
template void vector_apply_fact(const std::vector<int> &, std::vector<int> &);
template void vector_apply_fact(const std::vector<long> &, std::vector<long> &);
template void vector_apply_fact(const std::vector<long long> &, std::vector<long long> &);