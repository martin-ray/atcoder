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

    int n;
    cin >> n;
    vector<int> s(n);

    for(int i=0;i<n;i++){
        cin >> s[i];
    }

    int ans = 0;

    for(int i=0;i<n;i++){
        for(int a = 1;a <= 142;a++){
            if((s[i]-3*a)%(3+4*a)==0&&s[i]-3*a>0){
                ans++;
                break;
            }
        }
    }

    cout << n - ans << endl;
    
    return 0;
}