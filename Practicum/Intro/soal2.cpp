#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main(){
    int n, k;
    std::cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++){
        std::cin >> arr[i];
    }
    for (int i = 0; i < n; i++){
        int num;
        for (int z = i+1; z < n; z++){
            num = arr[i] - arr[z];
            if (num%k == 0){
                std::cout << "VULNERABLE";
                return 0;
            }
        }
    }
    std::cout << "SECURE";

    return 0;
}