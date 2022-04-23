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
    cin >> n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<n;i++)cin >> b[i];

    int ans1 = 0, ans2 = 0;

    //place and number
    for(int i=0;i<n;i++){
        if(a[i]==b[i])ans1++;
    }

    //number
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]==b[j]&&i!=j){
                ans2++;
            }
        }
    }

    cout << ans1 << endl;
    cout << ans2 << endl;

    return 0;
}