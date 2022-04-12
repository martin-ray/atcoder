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

    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    int tmp;
    for(int i=0;i<n-1;i++){
        cin >> a[i].first >> a[i].second;
    }


    if(a[0].first==a[1].first||a[0].first==a[1].second){
        tmp = a[0].first;
    }
    else if(a[0].second==a[1].first||a[0].second==a[1].second){
        tmp = a[0].second;
    }
    else{
        cout <<"No" << endl;
        return 0;
    }
    for(int i=0;i<n-1;i++){
        if(a[i].first!=tmp&&a[i].second!=tmp){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}