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

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    set<int> st;
    for(int i=0;i<n;i++){
        st.insert(a[i]);
    }

    cout << st.size() << endl;
    
    return 0;
}