#include <cstddef>              // for std::size_t
#include <iostream>
#include <initializer_list>     // for std::initializer_list
#include <stdexcept>            // for exceptions

template<typename T, std::size_t N>
class MyArray {
private:
    T m_data[N];  // Fixed-size array on stack

public:
    // Default constructor
    MyArray() = default;
    
    // Uniform initialization constructor
    MyArray(std::initializer_list<T> init) {
        if (init.size() != N)
            throw std::length_error("Initializer list size must match array size");

        std::size_t i = 0;
        for (const T& val : init) {
            m_data[i++] = val;
        }
    }
    

    // Assignment using initializer list
    MyArray<T, N>& operator=(std::initializer_list<T> init) {
        if (init.size() != N)
            throw std::length_error("Initializer list size must match array size");

        std::size_t i = 0;
        for (const T& val : init) {
            m_data[i++] = val;
        }
        return *this;
    }

    // Safe element access with bounds checking
    T& at(std::size_t index) {
        if (index >= N) throw std::out_of_range("Index out of bounds");
        return m_data[index];
    }

    // Unsafe element access (like built-in arrays)
    T& operator[](std::size_t index) {
        return m_data[index];
    }

    const T& operator[](std::size_t index) const {
        return m_data[index];
    }

    // Size of array
    constexpr std::size_t size() const noexcept {
        return N;
    }

    // Iterators
    T* begin() { return m_data; }
    T* end() { return m_data + N; }

    const T* begin() const { return m_data; }
    const T* end() const { return m_data + N; }
};

// === Usage Example ===
int main() {
    MyArray<int, 5> arr{};
    MyArray<int, 10> marr();

    const MyArray<int, 7> carr{};


    // Assignment using initializer list
    arr = {10, 20, 30, 40, 50};

    // Range-based for loop using iterators
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    // Safe access
    try {
        std::cout << "arr.at(3) = " << arr.at(3) << "\n";
        std::cout << "arr.at(5) = " << arr.at(5) << "\n"; // out-of-range
    } catch (const std::out_of_range& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    return 0;
}
