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

    int n,m;
    cin >> n >> m;
    vector<vector<int>> b(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> b[i][j];
        }
    }
    for(int i=0;i<m-1;i++){
        if(b[0][i]+1!=b[0][i+1]){
            cout << "No" << endl;
            return 0;
        }
    }

    //7の倍数が7行目以外に来るか
    for(int i=0;i<m-1;i++){
        if(b[0][i]%7==0){
            cout << "No" << endl;
            return 0;
        }
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            if(b[i][j]+7 != b[i+1][j]){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;

    
    return 0;
}