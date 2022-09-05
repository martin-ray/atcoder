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
std::vector<std::vector<int>> S(1000,std::vector<int>(1000,0));

int main(void){
    int n;
    cin >> n;
    std::vector<long long int> k_s_sum(n+1,0);
    k_s_sum[0] = 1000*1000;
    for(int i=0;i<n;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1;x2;y1;y2;
        for(int h=x1;h<x2;h++){
            for(int w=y1;w<y2;w++){
                k_s_sum[S[h][w]+1]++;
                k_s_sum[S[h][w]]--;
                S[h][w]++;
                // cout << S[h][w] << endl;
            }
        }
    }

    for(int i=1;i<=n;i++)std::cout << k_s_sum[i] << std::endl;

    return 0;
}