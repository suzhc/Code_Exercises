#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> v;

//将字符串转换为111100011000的形式（如果时元音字母就是0，不是就是1）
void TransString(string s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            v.push_back(0);
        else
            v.push_back(1);
    }
}

//判断字符串是否符合要求，如果前一位减后一位不等于0，则计数器加1，最后判断计数器是否等于3
bool JudgeString(vector<int> s){
    int flag = 0;
    for(int i = 1; i < v.size(); i++){
        if(v[i]-v[i-1] != 0){
            flag++;
        }
    }
    if(flag == 3){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string word;
    cin >> word;
    TransString(word);
    if(JudgeString(v)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    return 0;

}