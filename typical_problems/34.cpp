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
 
    int n,k;
    cin >> n >> k;
    vector<long long int> a(n+1);
    for(int i=1;i<=n;i++)cin >> a[i];
    int front = 1;
    int end = 1;
 
    map<long long int ,int> mp; // number to the number of the number
    int max_len = 0;
    int number_of_int = 0;

    bool go_flag = false;

    while(front<=n){
        

        if(mp[a[front]]==0&&front<=n){
            number_of_int++;
            mp[a[front]]++;
        }
        else if(front<=n&&go_flag){
            mp[a[front]]++;
        }

        if(number_of_int<=k&&front<=n){
            max_len = std::max(max_len,front - end + 1);
            front++;
            go_flag = true;
        }
        else{
            go_flag = false;
            mp[a[end]]--;
            if(mp[a[end]]==0)number_of_int--;
            end++;
        }
    }
 
    cout << max_len << endl;
 
    return 0;
}