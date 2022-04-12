#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>
#include<list>

using namespace std;

void dfs(int distance,int node,vector<vector<pair<int,int>>>& dd,vector<int>& borw){
    if(distance%2==0){
        borw[node] = 1;
    }
    else{
        borw[node] = 0;
    }
    for(int i=0;i<dd[node].size();i++){
        if(borw[dd[node][i].first]==-1){
            dfs(distance+dd[node][i].second,dd[node][i].first,(dd),borw);
        }

    }
    //cout << "kiteruyo" << endl;
}

int main(void){

    int n;
    cin >> n;
    vector<vector<pair<int,int>>> distance_destination(n);
    vector<int> black_or_white(n,-1);

    int first,second,third;
    for(int i=0;i<n-1;i++){
        cin >> first >> second >> third;
        first--;second--;
        distance_destination[first].push_back(make_pair(second,third));
        distance_destination[second].push_back(make_pair(first,third));
    }
    dfs(0,0,(distance_destination),black_or_white);

    for(int i=0;i<n;i++){
        cout << black_or_white[i] << endl;
    }


    
    return 0;
}