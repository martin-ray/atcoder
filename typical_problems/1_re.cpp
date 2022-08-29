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
#include<queue>

using namespace std;

int main(void){
    
    int n,l,k;
    cin >> n >> l >> k;
    std::vector<int> a(n);
    for(int i=0;i<n;i++)cin >> a[i];

    int ans;
    int left=-1,right=l+1,middle;
    int flag = false;
    
    while(left<=right){
        // 答えはmiddle以下か？
        middle = (left+right)/2;
        int slices = 1;
        int pre = 0;
        for(int i=0;i<n;i++){
            if(a[i] - pre >=middle && l - a[i]>=middle){
                slices++;
                pre = a[i];
            }
            else{
                continue;
            }
        }
        if(slices >= k+1 ){
            left = middle +1;
            flag = true;
        }
        else{
            right = middle -1;
            flag = false; 
        }
        
    }

    std::cout << left -1 << std::endl;


    return 0;
}