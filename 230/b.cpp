#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

int main(void){

    string s;
    cin >> s;

    string base = "oxx";
    int i;
    for(i=0;i<base.length();i++){
        int tmp=0;
        for(int j=0;j<s.length();j++){
            if(base[(i+j)%3]==s[j]){
                tmp++;
                continue;
            }
            else{
                break;
            }
        }
        if(tmp==s.length()){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}