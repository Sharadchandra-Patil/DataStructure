//implementation of basic operations of slll
#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int data;//4 bytes
    struct node *next;//self referential pointer - 4 bytes
}node_t;

//create an empty linked list
node_t *head = NULL;

//declarations of linked list functionalities
void add_node_at_last_position(int data);
void add_node_at_first_position(int data);
void add_node_at_specific_position(int pos, int data);
void display_list(void);
int count_nodes(void);

int menu(void)
{
    int choice;

    printf("********************************************************\n");
    printf("singly linear linked list\n");
    printf("0. exit\n");
    printf("1. add node at last position\n");
    printf("2. add node at first position\n");
    printf("3. add node at specific position\n");
    printf("4. delete node at first position\n");
    printf("5. delete node at last position\n");
    printf("6. delete node at specific position\n");
    printf("7. display list\n");

    printf("enter the choice: ");
    scanf("%d", &choice);

    return choice;
}

enum menu_options{ EXIT, ADDLAST, ADDFIRST, ADDATPOS, DELFIRST, DELLAST, DELATPOS, DISP };

int main(void)
{
    int pos;
    int data;
    //printf("sizeof(struct node): %d bytes\n", sizeof(struct node));
    //printf("sizeof(node_t): %d bytes\n", sizeof(node_t));

    while(1)
    {
        int choice = menu();
        switch( choice )
        {
            case EXIT:
                exit(0);

            case ADDLAST:
                printf("enter data: ");
                scanf("%d", &data);
                add_node_at_last_position(data);
                break;

            case ADDFIRST:
                printf("enter data: ");
                scanf("%d", &data);
                add_node_at_first_position(data);
                break;

            case ADDATPOS:
                while( 1 )
                {
                    //accept position from the user
                    printf("enter the pos: ");
                    scanf("%d", &pos);

                    //validate position
                    //pos is valid --> if( pos > 0 && pos <= cnt + 1 )
                    if( pos > 0 && pos <= count_nodes() + 1 )
                        break;
                    
                    printf("invalid position !!!\n");

                }
                printf("enter data: ");
                scanf("%d", &data);
                add_node_at_specific_position(pos, data);
                break;

            case DELFIRST:
                break;

            case DELLAST:
                break;

            case DELATPOS:
                break;

            case DISP:
                display_list();
                break; 

        }//end of swicth control block
    }//end of while loop

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
    //3. return starting addr of dynamically allocated node to the calling function
    return temp;
}

void display_list(void)
{
    //if list is not empty   
    if( head != NULL )
    {
        //start traversal from first node
        node_t *trav = head;
        printf("no. of nodes in a linked are: %d\n", count_nodes());
        printf("list is: head -> ");
        //traverse the list till last node including it
        while( trav != NULL )
        {
            printf("%d -> ", trav->data);//visit data part of each node
            trav = trav->next;//move trav towards it next node
        }
        printf(" null\n");
    }
    else
        printf("list is empty !!!\n");
}

int count_nodes(void)
{
    int cnt = 0;

    //if list is not empty
    if( head != NULL )
    {
        //start traversal from first node
        node_t *trav = head;
        //traverse the list till last node
        while( trav != NULL )
        {
            cnt++;
            trav = trav->next;
        }
    }

    return cnt;
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
    }
}

void add_node_at_first_position(int data)
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
        //store an addr of cur first node into next part of newly created node
        newnode->next = head;
        //attach newly craeted node to the head
        head = newnode;
    }
}

void add_node_at_specific_position(int pos, int data)
{
    if( pos == 1 )//if pos is the first position
        add_node_at_first_position(data);
    else if( pos == count_nodes() + 1 )//if pos is the first position
        add_node_at_last_position(data);
    else//if pos is in between position
    {
        //create a newnode
        node_t *newnode = create_node(data);
        int i = 1;
        //start traversal from first node
        node_t *trav = head;
        //traverse the list till (pos-1)th node
        while( i < pos-1 ){
            i++;
            trav = trav->next;
        }

        //store an addr of cur (pos)th node into next part of newly crreated node
        newnode->next = trav->next;
        //store an addr of newly created node into next part of (pos-1)th node
        trav->next = newnode;
    }
}








