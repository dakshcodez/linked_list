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

void insertAtBeg(struct ListNode **head, int val){
    struct ListNode* newNode = createNewNode(val);
    newNode -> next = *head;
    *head = newNode;
}

void insertAtPos(struct ListNode** head, int pos, int val){
    if (pos == 0){
        insertAtBeg(head,val);
        return;
    }
    int i = 0;
    struct ListNode* newNode = createNewNode(val);
    struct ListNode* temp = *head;
    while (i < pos - 1 && temp != NULL){
        temp = temp -> next;
        i++;
    }
    if (temp == NULL){
        printf("Index out of range.\n");
        return;
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

int countElements(struct ListNode* head){
    int count = 0;
    while (head != NULL){
        count++;
        head = head -> next;
    }
    return count;
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
    insertAtBeg(&head,0);
    insertAtPos(&head,5,50);

    int count = countElements(head);
    printf("%d\n", count);
    display(head);
    return 0;
}