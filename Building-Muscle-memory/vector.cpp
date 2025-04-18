#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v1;
    cout << v1.capacity() << endl;
    
    vector<int> v2 = {1,2,5,8,6,8,10};
    cout << v2.capacity() << endl;
    
    vector<int> v3(5,9);
    for(auto x : v3){
        cout << x ;
    }

    vector<char> v = {'a','b','c','e'};
    for(auto c : v){
        cout << c;
    }

    v.push_back('g');
    for(auto c : v){
        cout << c;
    }

    return 0;
}