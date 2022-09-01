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
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> b(n);
    for(int i=0;i<n;i++)std::cin >> a[i];
    for(int i=0;i<n;i++)std::cin >> b[i];
    std::sort(a.begin(),a.end());
    std::sort(b.begin(),b.end());

    int student = 0;
    int school = 0;
    long long int e_sum = 0;
    while(student<n){
        e_sum += std::abs(a[student++] - b[school++]);
    }

    std::cout << e_sum << std::endl;

    return 0;
}