#include <iostream>

struct Node {
    Node(int d, Node *n) {
        data = d;
        next = n;
    }
    int data;
    Node *next;
};

class LinkedList {
public:
    void add(int num);
    std::string toString();
    int remove();
    bool empty();
    void insert(int d, int x);
    int deleteAfter(int x);
    ~LinkedList();
private:
    Node *first = nullptr;
};


void LinkedList::add(int num) {
    Node *n = new Node(num, first);
    first = n;
}

std::string LinkedList::toString() {
    std::string arrow = " -> ";
    std::string s = " ";
    Node *node = first;
    while (node) {
        s += std::to_string(node->data);
        if (node->next) {
            s += arrow;
        }
        node = node->next;
    }
    return s;
}

int LinkedList::remove() {
    if (empty()){
        throw std::logic_error("Attempt to delete from empty list");
    }
    int removed = first->data;
    Node *n = first;
    first = first->next;
    delete n;
    return removed;
}

bool LinkedList::empty() {
    return first == nullptr;
}

void LinkedList::insert(int d, int x) {
    auto runner = first;
    while (runner->data != x) {
        runner = runner->next;
        if (runner == nullptr) {
            throw std::logic_error("Using insert function is impossible, number does not exist!");
        }
    }
    auto last = runner;
    Node *n = new Node(d, runner->next);
    last->next = n;
}

int LinkedList::deleteAfter(int x) {
    if (empty()){
        throw std::logic_error("Attempt to delete from empty list");
    }
    auto runner = first;
    while (runner->data != x) {
        runner = runner->next;
        if (runner == nullptr) {
            throw std::logic_error("Using deleteAfter function is impossible, number does not exist!");
        }
    }
    auto last = runner;
    if (runner->next) {
        auto new_first = runner->next;
        last->next = new_first->next;
        auto ret = new_first->data;
        delete new_first;
        return ret;
    } else {
        throw std::invalid_argument("There is no Node!");
    }

}

LinkedList::~LinkedList() {
    auto runner = first;
    while (runner) {
        auto new_first = runner->next;
        delete runner;
        runner = new_first;
    }
}


int main() {

    LinkedList l;


    l.add(3);
    l.add(2);
    l.add(1);

    std::cout << "removed: " << l.remove() << std::endl;

    std::cout << l.toString() << std::endl;


    std::cout << "Is empty? " << l.empty() << std::endl;

    l.insert(5, 2);   // 2 ОПЦИЯ (l.insert(5, 3);)

    std::cout << l.toString() << std::endl;


//    std::cout << l.deleteAfter(5) << std::endl;

    try {
//        l.remove()    if LL is empty
//        l.deleteAfter(255)   if LL is empty

        std::cout << l.deleteAfter(5) << std::endl;
        std::cout << l.deleteAfter(5463783) << std::endl;        // mapping?
    }catch (const std::exception &exception){
        std::cout << exception.what() << std::endl;
    }
    std::cout << l.toString() << std::endl;



    return 0;
}
