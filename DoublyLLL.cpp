//Doubly linear linked list
#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;  
}NODE,*PNODE,**PPNODE;

class DoublyLL
{
    private:
        PNODE first;
        int Count;

    public:
        DoublyLL();
        void InsertFirst(int no);
        void InsertLast(int no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(int no,int ipos);
        void DeleteAtPos(int ipos);
};

DoublyLL::DoublyLL()
{
    cout<<"Inside constructor\n";
    first=NULL;
    Count=0;
}

void DoublyLL::InsertFirst(int no)
{
    PNODE newn=NULL;

    newn= new NODE;

    newn->data=no;
    newn->prev=NULL;
    newn->next=NULL;  //#

    if(first==NULL)   //LL is empty
    {
        first=newn;
    }   
    else
    {
        newn->next=first;
        first->prev= newn; //#
        first=newn;
    }

}

// /*/////////////////////////////////////////////*/
void DoublyLL::InsertLast(int no)
{
    PNODE newn=NULL;
    PNODE temp=first;

    newn= new NODE;

    newn->data=no;
    newn->prev=NULL;
    newn->next=NULL;  //#

    if(first==NULL)   //LL is empty
    {
        first=newn;
    }   
    else
    {
        //type 2 loop
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
        newn->prev=temp; //#
    }
}

// /*/////////////////////////////////////////////*/
void DoublyLL::DeleteFirst()
{
    if(first==NULL) //empty LL
    {
        return;
    }
    else if(((first)->next==NULL)&&((first)->prev==NULL)) //single node #
    {
        free(first);
        first=NULL;
    }
    else
    {
        first=(first)->next;
        free((first)->prev);
        (first)->prev=NULL;
    }
}

// /*/////////////////////////////////////////////*/
// void DeleteLast(PPNODE Head)
// {
//     PNODE temp=*Head;

//     if(*Head==NULL) //empty LL
//     {
//         return;
//     }
//     else if(((*Head)->next==NULL)&&((*Head)->prev==NULL)) //single node #
//     {
//         free(*Head);
//         *Head=NULL;
//     }
//     else
//     {
//         while(temp->next->next!=NULL)
//         {
//             temp=temp->next;
//         }
//         free(temp->next);
//         temp->next=NULL;
//     }
// }

// /*/////////////////////////////////////////////*/
void DoublyLL::Display()
{
    printf("Contents of linked list are:\n");

    PNODE temp=first;

    while(temp!=NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp ->next;
    }
    cout<<"NULL\n";
}

// /*/////////////////////////////////////////////*/
// int Count(PNODE Head)
// {
//     int iCnt=0;
    
//     while(Head!=NULL)
//     {
//         iCnt++;
//         Head=Head->next;
//     }

//     return iCnt;
// }

// /*/////////////////////////////////////////////*/
// void InsertAtPos(PPNODE Head,int no,int ipos)
// {
//     int Size=0, i=0;
//     Size=Count(*Head);
//     PNODE newn=NULL;
//     PNODE temp=*Head;

//     if((ipos<1)||(ipos>(Size+1)))
//     {
//         printf("Invalid position\n");
//         return;
//     }
//     if(ipos==1)
//     {
//         InsertFirst(Head,no);
//     }
//     else if(ipos==Size+1)
//     {
//         InsertLast(Head,no);
//     }
//     else
//     {
//         newn=(PNODE)malloc(sizeof(NODE));
//         newn->data=no;
//         newn->next=NULL;
//         newn->prev=NULL;  //#

//         for(i=1;i<ipos-1;i++)
//         {
//             temp=temp->next;
//         }
//         newn->next=temp->next;
//         temp->next->prev=newn;
//         temp->next=newn;
//         newn->prev=temp; //#
//     }
// }

// /*/////////////////////////////////////////////*/
// void DeleteAtPos(PPNODE Head,int ipos)
// {
//     int Size=0,i=0;
//     Size=Count(*Head);
//     PNODE temp=*Head;

//     if((ipos<1)||(ipos>Size))
//     {
//         printf("Invalid position\n");
//         return;
//     }
//     if(ipos==1)
//     {
//         DeleteFirst(Head);
//     }
//     else if(ipos==Size)
//     {
//         DeleteLast(Head);
//     }
//     else
//     {
//         for(i=1;i<ipos-1;i++)
//         {
//             temp=temp->next;
//         }
//         temp->next=temp->next->next;
//         free(temp->next->prev);//#
//         temp->next->prev=temp;//#
//     }

// }

/*/////////////////////////////////////////////*/
int main()
{
    DoublyLL obj;
    int iRet = 0;

    obj.InsertFirst(111);
    obj.InsertFirst(101);
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    obj.InsertLast(400);
    obj.InsertLast(500);

    obj.Display();
    // iRet=Count(First);
    // printf("Number of nodes in linked list are:%d\n",iRet);

    // InsertAtPos(&First,105,5);
    // Display(First);
    // iRet=Count(First);
    // printf("Number of nodes in linked list are:%d\n",iRet);

    // DeleteAtPos(&First,5);
    // Display(First);
    // iRet=Count(First);
    // printf("Number of nodes in linked list are:%d\n",iRet);


    // DeleteFirst(&First);
    // Display(First);
    // iRet=Count(First);
    // printf("Number of nodes in linked list are:%d\n",iRet);

    // DeleteLast(&First);
    // Display(First);
    // iRet=Count(First);
    // printf("Number of nodes in linked list are:%d\n",iRet);

    return 0;
}