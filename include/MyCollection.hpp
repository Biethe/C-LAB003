#include <iostream>
#include <stdexcept>

template <class T>
class MyCollection {
  private:
    T *arr{};
    unsigned size{}; // current size - init to 0
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

    void print() {
      std::cout << "Size: " << size << std::endl;
      std::cout << "Max size: " << max_size << std::endl;
      for (unsigned i = 0; i < size; i++) {
        std::cout << arr[i] << ", ";
      }
      std::cout << std::endl;
    }

    // Insert at the end of the array, return true if success, false otherwise
    bool insert_end(T value) {
        if (size < max_size) {
            arr[size] = value;
            size++;
            return true;
        }
        return false;
    }

    T get_elem(int index) {
        if (index < size) {
            return arr[index];
        } else {
            throw std::invalid_argument("Index out of bounds!");
        }
    }
};