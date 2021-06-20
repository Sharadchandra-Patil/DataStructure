//implementation of singly linear linked list operations:
#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)
typedef struct emp
{
    int empno;
    char name[10];
    float sal;
} emp_t;
typedef struct node
{
    emp_t data;        //18 bytes
    struct node *next; //self referential pointer – 4 bytes
} node_t;
void accept_info(emp_t *e);
void display_info(const emp_t *e);
void add_node_at_last_position(emp_t data);
void add_node_at_first_position(emp_t data);
void add_node_at_specific_position(int pos, emp_t data);
emp_t delete_node_at_first_position(void);
void delete_node_at_last_position(void);
void delete_node_at_specific_position(int pos);
node_t *create_node(emp_t data);
void display_list(void);
int count_nodes(void);
void free_list(void);

//create an empty linked list
node_t *head = NULL;

int menu(void)
{
    int choice;

    printf("***** singly linear linked list operations *****\n");
    printf("0. exit\n");
    printf("1. add node into the list at last position\n");
    printf("2. add node into the list at first position\n");
    printf("3. add node into the list at specific position\n");
    printf("4. delete node from the list which is at first position\n");
    printf("5. delete node from the list which is at last position\n");
    printf("6. delete node from the list which is at specific position\n");
    printf("7. display list\n");
    printf("enter the choice: ");
    scanf("%d", &choice);

    return choice;
}

enum menu_options
{
    EXIT,
    ADDLAST,
    ADDFIRST,
    ADDATPOS,
    DELFIRST,
    DELLAST,
    DELATPOS,
    DISP
};

int main(void)
{
    int pos;
    emp_t data;
    //printf("sizeof(struct node): %d bytes\n", sizeof(struct node));
    //printf("sizeof(node_t): %d bytes\n", sizeof(node_t));

    while (1)
    {
        int choice = menu();

        switch (choice)
        {
        case EXIT:
            if (head != NULL)
                free_list();

            exit(0);

        case ADDLAST:
            printf("enter the emp info : ");
            accept_info(&data);
            add_node_at_last_position(data);
            break;

        case ADDFIRST:
            printf("enter the emp info : ");
            accept_info(&data);
            add_node_at_first_position(data);
            break;

        case ADDATPOS:
            while (1)
            {
                //step-1: accept position from the user
                printf("enter the position: ");
                scanf("%d", &pos);

                //validate position -> if pos is in between 1 to (count+1)
                if (pos >= 1 && pos <= count_nodes() + 1)
                    break;

                printf("invalid position !!!\n");
            }

            printf("enter the emp info : ");
            accept_info(&data);
            add_node_at_specific_position(pos, data);
            break;

        case DELFIRST:
            delete_node_at_first_position();
            break;

        case DELLAST:
            delete_node_at_last_position();
            break;

        case DELATPOS:
            while (1)
            {
                //step-1: accept position from the user
                printf("enter the position: ");
                scanf("%d", &pos);

                //validate position -> if pos is in between 1 to (count+1)
                if (pos >= 1 && pos <= count_nodes())
                    break;

                printf("invalid position !!!\n");
            }

            delete_node_at_specific_position(pos);
            break;

        case DISP:
            display_list();
            break;
        }
    }

    return 0;
}

void display_list(void)
{
    //if list is not empty
    if (head != NULL)
    {
        //start traversal from first node
        node_t *trav = head;
        printf("no. of nodes in a list are: %d\n", count_nodes());
        printf("list is: head -> ");
        //traverse the list till last node including it
        while (trav != NULL)
        {
            //printf("%d -> ", trav->data); //visit data part of each node
            display_info(&trav->data);
            trav = trav->next;
        }
        printf("null\n");
    }
    else
        printf("list is empty !!!\n");
}

