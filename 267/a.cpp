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
    std::map<std::string,int> s;
    s["Monday"]=5;
    s["Tuesday"]=4;
    s["Wednesday"]=3;
    s["Thursday"]=2;
    s["Friday"]=1;

    std::string S;
    std::cin >> S;
    std::cout << s[S] << std::endl;


    return 0;
}