#include <iostream>
using namespace std;

template<typename T, size_t N>
class my_array{
    private:
    T m_array[N];

    public:
    my_array() = default;
    my_array(const std::initializer_list<T>& list){
        if(list.size()>N){
            throw std::length_error("cant init length of this size");
        }
        size_t i=0;
        for(const T& ele:list){
            m_array[i++]=ele;
        }
    }
    my_array<T,N>& operator=(const std::initializer_list<T>& list){
        if (list.size() != N)
            throw std::length_error("Initializer list size must match array size");
        for(const T& ele:list){
            m_array[++i]=ele;
        }
        return *this;
    }

    T& operator[](size_t idx){
       return m_array[idx];
    }
    T& at(size_t idx){
        if(idx>=N){
            throw std::out_of_range("Out of range");
        }
        return m_array[idx];
    }
    constexpr size_t getSize() const{
        return N;
    }

    const T& operator[](size_t idx) const {
        return m_array[idx];
    }

    const T& at(size_t idx) const{
        if(idx>=N){
            throw std::out_of_range("Out of range");
        }
        return m_array[idx];
    }
    T* begin(){
        return m_array;
    }
    T* end(){
        return m_array+N;
    }
    const T* begin() const{
        return m_array;
    }
    const T* end() const{
        return m_array+N;
    }
};

class Pair{
    int m_a;
    int m_b;
    public:
    Pair()=default;
    Pair(int a, int b):m_a(a),m_b(b){}
    int getA(){ return m_a; }
    int getB(){ return m_b; }
};

int main(){
    my_array<int, 7> arr;

    // const array<int, 6> carray;
    const Pair pair{};
    Pair pair{};




    for(int i=0;i<7;i++){
        arr[i]=i;
    }
    
    for(int i=0;i<7;i++){
        cout<<arr[i];
    }
    constexpr int ec = arr.getSize();

}

