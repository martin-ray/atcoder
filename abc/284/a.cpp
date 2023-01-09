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
#define MOD 1000000007

int main(void){

    int n;
    cin >> n; 

    vector<string> s(n);
    for(int i=0;i<n;i++)cin >> s[i];

    for(int i=n-1;i>=0;i--){
        cout << s[i] << endl;
    }
    

    return 0;
}