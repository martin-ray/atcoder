#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<set>
#include<queue>

using namespace std;


vector<bool> is_acuired(2*100000,false);

void dfs(int waza,vector<vector<int>>& a,vector<int>& k){
    if(is_acuired[waza]==false){
        is_acuired[waza] = true;
        for(int i=0;i<k[waza];i++){
            dfs(a[waza][i],a,k);
        }
    }
}


int main(void){

    //後ろからやっていけばいいかね、ワザnの習得のためには何が必要で
    /*
    ってのを再帰でやっていけばいいか
    */
   int n;
   cin >> n;
   int tmp;
   vector<int> t(n);
   vector<int> k(n);
   vector<vector<int>> a(n);
   for(int i=0;i<n;i++){
       cin >> t[i];
       cin >> k[i];
       for(int j=0;j<k[i];j++){
           cin >> tmp;
           tmp--;
           a[i].push_back(tmp);
       }
   }

   dfs(n-1,a,k);

   
   //最後にis_acuiredをO(n)で走査して終了する感じで
   long long int ans = 0;
   for(int i=0;i<is_acuired.size();i++){
       if(is_acuired[i] == true){
           ans+=t[i];
       }
   }

   cout << ans << endl;
    return 0;
}