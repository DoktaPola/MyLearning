#include <iostream>
#include <vector>


int seqSearch(std::vector<int>& vec, int num){
    for (int i = 0; i < vec.size(); i++){
        if(vec[i] == num){
            return i;
        }
    }
    return -1;
}

int main(){
    int num;
    std::cin >> num;
    std::vector<int> vec = {1, 23, 45, 67, 88, 10};
    std::cout << "index: " << seqSearch(vec, num) << std::endl;
    return 0;
}