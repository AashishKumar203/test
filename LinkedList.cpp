//Linked list - insertion,deletion
//Linked Lists is a linear collection of data elements, called nodes pointing to the next nodes by means
//of pointers. Each node is divided into the two parts:
//the first part containing the information of the element
//the second part called the link or next pointer containing the address of the next node in the list
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{                //creating a structure where first data member is integer to hold the data
                            //and second data member is the pointer to a node to hold the address of the next node
    int data;
    node *next;
};
class linkedlist{
    private:
    node *head;              //head is referng to first node
    node *tail;              //tail is refering to the last node
    public:
    linkedlist(){
        head=NULL;
        tail=NULL;
    }
    void Insert_end(int value){ // function to inset the value at the end of the linked list
        node *temp=new node;    //We are allocating the space required for a node by the new operator.
                                //Now, ‘tmp’ points to a new node
        temp->data=value;       //We are giving a value to the ‘data’ of ‘tmp’
        temp->next=NULL;
        if(head==NULL){     // If ‘head’ is NULL, our current node (tmp) is the first node of the linked list and
                                //this it will be ‘head’ and ‘tail’ both
            head=temp;
            tail=temp;
        }
        else{                   // If ‘head’ is not NULL, it means that we have a linked list and
                                //we just have to add the node at the end of the linked list.
            tail->next=temp;    //The new node (tmp) will go after the ‘tail’ and then
                                //we are changing the tail because the new node is the new ‘tail’.
            tail=tail->next;
        }
    }
    void insert_front(int value){ // function to inseert the value at the begning of the linked list
        node *tmp=new node;       // making a new node
        tmp->data=value;          //assihning a value to the new node
        tmp->next=head;           //pointing the next (address) of the new node to head of the existing linkedlist
        head=tmp;                 //last line, we are making the new node as ‘head’ node
    }

    void insert_position(int value, int position){   //position = n
        node *temp1=new node;
        temp1->data=value;
        temp1->next=NULL;
        int i=0;
        if(position == 1){
            temp1->next=head;
            head=temp1;
        }
        else{
            node *temp2=new node;
            temp2=head;
            while(i<position-2){
                temp2=temp2->next; //temp2 points to (n-1)th node
                i++;
            }
            temp1->next=temp2->next; //(n-1)th node address pointing to new temp node address (right hand connection)
            temp2->next=temp1;  //address of temp1 assigned to address of temp2 (left hand connection)
        }
    }

    void delete_position(int position){  //position=n
        node *temp1 = new node;
        temp1=head;
        if(position==1){
            head=temp1->next;  //head points to second node
            free(temp1);     //deleting the first node
        }
        else{
            int i = 0;
            while(i<position-2){
                 temp1=temp1->next;
                 i++;
            }                       //temp1 points (n-1)th node
            node *temp2=new node;
            temp2=temp1->next;       //temp2 points (n)th node
            temp1->next=temp2->next; //(n-1)th pointing to (n+1)th node
            free(temp2);       //deleting temp2( (n)th node )
        }

    }

    void display_list(){
        node *p;                  // creating a new node pointer which is pointing to the head of the linkedlist
        p=head;
        while(p!=NULL){           // creating loop untill the head would be NULL
            cout<<p->data<<" ";   // pringting the value in the node
            p=p->next;            //moving to the next node
        }
    }
};
int main()
{
    linkedlist l1;                //creating object of the linkedlist class
    l1.Insert_end(12);            //calling the function
    l1.Insert_end(13);
    l1.insert_front(987);
    l1.Insert_end(123);
    l1.insert_position(15,3);     //3nd position would be filled with 15
    cout<<"List is : ";
    l1.display_list();          //list - 987 12 15 13 123
    cout<<endl;
    l1.delete_position(3);     //deleting 3rd node
    cout<<"List is : ";
    l1.display_list();
    cout<<endl;
    return 0;
}





