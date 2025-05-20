#include <iostream>

using namespace std;


class String{
private:
    char* res;
    unsigned int len;
public:
    explicit String(const char* pRes=nullptr){
        cout<<"ctor"<<endl;
        if(pRes==nullptr){
            res=new char[1];
            len=0;
            res[0]='\0';
            return;
        }
        res = new char[strlen(pRes)+1];
        strcpy(res, pRes);
        len = strlen(pRes);
    }

    String(const String& pStr){
        cout<<"copy-ctor"<<endl;
        res = new char[pStr.len+1];
        strcpy(res, pStr.res);
        len = pStr.len;
    }

    String(String&& pStr){
        cout<<"move copy"<<endl;
        res = pStr.res;
        len = pStr.len;
        pStr.res=nullptr;
        pStr.len=0;
    }

    // String& operator=(const String& pStr){
    //     if(this != &pStr){
    //         delete[] res;
    //         res = new char[pStr.len+1];
    //         strcpy(res, pStr.res);
    //         len = pStr.len;
    //     }
    //     return *this;
    // }

    String& operator=(String pStr){
        cout<<"copy assignment"<<endl;
        swap(pStr.res, res);
        swap(pStr.len, len);
        return *this;
    }

    String& operator=(String&& pStr){
        cout<<"move assignment"<<endl;
        if(this != &pStr){
            delete[] res;
            res = pStr.res;
            len = pStr.len;

            pStr.res=nullptr;
            pStr.len = 0;

        }
        return *this;
    }

    ~String(){
        cout<<"dtor"<<endl;
        if(res){
            delete[] res;
        }
    }
    friend ostream& operator<<(ostream& pOut, const String& pStr);


};

ostream& operator<<(ostream& pOut, const String& pStr){
    pOut<<pStr.res;
    return pOut;
}




int main(){

    // String str1("Prakhar"); //params ctor
    // cout<<str1<<endl;
    // String str2("Sugam");// default constructor
    // cout<<str2<<endl;

    // String str3(str2);
    // cout<<str3<<endl;
    // cout<<str2<<endl;


    String s1("Prakhar");
    String s2("Sugam");
    cout<<s2<<endl;
    // cout<<s1<<endl;
    

    s1 = s2;//copy ctor
    cout<<s1<<endl;
    cout<<s2<<endl;

    // String str6=std::move(str1);

    // str6=std::move(str1);
}