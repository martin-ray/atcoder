#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){

    int n,k;
    cin >> n >> k;

    vector<int> p(n);
    vector<int> p_cp(n);

    int max = 0;
    int tmp1,tmp2,tmp3;
    for(int i=0;i<n;i++){
        cin >> tmp1 >> tmp2 >> tmp3;
        p[i] = tmp1 + tmp2 + tmp3;

    }

    p_cp = p;
    sort(p_cp.rbegin(),p_cp.rend());
    int bound_point = p_cp[k-1];
    for(int i=0;i<n;i++){
        if(p[i] + 300 <bound_point){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl; 
        }
    }


    return 0;
}