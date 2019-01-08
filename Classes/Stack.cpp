#include <iostream>
#include <vector>

class Stack{
public:
    std::string CheckEmpty() const;
    int CheckSize();
    void Push(int num);
    int Pop();
    const int NO_VALUE = INT_MAX;
private:
    std::vector<int> vec;
};

std::string Stack::CheckEmpty() const {
    if (vec.empty()){
        return "Empty!";
    }else{
        return "Not Empty!";
    }
}

int Stack::CheckSize() {
    return vec.size();
}

void Stack::Push(int num) {
    vec.push_back(num);
}

int Stack::Pop() {
    if (!vec.empty()){
        int last = vec[vec.size() - 1];
        vec.erase(vec.begin() + vec.size() - 1);
        return last;
    }else{
        return NO_VALUE;
    }
}


int main(){
    Stack s;

    s.Pop();

    s.Push(1);
    s.Push(2);
    s.Push(3);

    s.CheckEmpty();

    s.CheckSize();

    std::cout << s.Pop() << std::endl;
    std::cout << s.Pop() << std::endl;
    std::cout << s.Pop() << std::endl;
    std::cout << s.Pop() << std::endl;

    s.CheckEmpty();

    s.CheckSize();

    return 0;
}