#include<iostream>

using namespace std;

int fun(int a){
    int c = 0;
    while(a != 1){
        if(a % 2 == 0){
            a/=2;
            c++;
        }
        else{
            a = (a*3+1)/2;
            c++;
        }
    }
    return c;
}

int main(){
    int n;
    cin >> n;
    cout << fun(n) << endl;
    return 0;
    
}