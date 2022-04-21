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

    vector<int> a(10);
    for(int i=0;i<10;i++)cin >> a[i];
    int k = 0;
    for(int i=0;i<3;i++){
        k = a[k];
    }
    cout << k << endl;

    return 0;
}