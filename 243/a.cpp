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

    int v,a,b,c;
    cin >> v >> a >> b >> c;
    while(v>=0){
        v-=a;
        if(v<0){
            cout << "F" << endl;
            return 0;
        }
        v-=b;
        if(v<0){
            cout << "M" << endl;
            return 0;
        }
        v-=c;
        if(v<0){
            cout << "T" << endl;
            return 0;
        }
    }

    return 0;
}