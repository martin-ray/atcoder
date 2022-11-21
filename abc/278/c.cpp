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
    cin >> n >> q;

    set <pair<int,int>> follow_set;
    for(int i=0;i<q;i++){
        int t,a,b;
        cin >> t >> a >> b;

        if(t == 1){
            follow_set.insert(make_pair(a,b));
        } else if(t == 2){
            follow_set.erase(make_pair(a,b));
        } else if(t == 3){
            cout << (follow_set.count(make_pair(a,b)) && follow_set.count(make_pair(b,a)) ? "Yes" : "No") << endl;
        }
    } 

    return 0;
}