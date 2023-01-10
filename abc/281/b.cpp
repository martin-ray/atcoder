#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>
#include<list>
#include<bits/stdc++.h>
#include <iomanip>
#include<queue> //do not forget about priority_queue;
//std::cout << std::setprecision(2) << 3.141; // "3.1"
#define MOD 1000000007
using namespace std;

int main(void){

    string s;
    cin >> s;

    if(s.size()!=8){
        cout << "No" << endl;
        return 0;
    }

    char s1 = s[0];
    char s2 = s[7];
    if(!(('A' <= s1 && s1 <= 'Z') && ('A' <= s2  && s2 <= 'Z'))){
        cout <<"No" << endl;
        return 0;
    }

    int num = stoi(s.substr(1,6));

    if(!(100000 <= num && num <= 999999)){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

    return 0;
}