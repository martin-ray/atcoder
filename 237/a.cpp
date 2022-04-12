#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

int main(void){

    long long  n;
    cin >> n;

    unsigned long long int upper_bound = pow(2,31);
    
    bool flag = false;

/*
    if(n[0]=='-'){
        n = n.substr(1);
        flag=true;
    }
    */

    unsigned long long  nn = llabs(n);

    if(nn < upper_bound && flag==false){
        cout << "Yes" << endl;
    }
    else if(nn == upper_bound && flag == true){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}