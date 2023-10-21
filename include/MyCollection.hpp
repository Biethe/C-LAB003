#include <iostream>
#include <stdexcept>
#include <vector>

template <class T>
class MyCollection {
private:
    T *arr{};
    unsigned size{};         // current size - init to 0
    const unsigned max_size; // max size - init in constructor

public:
    MyCollection(unsigned max) : max_size(max) {
        arr = new T[max_size]();
    }

    // Copy constructor
    MyCollection(const MyCollection &c2) {
        this->max_size = c2.max_size;
        this->size = c2.size;
        this->arr = new T[max_size];
    }

    // Destructor
    ~MyCollection() {
        delete[] arr;
    }

    // Getters
    unsigned get_size() const {
        return size;
    }

    unsigned get_max_size() const {
        return max_size;
    }

    T get_elem(unsigned index) const {
        if (index < size) {
            return arr[index];
        } else {
            throw std::invalid_argument("Index out of bounds!");
        }
    }

    void insert_end(T value) {
        if (size >= max_size)
            throw std::range_error("Not enough space!");
        arr[size] = value;
        size++;
    }

    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const MyCollection<U> &obj);
};

template <class T>
void init(MyCollection<T> &c, int k, T min_value = 0, T max_value = 100);

template <class T>
void apply_fact(const MyCollection<T> &c, MyCollection<T> &res);

template <class T>
int factorial(T n);

template <class T>
void vector_init(std::vector<T> &v, int k, T min_value, T max_value);

template <class T>
void vector_apply_fact(const std::vector<T> &c, std::vector<T> &res);