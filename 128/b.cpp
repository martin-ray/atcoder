#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>
#include<list>

using namespace std;

typedef struct restarurant {
    string s;
    int p;
    int num;
}Rest;

int main(void){

    int n;
    cin >> n;

    Rest r[n];
    Rest tmp;
    for(int i=0;i<n;i++){
        cin >> r[i].s >> r[i].p;
        r[i].num = i+1;
    }
    
    //並び替え
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(r[i].s > r[j].s){
                swap(r[i],r[j]);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(r[i].p < r[j].p && r[i].s == r[j].s){
                swap(r[i],r[j]);
            }
        }
    }

    for(int i=0;i<n;i++){
        cout << r[i].num << endl;
    }
    return 0;
}