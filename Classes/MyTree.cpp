#include <iostream>

struct Node {
    Node(int d, Node *l, Node *r) {
        data = d;
        left = l;
        right = r;
    }

    int data;
    Node *left = nullptr;
    Node *right = nullptr;
};

class Tree {
public:
    void add(int num);

    bool isEmpty();

    bool get(int num);

    int getMin();

    int getMax();

    std::string preOrder();

    std::string inOrder();

    std::string postOrder();


private:
    Node *first = nullptr;

    std::string preOrderHidden(Node *currentNode);

    std::string inOrderHidden(Node *currentNode);

    std::string postOrderHidden(Node *currentNode);

    int getMin(Node *currentNode);

};

void Tree::add(int num) {
    if (isEmpty()) {
        first = new Node(num, nullptr, nullptr);
    } else {
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
        if (prev->data < num) {
            prev->right = new Node(num, nullptr, nullptr);
        } else {
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
        while (otherNode) {
            if (num > otherNode->data) {
                otherNode = otherNode->right;
            } else if (num < otherNode->data) {
                otherNode = otherNode->left;
            } else if (num == otherNode->data) {
                flag = true;
                break;
            }
        }
    }
    return flag;
}

bool Tree::isEmpty() {
    return first == nullptr;
}

int Tree::getMin(Node *currentNode) {
    if (isEmpty()) {
        throw std::logic_error("Using GETMIN function is impossible, Tree is empty!");
    }
    if (currentNode->left) {
        return getMin(currentNode->left);
    } else {
        return currentNode->data;
    }
}

int Tree::getMin() {
    return getMin(first);
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


std::string Tree::preOrderHidden(Node *currentNode) {
    std::string s;
    if (isEmpty()) {
        throw std::logic_error("Using this function is impossible, Tree is empty!");
    } else if (!currentNode) {
        return s;
    } else {
        s += std::to_string(currentNode->data);
        s += preOrderHidden(currentNode->left);
        s += preOrderHidden(currentNode->right);
    }
    return s;
}

std::string Tree::preOrder() {
    auto runner = first;
    std::string st;
    st += preOrderHidden(runner);
    return st;
}


std::string Tree::inOrderHidden(Node *currentNode) {
    std::string s;
    if (isEmpty()) {
        throw std::logic_error("Using this function is impossible, Tree is empty!");
    } else {
        inOrderHidden(currentNode->left);
        s += std::to_string(currentNode->data);
        inOrderHidden(currentNode->right);
    }
    return s;
}

std::string Tree::inOrder() {

}

std::string Tree::postOrderHidden(Node *currentNode) {
    std::string s;
    if (isEmpty()) {
        throw std::logic_error("Using this function is impossible, Tree is empty!");
    } else {
        while (currentNode) {
            s += std::to_string(currentNode->data);
            preOrderHidden(currentNode->right);
            preOrderHidden(currentNode->left);
        }
    }
    return s;
}

std::string Tree::postOrder() {

}


//int main() {
//    Tree t;
//
//    freopen("natural_order_1M.txt", "r", stdin);
//    int num;
//    for (int i = 0; i < 1000000; ++i){
//        std::cin >> num;
//        t.add(num);
//        }
//    std::cout << "Is there such a number? " << t.get(2) << std::endl;
//    return 0;
//}


int main() {
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

    std::cout << t.preOrder();
    std::cout << std::endl;

    return 0;
}
