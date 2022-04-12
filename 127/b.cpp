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
    long long int r,D,x;
    cin >> r >> D >> x;

    for(int i=0;i<10;i++){
        long long int nextx = r*x -D;
        cout << nextx << endl;
        x = nextx;
    }
    
    return 0;
}