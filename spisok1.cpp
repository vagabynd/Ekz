
#include <stdio.h>
#include <stdlib.h>
int global;
typedef struct node
{
    int data;
    struct node *next;
} ITEM;

ITEM* add_node(ITEM* head, int new_data)
{
    ITEM *new_item, *prev;
    new_item=(ITEM *)malloc(sizeof(ITEM)); 
    if(new_item==NULL)
    {
        puts("Ошибка");
        return head; 
    }
    new_item->data=new_data;
    if(head==NULL) 
    {
        puts("Список создан");
        new_item->next=NULL;
        return new_item; 
    } else {
        printf("Элемент %d вставлен в начало списка\n", new_data);
        new_item->next = head;
        return new_item; 

    }
}


ITEM* delete_node(ITEM* head, int delete_data)
{
    ITEM *cur, *prev;
    prev=NULL;
    cur=head;
    while(cur!=NULL)
    {
        if(cur->data==delete_data)
        {
            printf("Удаление элемента %d\n ",cur->data);
            if(prev==NULL)
            {
                
                head=head->next;
            }
            else
            {
                
                prev->next=cur->next;
            }
            free(cur);
            return head;
        }
        prev=cur;
        cur=cur->next;
    }
    printf("Элемент %d отсуствует в списке\n ",delete_data);
    return head;

}
ITEM* find_node(ITEM* head, int find_data)
{
    ITEM *cur;
    cur=head;
    while(cur!=NULL)
    {
        if(cur->data==find_data)
        {
            printf("Элемент %d найден\n",find_data);
            return cur;
        }
        
        cur=cur->next;
    }
    printf("Элемент %d НЕ найден \n",find_data);
    return NULL;
}
ITEM* Show_node(ITEM* head)
{
    ITEM *cur;
    cur = head;
    while (cur != NULL){
        printf("\n %d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
    puts("Для продолжения введите любое число");
    scanf("%d",&global);
    return NULL;
}
void Sum(ITEM* head) {

    ITEM *cur;
    cur = head;
    int sum = 0;
    while (cur != NULL) {
        sum++;
        cur = cur->next;
    }
    printf("кол-во элементов = %d\n", sum);
}
int list_main()
{
    ITEM *Head = NULL; 
    char key,str[50] = {0}; 
    int n1,n2,search,id; 
    while(1)
    {
        puts("1 - добавить");
        puts("2 - удалить");
        puts("3 - найти");
        puts("4 - вывести список");
        puts("5 - кол-во элементов");
        puts("6 - выйти");
        scanf("%c",&key);

        switch(key)
        {
            case '1':
                puts("Введите число");
                scanf("%d",&id);
                Head=add_node(Head,id);
                break;
            case '2':
                puts("Введите какой элемент удалить");
                scanf("%d",&n1);
                Head=delete_node(Head,n1);
                break;
            case '3':
                puts("Введите число");
                scanf("%d",&search);
                find_node(Head,search);
                break;
            case '4':
                Show_node(Head);
                break;
            case '5':
                Sum(Head);
                break;
            case '6':
                puts("Выход");
                return 0;
        }
    }
}
