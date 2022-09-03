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

    int n,m;
    cin >> n >>m;
    vector<long long int> a(n);
    for(int i=0;i<n;i++)cin >> a[i];

    vector<long long int> cum_sum(n+1,0); // nまでの累積和
    vector<long long int> cum_sum_i(n+1,0); // nまでのi*aiの累積和
    long long int sum = 0;
    long long int sum2 = 0;
    for(int i=1;i<=n;i++){
        sum2+=(i)*a[i-1];
        sum+=a[i-1];
        cum_sum[i] = sum;
        cum_sum_i[i] = sum2;
    }

    // for(int i=0;i<n;i++)cout << cum_sum[i+1] <<" " << cum_sum_i[i+1] << std::endl;

    long long int max = -(long long int)1 << 62;
    for(int i=0;i<=n;i++){
        long long int tmp;
        if(m+i>n)continue;
        tmp = cum_sum_i[i+m]-cum_sum_i[i] - i*(cum_sum[i+m]-cum_sum[i]);
        if(tmp > max)max = tmp;
    }

    std::cout << max << std::endl;
    return 0;
}