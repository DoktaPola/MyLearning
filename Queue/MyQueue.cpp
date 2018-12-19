#include <iostream>
#include <vector>

class Queue{
public:
    void CheckEmpty() const ;
    void Enque(int num);
    int Deque();
    const int NO_VALUE = INT_MAX;
private:
    std::vector<int> vec;
};

void Queue::CheckEmpty() const {
    if (vec.empty()){
        std::cout << "Empty" << std::endl;
    } else{
        std::cout << "Queue is not empty" << std::endl;
    }
}

void Queue::Enque(int num) {
    vec.push_back(num);
}

int Queue::Deque() {
    if (vec.empty()){
        return NO_VALUE;
    }else{
        int first_num = vec[0];
        vec.erase(vec.begin());
        return first_num;
    }
}

int main() {
    Queue q;

    q.Enque(6);
    q.Enque(60);
    q.Enque(61);
    q.Enque(90);

    std::cout << q.Deque() << std::endl;
    std::cout << q.Deque()<< std::endl;
    std::cout << q.Deque()<< std::endl;
    std::cout << q.Deque()<< std::endl;
    std::cout << q.Deque()<< std::endl;

    q.CheckEmpty();

    return 0;
}

