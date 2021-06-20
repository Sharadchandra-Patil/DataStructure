
//implementation of singly linear linked list operations:
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;//4 bytes
	struct node *next;//self referential pointer – 4 bytes
}node_t;

void add_node_at_last_position(int data);
void add_node_at_first_position(int data);
node_t *create_node(int data);
void display_list(void);
void Reverse_display_list(node_t *trav);
void free_list(void);
void delete_node_at_first_position(void);

//create an empty linked list
node_t *head = NULL;


int main(void)
{
    //printf("sizeof(struct node): %d bytes\n", sizeof(struct node));
    //printf("sizeof(node_t): %d bytes\n", sizeof(node_t));

    /*
    add_node_at_last_position(10);
    add_node_at_last_position(20);
    add_node_at_last_position(30);
    add_node_at_last_position(40);
    add_node_at_last_position(50);
    add_node_at_last_position(60);
    add_node_at_last_position(70);

    display_list();

    add_node_at_first_position(5);
    */
    add_node_at_first_position(11);
    add_node_at_first_position(22);
    add_node_at_first_position(33);
    add_node_at_first_position(44);
    add_node_at_first_position(55);

    //head -> 55 -> 44-> 33-> 22 -> 11 -> null

    display_list();

    node_t *trav = head;
    //printf("no. of nodes in a linked are: %d\n", count_nodes());
    printf("rev list is: null -> ");
    Reverse_display_list(trav);
    printf(" Head\n");    
    free_list();
    return 0;
}

void display_list(void)
{
    //if list is not empty
    if( head != NULL ){
        //start traversal from first node
        node_t *trav = head;
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

void add_node_at_last_position(int data)
{
    //step-1: create a newnode
    node_t *newnode = create_node(data);

    //step-2: if list is empty --> attach newly created node to the head
    if( head == NULL )
    {
        //store an addr of newly created node into the head
        head = newnode;    
    }
    else//step-3: if list is not empty
    {
        //start traversal from first node
        node_t *trav = head;
        //traverse list till last node
        while( trav->next != NULL ){
            trav = trav->next;//move trav pointer towards its next node
        }

        //attach newly created node to the last node
        //i.e. store an addr of newly created node into the next part last node
        trav->next = newnode;

    }
}

void add_node_at_first_position(int data)
{
    //step-1: create a newnode
    node_t *newnode = create_node(data);

    //step-2: if list is empty --> attach newly created node to the head
    if( head == NULL )
    {
        //store an addr of newly created node into the head
        head = newnode;    
    }
    else//step-3: if list is not empty
    {
        //store an addr of cur first node into the next part of newly created node
        newnode->next = head;
        //attach newly created node to the head
        head = newnode;
    }
}






void Reverse_display_list(node_t *trav)
{
    
        if(trav == NULL )
            return;
        else
        {
            Reverse_display_list(trav->next); 
            printf("%d -> ", trav->data);
        }
    
        return;   
}

void delete_node_at_first_position(void)
{
    //step-1: check list is not empty, if list is not empty
    if( head != NULL )
    {
        //step-2: if list contains only one node
        if( head->next == NULL ){
            //delete the node and make head as NULL
            free(head);
            head = NULL;
        }
        else//step-3: if list contains more than one nodes
        {
            //store an addr of first node into the temp which is to be deleted
            node_t *temp = head;
            //attach cur second node to the head
            head = head->next;
            free(temp);
        }
    }
    else
        printf("list is empty !!!\n");
}
    void free_list(void)
{
    while( head != NULL )//while list not becomes empty
        delete_node_at_first_position();

        //delete_node_at_first_position();//delete all nodes one by one

    printf("list frees successfully ....\n");
}