#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>
#include<list>
#include<bits/stdc++.h>
#include<bitset>

int main(void){

    long long int k;
    std::cin >> k;

    std::string ans;

    do{
        ans = std::to_string(k%2) + ans;
        k = k/2;
    }while(k!=0);

    for(int i=0;i<ans.length();i++){
        if(ans[i]=='1'){
            ans[i]= '2';
        }
    }
    std::cout << ans << std::endl;



    return 0;
}