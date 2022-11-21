#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>
#include<list>
#include<bits/stdc++.h>
#include <iomanip>
#include<queue> //do not forget about priority_queue;
//std::cout << std::setprecision(2) << 3.141; // "3.1"

using namespace std;

#define MOD 1000000007

bool is_misleading(int a,int b,int c,int d){
    int ji= a*10 + c;
    int minute = b*10 + d;
    if(0 <= ji && ji < 24 && 0<= minute && minute < 60){
        return true;
    } else {
        return false;
    }
}

int main(void){
    int h,m;
    cin >> h >> m;
    for(int hh=0;hh<24;hh++){
        for(int min = 0; min < 60; min++ ){
            int ji = (h + hh)%24;
            int fun;
            if(hh==0){
                fun =(m + min)%60;
                if(fun < m)break;
            } else {
                fun = min;
            }
            int a = ji/10;
            int b = ji%10;
            int c = fun/10;
            int d = fun%10;
            if(is_misleading(a,b,c,d)){
                cout << a*10 + b << " " << c*10 + d << endl;
                return 0;
            }
        }
    }
    return 0;
}