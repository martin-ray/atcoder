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
    int left = 1,right = n;
    for(int i=0;i<m;i++){
        int right_tmp,left_tmp;
        cin >> left_tmp >> right_tmp;
        if(left_tmp>left){
            left = left_tmp;
        }
        if(right > right_tmp){
            right = right_tmp;
        }


    }

    if(right<left){
        cout << 0 << endl;
        return 0;
    }

    cout << right - left + 1 << endl;
    
    return 0;
}