#include<iostream>

using namespace std;

string s = "";

string pinyin(int a){
    switch(a){
        case 1: return "yi ";
        case 2: return "er ";
        case 3: return "san ";
        case 4: return "si ";
        case 5: return "wu ";
        case 6: return "liu ";
        case 7: return "qi ";
        case 8: return "ba ";
        case 9: return "jiu ";
        case 0: return "ling ";
    }
}

void split(int b){
    int cc[100], f;
    for(int i = 0; b%10 != 0; i++){
        cc[i]=b%10;
        b/=10;
        f = i;
    }
    for( int i = f; i>=0;i--){
    	s+=pinyin(cc[i]);
	}
    
}

long func(long n){
    if(n/10 == 0){
        return n;
    }
    else{
        n = n%10 + func(n/10);
    }
}

int main(){
    long a ;
    cin >> a;
    split(func(a));
    cout << s << endl;
    return 0;
}
