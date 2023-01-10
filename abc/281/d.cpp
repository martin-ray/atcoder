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

// <n,k> -> val
// n番目の整数のうち、k個使ったときのって駄目やろそれは。
map<pair<int,int>,int> mp;
int N,K;

void dfs(int n,int k,int val,vector<int>& a){
    pair<int,int> p = make_pair(n,k);
    cout << "kitazo1" << endl;
    if( mp [p] != 0)return;
    cout << "kitazo2" << endl;
    cout << "k=" << k << " " << "K=" << K << endl;
    if(k == K+1)return;
    cout << "kitazo3" << endl;
    if(n == N)return;
    cout << "kitazo4" << endl;

    cout << "val=" << val << endl;

    // n番目を使う
    pair<int,int> p_n_use = make_pair(n,k+1);
    mp[p_n_use] = val + a[n];
    cout << "kitazo5" << endl;
    dfs(n+1,k+1,val + a[n],a);

    // n番目を使わない
    pair<int,int> p_n_no_use = make_pair(n,k);
    mp[p_n_no_use] = val;
    dfs(n+1,k,val,a);
}

int main(void){

    int D;
    cin >> N >> K >> D;
    vector<int> a(N);
    long long int sum = 0;

    for(int i=0;i<N;i++){
        cin >> a[i];
        sum += a[i];
    }

    dfs(0,0,0,a);

    long long int ans = -1;

    for(int i=0;i<=N;i++){
        //for(int k=0;k<=K+1;k++){
            pair<int,int> key = make_pair(i,K+1);
            if(mp[key]%D == 0 && ans < mp[key]){
                cout << "change kita" << endl;
                cout << "i=" << i << " " << "k=" << K << endl;
                ans = mp[key];
            }
            //cout << mp[key] << endl;
        //}

    }

    cout << ans << endl;

    return 0;
}