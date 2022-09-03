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
    string s;
    cin >> s;

    std::vector<bool> stands(7,false);
    if(s[0]=='1'||s[4]=='1')stands[3] = true;
    if(s[1]=='1'||s[7]=='1')stands[2] = true;
    if(s[2]=='1'||s[8]=='1')stands[4] = true;
    if(s[3]=='1')stands[1] = true;
    if(s[5]=='1')stands[5] = true;
    if(s[6]=='1')stands[0] = true;
    if(s[9]=='1')stands[6] = true;
    if(s[0]=='1'){
        std::cout << "No" << std::endl;
        return 0;
    }

    for(int i=0;i<7;i++){
        if(stands[i]==false)continue;
        int row=0;
        for(int j=i+1;j<7;j++){
            if(stands[j]==false)row++;
            else if(row>0){
                std::cout << "Yes" << std::endl;
                return 0;
            }
        }
    }

    std::cout << "No" << std::endl;
    return 0;
}