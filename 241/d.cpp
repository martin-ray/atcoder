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

    int q;
    cin >> q;

    multiset<long long int> st;
    for(int i=0;i<q;i++){

        int type,x;
        cin >> type >> x;
        if(type==1){
            st.insert(x);
        }
        else if(type==2){
            int k;
            cin >> k;
            auto it = st.upper_bound(x);
            bool flag = true;
            for(int j=0;j<k;j++){
                if(it==st.begin()){
                    flag = false;break;
                }
                it--;
                
            }
            //cout << "ans1:" << endl;
            if(flag)cout << *it << endl;
            else cout << -1 << endl;
        }
        else if(type==3){
            int k;
            cin >> k;
            bool flag = true;
            auto it = st.lower_bound(x);
            for(int j=0;j<k-1;j++){
                if(it==st.end()){
                    flag= false;break;
                }
                it++;
                
            }
            //cout << "ans2:" << endl;
            if(flag&&it!=st.end()) cout << *it << endl;
            else cout << -1 << endl;
        }



    }

    return 0;
}