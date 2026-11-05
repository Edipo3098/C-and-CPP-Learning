#include<iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main(){

    vector<int> v{1,2,3,4,5};
    for(size_t i = 0; i < v.size(); i++){
        cout<< v.operator[](i)<< " "  ;
    }
    cout<< endl;
    vector<int> v2;
    v2.operator = (v);
    for(size_t i = 0; i < v2.size(); i++){
        cout<< v2.operator[](i)<< " "  ;
    }




    return 0 ;
}