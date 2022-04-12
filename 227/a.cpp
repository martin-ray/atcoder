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

    int n,k,a;
    cin >> n >> k >> a;

    int ans = (a + k -1)%n;

    if(ans == 0){
        cout << n << endl;
    }
    else{
        cout << ans << endl;
    }
    
    return 0;
}