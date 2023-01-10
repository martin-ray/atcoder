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

    long long int N,T;
    cin >> N >> T;
    vector<int> a(N);

    unsigned long long int cycle=0;
    for(int i=0;i<N;i++){
        cin >> a[i];
        cycle += a[i];
    }

    unsigned long long int t = 0;
    for(int i=0;i<N;i++){
        if(t < T%cycle && T%cycle < t + a[i] ){
            cout << i + 1 << " " << T%cycle - t << endl;
            return 0;
        } else {
            t += a[i];
        }
    }

    return 0;
}