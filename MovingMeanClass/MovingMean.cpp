#include <iostream>
#include <vector>
#include "MyQueue.h"


class MovingMean{
public:
    MovingMean(int n){
        n1 = n;
    }
    double handleNext(double x);

private:
    Queue q;
    int n1;
};

double MovingMean::handleNext(double x) {
    q.Enque(x);
    double count = 0;

    if (q.passThroughVector().size() > n1){
        q.Deque();
    }
    for (auto& i:q.passThroughVector()){
        count += i;
    }
    double average = count/ q.passThroughVector().size();
    return average;
}

int main(){
    MovingMean mm(2);

    std::cout << mm.handleNext(1) << std::endl;
    std::cout << mm.handleNext(3) << std::endl;
    std::cout << mm.handleNext(4) << std::endl;
}