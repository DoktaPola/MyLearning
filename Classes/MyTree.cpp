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

    Node *prevNode(int num);

    void add(int num);

    bool isEmpty();

    bool get(int num);

    bool getRec(int num);

    Node *getMin();

    int getMax();

    std::string preOrder();

    std::string inOrder();

    std::string postOrder();

    void deleteNode(int num);

    int floor(int num);

    int ceil(int num);

    bool isBST();

    int* floor2(int num);

    ~Tree();


private:
    Node *first = nullptr;

    bool getRecHidden(int num, Node *otherNode);

    std::string preOrderHidden(Node *currentNode);

    void inOrderHidden(Node *currentNode, std::string &st);

    std::string postOrderHidden(Node *currentNode);

    Node *getMin(Node *currentNode);

    bool floorHidden(int num);

    bool ceilHidden(int num);

    bool isBST(Node *node, int *leftMin, int *rightMax);

    int* floor2Rec(Node *node, int num);

    void vanish(Node* node, Node* Left, Node* Right);
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

bool Tree::getRecHidden(int num, Node *otherNode) {
    bool flag = false;
    if (isEmpty()) {
        throw std::logic_error("Using GETREC function is impossible, Tree is empty!");
    } else if (!otherNode) {
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

Node *Tree::getMin(Node *currentNode) {                                  // new
    if (isEmpty()) {
        throw std::logic_error("Using GETMIN function is impossible, Tree is empty!");
    }
    if (currentNode->left) {
        return getMin(currentNode->left);
    } else {
        return currentNode;
    }
}

Node *Tree::getMin() {                                                        // new
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
    inOrderHidden(runner, st);
    return st;
}

std::string Tree::postOrderHidden(Node *currentNode) {
    std::string s;
    if (isEmpty()) {
        throw std::logic_error("Using this function is impossible, Tree is empty!");
    } else if (!currentNode) {
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
        Node *prev = nullptr;
        while (otherNode && num != otherNode->data) {
            if (num > otherNode->data) {
                prev = otherNode;
                otherNode = otherNode->right;
            } else if (num < otherNode->data) {
                prev = otherNode;
                otherNode = otherNode->left;
            }
        }
        if (!otherNode) {
            throw std::invalid_argument("Key is not in tree!");
        }
        if (otherNode->left == nullptr && otherNode->right == nullptr) {
            auto tmp = otherNode;
            if (otherNode->data < prev->data) {
                prev->left = nullptr;
            } else {
                prev->right = nullptr;
            }
            delete tmp;
        } else if (otherNode->left == nullptr) {
            otherNode->data = otherNode->right->data;
            auto tmp = otherNode->right;
            otherNode->right = otherNode->right->right;
            delete tmp;
        } else if (otherNode->right == nullptr) {
            otherNode->data = otherNode->left->data;
            auto tmp = otherNode->left;
            otherNode->left = otherNode->left->left;
            delete tmp;
        } else if (otherNode->left && otherNode->right) {
            auto minNode = getMin(otherNode->right);
            if (otherNode->right->data > minNode->data) {
                int addMin = minNode->data;
                deleteNode(minNode->data);
                otherNode->data = addMin;
            } else if (otherNode->right->data <= minNode->data) {
                otherNode->right = minNode;
                int addMin = minNode->data;
                deleteNode(minNode->data);
                otherNode->data = addMin;
            }
        }
    }
}

Node *Tree::prevNode(int num) {
    auto runner = first;
    Node *neededNode = nullptr;
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

bool Tree::floorHidden(int num) {
    bool checkForMin;
    if (num < getMin(first)->data && num < first->data) {
        checkForMin = false;
    } else {
        checkForMin = true;
    }
    return checkForMin;
}

int Tree::floor(int num) {
    if (floorHidden(num)) {
        if (getRec(num)) {
            return num;
        } else {
            return floor(num - 1);
        }
    } else {
        throw std::logic_error("There is no value less than specified!");
    }
}

bool Tree::ceilHidden(int num) {
    bool checkForMax;
    if (num > getMax()) {
        checkForMax = false;
    } else {
        checkForMax = true;
    }
    return checkForMax;
}

int Tree::ceil(int num) {
    if (ceilHidden(num)) {
        if (getRec(num)) {
            return num;
        } else {
            return ceil(num + 1);
        }
    } else {
        throw std::logic_error("There is no value bigger than specified!");
    }
}

bool Tree::isBST(Node *node, int *leftMin, int *rightMax) {
    bool Flag = false;
    bool isLeftOk;
    bool isRightOk;
    if (node == nullptr) {
        return true;
    } else {
        if ((rightMax == nullptr || node->data < *rightMax) && (leftMin == nullptr || node->data > *leftMin)) {
            Flag = true;
        }
        isLeftOk = isBST(node->left, leftMin, &node->data);
        isRightOk = isBST(node->right, &node->data, rightMax);
        return Flag && isLeftOk && isRightOk;
    }
}

bool Tree::isBST() {
    auto node = first;
    int *leftMin = nullptr;
    int *rightMax = nullptr;
    bool answer = isBST(node, leftMin, rightMax);
    return answer;
}

int* Tree::floor2Rec(Node *node, int num) {
    int* value = nullptr;
    if (node == nullptr) {
        return value;
    } else if (node->data == num) {
        return &node->data;
    } else if (node->data > num) {
        value = floor2Rec(node->left, num);
        return value;
    } else {
        value = floor2Rec(node->right, num);
        if (value == nullptr) {
            return &node->data;
        }
        return value;
    }
}

int* Tree::floor2(int num) {
    Node *node = first;
    return floor2Rec(node, num);
}

//void Tree::vanish(Node* node, Node* Left, Node* Right) {  // три параметра
//
//    // удаление корня
//
//    auto new_left = Left->left;
//    delete Left;
//    Left = new_left;
//    vanish(Left);
//
//    auto new_right = Right->right;
//    delete Right;
//    Right = new_right;
//    vanish(Right);
//}
//
//Tree::~Tree() {
//    auto root = first;
//    auto Left = first->left;
//    auto Right = first->right;
//    vanish(root, Left, Right);  //  или просто root  и три вызова
//}



//LinkedList::~LinkedList() {
//    auto runner = first;
//    while (runner) {
//        auto new_first = runner->next;
//        delete runner;
//        runner = new_first;
//    }
//}




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

//    t.add(5);
//    t.add(3);
//    t.add(1);
//    t.add(4);
//    t.add(4);
//    t.add(2);
//    t.add(6);
//    t.add(20);
//    t.add(9);
//    t.add(31);
    t.add(9);
    t.add(5);
    t.add(3);
    t.add(7);
//    t.add(6);

    std::cout << "New floor: " << t.floor2(6) << std::endl;

    t.prevNode(5);
//    std::cout << "Is there such a number? " << t.get(0) << std::endl;
//    std::cout << "Is there such a number? " << t.get(1) << std::endl;

    std::cout << "Is Tree? " << t.isBST() << std::endl;

    std::cout << "*rec*  Is there such a number? " << t.getRec(1) << std::endl;

    std::cout << "Min number: " << t.getMin() << std::endl;

    std::cout << "Max number: " << t.getMax() << std::endl;

    std::cout << "Floor: " << t.floor(6) << std::endl;

    std::cout << "Ceil: " << t.ceil(22) << std::endl;

    std::cout << "Pre-Order: " << t.preOrder();
    std::cout << std::endl;

//    t.deleteNode(5);
//    t.deleteNode(2);
//    t.deleteNode(1);

    std::cout << "Pre-Order: " << t.preOrder();
    std::cout << std::endl;

    std::cout << "Post-Order: " << t.postOrder();
    std::cout << std::endl;

    std::cout << "In-Order: " << t.inOrder();
    std::cout << std::endl;

    return 0;
}
