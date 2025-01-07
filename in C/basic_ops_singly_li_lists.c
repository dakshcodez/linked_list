#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int val;
    struct ListNode* next;
};

struct ListNode* createNewNode(int val){
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode -> val = val;
    newNode -> next = NULL;
}

void insertAtEnd(struct ListNode** head, int val){
    if (*head == NULL){
        *head = createNewNode(val);
        return;
    }
    struct ListNode* newNode = createNewNode(val);
    struct ListNode* temp = *head;
    while (temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
}

void display(struct ListNode* head){
    while (head != NULL){
        printf("%d -> ", head -> val);
        head = head -> next;
    }
    printf("NULL");
}

int main(){
    struct ListNode* head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    display(head);
    return 0;
}