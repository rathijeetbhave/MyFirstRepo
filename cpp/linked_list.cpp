#include<iostream>
using namespace std;

class linked_list{

private:
		struct node{
		int data;
		node* link;
		}*p;

public:
		linked_list();
		void createnode(int data);
		void printlist();
		void insert_begin(int data);
		void insert_after(int data,int n);
		void delete_begin();
		void delete_end();
		void delete_value(int data);
		int count_nodes();
		~linked_list();

};

linked_list::linked_list()
{
		p=NULL;
}

void linked_list::createnode(int data)
{
		if(p==NULL)
		{
				p=new node;
				p->data=data;
				p->link=NULL;
		}
		else
		{
				node *q,*t;
				q=p;
				while(q->link!=NULL)
						q=q->link;
				t=new node;
				q->link=t;
				t->data=data;
				t->link=NULL;
		}
				
}

void linked_list::insert_begin(int data)
{
		node*t=new node;
		t->data=data;
		t->link=p;
		p=t;
}

void linked_list::insert_after(int data,int n)
{
		node *q,*t;
		q=p;
		for(int i=0;i<n-1;i++)
		{
				q=q->link;
				if(q==NULL)
				{
						cout<<"there are less than"<<n<<"elements chutiye"<<endl;
						return;
				}
		}
		t=new node;
		t->data=data;
		t->link=q->link;
		q->link=t;
}		

void linked_list::printlist()
{
		node *q;
		q=p;
		while(q->link!=NULL)
		{
				cout<<q->data<<" ";
				q=q->link;
		}

		cout<<q->data<<endl;
}

void linked_list::delete_begin()
{
		node *q;
		q=p;
		p=q->link;
		delete q;
}

void linked_list::delete_end()
{
		node *q,*r;
		q=p;
		while(q->link!=NULL)
		{
				r=q;
				q=q->link;
		}
		r->link=NULL;
		delete q;
}

void linked_list::delete_value(int num)
{
		node *q,*r;
		q=p;
		if(q->data==num)
		{
				p=q->link;
				delete q;
		}
		else
		{
				while(q->data!=num)
				{
						r=q;
						q=q->link;
				}
				r->link=q->link;
				delete q;
		}
}

int linked_list::count_nodes()
{
		int count=0;
		node *q;
		q=p;
		while(q->link!=NULL)
		{
				q=q->link;
				count++;
		}
		return count+1;
}

linked_list::~linked_list()
{
		node *q;
		q=p;
		while(p!=NULL)
		{
				p=q->link;
				delete q;
				q=p;
		}
		cout<<"destructor called"<<endl;
}

int main()
{
		linked_list ll;
		int n;
		ll.createnode(11);
		ll.createnode(33);
		ll.createnode(44);
		ll.createnode(55);
		ll.createnode(66);
		ll.createnode(77);
		ll.printlist();

		ll.insert_begin(100);
		ll.insert_begin(200);
		ll.insert_begin(300);
		ll.insert_begin(400);

		ll.insert_after(333,3);
		ll.insert_after(444,4);
		ll.insert_after(666,6);

		ll.printlist();
		n=ll.count_nodes();
		cout<<"number of nodes are "<<n<<endl;

		ll.delete_begin();
		ll.delete_begin();
		ll.printlist();
		ll.delete_end();
		ll.delete_end();
		ll.delete_end();

		ll.delete_value(333);
		ll.delete_value(444);
		ll.delete_value(666);
		ll.printlist();

		return 0;
}
