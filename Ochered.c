#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}PNode;

PNode *head = NULL;
PNode *tail = NULL;

PNode *Push(int newData){
    PNode *q;
    q = (PNode*)malloc(sizeof(PNode));
    q -> data = newData;

    if (head == NULL){
        q->next = NULL;
        head = q;
        tail = q;
        return head;
    } else {
        tail -> next = q;
        tail = tail ->next;
        q -> next = NULL;
        return head;
    }
}

PNode *Pop(PNode *head){
    int a = head -> data;
    PNode *q = head;
    head = head->next;
    free(q);
    return head;
}


void View(PNode *head){
    PNode *q = head;
    while (q != NULL){
        printf("%d ",q->data);
        q= q-> next;
    }
}


int main() {
    char key;
    int c,a;
    while(1) {
        scanf("%c",&key);
        switch (key) {

            case '1':
                scanf("%d", &c);
                head = Push(c);
                break;
            case '2':
                head = Pop(head);
                break;
            case '3':
                return 0;
            case '4':
                View(head);
                break;
        }
    }
    return 0;
}