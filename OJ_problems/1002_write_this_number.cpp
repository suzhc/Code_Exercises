#include<iostream>

using namespace std;

char c[100];

char pinyin(int a){
    switch(a){
        case 1: return 'yi ';
        case 2: return 'er ';
        case 3: return 'san ';
        case 4: return 'si ';
        case 5: return 'wu ';
        case 6: return 'liu ';
        case 7: return 'qi ';
        case 8: return 'ba ';
        case 9: return 'jiu ';
        case 0: return 'ling';
    }
}

void split(int b){
    int cc[100];
    for(int i = 0; b%10 != 0; i++){
        cc[i]=b%10;
        c[i]=pinyin(cc[i]);
        printf("%s",c[i]);
        b/=10;
    }
}

int func(int n){
    if(n%10 == 0){
        return n;
    }
    else{
        n = n%10 + func(n/10);
    }
}

int main(){
    int a = 345;
    split(func(a));
    printf("%s\n",c);
    return 0;
}