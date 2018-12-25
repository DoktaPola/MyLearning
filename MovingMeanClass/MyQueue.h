
#ifndef LEARNING_MYQUEUE_H
#define LEARNING_MYQUEUE_H

#include <climits>
#include <vector>

class Queue{
public:
    void CheckEmpty() const ;
    void Enque(int num);
    int Deque();
    std::vector<int> passThroughVector();
    const int NO_VALUE = INT_MAX;
private:
    std::vector<int> vec;
};
#endif //LEARNING_MYQUEUE_H
