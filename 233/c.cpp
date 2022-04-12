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

unsigned long long int n,x;
long long int ans=0;

unsigned long long int MAX = pow(10,18);


void dfs(vector<vector<long long int>>& a,int depth,unsigned long long int sum){
    if(depth==n){
        if(sum==x){
            ans++;
        }
        else{
            return ;
        }

    }
    else{
        for(int i=0;i<a[depth].size();i++){
            if(sum*a[depth][i] > MAX){
                continue;
            }
            else{
                dfs(a,depth+1,sum*a[depth][i]);
            }

        }
    }
}

int main(void){

    cin >> n >> x;
    vector<vector<long long int>> a(n);
    for(int i=0;i<n;i++){
        int l;
        cin >> l;
        for(int j=0;j<l;j++){
            int tmp;
            cin >> tmp;
            a[i].push_back(tmp);
        }
    }


    dfs(a,0,1);
    cout << ans << endl;

    
    return 0;
}