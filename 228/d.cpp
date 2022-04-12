#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
 
using namespace std;
 
int main(void){
 
    int q;
    cin >> q;
    
    long long int x;
    int t;
    long long int n = pow(2,20);
    vector<long long int> a(n,-1);
    //時間的にクエリを愚直にやっても間に合うっぽい
 
    for(int i=0;i<q;i++){
        cin >> t >> x;
        long long h = x;
        if(t==1){
            //個々でなにか奇跡を起こしたいhを線形でやらずに済むような。
            /**/

            if(h==nonzero_start){
                h = nonzero_goal + 1;
                nonzero_goal++;
            }
            while(a[h%n]!=-1){
                h++;
            }



            a[h%n] = x;
        }
        else{
            cout << a[x%n] << endl;
        }
    }
 
 
    return 0;
}