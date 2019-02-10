#include <iostream>

struct Node{
    Node(int d, Node* l, Node* r){
        data = d;
        left = l;
        right = r;
    }
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
};

class Tree{
public:
    void add(int num);
    bool isEmpty();
    bool get(int num);
    int getMin();
    int getMax();

private:
    Node *first = nullptr;

};

void Tree::add(int num) {
    if (isEmpty()){
        first = new Node(num, nullptr, nullptr);
    }else{
        auto otherNode = first;
        auto prev = otherNode;
        while (otherNode) {
            if (num > otherNode->data) {
                prev = otherNode;
                otherNode = otherNode->right;
            } else if (num < otherNode->data) {
                prev = otherNode;
                otherNode = otherNode->left;
            } else if (num == otherNode->data) {
                return;
            }
        }
        if (prev->data < num){
            prev->right = new Node(num, nullptr, nullptr);
        }else{
            prev->left = new Node(num, nullptr, nullptr);
        }
    }
}

bool Tree::get(int num) {
    bool flag = false;
    if (isEmpty()) {
        throw std::logic_error("Using GET function is impossible, Tree is empty!");
    } else {
        auto otherNode = first;
        while (otherNode){
            if (num > otherNode->data) {
                otherNode = otherNode->right;
            } else if (num < otherNode->data) {
                otherNode = otherNode->left;
            } else if (num == otherNode->data) {
                flag =  true;
                break;
            }
        }
    }
    return flag;
}

bool Tree::isEmpty() {
    return first == nullptr;
}

int Tree::getMin() {
    auto otherNode = first;
    auto prev = otherNode;
    if (isEmpty()) {
        throw std::logic_error("Using GETMIN function is impossible, Tree is empty!");
    } else {
        while (otherNode) {
                prev = otherNode;
                otherNode = otherNode->left;
        }
    }
    return prev->data;
}

int Tree::getMax() {
    auto otherNode = first;
    auto prev = otherNode;
    if (isEmpty()) {
        throw std::logic_error("Using GETMAX function is impossible, Tree is empty!");
    } else {
        while (otherNode) {
            prev = otherNode;
            otherNode = otherNode->right;
        }
    }
    return prev->data;
}


int main(){
    Tree t;

//    try {
//        t.get(9);
//        t.getMin();
//        t.getMax();
//    }catch (const std::exception &exception){
//        std::cout << exception.what() << std::endl;
//    }

    t.add(5);
    t.add(3);
    t.add(1);
    t.add(4);
    t.add(4);
    t.add(2);
    t.add(6);

    std::cout << "Is there such a number? " << t.get(0) << std::endl;
    std::cout << "Is there such a number? " << t.get(1) << std::endl;

    std::cout << "Min number: " << t.getMin() << std::endl;

    std::cout << "Max number: " << t.getMax() << std::endl;

    return 0;
}
