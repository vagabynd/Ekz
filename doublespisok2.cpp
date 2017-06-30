#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    float f;
    struct node *next, *prev;
}ITEM;

typedef struct head{
    struct node *first,*last;
    int num;
}HEAD;

HEAD* add_node(HEAD* head, int new_data, float f)
{
    ITEM *new_item, *prev;
    new_item=(ITEM *)malloc(sizeof(ITEM));
    if(new_item==NULL)
    {
        printf("Error \n");
        return head;
    }
    new_item->data=new_data;
    new_item->f = f;

    if(head==NULL)
    {
        head=(HEAD *)malloc(sizeof(HEAD));
        puts("List created!");
        new_item->next=NULL;
        new_item->prev=NULL;
        head->first=head->last=new_item;
        return head;
    }
    if(head->first->data>new_data)
    {
        printf("Element %d insert in begin \n",new_data);
        new_item->next=head->first;
        head->first->prev=new_item;
        head->first=new_item;
        new_item->prev=NULL;
        head->num++;
        return head;
    }
    prev=head->first;
    while(prev->next!=NULL)
    {
        if(prev->next->data>new_data)
        {
            printf("Element %d inserted in middle \n",new_data);
            new_item->next=prev->next;
            prev->next=new_item;
            new_item->prev=prev;
            new_item->next->prev=new_item;
            head->num++;
            return head;
        }
        else
        {
            prev=prev->next;
        }
    }
    printf("Element %d inserted in the end \n",new_data);
    head->last->next=new_item;
    new_item->prev=head->last;
    head->last=new_item;
    new_item->next=NULL;
    return head;
}

void print_begin(HEAD* head)
{
    ITEM *cur;
    if(head==NULL || head->first==NULL)
    {
        puts("List empty!");
        return;
    }
    cur=head->first;
    puts("Print begin:");
    while(cur!=NULL)
    {
        printf("%d ",cur->data);
        printf("%f",cur->f);
        printf("\n");
        cur=cur->next;
    }
    puts("");
}

void print_end(HEAD* head)
{
    ITEM *cur;
    if(head==NULL || head->last==NULL)
    {
        puts("List empty!");
        return;
    }
    cur=head->last;
    puts("Print end:");
    while(cur!=NULL)
    {
        printf("%d ",cur->data);
        printf("%f",cur->f);

        printf("\n");
        cur=cur->prev;
    }
    puts("");
}

HEAD* delete_node(HEAD* HEAD, ITEM* head, int delete_data)
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
                HEAD ->first = cur;
                HEAD ->first ->prev = NULL;
            }
            else
            {
                del = cur;
                cur = cur->next;
                cur->prev = prev;
                free(del);
                prev->next = cur;

            }
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    return HEAD;
}
int find(HEAD* head, int find_item){
    ITEM *cur;
    cur = head->first;
    while (cur!=NULL && cur->data <= find_item){
        if (cur->data = find_item){
            printf("Item found: %d ",cur->data);
            printf("%f \n",cur->f);
            return 1;
        }
        cur=cur->next;
    }
    printf("Item not found");
}

void add(ITEM* head)
{
    float x=0,y=0;
    float z = 0;
    ITEM *cur;
    cur = head;
    while (cur != NULL) {
        x = x + cur->data;
        y++;
        cur = cur->next;
    }
    z = x/y;
    printf("%f\n",z);
}

int list_main()
{
    HEAD *Head=NULL;
    char key;
    float f;
    int chislo;
    while(1)
    {
        puts("1 - Insert element");
        puts("2 - Delete function");
        puts("3 - Print function");
        puts("4 - Find function");
        puts("5 - Additional function");
        puts("6 - Exit");
        scanf("%c",&key);
        switch(key)
        {
            case '1':
                puts("Enter number");
                scanf("%d",&chislo);
                puts("Enter float number");
                scanf("%f",&f);
                Head=add_node(Head,chislo,f);
                break;
            case '2':
                puts("Enter number");
                scanf("%d",&chislo);
                Head=delete_node(Head,Head->first,chislo);
                break;
            case '3':
                print_begin(Head);
                print_end(Head);
                break;
            case '4':
                puts("Enter find number");
                scanf("%d",&chislo);
                find(Head,chislo);
                break;
            case '5':
                add(Head->first);
                break;
            case '6':
                puts("Exit");
                return 0;
        }

    }
}
