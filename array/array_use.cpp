#include <iostream>

using namespace std;
class Pair{
    public:
        int a;
        int b;
        Pair(int x, int y) : a(x), b(y) {}
        Pair():a(0),b(0){}
        friend ostream& operator<<(ostream& cout, Pair& p);
    
};
ostream& operator<<(ostream& out, Pair& p){
    return out<<p.a<<" "<<p.b<<endl ;
}


int main(){

    //array<Pair,5> arr;
    //Pair arr[10];
    //Pair * p = new Pair[10];
    array<Pair,5> my_array = {Pair(0,20),Pair(1,30),Pair(2,20),Pair(3,11),Pair(4,11)};
    for(auto it=my_array.begin(); it!=my_array.end();it++){
        cout<<*it<<endl;
    }
    
    //cout<<arr[0]<<endl;
}