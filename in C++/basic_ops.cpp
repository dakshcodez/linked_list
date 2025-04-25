#include<iostream>
using namespace std;

class LinkedList{
    private:
        struct Node{
            int val;
            Node* next;

            Node(int value): val(value) , next(nullptr) {}
        };
        Node* head;

    public:
        LinkedList(): head(nullptr) {}

        void add(int val){
            Node* newNode = new Node(val);
            if (head == nullptr){
                head = newNode;
                return;
            }

            Node* temp = head;
            while (temp->next){
                temp = temp->next;
            }
            temp->next = newNode;
        }

        void display(){
            Node* temp = head;
            while (temp){
                cout<<temp->val<<" -> ";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }

        void deleteNode(int val) {
            if (head == nullptr) return;
        
            Node* current = head;
            Node* prev = nullptr;
        
            // Traverse until the node with the value is found
            while (current && current->val != val) {
                prev = current;
                current = current->next;
            }
        
            // Value not found
            if (current == nullptr) {
                cout << "Node with value " << val << " not found." << endl;
                return;
            }
        
            // Node to delete is the head
            if (current == head) {
                head = head->next;
                delete current;
                return;
            }
        
            // Node is in the middle or end
            prev->next = current->next;
            delete current;
        }        

        ~LinkedList(){
            Node* current = head;
            while (current){
                Node* nextNode = current->next;
                delete current;
                current = nextNode;
            }
        }
};

int main(){
    LinkedList l1;
    l1.add(1);
    l1.add(2);
    l1.add(3);
    l1.add(4);
    l1.add(5);
    l1.display();
    l1.deleteNode(6);
    l1.add(6);
    l1.display();
    return 0;
}