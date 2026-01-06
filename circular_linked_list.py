# Day 14: Circular Linked List Implementation in Python

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class CircularLinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            new_node.next = new_node
            return
        current = self.head
        while current.next != self.head:
            current = current.next
        current.next = new_node
        new_node.next = self.head

    def display(self):
        nodes = []
        if not self.head:
            print("List is empty")
            return
        current = self.head
        while True:
            nodes.append(str(current.data))
            current = current.next
            if current == self.head:
                break
        print(" -> ".join(nodes) + " -> (Back to head)")

# Test the CircularLinkedList
cll = CircularLinkedList()
cll.append(1)
cll.append(2)
cll.append(3)

print("Circular Linked List:")
cll.display()
