#include <iostream>

class Queue{

public:
    Queue(){
        arr = new int[5];
        size = 5;
}
    void Enque(int num);
    int Deque();
    const int NO_VALUE = INT_MAX;
private:
    int size = 0;
    int* arr ;
    int first = 0;
    int index = 0;
};

void Queue::Enque(int num) {
    if (index != 0 && first == index){
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

int Queue::Deque() {
    if(first != index){
        int del_first = arr[first];
        first++;
        return del_first;
    }else{
        return NO_VALUE;
    }
}

int main(){
    Queue q;

    q.Enque(3);
    q.Enque(7);
    q.Enque(2);

    std::cout << q.Deque() << std::endl;
    std::cout << q.Deque() << std::endl;
    std::cout << q.Deque() << std::endl;
    std::cout << q.Deque() << std::endl;

    return 0;
}