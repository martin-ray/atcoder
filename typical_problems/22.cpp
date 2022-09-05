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
    long long int a,b,c;
    std::cin >> a >> b >> c;
    long long int gcd = std::__gcd(__gcd(a,b),c);
    cout << (a/gcd-1) + (b/gcd-1) + (c/gcd-1) << endl;
    return 0;
}