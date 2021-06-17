//implementation of basic operations of dlll
#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int data;//4 bytes
    struct node *next;//self referential pointer - 4 bytes
    struct node *prev;//self referential pointer - 4 bytes
}node_t;

//create an empty linked list
node_t *head = NULL;

//declarations of linked list functionalities
void add_node_at_last_position(int data);
void display_list(void);


int main(void)
{
    add_node_at_last_position(10);
    add_node_at_last_position(20);
    add_node_at_last_position(30);
    add_node_at_last_position(40);
    add_node_at_last_position(50);
    add_node_at_last_position(60);
    add_node_at_last_position(70);

    display_list();

    return 0;
}

//definitions of linked list functionalities

node_t *create_node(int data)
{
    //1. allocate memory dynamically for a node
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    /* malloc() function allocates requested bytes of memory from heap section and on sucess
    it returns starting addr of dynamically allocated block, and on failure it returns NULL */
    if( temp == NULL )
    {
        printf("malloc() failed\n");
        exit(1);//exit program - program gets exited due an error
    }

    //2. initialize members of the node
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    //3. return starting addr of dynamically allocated node to the calling function
    return temp;
}

void display_list(void)
{
    //if list is not empty   
    if( head != NULL )
    {
        //start traversal from first node
        node_t *trav = head, *temp = NULL;
        printf("list in forward dir : ");
        //traverse the list till last node including it
        while( trav != NULL )
        {
            temp = trav;
            printf("%4d", trav->data);//visit data part of each node
            trav = trav->next;//move trav towards it next node
        }
        printf("\n");

        trav = temp;
        printf("list in backward dir: ");
        //traverse the list till last node including it
        while( trav != NULL )
        {
            printf("%4d", trav->data);//visit data part of each node
            trav = trav->prev;//move trav towards it next node
        }
        printf("\n");

    }
    else
        printf("list is empty !!!\n");
}

void add_node_at_last_position(int data)
{
    //step-1: create a newnode - dynamically i.e. runtime
    node_t *newnode = create_node(data);

    //step-2: if list is empty then attach newly created node to the head
    if( head == NULL )
    {
        //store an addr of newly created node into the head
        head = newnode;
    }
    else//step-3: if list is not empty
    {
        //start traversal of the from first node
        node_t *trav = head;

        //traverse the list till last node
        while( trav->next != NULL )
            trav = trav->next;//move trav pointer towards its next node

        //attach newly created node to the last node i.e. store an addr of newly created node
        //into the next part of last node
        trav->next = newnode;
        newnode->prev = trav;
    }
}

