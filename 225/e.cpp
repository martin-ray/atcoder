#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>
#include<list>
#include<cmath>

using namespace std;

int main(void){

    int n;
    cin >> n;
    vector<pair<double,double>> p(n);
    vector<pair<double,double>> occupy_range(n);

    for(int i=0;i<n;i++){
        cin >> p[i].first >> p[i].second;
        occupy_range.push_back(make_pair(atan2f64(p[i].second,p[i].first-1),atan2f64(p[i].second-1,p[i].first)));
    }
    sort(occupy_range.begin(),occupy_range.end());

    for(int i=0;i<n;i++){
        cout << occupy_range[i].first << " " << occupy_range[i].second << endl;
    }
    int ans=0;

    double now_at = 0.0;
    now_at = occupy_range[0].first;
    ans++;
    for(int i=1;i<n;i++){
        while(occupy_range[i].second<now_at&&now_at<=occupy_range[n-1].first&&i<n){
            i++;
        }
        if(i<n){
            ans++;
            now_at = occupy_range[i].first;
        }
    }

    cout << ans << endl;
    
    return 0;
}