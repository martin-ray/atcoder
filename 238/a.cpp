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

    int n;
    std::cin >> n;

    if(n==1){
        cout << "Yes" << endl;
    }
    else if(n ==2){
        cout << "No" << endl;
    }
    else if(n==3){
        cout << "No" << endl;
    }
    else if(n ==4 ){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }

    return 0;
}