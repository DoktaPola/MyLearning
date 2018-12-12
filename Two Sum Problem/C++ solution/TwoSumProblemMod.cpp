#include <iostream>
#include <vector>
#include "q_sort.h"
#include "BinarySearch.h"


void TwoSumProblem(std::vector<int>& vec){
    int count = 0;
    for (int num = 0; num < vec.size() - 1; num++){
        if (vec[num] >= 0){
            break;
        }else{
            int new_num = BinarySearch(abs(vec[num]), vec);
            if (new_num){
                count += 1;
            }
        }
    }
    std::cout << count;
}


int main(){
    int nums;
    freopen("1Mints.txt", "r", stdin);
    std::vector<int> numbers;
    for (int i = 0; i < 1000000; ++i) {
        std::cin >> nums;
        numbers.push_back(nums);
    }
    int low = 0;
    int high = numbers.size() - 1;
    QSort(numbers, low, high);
    TwoSumProblem(numbers);
    return 0;
}
