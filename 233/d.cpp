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
    //これは一見尺取り法だが、部分和っぽい感じもある
    long long int n,k;
    cin >> n >> k;
    vector<long long int> a(n);
    long long int min = 1000100010001000;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(min > a[i]) min = a[i];
    }
    vector<long long int > na;
    //単調増加に変更

    long long int geta = abs(min) +1 ;

    for(int i=0;i<a.size();i++){
        a[i]+=geta;
    }

    vector<long long int> acum(n);
    acum[0] = a[0];
    for(int i=1;i<a.size();i++){
        acum[i] = acum[i-1] + a[i];
    }

    int r=0,l=0;
    long long int ans =0;
    //l=1
    while(r < acum.size()){
        if(acum[r] - geta*(r+1) == k){
            ans++;
            cout << "kita0" << endl;
        }
        r++;
    }
    r = 1;
    //1<l
    while(r < acum.size() && l<=r){
        if(acum[r] - acum[l]  < k + geta*(r-l+1)){
            r++;
            cout << "kita1" << endl;
        }
        else if(acum[r] - acum[l]  > k + geta*(r-l+1)){
            l++;
            cout << "kita2" << endl;
        }
        else if(acum[r] - acum[l]  == k + geta*(r-l+1)){
            ans++;
            r++;
            cout << "kita3" << endl;
        }
    }

    cout << ans << endl;

    
    
    return 0;
}