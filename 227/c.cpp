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


int main(void){

    unsigned long long int n;
    cin >> n;

    long long int ans = 0;
    long long int a = 1;
    long long int b;
    long long int c_upmost;

    for(long long int a = 1;a*a*a <=n;a++){
        for(long long int b = a; a*b*b <= n;b++){
            c_upmost = n/(a*b);
            ans += c_upmost - b + 1;
        }
    }

    cout << ans << endl;
    
    return 0;
}