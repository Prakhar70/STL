#include <iostream>
#include <utility>


template<class T>
class Vector{
    private:
    T* res;
    int cap;
    int size;

    public:
    Vector():res(nullptr),cap(0), size(0){}

    Vector(int pSize,const T& pVal = {}):size(pSize),cap(pSize){
        res= new T[pSize];
        for(int i=0;i<pSize;i++){
            res[i]=pVal;
        }
    }
    Vector(const Vector& pVec):size(pVec.size), cap(pVec.cap){
        res = new T[cap];
        for(int i=0;i<size;i++){
            res[i]=pVec.res[i];
        }
    }
    Vector(Vector&& pVec):size(pVec.size), cap(pVec.cap){
        res = pVec.res;
        pVec.res=nullptr;
        pVec.cap=0;
        pVec.size=0;
    }

    Vector& operator=(Vector pVec){
        std::swap(res, pVec.res);
        std::swap(cap,pVec.cap);
        std::swap(size, pVec.size);
        return *this;
    }

    // Vector& operator=(const Vector& pVec){
    //     if(this != &pVec){
    //         T* temp = res;
       
    //         size=pVec.size;
    //         cap=pVec.cap;
    //         res= new T[cap];

    //         for(int i=0;i<size;i++){
    //             res[i]=pVec.res[i];
    //         }

    //         delete[] temp;
    //     }
    //     return *this;
        
    // }
    Vector& operator=(Vector&& pVec){
        if(this != &pVec){

            delete[] res;
            size=pVec.size;
            cap=pVec.cap;
            res=pVec.res;

            pVec.res=nullptr;
            pVec.cap=0;
            pVec.size=0;
        }
        return *this;
    }
    T& operator[](size_t i){
        return res[i];
    }

    int capacity() const{
        return cap;
    }

    void push_back(const T& pVal){
        if(cap==size){

            T* temp = res;

            int new_cap=(cap==0)?1:2*cap;

            res=new T[new_cap];
            for(int i=0;i<size;i++){
                res[i]=temp[i];
            }

            delete[] temp;
            cap=new_cap;
        }
        res[size]=pVal;
        size++;
    }



    ~Vector(){
        delete[] res;
    }
};


int main()
{

    Vector<int> p(2, 100); //{100,100}
    //1.params constructor

    Vector<int> p2(3); //{100,100,100};
    //1.1 params constructor

    p.push_back(1); //{100, 100, 1}
    //2. push_back

    p.capacity();
    //3. capacity

    Vector<int> vec(p);
    //4. copy ctor

    Vector<int> vec(std::move(p));
    //5. move copy ctor

    //p = vec;
    //6. copy assignment

    // p = std::move(vec);
    //7. move assignment

    vec[0]=12;
    //8.operator[]
    int val = vec[0];

    //9. dtor



}