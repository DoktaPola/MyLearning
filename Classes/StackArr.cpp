#include <iostream>

class Stack{
public:
    Stack(){
        arr = new int[3];
        size = 3;
        index = 0;
    }
    void CheckEmpty() const;
    void CheckSize();
    void Push(int num);
    int Pop();
    const int NO_VALUE = INT_MAX;
private:
    int size;
    int *arr;
    int index;
};

void Stack::CheckEmpty() const {

}

void Stack::CheckSize() {

}

void Stack::Push(int num) {
    if (index == size){
        int* arr2 =  new int[size*2];
        for (int i = 0; i < size; i++){
            arr2[i] = arr[i];
        }
        size = size * 2;
        delete[] arr;
        arr = arr2;
    }
    arr[index] = num;
    index++;
}

int Stack::Pop() {
    if(index == 0){
        return NO_VALUE;
    }else{
        int del_first = arr[index - 1];
        index--;
        return del_first;
    }
}


int main(){
    Stack s;

    s.Push(3);
    s.Push(5);
    s.Push(7);
    s.Push(8);

    std::cout << s.Pop() << std::endl;
    std::cout << s.Pop() << std::endl;
    std::cout << s.Pop() << std::endl;
    std::cout << s.Pop() << std::endl;
    std::cout << s.Pop() << std::endl;


    return 0;
}