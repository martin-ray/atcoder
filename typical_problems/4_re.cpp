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

int main(void){

    int H,W;
    std::cin >> H >> W;
    std::vector<std::vector<int>> a(H+1,std::vector<int>(W+1));

    for(int h=0;h<H;h++){
        int sum=0;
        for(int w=0;w<W;w++){
            std::cin >> a[h][w];
            sum+=a[h][w];
        }
        a[h][W] = sum;
    }

    for(int w=0;w<W;w++){
        int sum=0;
        for(int h=0;h<H;h++){
            sum+=a[h][w];
        }
        a[H][w] = sum;
    }

    for(int h=0;h<H;h++){
        for(int w=0;w<W;w++){
            std::cout << a[h][W] + a[H][w] - a[h][w] << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}