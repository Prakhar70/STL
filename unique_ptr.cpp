#include <iostream>

using namespace std;

template<class T>
class uniquePtr
{
    private:
    T* res;
    public:
    uniquePtr(T* pRes=nullptr):res(pRes){}

    uniquePtr(const uniquePtr& pUniquePtr)=delete;

    uniquePtr(uniquePtr&& pUniquePtr){
        res= pUniquePtr.res;
        pUniquePtr.res = nullptr;
    }

    uniquePtr& operator=(const uniquePtr& pUniquePtr)=delete;

    uniquePtr& operator=(uniquePtr&& pUniquePtr){
        if(this != &pUniquePtr){
            if(res){
                delete res;
            }
            res=pUniquePtr.res;
            pUniquePtr.res=nullptr;
        }
        return *this;
    }
    T& operator*(){
        return *res;
    }

    T* operator->(){
        return res;
    }

    T* get(){
        return res;
    }
    void reset(T* pRes=nullptr){
        if(res){
            delete res;
        }
        res = pRes;
    }
    ~uniquePtr(){
        delete res;
    }

};

int main(){
    uniquePtr<int> ptr(new int(10));//ctor


    // uniquePtr<int> ptr2 = ptr;//compile time error

    uniquePtr<int> ptr2 = std::move(ptr);

    // ptr2 = ptr;//compile time error

    ptr2= std::move(ptr);

    ptr.reset(new int(10));

    // int p = *ptr;
}