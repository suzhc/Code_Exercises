#include<cstdio>


int fun(int a,int b,int c,int d){
    if(a==c){
        return b<d?b:d;
    }
    else{
        return a<c?a:d;
    }
}

int main(){
    int m, n, k, l, d;
    int kl[2][1000];
    int a1, a2, a3, a4;
    int i = 0;
    scanf("%d%d%d%d%d", &m, &n, &k, &l, &d);
    while(scanf("%d%d%d%d", &a1, &a2, &a3, &a4)){
        if(i==d) break;
        if(a1 == a3) kl[1][i] = fun(a1,a2,a3,a4);
        if(a2 == a4) kl[0][i] = fun(a1,a2,a3,a4);
        i++;
    }
    for ( i = k - 1; i >=0;i--){
        printf("%d ",kl[0][i]);
    }
    printf("\n");
    for ( i = l - 1; i >=0;i--){
        printf("%d ",kl[1][i]);
    }
    return 0;
}