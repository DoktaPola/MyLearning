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

    Node* prevNode(int num);

    void add(int num);

    bool isEmpty();

    bool get(int num);

    bool getRec(int num);

    Node* getMin();

    int getMax();

    std::string preOrder();

    std::string inOrder();

    std::string postOrder();

    void deleteNode(int num);


private:
    Node *first = nullptr;

    bool getRecHidden(int num, Node* otherNode);

    std::string preOrderHidden(Node *currentNode);

    void inOrderHidden(Node *currentNode, std::string &st);

    std::string postOrderHidden(Node *currentNode);

    Node* getMin(Node *currentNode);

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

bool Tree::getRecHidden(int num, Node* otherNode) {
    bool flag = false;
    if (isEmpty()) {
        throw std::logic_error("Using GETREC function is impossible, Tree is empty!");
    }  else if (!otherNode){
        return flag;
    } else {
        if (num > otherNode->data) {
            return getRecHidden(num, otherNode->right);
        } else if (num < otherNode->data) {
            return getRecHidden(num, otherNode->left);
        } else if (num == otherNode->data) {
            flag = true;
        }
        return flag;
    }
}

bool Tree::getRec(int num) {
    auto otherNode = first;
    return getRecHidden(num, otherNode);
}


bool Tree::isEmpty() {
    return first == nullptr;
}

Node* Tree::getMin(Node *currentNode) {                                  // new
    if (isEmpty()) {
        throw std::logic_error("Using GETMIN function is impossible, Tree is empty!");
    }
    if (currentNode->left) {
        return getMin(currentNode->left);
    } else {
        return currentNode;
    }
}

Node* Tree::getMin() {                                                        // new
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


void Tree::inOrderHidden(Node *currentNode, std::string &st) {
    if (isEmpty()) {
        throw std::logic_error("Using this function is impossible, Tree is empty!");
    } else if (!currentNode) {
        return;
    } else {
        inOrderHidden(currentNode->left, st);
        st += std::to_string(currentNode->data);
        inOrderHidden(currentNode->right, st);
    }
}

std::string Tree::inOrder() {
    auto runner = first;
    std::string st;
    inOrderHidden(runner,st);
    return st;
}

std::string Tree::postOrderHidden(Node *currentNode) {
    std::string s;
    if (isEmpty()) {
        throw std::logic_error("Using this function is impossible, Tree is empty!");
    } else if (!currentNode){
        return s;
    } else {
        s += postOrderHidden(currentNode->left);
        s += postOrderHidden(currentNode->right);
        s += std::to_string(currentNode->data);
    }
    return s;
}

std::string Tree::postOrder() {
    auto runner = first;
    std::string st;
    st += postOrderHidden(runner);
    return st;
}

void Tree::deleteNode(int num) {
    if (isEmpty()) {
        throw std::logic_error("Using delete function is impossible, Tree is empty!");
    } else {
        auto otherNode = first;
        Node* additionalPrev = nullptr;
        while (otherNode && num != otherNode->data) {
            if (num > otherNode->data) {
                additionalPrev = otherNode;
                otherNode = otherNode->right;
            } else if (num < otherNode->data) {
                additionalPrev = otherNode;
                otherNode = otherNode->left;
            }
        }
        if (!otherNode){
            throw std::invalid_argument("Key is not in tree!");
        }
        auto tmp = otherNode;
        if (additionalPrev == nullptr){
            additionalPrev = otherNode;
            deleteNode(otherNode->data);
        }
        if (otherNode->left == nullptr) {
            if (additionalPrev->data > otherNode->data) {
                additionalPrev->left = otherNode->right;
            } else if (additionalPrev->data <= otherNode->data) {
                additionalPrev->right = otherNode->right;
            }
            delete tmp;
        } else if (otherNode->right == nullptr){
            if (additionalPrev->data > otherNode->data){
                additionalPrev->left = otherNode->left;
            } else if (additionalPrev->data < otherNode->data){
                additionalPrev->right = otherNode->left;
            }
            delete tmp;
        } else if (otherNode->left && otherNode->right){
            auto minNode = getMin(otherNode->right);
            if (otherNode->right->data > minNode->data){
                int addMin = minNode->data;
                deleteNode(minNode->data);
                otherNode->data = addMin;
            }else if (otherNode->right->data <= minNode->data){
                otherNode->right = minNode;
                int addMin = minNode->data;
                deleteNode(minNode->data);
                otherNode->data = addMin;
            }
        }
    }
}

Node* Tree::prevNode(int num) {
    auto runner = first;
    Node* neededNode = nullptr;
    while (runner) {
        if (num > runner->data) {
            neededNode = runner;
            runner = runner->right;
        } else if (num < runner->data) {
            neededNode = runner;
            runner = runner->left;
        } else if (num == runner->data) {
            break;
        }
    }
    return neededNode;
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

    t.prevNode(5);
//    std::cout << "Is there such a number? " << t.get(0) << std::endl;
//    std::cout << "Is there such a number? " << t.get(1) << std::endl;
    std::cout << "*rec*  Is there such a number? " << t.getRec(1) << std::endl;

    std::cout << "Min number: " << t.getMin() << std::endl;

    std::cout << "Max number: " << t.getMax() << std::endl;

    std::cout << "Pre-Order: " << t.preOrder();
    std::cout << std::endl;

    t.deleteNode(3);

    std::cout << "Pre-Order: " << t.preOrder();
    std::cout << std::endl;

    std::cout << "Post-Order: " << t.postOrder();
    std::cout << std::endl;

    std::cout << "In-Order: " << t.inOrder();
    std::cout << std::endl;

    return 0;
}
