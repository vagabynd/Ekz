#include <stdio.h>
#include <stdlib.h>

int global;

typedef struct node
{
    int data;
    float f;
    struct node *next;
}ITEM;





ITEM* find_node(ITEM* head, int find_data)
{
    ITEM *cur;
    cur=head;
    while(cur!=NULL && cur->data >= find_data)
    {
        if(cur->data==find_data)
        {
            printf("Элемент %d найден и он содержит число: ",find_data);
            printf("%f",cur->f);
            printf("\n");
            puts("Для продолжения введите любое число");
            scanf("%d",&global);
            return cur;
        }
        cur=cur->next;
    }
    printf("Элемент %d НЕ найден \n",find_data);
    puts("Для продолжения введите любое число");
    scanf("%d",&global);
    return NULL;
}

ITEM* Show_node(ITEM* head)
{
    ITEM *cur;
    cur = head;
    while (cur != NULL){
        printf("\nid: %d число: ", cur->data);
        printf("%f",cur->f);
        cur = cur->next;
    }
    printf("\n");
    puts("Для продолжения введите любое число");
    scanf("%d",&global);
    return NULL;
}


void add(ITEM* head)
{
    float x=0,y=0 ;
    float z = 0;
    ITEM *cur;
    cur = head;
    while (cur != NULL){
        x = x + cur->data;
        y++;
        cur = cur->next;
    }
    z = x/y;
    printf("%f\n",z);
}


int list_main()
{
    ITEM *Head = NULL;
    char key;
    float f;
    int n1,search,id;
    while(1)
    {

        puts("1 - добавить элемент");
        puts("2 - удалить элемент");
        puts("3 - найти элемент");
        puts("4 - вывести список");
        puts("5 - среднее арифметическое");
        puts("6 - выйти");
        scanf("%c",&key);
        switch(key)
        {
            case '1':
                puts("Введите число");
                scanf("%d",&id);
                puts("Введите число вещественного типа");
                scanf("%f",&f);
                Head = add_node(Head,id,f);
                
                
                ITEM* add_node(ITEM* head, int new_data, float f)
            {
                ITEM *new_item = NULL, *prev;
                new_item=(ITEM *)malloc(sizeof(ITEM));
                if(new_item==NULL)
                {
                    puts("Ошибка выделения памяти");
                    return head;
                }
                
                
                {
                    int data = new_data;
                    float f = f;
                    struct node *next = NULL;
                }new_item;
                
                new_item->data=new_data;
                new_item->f = f;
                
                if(head==NULL)
                {
                    puts("Список создан");
                    new_item->next=NULL;
                    puts("Для продолжения введите любое число");
                    scanf("%d",&global);
                    return new_item;
                }
                
                if(head->data <= new_data)
                {
                    printf("Элемент %d вставлен в начало списка\n",new_data);
                    new_item->next = head;
                    puts("Для продолжения введите любое число");
                    scanf("%d",&global);
                    return new_item;
                }
                
                prev=head;
                
                while(prev->next!=NULL)
                {
                    if(prev->next->data <= new_data)
                    {
                        /*вставка*/
                        printf("Элемент %d вставлен в середину списка\n",new_data);
                        new_item->next = prev->next;
                        prev->next = new_item;
                        puts("Для продолжения введите любое число");
                        scanf("%d",&global);
                        return head;
                    }
                    else
                    {
                        prev=prev->next;
                    }
                }
                printf("Элемент %d вставлен в конец списка\n ",new_data);
                prev->next = new_item;
                new_item->next = NULL;
                puts("Для продолжения введите любое число");
                scanf("%d",&global);
                return head;
            }

                break;
            case '2':
                puts("Введите элемент для удаления");
                scanf("%d",&n1);
                Head=delete_node(Head,n1);
                
                ITEM* delete_node(ITEM* head, int delete_data)
            {
                ITEM *cur, *prev, *del;
                prev=NULL;
                cur=head;
                while(cur!=NULL)
                {
                    if(cur->data == delete_data)
                    {
                        printf("Удаление элемента %d\n ",cur->data);
                        if(prev==NULL)
                        {
                            head = head -> next;
                            free(cur);
                            prev = NULL;
                            cur = head;
                        }
                        else
                        {
                            del = cur;
                            cur = cur->next;
                            free(del);
                            prev->next = cur;
                        }
                    } else {
                        prev = cur;
                        cur = cur->next;
                    }
                }
                return head;
                
            }
                
                
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
                add(Head);
                break;
            case '6':
                puts("Выход");
                return 0;
        }
    }
}

