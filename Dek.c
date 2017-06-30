#include <stdio.h>
#include <stdlib.h>

typedef struct dec{
    int data;
    struct dec *next;
    struct dec *prev;
}DEC;

DEC *head = NULL, *tail = NULL;

void PushF(int newdata){
    DEC *q;
    q = (DEC*)malloc(sizeof(DEC));
    q->data = newdata;
    if (head == NULL){
    q->next = head;
    head = q;
    tail = q;
    } else{
        q->next = head;
        head = q;

    }
}

int PopF(){
    int a = head -> data;
    DEC *q = head;
    head = head -> next;
    free(q);
    return a;
}

void PushL(int newdata){
    DEC *q;
    q = (DEC*)malloc(sizeof(DEC));
    q -> data = newdata;

    if (head == NULL){
        q->next = NULL;
        head = q;
        tail = q;
    } else {
        tail -> prev = tail;
        tail -> next = q;
        tail = tail ->next;
        q -> next = NULL;
    }
}

int PopL(){
    int a = tail -> data;
    DEC *q = tail;
    tail = tail ->  prev;
    free(q);
    return a;
}


void View(DEC *head){
    DEC *q = head;
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
                PushF(c);
                break;
            case '2':
                a = PopF();
                break;
            case '3':
                scanf("%d", &c);
                PushL(c);
                break;
            case '4':
                View(head);
                break;
            case '5':
                a = PopL();
                printf("%d",a);
                break;
            case '6':
                return 0;
        }
    }
}