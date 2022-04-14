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

    int a;
    std::cin >> a;
    
    a += 100*(a/10%10) + 10*(a%10) + (a/100) + 100*(a%10) + 10*(a/100) + (a/10%10);

    std::cout << a << std::endl;

    return 0;
}