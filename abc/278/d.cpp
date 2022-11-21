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

    int n,q;
    cin >> n;
    vector<long long int> a(n);
    map<long long int,long long int> mp;
    for(int i = 0; i < n ; i++)cin >> a[i];
    cin >> q;

    int all = -1;
    for(int i = 0; i < q ; i++){

        int query;
        cin >> query;

        if(query == 1){
            int x;
            cin >> x; 
            all = x;
            mp.clear();
        } else if(query == 2){
            int iq,x;
            cin >> iq >> x;iq--;
            if(all == -1){
                a[iq] += x;
            } else {
                mp[iq] += x;
            }

        } else if(query == 3){
            int iq;
            cin >> iq;iq--;

            if(all==-1){
                cout << a[iq] << endl;
            } else {
                cout << mp[iq] + all << endl;
            }

        }
    }
    return 0;
}