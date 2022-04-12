#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<iomanip>

using namespace std;

int main(void){

    int n;
    cin >> n;
    if(n >= 42){
        n++;
    }

    cout << "AGC"<< setfill('0') << std::right << std::setw(3) << n << "\n";


    return 0;
}