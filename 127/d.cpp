#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>
#include<list>

using namespace std;

int main(void){

    int n,m;
    cin >> n >> m;
    map<long long int,int> card;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        card[a]++;
    }
    for(int i=0;i<m;i++){
        int num,c;
        cin >> num >> c;
        card[c]+=num;
    }

    long long int ans = 0;
    int maisu = 0;

    for(auto itr=card.rbegin();itr!=card.rend();itr++){
        if(maisu + itr->second > n){
            ans += (n - maisu)*itr->first;
            break;
        }
        else{
            ans += itr->second*itr->first;
            maisu += itr->second;
        }

    }

    cout << ans << endl;
    
    return 0;
}