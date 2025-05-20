#include<iostream>
using namespace std;

template<class T>
class sharedPtr{
    private:
    T* res;
    int* count;

    void increment_count(){
        if(count){
            (*count)++;
        }
    }

    void decrement_count(){
        if(count){
            (*count)--;
            if(*count == 0){
                if(res){
                    delete res;
                    delete count;
                    res=nullptr;
                }
                
            }
        }
    }
    public:
    sharedPtr(T* pRes= nullptr):res(ptr), count = new int(1){
    }

    sharedPtr(const sharedPtr& pSharedPtr){
        res=pSharedPtr.res;
        count = pSharedPtr.count;
        increment_count();
    }
    sharedPtr(sharedPtr&& pSharedPtr){
        res = pShared.res;
        count = pSharedPtr.count;
    }

    sharedPtr& operator=(const sharedPtr& pSharedPtr){
        if(this!=&pSharedPtr){
            decrement_count();
            res = pSharedPtr.res;
            count = pSharedPtr.count;
            increment_count();
        }
        return *this;
    }
    sharedPtr& operator=(sharedPtr&& pSharedPtr){
        if(this!=*pSharedPtr){
            decrement_count();
            res = pSharedPtr.res;
            count = pSharedPtr.count;
            pSharedPtr.res=nullptr;
            pSharedPtr.count=nullptr;
        }
        return *this;
    }
    T& operator*(){

        return *res;
    }

    int get_count(){
        if(*count)
            return *count;
    }

    void reset(T* pRes){
        decrement_count();
        res=pRes;
        count = new int(1);
    }

    T* operator->(){
        return res;
    }

    ~sharedPtr(){
        decrement_count();
    }
    T* get(){
        return res;
    }

};

int main(){

    
    // sharedPtr<int> p(new int(10));//ctor

    // sharedPtr<int> r(p);//copy-ctor


    // sharedPtr<int> op(new int(20));
    // sharedPtr<int> np(std::move(op));//move-ctor


    // sharedPtr<int> ptr1(new int(10));
    // sharedPtr<int> ptr2(new int(20));
    // ptr1=ptr2;//copy-assignment operator

    // sharedPtr<int> ptr1(new int(10));
    // sharedPtr<int> ptr2(new int(20));
    // ptr1=std::move(ptr2);//move-assignment operator

    sharedPtr<int> ptr(new int(10));
    int value = *ptr; // oerloading * operator

    sharedPtr<int> ptr(new int(90));
    ptr.get_count();

    // ptr.reset(new int(10));
    // ptr.reset();//nullptr by default;
}