node_t *create_node(emp_t data)
{
    //1. allocate memory dynamically for node
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    /* malloc() functions allocates requested bytes of memory from heap section and on success
    it returns starting addr of dynamically allocated block and on failure it returns
    NULL */
    if (temp == NULL)
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

void add_node_at_last_position(emp_t data)
{
    //step-1: create a newnode
    node_t *newnode = create_node(data);

    //step-2: if list is empty --> attach newly created node to the head
    if (head == NULL)
    {
        //store an addr of newly created node into the head
        head = newnode;
    }
    else //step-3: if list is not empty
    {
        //start traversal from first node
        node_t *trav = head;
        //traverse list till last node
        while (trav->next != NULL)
        {
            trav = trav->next; //move trav pointer towards its next node
        }

        //attach newly created node to the last node
        //i.e. store an addr of newly created node into the next part last node
        trav->next = newnode;
    }
}

void add_node_at_first_position(emp_t data)
{
    //step-1: create a newnode
    node_t *newnode = create_node(data);

    //step-2: if list is empty --> attach newly created node to the head
    if (head == NULL)
    {
        //store an addr of newly created node into the head
        head = newnode;
    }
    else //step-3: if list is not empty
    {
        //store an addr of cur first node into the next part of newly created node
        newnode->next = head;
        //attach newly created node to the head
        head = newnode;
    }
}

int count_nodes(void)
{
    int cnt = 0;
    //if list is not empty
    if (head != NULL)
    {
        //start traversal from first node
        node_t *trav = head;
        //traverse the list till last node (including it)
        while (trav != NULL)
        {
            cnt++;             //increment the counter by 1
            trav = trav->next; //to move trav towards its next node
        }
    }

    return cnt;
}

void add_node_at_specific_position(int pos, emp_t data)
{
    if (pos == 1) //if pos is the first position
        add_node_at_first_position(data);
    else if (pos == count_nodes() + 1) //if pos is the last position
        add_node_at_last_position(data);
    else
    { //if pos is the inbetween position
        //create a newnode
        node_t *newnode = create_node(data);
        int i = 1;
        //start traversal from first node
        node_t *trav = head;
        //traverse the list till (pos-1)th node
        while (i < pos - 1)
        {
            i++;
            trav = trav->next;
        }

        //store an addr of cur (pos)th node into next part of newly created node
        newnode->next = trav->next;
        //strore an addr of newly created into the next part of (pos-1)th node
        trav->next = newnode;
    }
}

emp_t delete_node_at_first_position(void)
{
    emp_t value = {0};
    //step-1: check list is not empty, if list is not empty
    if (head != NULL)
    {
        //step-2: if list contains only one node
        if (head->next == NULL)
        {
            //delete the node and make head as NULL
            value = head->data;
            free(head);
            head = NULL;
        }
        else //step-3: if list contains more than one nodes
        {
            //store an addr of first node into the temp which is to be deleted
            node_t *temp = head;
            //attach cur second node to the head
            head = head->next;
            value = temp->data;

            free(temp);
        }
    }
    else
        printf("list is empty !!!\n");
    return value;
}

void delete_node_at_last_position(void)
{
    //step-1: check list is not empty, if list is not empty
    if (head != NULL)
    {
        //step-2: if list contains only one node
        if (head->next == NULL)
        {
            //delete the node and make head as NULL
            free(head);
            head = NULL;
        }
        else //step-3: if list contains more than one nodes
        {
            //start traversal from first node
            node_t *trav = head;
            //traverse the list till second last node
            while (trav->next->next != NULL)
                trav = trav->next;

            //delete last node
            free(trav->next); //free(5000);
            //make next part of second last node as NULL
            trav->next = NULL;
        }
    }
    else
        printf("list is empty !!!\n");
}

void free_list(void)
{
    emp_t value = {0};
    while (head != NULL) //while list not becomes empty
    {
        value = delete_node_at_first_position();
        printf("\n node having empno %d is deleted", value.empno);
    }
    //delete_node_at_first_position();//delete all nodes one by one

    printf("\nlist frees successfully ....\n");
}

void delete_node_at_specific_position(int pos)
{
    if (pos == 1) //if pos is the first position
        delete_node_at_first_position();
    else if (pos == count_nodes()) //if pos is the last position
        delete_node_at_last_position();
    else
    { //if pos is the first position

        int i = 1;
        node_t *trav = head, *temp = NULL;
        //traverse the list till (pos-1)th node
        while (i < pos - 1)
        {
            i++;
            trav = trav->next;
        }

        //store an addr node which is to be deleted in a temp
        temp = trav->next;
        //store an addr of (pos+1)th node into the next part (pos-1)th node
        trav->next = trav->next->next; //trav->next = temp->next;
        //delete the node
        free(temp);
        temp = NULL;
    }
}
void accept_info(emp_t *e)
{
    printf("\n Enter EmpNo:: ");
    scanf("%d", &e->empno);

    printf("\n Enter EmpName:: ");
    scanf("%s", e->name);

    printf("\n Enter EmpNo:: ");
    scanf("%f", &e->sal);
    return ;
}
void display_info(const emp_t *e)
{
    printf("[%d %s %.2f]--->", e->empno, e->name, e->sal);
    return;
}