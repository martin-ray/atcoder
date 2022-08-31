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
    vector<int> cum_sum1(n+1,0);
    vector<int> cum_sum2(n+1,0);
    int cum1 = 0;
    int cum2 = 0;
    for(int i=1;i<=n;i++){
        int c,p;
        cin >> c >> p;
        if(c==1){
            cum1+=p;
        }
        else{
            cum2+=p;
        }
        cum_sum1[i] = cum1;
        cum_sum2[i] = cum2;
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        std::cout << cum_sum1[r] - cum_sum1[l-1] << " " << cum_sum2[r] - cum_sum2[l-1] << std::endl;
    }
    return 0;
}