class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
    
    def append(self, data):
        new_node = Node(data)

        if not self.head:
            self.head = new_node
            return
        
        last = self.head

        while last.next:
            last = last.next

        last.next = new_node

    def display(self):
        temp = self.head
        while temp:
            print(temp.data,end=" -> ")
            temp = temp.next
        print("None")

l1 = LinkedList()
l1.append(1)
l1.append(2)
l1.append(3)
l1.append(4)
l1.append(5)
l1.display()

