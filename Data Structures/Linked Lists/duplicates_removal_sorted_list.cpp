#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node* next;
};

void removeDuplicates(Node *head)
{
    if(head==NULL)
        return;
    Node* temp=head;
    Node* nextn=NULL;
    while(temp->next!=NULL)
    {
        if(temp->data==temp->next->data)
        {
            nextn=temp->next->next;
            free(temp->next);
            temp->next=nextn;
        }
        else{
            temp=temp->next;
        }
    }
}
int main()
{
    Node* head=new Node;
    char x;
    cin>>x;
    
    head->data=x;
    head->next=NULL;
    Node* temp=head;
    while(1)
    {
        //char x;
        cin>>x;
        if(x=='0')break;
        Node* new_node=new Node;
        new_node->data=x;
        new_node->next=NULL;
        temp->next=new_node;
        temp=new_node;
    }
    removeDuplicates(head);
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
