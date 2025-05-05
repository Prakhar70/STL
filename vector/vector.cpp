#include <initializer_list>     // for std::initializer_list
#include <cstddef>              // for std::size_t
#include <vector>
#include <iostream>

template<typename T>
class my_vector{
    private:
    T* m_arr;
    size_t m_size;
    size_t m_capacity;

    public:
    my_vector(std::size_t size):m_size{size},m_capacity{size}{
        m_arr=new T[m_capacity];
    }
    my_vector(std::size_t size, int fill_value):m_size{size},m_capacity{size}{
        m_arr=new T[m_size];
        for(size_t i =0;i<m_size;i++){
            m_arr[i] = fill_value;
        }
    }

    my_vector(const std::initializer_list<T> list):m_size{list.size()}, m_capacity{list.size()}{
        m_arr = new T[m_size];
        size_t i=0;
        for(const T& ele:list){
            m_arr[i++]=ele;
        }
    }

    my_vector(const my_vector<T>& other):m_size{other.m_size},m_capacity{other.m_capacity}{
        m_arr = new T[m_capacity];
        
        for(size_t i=0;i<other.m_size;i++){
            m_arr[i]=other.m_arr[i];
        }
    }

    my_vector(my_vector<T>&& other):m_size{other.m_size},m_capacity{other.m_capacity}{
        m_arr = other.m_arr;
        other.m_arr = nullptr;
        other.m_capacity = 0;
        other.m_size = 0;
    }
    // my_vector<T>& operator=(const vector<T>& other){
    //     if(this != &other){
    //         //Step 1:
    //         T* new_arr = new T[other.capacity];

    //         //Step 2:
    //         for(size_t i =0;i<other.size;i++){
    //             new_arr[i]=other.m_arr[i];
    //         }

    //         //Step 3:
    //         delete[]  m_arr;

    //         //Step 4:
    //         m_arr = new_arr;
    //         m_capacity = other.capacity;
    //         m_size = other.size;

    //     }
    //     return *this;
    // }

    //Copy And Swap implementation 
    my_vector<T>& operator=(my_vector<T> other){
        std::swap(m_arr,other.m_arr);
        std::swap(m_capacity,other.m_capacity);
        std::swap(m_size,other.m_size);

        return *this;
    }

    my_vector<T>& operator=(my_vector<T>&& other){
        if(this != &other){
            delete[] m_arr;
            m_arr = other.m_arr;
            m_size = other.m_size;
            m_capacity = other.m_capacity;

            other.m_arr = nullptr;
            other.m_capacity = 0;
            other.m_size = 0;
        }
        return *this;
    }


    ~my_vector(){
        if(m_arr)
            delete[] m_arr;
    }
    void push_back(const T& ele){
        if(m_size == m_capacity){
            size_t new_cap = m_capacity==0?1:m_capacity*2;
            resize(new_cap);
        }
        m_arr[m_size++]=ele;
    }
    void push_back(T&& ele){
        if(m_size == m_capacity){
            size_t new_cap = m_capacity==0?1:m_capacity*2;
            resize(new_cap);
        }
        m_arr[m_size++]=std::move(ele);
    }
    void resize(size_t new_cap, bool keepSize = true){
        if(new_cap<=m_capacity){
            return;
        }
        //delete m_arr;
        T* new_arr = new T[new_cap];
        if(keepSize){
            for(size_t i =0;i<m_size; i++){
                new_arr[i]=std::move(m_arr[i]);
            }
        }
        

        
        delete[] m_arr;
        m_arr = new_arr;
        m_capacity = new_cap;
        if(!keepSize){
            m_size=0;
        }

    }
    size_t capacity() const{
        return m_capacity;
    }
    T& operator[](size_t idx){
        return m_arr[idx];
    }

    const T& operator[](size_t idx) const{
        return m_arr[idx];
    }



};

int main(){

    // my_vector<int> vec{5};

    // my_vector<int> vect={1,3,5,6};
    std::vector<int> vect{1,3};

    for(auto& ele:vect){
        std::cout<<ele<<std::endl;
    }
    vect.push_back(1);

    for(auto& ele:vect){
        std::cout<<ele<<std::endl;
    }

    std::vector<double> ve(12,100);
    for(auto& ele:ve){
        std::cout<<ele<<std::endl;
    }

}