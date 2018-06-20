//Program to swap nodes without swapping the data
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* next;
};
void swapnodes(Node** head,int x,int y)
{	if(x==y)
		return;
		
	Node* temp=*head;
	Node* node1=NULL;
	Node* node2=NULL;
	Node* prev1=NULL;
	Node* prev2=NULL;
	Node* prev=NULL;
	while(temp!=NULL)
	{	
		
		if(temp->data==x)
			{
				prev1=prev;
				node1=temp;
			}
		if(temp->data==y)
			{	
				prev2=prev;
				node2=temp;
			}	
		prev=temp;
		temp=temp->next;
		
	}
	
	if(node1==NULL || node2==NULL)
		{
			cout<<"Nodes not found";
			return;
		}
	if(prev1!=NULL)
		prev1->next=node2;
	else
		*head=node2;
	if(prev2!=NULL)
		prev2->next=node1;
	else
		*head=node1;
	temp=node1->next;
	node1->next=node2->next;
	node2->next=temp;
	
}
void print(Node* head)
{
	while(head!=NULL)
		{
			cout<<head->data<<" ";
			head=head->next;
		}
		cout<<endl;
}
int main()
{
	Node* head=NULL,*temp=NULL;
	int n;
	cin>>n;
	int x;
	for(int i=0;i<n;i++)
	{	
		cin>>x;
		Node* new_node=new Node;
		new_node->data=x;
		new_node->next=NULL;
		if(head==NULL)
			{
				head=new_node;
				temp=head;
			}
		else{
			temp->next=new_node;
			temp=new_node;
		}
		
	}
	int x1,y1;
	cin>>x1>>y1;
	print(head);
	swapnodes(&head,x1,y1);
	print(head);
}
