#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>

int main(void){

    int n,q;
    std::cin >> n >> q;

    std::vector<long long> a(n);
    std::vector<long long> x(q);
    for(int i=0;i<n;i++){
        std::cin >> a[i];
    }

    for(int i=0;i<q;i++){
        std::cin >> x[i];
    }

    //昇順
    std::sort(a.begin(),a.end());

    //クエリ処理
    for(int i=0;i<q;i++){
    //二分探索
        int upper = n;
        int lower = -1;
        int center = (upper+lower)/2;

        while(upper > lower + 1){
            if(x[i] > a[center]){
                lower = center;
            }
            else{
                upper = center;
            }
            center = (upper+lower)/2;
        }

        std::cout << n - upper << std::endl;


    }

    
    
}