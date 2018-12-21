#include <iostream>


void revArr(int* arr, int size){
    int j = 0;
    for (int i = size - 1; i >= 0; i--){
        if (i == j){
            break;
        }
        int tmp;
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
        j++;
    }
}


int main(){
    int arr[5] = {4, 5, 3, 1, 8};
    int s = sizeof(arr)/ sizeof(arr[0]);
    revArr(arr, s);
    for (auto& a:arr){
        std::cout << a << " ";
    }
    return 0;
}
