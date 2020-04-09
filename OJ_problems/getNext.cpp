#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>



using namespace std;



void Getnext(int next[],string t)
{
   int j=0,k=-1;
   next[0]=-1;
   while(j<t.length()-1)
   {
      if(k == -1 || t[j] == t[k])
      {
         j++;k++;
         if(t[j]==t[k])//当两个字符相同时，就跳过
            next[j] = next[k];
         else
            next[j] = k;
      }
      else k = next[k];
   }
}



int main(){
    int next[15];
    string t = "babbabab";
    Getnext(next,t );
    for(int i  = 0; i<14; i++)
        cout << next[i] << "    ";

}