class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class LinkedList:
    def __init__(self, first=None):
        self.first = first

    def add(self, data):
        new_node = Node(data)
        new_node.next = self.first
        self.first = new_node

    def print_linked_list(self):
        arrow = ' -> '
        node = self.first
        string = ''
        while node:
            string += str(node.value)
            if node.next:
                string += arrow
            node = node.next
        return string

    def remove(self):
        removed = self.first.value
        self.first = self.first.next
        return removed


l = LinkedList()

l.add(3)
l.add(2)
l.add(1)
print('removed:', l.remove())
print(l.print_linked_list())
