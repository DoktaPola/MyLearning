#include <iostream>
#include <vector>
#include <algorithm>

void Swap(int& el1, int& el2) {
    int tmp;
    tmp = el1;
    el1 = el2;
    el2 = tmp;
}

void QSort(std::vector<int>& vec, int low, int high){
    int l = low, h = high;
    int pointer = low + (high - low + 1) / 2;
    int pivot = vec[pointer];
    while (low <= high) {
        while (vec[low] < pivot) {
            low++;
        }
        while (vec[high] > pivot) {
            high--;
        }
        if (low <= high){
            Swap(vec[low], vec[high]);
            low++;
            high--;
        }
    }
    if (high > l){
        QSort(vec, l, high);
    }
    if (low < h){
        QSort(vec, low, h);
    }
}

