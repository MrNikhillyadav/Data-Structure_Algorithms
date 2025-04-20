#include <iostream>
using namespace std;

void printString(string s){

    for(int i =0; i < s.size(); i++){
        cout << s[i]  ;
    }
}

void printInteger(int arr[], int size){
    
    for(int i =0; i < size; i++){
        cout << arr[i]  ;
    }
}

int main(){

    int arr[] = {1,2,3,4,5,7,9,15};
    int size = sizeof(arr)/sizeof(arr[0]);

    printInteger(arr,size);

    string s = {'s','d','e','f','g'};
    printString(s);

    return 0;
}