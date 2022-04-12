#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

int main(void){

    int n;
    long long int d;
    cin >> n >> d;

    vector<pair<int,int>> range(n);
    for(int i=0;i<n;i++){
        cin >> range[i].second >> range[i].first;
    }
    sort(range.begin(),range.end());

    //パンチ回数、現在の
    int ans = 0;
    int x = -1;
    for(auto itr=range.begin();itr!=range.end();itr++){
        int l = itr->second;
        int r = itr->first;
        if(l <= x){
            continue;
        }
        else{
            ans++;
            x = r + d - 1;
        }
    }

    cout << ans << endl;;


    
    return 0;
}