#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>
#include<list>
#include<bits/stdc++.h>
#include <iomanip>
#include<queue> //do not forget about priority_queue;
//std::cout << std::setprecision(2) << 3.141; // "3.1"
using namespace std;
#define LARGE  998244353
#define inv2 499122177

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

unsigned long long int ipow( unsigned long long int base, int exp )
{
    unsigned long long int result = 1ULL;
    while( exp )
    {
        if ( exp & 1 )
        {
            result *= (unsigned long long int)base;
        }
        exp >>= 1;
        base *= base;
    }
    return result;
}

int main(void){

    long long int N;
    cin >> N;

    int keta = 0;
    long long int N_tmp = N;

    while(N_tmp!=0){
        N_tmp = N_tmp/10;
        keta++;
    }

    long long int ans = 0;
    for(int i=0;i<keta-1;i++){
        ans = ans + (((9*ipow(10,i))%LARGE*(9*ipow(10,i) + 1)))%LARGE*inv2;
        ans%=LARGE; 
    }

    ans = ans%LARGE;

    long long int a = (N-(ipow(10,keta-1)-1))%LARGE;
    long long int b = (N-(ipow(10,keta-1)-1)+1)%LARGE;

    cout <<  (a*b)%LARGE*inv2%LARGE << endl;

    ans = ans + (a*b)%LARGE*inv2%LARGE;
   
    cout << ans%LARGE << endl;

    return 0;
}