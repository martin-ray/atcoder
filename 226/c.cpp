#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<set>
#include<queue>

using namespace std;


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
   vector<bool> is_acuired(n,false);

   queue<int> q;
   q.push(n-1);
   is_acuired[n-1] = true;
   while(!q.empty()){
       int waza = q.front();
       q.pop();
       for(int i=0;i<k[waza];i++){
           if(is_acuired[a[waza][i]]==false){
              q.push(a[waza][i]); 
              is_acuired[a[waza][i]] = true;              
           }
       }
   }
   //最後にis_acuiredをO(n)で走査して終了する感じで
   long long int ans = 0;
   for(int i=0;i<n;i++){
       if(is_acuired[i] == true){
           ans+=t[i];
       }
   }

   cout << ans << endl;
    return 0;
}