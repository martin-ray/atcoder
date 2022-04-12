#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;

int main(void){

    double x;

    cin >> x;
    x=x*10;
    int ans = x;
    if(ans%10>=5){
        cout << (ans+10)/10 << endl;;
    }
    else{
        cout << ans/10 <<endl;
    }

    return 0;
}