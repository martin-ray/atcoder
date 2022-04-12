#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

int main(void){

    int n,m;
    cin >> n >> m;

    vector<pair<long long,long long>> card;
    long long int a,b;

    for(int i=0;i<n;i++){
        cin >> a;
        card.push_back(make_pair(a,1));
    }
    for(int i=0;i<m;i++){
        cin >> a >> b;
        card.push_back(make_pair(b,a));
    }

    sort(card.rbegin(),card.rend());
    
    long long int ans = 0;
    int kosu = 0;
    int i = 0;

    while(kosu!=n){
        if(card[i].second + kosu >= n){
            ans += card[i].first*(n - kosu);
            break;
        }
        else{
            ans += card[i].first*card[i].second;
            kosu += card[i].second;
        }
        i++;
    }

    cout << ans << endl;

    return 0;
}