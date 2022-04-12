#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<set>
#include<unordered_set>

using namespace std;

int main(void){

    int n;
    set<vector<int>> se;


    cin >> n;
    for(int i=0;i<n;i++){
        int l;
        cin >> l;
        vector<int> a(l);
        for(int j=0;j<l;j++){
            cin >> a[j];
        }
        se.insert(a);
    }

    cout << se.size() << endl;

    return 0;
}