#include<stdio.h>
#include<stdlib.h>
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

struct listNode
{
    int item;
    struct listNode * next;
};

struct listNode * head;
struct listNode * tail;

void initializeList()
{
    head = 0;  //initially set to NULL
	tail = 0;
}

//The following function inserts the item in front of the list
int insertItem(int item) //insert at the beginning
{
    struct listNode * newNode ;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	newNode->item = item ;
	newNode->next = head;
	head = newNode ;
    if(head->next==0){tail=newNode;}
	return SUCCESS_VALUE ;
    //Write your code here. Make sure to handle tail pointer.
}

//The following function deletes the item from the list
int deleteItem(int item)
{

    struct listNode *temp, *prev ;
	temp = head ; //start at the beginning
	while (temp != 0)
	{
		if (temp->item == item) break ;
		prev = temp;
		temp = temp->next ; //move to next node
	}
	if (temp == tail->next) return NULL_VALUE ; //item not found to delete
	if (temp == head) //delete the first node
	{
		head= head->next ;
		free(temp) ;
	}
	else if(temp==tail)
    {
        prev->next=0;
        tail=prev;
    }
	else
	{
		prev->next = temp->next ;
		free(temp);
	}
	return SUCCESS_VALUE ;
}

//The following function returns the address of the item in the list. If the item is not present, it returns 0 or null pointer.
struct listNode * searchItem(int item)
{
   struct listNode * temp ;
	temp = head;
	while (temp != 0)
	{
		if (temp->item == item) return temp ;
		temp = temp->next ; //move to next node
	}
	return 0 ;
}

void printList()
{
    struct listNode * temp;
    temp = head;
    while(temp!=0)
    {
        printf("%d->", temp->item);
        temp = temp->next;
    }
    printf("\n");
    //printf("Tail: %d\n",tail->item);
}

//The following function inserts item at the end of the list
int insertLast(int item)
{
    struct listNode * last;
    last = (struct listNode*) malloc (sizeof(struct listNode)) ;
    last->item=item;
    last->next=0;
    tail->next=last;
    tail=last;
}


int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4. InsertLast. 5. Print. 6. exit.\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(item);
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            deleteItem(item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct listNode * res = searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            int item;
            scanf("%d",&item);
            insertLast(item);
        }
        else if(ch==5)
        {
            printList();
        }
        else if(ch==6)
        {
            break;
        }
    }

}

