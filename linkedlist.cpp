//create a driver function that can explain all the basic operations of linkedlist
//also,try to improvise this codebase to cover as much problems related to linkedlist as possible
//write your name and then add your code below.


//harsh

/ --------------------------------LINKEDLIST----------------------------

// push node at 0th position, push node at end, push node at given index
// delete a node at given index
// display linkedlist
// show the size of linkedlist

// display the data of nth node from end
// display data of the middle node in the linkedlist 
// detect loop in a linkedlist
// find length of that loop
// remove duplicates and also find duplicates from sorted and unsorted linkedlist
// swap nodes in linkedlist without swaping data
// move last element to front of the linkedlist
// segregate even and odd noddes in given linkedlist
// intersection of two sorted linkedlist
// reverse a linked list




#include <bits/stdc++.h>
using namespace std;

// created a node class i.e. like the skeleton of our node.
class node {
    public:
        int data;
        node* next;
};


// push function adds a node before the first node in linkedlist
void push(node** head, int data) {
    node* t= new node();
    t->data=data;
    t->next=(*head);
    (*head)=t;
}


// append function adds a node at the end of linkedlist
void append(node** head, int data) {
    node* t= new node();
    t->data=data;
    t->next=NULL;
    node* p= *head;
    while(p->next) {
        p=p->next;
    }

    if(*head==NULL)
    {
        *head=t;
        return;
    }

    p->next=t;
    return;
}

// add a node at a given index starting from 0
void addAtPos(node** head, int pos, int data) {
    node* t=new node();
    t->data=data;
    node *p=(*head);
    for(int i=0;i<pos-1;i++)
    {
        p=p->next;
        if(p==NULL) {
            cout<<"cant do that, add some more nodes to fill the empty positions before this position."<<endl;
            return;
        }
    }

   if(pos>0)
   {
        t->next=p->next;
        p->next=t;
   }
   else if(pos==0) {
      t->next=*head;
      (*head)=t;
   }
}




// display function represent our linkedlist formed
void display(node* head) {
    node* p=head;
    while(p) {
        cout<<p->data<<"--------";
        p=p->next;
    };
    cout<<endl;
}

// delete a node
void delAtPos(node** head, int pos) {
    node*p=*head, *q=(*head)->next;
    if(pos==0) {
        (*head)=q;
        free(p);
        return;
    }
    for(int i=0;i<pos-1;i++) {
        p=p->next;
        q=q->next;

        if(p->next==NULL){
            cout<<"cant delete at this position, maybe index given is invalid"<<endl;
            return;
        }
    }
    p->next=q->next;
    free(q);
    

}


int countSize(node *head) {
    if(head==NULL){
        return 0;
    }
    return countSize(head->next)+1;
}







// driver function
int  main()
{
    // create a linkedlist head pointing to null
    node* linkedlist= NULL;

    // push these elementd in the linkedlist provided in first argument
    push(&linkedlist, 1);
    push(&linkedlist, 2);
    push(&linkedlist, 3);

    // append this at the end of linkedlist
     append(&linkedlist, 24);


    // push a node at a given position
    addAtPos(&linkedlist, 3, 59);

    // display the linkedlist
    display(linkedlist);

    // delete an element from given position
    delAtPos(&linkedlist, 0);

    // again displaying the linked list
    display(linkedlist);

    // count the elements in linkedlist, there are 2 ways, one is normal(loop through and increase the counter), other is recursive
    int size=countSize(linkedlist);
    cout<<"there are "<<size<<" nodes in the linkedlist currently..."<<endl;


    
    return 0;
}
