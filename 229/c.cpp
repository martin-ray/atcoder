#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include <cassert>
#include <functional>

using namespace std;

int main(void){

    int n;
    int w;
    cin >> n >> w;

    vector<pair<int,int>> cheese(n);

    for(int i=0;i<n;i++){
        cin >> cheese[i].first >> cheese[i].second;
    }
    sort(cheese.rbegin(),cheese.rend());
    

    long long int weight=0;
    long long int taste=0;
    for(int i=0;i<n;i++){
        //cout << cheese[i].first <<endl;
        if(weight+cheese[i].second<=w){
            taste+=(long long int)cheese[i].first*(cheese[i].second);
            weight+=cheese[i].second;
        }
        else{
            taste+=cheese[i].first*(w-weight);
            break;
        }
    }

    cout << taste << endl;
    return 0;
}