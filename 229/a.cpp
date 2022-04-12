#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>

using namespace std;

int main(void){

    string s[2];

    for(int i=0;i<2;i++){
        cin >> s[i];
    }

    if(s[0]=="##"||s[1]=="##"){
        cout << "Yes" << endl;
        return 0;
    }
    else if(s[0][0]=='#'&&s[1][0]=='#'){
        cout << "Yes" << endl;
        return 0;        
    }
    else if(s[0][1]=='#'&&s[1][1]=='#'){
        cout << "Yes" << endl;
        return 0;                
    }

    cout << "No" << endl;

    return 0;
}