#include<iostream>
using namespace std;
class node //data members
{
	public:
	int data;
	node* right,*down;
	int flag;
	node()
	{
		right=down=NULL;
	}
};
class matrix //
{
	private:
	node* head;
	public:
	matrix()
	{
		head=NULL;
	}
	node* create_matrix(int row,int column);
	void print_matrix(int row ,int column,node*);
	void perimeter(int row ,int column,node*);
	void transpose(int row ,int column,node*);
	void diagonal_sum(int row,int column,node*);
};
	void Swap(node*p,node*q)
	{
		int temp;
		temp=p->data;
		p->data=q->data;
		q->data=temp;	
	}
node* matrix::create_matrix(int row,int column)
	{
		node* t;
		t=new node();
		cout<<"enter data ";
		cin>>t->data;	
	
			if(row==1&&column==1)
			{
				head=t;
	 		}
	 		else
	 		{ 
	 			head=t;
				for(int i=0;i<row;i++)
				{
					node*p=t;
					for(int j=1;j<column;j++)
					{
						t->right=new node();
					//cout<<"enter data ";
						cin>>t->right->data;
						t=t->right;
					
					}
					if(i < row-1)
					{
						p->down=new node();
					//	cout<<"enter data ";
						cin>>p->down->data;
						t=p->down;
					
					}
				}
				t=head;
				node*p=t->down;
				for(int i=1;i<row;i++)
				{
					node*q=t;
					node*r=p;
					for(int j=1;j<column;j++)
					{
						t->right->down=p->right;
						t=t->right;
						p=p->right;
					}
					t=q->down;
					p=r->down;          
				}
			}
		return head;
	}
void matrix::print_matrix(int row,int column,node* Snode)
	{
			node*p=Snode;
		for(int i=0;i<row;i++)
		{
			node*t=p;
		   cout<<p->data;
			for(int j=1;j<column;j++)
			{
				p=p->right;
				cout<<" "<<p->data<<" ";		
			}
			p=t->down;
			cout<<"\n";
		}
	}
	void matrix:: perimeter(int row,int column,node* Snode)
	{
		node*p,*q,*r,*s;
		q=p=Snode; 
		int sum =0;
		sum=p->data;
		r=p=p->right;
		s=q=q->down;
		while(r!=s)
		{
			if(p!=NULL)
			{
				r=p;
				sum=sum+(p->data);
				p=p->right;
			}
			else
			{
				r=r->down;
				sum=sum+(r->data);
			}
			if(q!=NULL)
			{
				s=q;
				sum=sum+(q->data);
				q=q->down;
			}
			else
			{	
				s=s->right;
				sum=sum+(s->data);
			}
		}
		sum=sum-(s->data);
		cout<<"\nPerimeter is: "<<sum<<"\n";
	}
	void matrix::transpose(int row,int column,node* Snode)
	{
		node*p,*q,*r,*s;
		q=p=Snode; 
		r=p->right;
		s=q->down;
		while(r!=s)
		{
			if(p->right!=NULL)
			{
				p=p->right;
					r=p;
			}
			else
			{
				r=r->down;
			}
			if(q->down!=NULL)
			{
				q=q->down;
				s=q;
			}
			else
			{	
				s=s->right;
			}
			if(p->right!=NULL)
			{
				Swap(p,q);
			}
			else if(r!=s)
			{
				Swap(r,s);
			}
		}
	}
	void matrix::diagonal_sum(int row,int column,node* Snode)
	{
		node* p=Snode;
		int sum=0;
		while(p!=NULL)
		{
			sum=sum+(p->data);
			if(p->right!=NULL)
			{
				p=p->right->down;
			}
			else
			{
				p=NULL;
			}
		}
		cout<<"\nDiagonal sum is:"<<sum<<" ";
	}
int main( )
{
	matrix obj;
	node*p=obj.create_matrix(3,3);
	obj.perimeter(3,3,p);
	cout<<"\n";
	cout<<"The input matrix is:\n";
	obj.print_matrix(3,3,p); 
	cout<<"\n";
	obj.transpose(3,3,p);
	cout<<"The transpose of matrix is:\n";
	obj.print_matrix(3,3,p);
	obj.diagonal_sum(3,3,p);
}
