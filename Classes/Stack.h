

#ifndef LEARNING_STACK_H
#define LEARNING_STACK_H

#include <climits>
#include <vector>

class Stack {
public:
    void CheckEmpty() const;
    void CheckSize();
    void Push(int num);
    int Pop();
    const int NO_VALUE = INT_MAX;
private:
    std::vector<int> vec;
};


#endif //LEARNING_STACK_H
