#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node* next;
};
Node* reverse(Node* temp)
{
    Node* current=temp;
    Node* prev=NULL;
    Node* nextn=NULL;
    while(current!=NULL)
    {
        nextn=current->next;
        current->next=prev;
        prev=current;
        current=nextn;
    }
    
    return prev;
}
bool checkPallindrome(Node *head)
{
    Node* fp=head;
    Node* sp=head;
    Node* temp=head;
    while(fp!=NULL && fp->next!=NULL)
    {
        fp=fp->next->next;
        sp=sp->next;
    }
    if(fp!=NULL)
        sp=sp->next;
    sp=reverse(sp);
    while(sp!=NULL)
    {
        if(temp->data!=sp->data)
            return false;
        temp=temp->next;
        sp=sp->next;
    }
    
    return true;
}
int main()
{
    Node* head=NULL ;
    char x='1';
    while(1)
    {
        //char x;
        cin>>x;
        if(x=='0')break;
        Node* new_node=new Node;
        new_node->data=x;
        new_node->next=head;
        head=new_node;
    }
    if(checkPallindrome(head))
        cout<<"Pallindrome\n";
    else 
        cout<<"Not a Pallindrome\n";
    
}
