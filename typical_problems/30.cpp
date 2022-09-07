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

    long long int n;
    int k;
    cin >> n >> k;
    long long int ans=0;
    vector<int> soinsu_num(n+1,0);
    for(long long int i=2;i<=n;i++){
        if(soinsu_num[i]!=0)continue;
        for(int j=i;j<=n;j+=i){
            soinsu_num[j]++;
        }
    }

    for(int i=2;i<=n;i++){
        if(soinsu_num[i]>=k)ans++;
    }

    //for(int i=0;i<=n;i++)std::cout << soinsu_num[i] << endl;

    std::cout << ans << std::endl;

    return 0;
}