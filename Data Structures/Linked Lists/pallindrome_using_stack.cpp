#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node* next;
};
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
    stack<char>s;
    Node* temp=head;
    while(temp!=NULL)
    {
        s.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==s.top())
            {
                s.pop();
            }
        else
            {
                cout<<"Not Pallindrome";
                return 0;
            }
        temp=temp->next;
    }
    cout<<"Pallindrome\n";
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
