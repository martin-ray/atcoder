#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

int main(void){

    string s;
    cin >> s;
    
    int last_char = s.length() - 1;
    int str_len = s.length();
    int front_char = 0;

    //後尾取り除き
    while(s[last_char]=='a' && str_len>0){
        str_len--; 
        last_char--;
        //cout << "kiritori" << endl;
        if(s[front_char]=='a'){
            front_char++;
        }
    }


    bool flag = true;
    for(int i=0;i<(str_len - front_char)/2;i++){
        //cout << s[i] << s[str_len - i -1] << endl;
        //cout << str_len - i - 1 << endl;
        if(s[front_char + i]==s[str_len-i-1]){
            continue;
        }
        else{
            flag = false;
            break;
        }
        
    }

    if(flag){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }


    

    return 0;
}