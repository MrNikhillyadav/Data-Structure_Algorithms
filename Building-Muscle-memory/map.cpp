#include <iostream>
#include <map>
using namespace std;


int main(){
    map<int,string> mp;
    
    map<int,string> mp2 = {
        {1,"Nikhil"},
        {2,"Yadav"},
        {3,"is awesome"}
    };

    for(auto x : mp2){
        cout << "key:" << x.first << " " <<  "values: " << x.second << endl;
    }
  

    return 0;
}