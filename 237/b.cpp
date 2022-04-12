#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

int main(void){

    int h,w;
    cin >> h >> w;

    vector<vector<int>> matrix(h, vector<int>(w));

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> matrix[i][j];
        }
    }

    //レンダリング
    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            cout << matrix[j][i] << " ";
        }
        cout << "\n";
    }

    return 0;
}