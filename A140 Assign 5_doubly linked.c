#include<stdio.h>
#include<stdlib.h>


void push_back();
void delete();
void printList();
void modify();

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

int main()
{
    struct Node* head=NULL;


    while(1)
    {
        printf("\n*********Menu*********");
        printf("\n\tPress 1 to Insert Record\n\tPress 2 to Delete Record\n\tPress 3 to Print Record\n\tPress 4 to Modify Record\n\tPress 0 to Exit\n");
        printf(" Press: ");
        int x;
        scanf("%d",&x);
        switch (x)
        {
        case 1:
            push_back(&head);
            break;
        case 2:
            delete(&head);
            break;
        case 3:
            printList(head);
            break;
        case 4:
            modify(head);
            break;
        case 0:
            break;
        }
        if(x==0)
            break;
        
        printf("\nPress ENTER to countinue....");
        getchar();
        getchar();
        printf("---------------------------------\n");

    }
}

void push_back(struct Node** head)
{
    struct Node* temp=*head;
    struct Node* new =(struct Node*) malloc(sizeof(struct Node));
    printf("\nEnter Data: ");
    scanf("%d",&new->data);
    new->next=NULL;

    if(temp==NULL)
    {
        *head=new;
        new->prev=NULL;
    }
    else
    {
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next= new;
        new->prev=temp;
    }
    printf("\nData Successfully Inserted....\n");
}

void delete(struct Node** head)
{
    int value;
    struct Node *temp=*head;
    printf("\nEnter Data to be Deleted: ");
    scanf("%d",&value);
    if(temp->data==value)
    {
        *head=temp->next;
        temp->next->prev=NULL;
        free(temp);
        printf("\nData Successfully Deleted....\n");
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->data==value)
            {
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                free(temp);
                printf("\nData Successfully Deleted....\n");
                return;
            }
            temp=temp->next;
        }

        printf("\nWrong Input!! No such data exist in given List\n");
    }
}
 
void modify(struct Node* head)
{
    int value,new;

    printf("\nEnter Data to be modified: ");
    scanf("%d",&value);
    while(head!=NULL)
    {
        if(head->data==value)
        {
            printf("Enter New Data: ");
            scanf("%d",&new);
            head->data=new;
            printf("\nData Successfully Modified....\n");
            return;
        }
    }
    printf("\nWrong Input!! No such data exist in given List\n");

}


void printList(struct Node* head)
{
    struct Node* last;
    printf("\nTraversal in forward direction \n");
    while (head != NULL) {
        printf(" %d ", head->data);
        last = head;
        head = head->next;
    }

    printf("\nTraversal in reverse direction \n");
    while (last != NULL) {
        printf(" %d ", last->data);
        last = last->prev;
    }
}
