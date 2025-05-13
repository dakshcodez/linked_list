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

    def deleteNode(self, value):
        if self.head and self.head.data == value:
            self.head = self.head.next
            print(f"Node {value} delted")
            return
        temp = self.head
        while temp.next:
            if temp.next.data == value:
                temp.next = temp.next.next  
                print(f"Node {value} delted")
                return
            temp = temp.next
        print("Node not found")

l1 = LinkedList()
l1.append(1)
l1.append(2)
l1.append(3)
l1.append(4)
l1.append(5)
l1.display()
l1.deleteNode(1)
l1.deleteNode(3)
l1.deleteNode(5)
l1.display()
