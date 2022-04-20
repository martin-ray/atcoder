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

    int n,x;
    cin >> n >> x;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)cin >> a[i] >> b[i];

    //部分和問題に帰着させたい
    int all_a=0;
    vector<int> replace_a2b(n);
    for(int i=0;i<n;i++)replace_a2b[i] = b[i] - a[i];
    for(int i=0;i<n;i++)all_a += a[i];
    if(all_a == x){cout << "Yes" << endl; return 0;}
    else{
         //replace_a2bを選択する/しないことでsubを作れるか
        int sub = x - all_a;
    }

    return 0;
}