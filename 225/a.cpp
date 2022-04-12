#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>
#include<list>

using namespace std;

int main(void){

    string s;
    cin >> s;
    int n = 1;
    sort(s.begin(),s.end());
    for(int i=0;i<s.length()-1;i++){
        if(s[i]!=s[i+1]){
            n++;
        }
    }
    if(n==3){
        cout << 6 << endl;
    }
    else if(n==2){
        cout << 3 << endl;
    }
    else if(n==1){
        cout << 1 << endl;
    }

    
    return 0;
}