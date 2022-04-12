#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>

using namespace std;

int main(void){


    int n,m;
    cin >> n >> m;

    map<long long int,long long int> card;

    long long int tmp1,tmp2;
    for(int i=0;i<n;i++){
        cin >> tmp1;
        card[tmp1]++;
    }

    for(int i=0;i<m;i++){
        cin >>  tmp1 >> tmp2;
        card[tmp2]+=tmp1;
    }

    long long int ans = 0;

    long long int kosu=0;

    for(auto itr=card.rbegin();itr != card.rend();itr++){
        //cout << itr->first << endl;
        if(kosu + itr->second >= n){
            ans += (n - kosu)*itr->first;
            break;
        }
        else{
            ans += itr->first*itr->second;
            kosu += itr->second;
            //cout << ans << " "<< itr->first << " " << itr->second << endl;
        }
    }

    for(auto itr = card.begin();itr != card.end();itr++){
        //cout << itr->first << " " << itr->second << endl;
    }

    cout << ans << endl;

    return 0;
}