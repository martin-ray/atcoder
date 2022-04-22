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

    int a,b,c,x;
    cin >> a >> b >> c >> x;
    if(x <= a)cout << 1 << endl;
    else if(x > b) cout << 0 << endl;
    else cout << setprecision(15) << (double)c/(double)(b-a) << endl;

    return 0;
}