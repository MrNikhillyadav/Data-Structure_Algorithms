#include <iostream>
#include <set>
using namespace std;


int main(){
    set<string> s1;
    
    set<string> s2 = {"a","b","cccc","d","b","b"};

    set <int> s3 = {1,5,6,8,4,2,5};

    for(auto x : s3){
        cout  << x ;
    };

    auto it = s3.find(5);
    if(it != s3.end()) {
        cout << *it << endl;
    }else {
        cout << "Element not found";
    };

    return 0;
}