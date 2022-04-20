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

bool flag = false;
int n,x;

//メモか:いや、目も貸しても意味ない。なぜなら、一度訪れたことがあるかないかは答えに関係ないから。
vector<bool> has_come(10100,false);

void dfs(int now,int i,vector<int>& a,vector<int>& b){
    has_come[now] = true;
    if(now==x&&i==n){
        cout << "Yes" << endl;
        flag = true;
        return;
    }
    else if(now > x || i > n){
        return;
    }
    else if(!flag){
        if(has_come[now+a[i]]==false){
            dfs(now+a[i],i+1,a,b);
        }
        if(has_come[now+b[i]]==false){
            dfs(now+b[i],i+1,a,b);
        }
        
    }
}

int main(void){

    
    cin >> n >> x;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)cin >> a[i] >> b[i];

    dfs(0,0,a,b);

    if(!flag)cout << "No" << endl;

    return 0;
}