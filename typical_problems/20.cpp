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

int main(void){

    unsigned long long int a,b,c;
    std::cin >> a >> b >> c;
    long long int cb = c;
    for(int i=0;i<b;i++){
        if(a<cb){
            std::cout <<"Yes" << std::endl;
            return 0;
        }
        else{
            cb*=c;
        }
        //std::cout << "cb=" << cb << std::endl;
    }

    std::cout << "No" << std::endl;
    return 0;
}