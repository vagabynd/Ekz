#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode{
    struct treeNode *left;
    struct treeNode *right;
    int data;
    float f;
}TREENODE;

TREENODE* searchNode(TREENODE* tree, int value)
{
    TREENODE* q = tree;
    while (q != NULL)
    {
        if (q -> data == value)
            break;
        else
        {
            if (value < q->data)
                q = q->left;
            else
                q = q->right;
        }
    }
    if (q == NULL)
    {
        puts("Not founded!");
        return NULL;
    }
    puts("Founded!");
    return q;
}

TREENODE* insertNode(TREENODE* tree, int value, float f)
{
    TREENODE* newNode = (TREENODE*)malloc(sizeof(TREENODE));
    TREENODE* root = tree;
    if (newNode != NULL)
    {
        newNode->data = value;
        newNode->f = f;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    else
    {
        puts("Error!");
    }
    if (root == NULL)
        return newNode;
    while (root != NULL)
    {
        if (value < root->data)
        {
            if (root->left != NULL)
                root = root->left;
            else
            {
                root->left = newNode;
                break;
            }
        }
        else if (value > root->data)
        {
            if (root->right != NULL)
                root = root->right;
            else
            {
                root->right = newNode;
                break;
            }
        }
        else
        {
            puts("Clone");
            break;
        }
    }
    return tree;
}

TREENODE* deleteNode(TREENODE* tree, int value)
{
    TREENODE* q = tree;
    TREENODE* parent = NULL;
    TREENODE *s1, *s2, *s;
    TREENODE *max_node;
    int tmp;

    while(q != NULL)
    {
        if (q->data == value)
            break;
        else
        {
            parent = q;
            if (value < q->data)
                q = q->left;
            else
                q = q->right;
        }
    }
    if (q == NULL)
    {
        puts("Not founded!");
        return tree;
    }
    s1 = q->left;
    s2 = q->right;
    if (s1 == NULL && s2 == NULL)
    {
        if (parent != NULL)
        {
            if (parent->left == q)
                parent->left = NULL;
            else parent->right = NULL;
        }
        else
        {
            free(q);
            return NULL;
        }
    }
    else if (s1 == NULL || s2 == NULL)
    {
        s = (s1==NULL) ? s2 : s1;
        if (parent != NULL)
        {
            if (parent->left == q)
                parent->left = s;
            else parent->right = s;
        }
        else
        {
            free(q);
            return s;
        }
    }
    else
    {
        max_node = q->left;
        while (max_node->right != NULL)
        {
            max_node = max_node->right;
        }
        tmp = max_node->data;
        tree = deleteNode(tree,tmp);
        q->data = tmp;
        return tree;
    }
    free(q);
    return tree;
}
//симметричный
void inOrder(TREENODE* tree)
{
    if (tree != NULL)
    {
        inOrder(tree->left);
        printf("%3d ",tree->data);
        printf("%3f ",tree->f);
        inOrder(tree->right);
    }
}
//прямой
void preOrder(TREENODE* tree)
{
    if (tree!=NULL)
    {
        printf("%3d ",tree->data);
        printf("%3f ",tree->f);
        preOrder(tree->left);
        preOrder(tree->right);
    }
}
//обратный
void postOrder(TREENODE* tree)
{
    if (tree!=NULL)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        printf("%3d ",tree->data);
        printf("%3f ",tree->f);
    }
}
int count(TREENODE* tree)
{
    if (tree == NULL)
        return 0;
    a = count(tree->right) + count(tree->left) + 1;
    return a;
}

int treeBin(){
    TREENODE* tree;
    int y = 0;
    int number;
    float f;
    char key;

    while(1){
        puts("1 - Добавить элемент");
        puts("2 - Удалить элемент");
        puts("3 - Найти элемент");
        puts("4 - Симметричный вывод дерева");
        puts("5 - Прямой вывод дерева");
        puts("6 - Обратный вывод дерева");
        puts("7 - Дополнительная функция");
        puts("8 - Выход");
        scanf("%c",&key);
        switch(key){
            case '1':
                puts("Введите число");
                scanf("%d",&number);
                puts("Введите число с точкой");
                scanf("%f",&f);
                tree = insertNode(tree,number,f);
                break;
            case '2':
                puts("Введите число");
                scanf("%d",&number);
                tree = deleteNode(tree,number);
                break;
            case '3':
                puts("Введите число");
                scanf("%d",&number);
                searchNode(tree,number);
                break;
            case '4':
                inOrder(tree);
                printf("\n");
                break;
            case '5':
                preOrder(tree);
                printf("\n");
                break;
            case '6':
                postOrder(tree);
                printf("\n");
                break;
            case '7':
                y = count(tree);
                printf("\n%d\n",y);
                break;
            case '8':
                puts("Выход");
                return 0;
        }
    }
}
