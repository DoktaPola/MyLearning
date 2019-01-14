#include <iostream>

struct Node{
    Node(int d,Node* n){
        data = d;
        next = n;
    }
    int data;
    Node* next;
};

class LinkedList{
public:
    void add(int num);
    std::string printLL();
    int remove();
private:
      Node* first = NULL;
};

void LinkedList::add(int num) {
    Node* n = new Node(num, first);
    first = n;
}

std::string LinkedList::printLL() {
    std::string arrow = " -> ";
    std::string s = " ";
    Node* node = first;
    while (node){
        s += std::to_string(node->data);
        if (node->next){
            s += arrow;
        }
        node = node->next;
    }
    return s;
}

int LinkedList::remove() {
    int removed = first->data;
    first = first->next;
    return removed;
}

int main(){
    LinkedList l;

    l.add(3);
    l.add(2);
    l.add(1);

    std::cout << "removed: " << l.remove() << std::endl;

    std::cout << l.printLL() << std::endl;

    return 0;
}
