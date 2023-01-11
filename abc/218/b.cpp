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

string alph = "abcdefghijklmnopqrstuvwxyz";

int main(void){

    vector<int> p(26);
    for(int i=0;i<26;i++){
        int p;
        cin >> p;
        cout << alph[p-1];
    }
    
    cout << endl;

    return 0;
}