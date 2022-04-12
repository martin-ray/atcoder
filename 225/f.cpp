#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>
#include<list>

using namespace std;
//区間スケジューリングの練習よ
int main(void){

    int n;
    cin >> n;
    vector<pair<int,int>> task(n);
    for(int i=0;i<n;i++){
        cin >> task[i].second >> task[i].first;
    }
    sort(task.begin(),task.end());

    int ans = 1;
    int now_at = task[0].first;
    for(int i=1;i<n;i++){
        if(task[i].second < now_at){
            continue;
        }
        else{
            ans++;
            now_at = task[i].first;
        }
    }

    cout << ans << endl;

    
    return 0;
}