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

    int x,y;
    cin >> x >> y;
    int diff = y-x;
    if(diff%10==0){
        cout << diff/10 << endl;
    }
    else if(diff > 0){
        cout << diff/10+1 << endl;
    }
    else{
        cout << 0 << endl;
    }
    
    return 0;
}