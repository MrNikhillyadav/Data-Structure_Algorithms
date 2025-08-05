#include <iostream>
#include <vector>
using namespace std;

int main(){
    // creating a vector
    vector<int> numbers;

    numbers.push_back(5);
    numbers.push_back(8);
    numbers.push_back(20);
    numbers.push_back(12);

    //printing vectors
    for(int i=0; i < numbers.size(); i++){
        cout << numbers[i] << endl;
    }

    //other way is :
    for(auto x : numbers){
        cout << x << endl;
    }

    numbers.pop_back();

    numbers.clear();

    
    vector<string> ch;

    ch.push_back("h");
    ch.push_back("e");
    ch.push_back("l");
    ch.push_back("l");
    ch.push_back("o");

    for(auto c : ch){
        cout << c << " ";
    }

    return 0;
}