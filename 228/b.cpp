#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

int main(void){

    int n,x;
    cin >> n >> x;

    vector<int> a(n);
    vector<int> does_know(n,0);

    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i]--;
    }

    x--;

    does_know[x] = 1;
    int ans =1;

    int prev = x;
    for(int i=0;i<n;i++){
        int next = a[prev];
        if(does_know[next]==0){
            does_know[next]++;
            ans++;
            prev = next;
        }
        else{
            break;
        }
    }

    cout << ans << endl;

    return 0;
}