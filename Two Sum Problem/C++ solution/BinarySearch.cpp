#include <iostream>
#include <vector>

bool BinarySearch(int num, const std::vector<int>& ar){
    int low = 0;
    int half = 0;
    int high = ar.size() - 1;
    while (low <= high){
        half = (low + high) / 2;
        if (num < ar[half]){
            high = half - 1;
        }else if (num > ar[half]){
            low = half + 1;
        }else if (num == ar[half]){
            return true;
        }
    }
    return false;
}



