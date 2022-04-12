#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>
#include<list>
#include<cmath>
#include<iomanip>

using namespace std;

int main(void){

    int N,k;
    cin >> N >> k;

    double ans = 0;
    for(int n=1;n<=N;n++){
        double tmp = 1/(double)N;
        int i = 0;
        while(n*pow(2,i) <= k-1){
            i++;            
        }
        
        ans += tmp*pow(1/(double)2,i);
    }
    
    cout << setprecision(10) << ans << endl;

    return 0;
}