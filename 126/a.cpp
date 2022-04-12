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

    int n,k;
    cin >> n >> k;
    k--;
    string s;
    cin >> s;
    if(s[k]=='A'){
        s[k]='a';
    }
    else if(s[k]=='B'){
        s[k]='b';
    }
    else{
        s[k] = 'c';
    }
    cout << s << endl;

    
    return 0;
}