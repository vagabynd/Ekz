#include <stdio.h>
#include <stdlib.h>
typedef struct stack{
    int num;
    struct stack *next;
}Stack;
Stack *Head = NULL;
void Push(int num)
{
    Stack *p;
    p = (Stack*)malloc(sizeof(Stack));
    if(p != NULL) {
        p -> num = num;
        p -> next = Head;
        Head = p;
    }
}
void Pop()
{
    int a;
    a = Head -> num;
    Stack* p = Head;
    Head = Head->next;
    free(p);
    printf("%d ",a);
}
int main() {
    int x, y=0;
    char key;
    while (1){
        puts("1 - добавить");
        puts("2 - вывести стек и очистить его");
        puts("3 - выход");
        scanf("%c",&key);
        switch(key) {
            case '1':
                puts("Введите число");
                scanf("%d",&x);
                Push(x);
                y++;
                break;
            case '2':
                puts("Стек:");
                for(int i = 0; i < y; i++) {
                    Pop();
                }
                printf("\n");
                y=0;
                break;
            case '3':
                return 0;
        }
    }
}