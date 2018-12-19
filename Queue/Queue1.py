class Queue:
    def __init__(self):
        self.array = []

    def enque(self, number):
        self.array.append(number)

    def deque(self):
        if len(self.array) == 0:
            return None
        else:
            first = self.array[0]
            del self.array[0]
            return first

    def empty(self):
        if len(self.array) == 0:
            return True
        else:
            return False

    def size(self):
        return len(self.array)


q = Queue()
q.enque(6)
q.enque(60)
q.enque(61)
q.enque(90)

# q.deque()
# q.deque()
# q.deque()
# q.deque()
# q.deque()

print(q.deque())
print(q.deque())
print(q.size())

