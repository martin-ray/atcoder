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
#include<cmath>
#define MIX 1000000000000000000

using namespace std;

int main(void){

    int n;
    long long int x;
    cin >> n >> x;
    string s;
    cin >> s;
    deque<char> que;

    for(int i=0;i<n;i++){
        if(s[i]=='R'){
            que.push_back('R');
        }
        else if(s[i]=='L'){
            que.push_back('L');
        }
        else if(que.empty()&&s[i]=='U'){
            if(x%2==0){
                x = x/2;
            }
            else{
                x = (x-1)/2;
            }
        }
        else{
            que.pop_back();
        }
    }
    while(!que.empty()){
        char c = que.front();que.pop_front();
        switch (c)
        {
        case 'R':
            x = x*2+1;
            break;
        case 'L':
            x = 2*x;
        }
    }
    cout << x << endl;

    return 0;
}