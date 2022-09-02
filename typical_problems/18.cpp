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

double product(std::vector<double> p1, std::vector<double>p2){
    double ret =0;
    for(int i=0;i<3;i++){
        ret+=p1[i]*p2[i];
    }
    return ret;
}

double vec_abs(std::vector<double> p){
    return sqrtf64(p[0]*p[0] + p[1]*p[1] + p[2]*p[2]);
}

int main(void){
    int t;
    cin >> t;
    int l,x,y;
    cin >> l >> x >> y;
    int q;
    cin >> q;
    std::vector<int> e(q);
    std::vector<double> statue = {(double)x, (double)y, 0};
    for(int i=0;i<q;i++){
        int e;
        cin >> e;
        e%=t;
        std::vector<double> kanran = {0, -l/2.0*sin(2*M_PI/t*e) , l/2.0*(1-cos(2*M_PI/t*e))};
        std::vector<double> bottom = {(double)x,(double)y,l/2.0*(1-cos(2*M_PI/t*e))};
        std::vector<double> ks(3);
        std::vector<double> kb(3);
        for(int i=0;i<3;i++){
            ks[i] = statue[i] - kanran[i];
            kb[i] = bottom[i] - kanran[i];
        }
        if((kanran[1]==0&&kanran[2]==0)){
            std::cout << 0 << std::endl;
            continue;
        }
        double ans = acos(product(ks,kb)/(vec_abs(ks)*vec_abs(kb)))*180/M_PI;
        std::cout << std::setprecision(20) << ans << std::endl;
        
    }

    return 0;
}