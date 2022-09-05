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
using namespace std;

int main(void){
    int n;
    cin >> n;
    set<string> st;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        if(st.find(s)!=st.end())continue;
        st.insert(s);
        std::cout << i+1 << std::endl;
    }
    return 0;
}