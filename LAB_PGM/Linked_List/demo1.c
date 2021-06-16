//implementation of singly linear linked list operations:
#include<stdio.h>
#include<stdlib.h>
#pragma pack(1)
typedef struct node
{
	int data;//4 bytes
	struct node *next;//self referential pointer – 4 bytes
}node_t;

typedef struct list
{
    node_t *head;
}list_t;

void add_node_at_last_position( list_t *list,int data);
void add_node_at_first_position(list_t *list,int data);
node_t *create_node(int data);
void display_list(list_t *list);

void init_list(list_t *list);



int main(void)
{
/*    printf("sizeof(struct node): %d bytes\n", sizeof(struct node));
    printf("sizeof(node_t): %d bytes\n", sizeof(node_t));

    
    add_node_at_last_position(10);

    display_list();
    add_node_at_last_position(20);

    display_list();
    add_node_at_last_position(30);

    display_list();
    add_node_at_last_position(40);

    display_list();
    add_node_at_last_position(50);

    display_list();
    add_node_at_last_position(60);

    display_list();
    add_node_at_last_position(70);

    display_list();
*/
    list_t l1, l2;
    init_list(&l1);
    display_list(&l1);

    add_node_at_first_position(&l1,5);
    display_list(&l1);

    add_node_at_first_position(&l1,11);
    display_list(&l1);

    add_node_at_first_position(&l1,22);
    display_list(&l1);

    add_node_at_first_position(&l1,33);
        display_list(&l1);

    add_node_at_first_position(&l1,44);
        display_list(&l1);

    add_node_at_first_position(&l1,55);
    display_list(&l1);

    //head -> 55 -> 44-> 33-> 22 -> 11 -> null
    printf("\n=========================\n");
    init_list(&l2);

    display_list(&l2);
    add_node_at_last_position(&l2, 11);
    display_list(&l2);


    display_list(&l2);
    add_node_at_last_position(&l2, 22);
    display_list(&l2);

    display_list(&l2);
    add_node_at_last_position(&l2, 33);
    display_list(&l2);


    return 0;
}

void display_list(list_t *list)
{
    //if list is not empty
    if( list->head != NULL ){
        //start traversal from first node
        node_t *trav = list->head;
        printf("list is: head -> ");
        //traverse the list till last node including it
        while( trav != NULL )
        {
            printf("%d -> ", trav->data);//visit data part of each node
            trav = trav->next;
        }
        printf("null\n");
    }
    else
        printf("list is empty !!!\n");
}


node_t *create_node(int data)
{
    //1. allocate memory dynamically for node
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    /* malloc() functions allocates requested bytes of memory from heap section and on success
    it returns starting addr of dynamically allocated block and on failure it returns
    NULL */
    if( temp == NULL )
    {
        printf("malloc() failed !!! insufficient heap memory !!!\n");
        exit(1);
    }

    //2. initialize members of the node
    temp->data = data;
    temp->next = NULL;
    //3. return starting of dynamically allocated node to the calling function
    return temp;
}

void add_node_at_last_position(list_t *list,int data)
{
    //step-1: create a newnode
    node_t *newnode = create_node(data);

    //step-2: if list is empty --> attach newly created node to the head
    if( list->head == NULL )
    {
        //store an addr of newly created node into the head
        list->head = newnode;    
    }
    else//step-3: if list is not empty
    {
        //start traversal from first node
        node_t *trav = list->head;
        //traverse list till last node
        while( trav->next != NULL ){
            trav = trav->next;//move trav pointer towards its next node
        }

        //attach newly created node to the last node
        //i.e. store an addr of newly created node into the next part last node
        trav->next = newnode;

    }
}

void add_node_at_first_position(list_t *list, int data)
{
    //step-1: create a newnode
    node_t *newnode = create_node(data);

    //step-2: if list is empty --> attach newly created node to the head
    if( list->head == NULL )
    {
        //store an addr of newly created node into the head
        list->head = newnode;    
    }
    else//step-3: if list is not empty
    {
        //store an addr of cur first node into the next part of newly created node
        newnode->next = list->head;
        //attach newly created node to the head
        list->head = newnode;
    }
}





void init_list(list_t *list)
{
    list->head=NULL;
    return;
}