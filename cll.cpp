#include<iostream>
using namespace std;

class Node 
{
	//type
	public:

	//pointer to the next node
	Node *next;

	//data
	int data;

	//construct
	Node()
	{
		next=NULL;
	}
};

class clinklist
{
	//head->node type pointer
	Node *head;

	//tail->node type pointer
	Node *tail;

	//type
	public:

	//construction of the circular linklist
	clinklist()
	{
		head=NULL;
		tail=NULL;
	}

//insert
void insert(int value)
{
	//addition of the 1st node
	Node *p=new Node;
	p->data=value;

	//for the 1st node
	if (head==NULL)
	{head=p;}

	//for other node
	else
	{
	 tail->next=p;
	 p->next=head;
	}
	tail=p; 	
}

//insertat
void insertat(int pos,int value)
{
	//condition if the given input has more element than the linklist
	if( pos>(this->count()+1) )
	cout<<"A position as such doesn't exist in the linklist. "<<endl;
	else
	{
		Node *p=new Node;
		p->data=value;
		int i=1;Node *current=head;
		while(i<pos-1)
		{current=current->next;i++;}
		if(pos!=1)
		{
			p->next=current->next;
			current->next=p;
		}
		else if(pos==1)
		{
			p->next=current;
			head=p;
		}
	}
}

//delete
void del()
{
	//before tail has to point to the head
	Node *p=head;
	while(p->next!=tail)
	{p=p->next;}

	//updation of tail
	tail=p;
	p=p->next;
	p->next=NULL;

	//delete p
	delete p;
	tail->next=head;
}

//delat
void delat(int pos)
{
	if ( pos>this->count() )
	cout<<"The linklist does not contain that many elements";
	else 
	{
		//reach the point before the pos
		Node *p=head;
		int i=1;
		while(i<pos-1)
		{p=p->next;i++;}
	
		Node *d=p->next;
		p->next=d->next;
		d->next=NULL;
		delete d;
	}
}

//count
int count()
{
	Node *p=head;int i=1;
	while (p!=tail)
	{p=p->next;i++;}
	return i;
}

//display
void display()
{
	Node *p=head;
	while(p!=tail)
	{
		cout<<p->data<<"->";
		p=p->next;
	}
	cout<<"NULL"<<endl;
	cout<<p->data<<endl;
	
}
};

int main()
{
	clinklist cl;
	cl.insert(1);cl.insert(2);cl.insert(3);cl.insert(4);cl.insert(5);cl.insert(6);cl.insert(7);cl.insert(8);cl.insert(9);cl.insert(10);
	cl.display();
	cl.insertat(6,1);
	cl.display();
	cl.insertat(20,3);
	cl.del();
	cl.display();
	cl.delat(5);cl.display();
	return 8;
}