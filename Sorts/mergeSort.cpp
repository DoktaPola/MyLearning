#include <iostream>
#include <vector>
#include <algorithm>


void mergeSort(std::vector<int>& arr, int low, int mid, int high, std::vector<int>& arr2){
    int second_half = mid;
    for (int i = low; i < high + 1; i++){
        arr2[i] = arr[i];
    }
    for (int i = low; i < high + 1; i++){
        if (low >= mid) {
            arr[i] = arr2[second_half];
            second_half += 1;
        }else if (second_half > high){
            arr[i] = arr2[low];
            low += 1;
        }else if (arr2[low] >= arr2[second_half]) {
            arr[i] = arr2[second_half];
            second_half += 1;
        }else if (arr2[low] < arr2[second_half]) {
            arr[i] = arr2[low];
            low += 1;
        }
    }
}


std::vector<int> sort(std::vector<int>& arr, int low, int high, std::vector<int>& arr2){
    int mid = low + (high - low) / 2;
    if (low < high){
        sort(arr, low, mid, arr2);
        sort(arr, mid + 1, high, arr2);
        mergeSort(arr, low, mid + 1, high, arr2);
        return arr;
    }
    return arr;
 }


int main(){
    std::vector<int> arr(1000);
    std::generate(arr.begin(), arr.end(), std::rand);
    for (int &e : arr) {
        e = e % 500;
    }

//    std::vector<int> arr = {10, -2, 5, 3, 4, 9, -2};
    std::vector<int> new_(arr);
    int low = 0;
    int high = arr.size() - 1;
    sort(arr, low, high, new_);
    bool res = std::is_sorted(arr.begin(), arr.end());
    std::cout << "Is sorted? " << res << std::endl;
//    for (auto& item:arr){
//        std::cout << item << " ";
//    }
}