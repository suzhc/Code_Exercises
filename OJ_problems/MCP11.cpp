#include<cstdio>
#include<iostream>


using namespace std;


int MaxSubseqSum4( int A[], int N ){
  int ThisSum, MaxSum;
  int i;
  ThisSum = MaxSum = 0;
  for(i = 0; i< N; i++){
    ThisSum += A[i];
    if( ThisSum > MaxSum )
      MaxSum = ThisSum;
      else if(ThisSum < 0)
        ThisSum = 0;
  }
  return MaxSum;
}


int main(){
    int n, A[100000];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    cout << MaxSubseqSum4(A, n );
    return 0;
}