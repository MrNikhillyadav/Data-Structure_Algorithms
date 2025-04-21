#include <iostream>
#include <unordered_map>

using namespace std;


int main(){
    unordered_map<int,string> mp = {
        {1, "Red"},
        {2, "Orange"},
        {3, "Blue"},
    };

    for(auto x : mp){
        cout << "keys: " << x.first << " " <<  "values: " << x.second << endl;
    };
   
    return 0;
};
