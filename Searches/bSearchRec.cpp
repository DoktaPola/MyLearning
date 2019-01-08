#include <iostream>
#include <vector>

int bSearchRec(int num, const std::vector<int>& vec, int low, int high){
    if (low <= high){
        int half = (low + high) / 2;
        if (num < vec[half]){
            return bSearchRec(num, vec, low, half - 1);
        }else if (num > vec[half]){
            return bSearchRec(num, vec, half + 1, high);
        }else{
            return half;
        }
    }else{
        return -1;
    }
}

int main(){
    int num;
    std::cin >> num;
    std::vector<int> vec = {0, 1, 98, 456, 2334, 10000};
    int low = 0;
    int high = vec.size() - 1;
    std::cout << "index: " << bSearchRec(num, vec, low, high);
    return 0;
}

