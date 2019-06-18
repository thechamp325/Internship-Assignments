#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<String.h>
#include<iomanip>
using namespace std;
long long int a=9000000000;

class info//data members
{
	public:
	int ID;
		string F_name;
		string G_name;
		string L_name;
		bool blacklist;
		info* right;
		info* left;
		info()
		{	blacklist=false;
			right=left=NULL;
		} 
};
class AAdhar//record class with functions
{
	
	public:
		info* head;
		static info*req ;
	AAdhar()						//constructor
	{
		head=NULL;
		req=NULL;
	}
	info* create_info();			//function declaration
	void scan(info* );
	void print_all(info *);
	info* Delete (info *);
	info*delete_rec(info*,int);
	info* find_min(info*t);
	int IDgen();
	int IDsearch(info*,int );
	info* search(info* t,int x);
	void blacklist(info*,int);
	long long int Mobileno();
	bool  getinfo(info* head);
	bool updateentry(info*);
	void print(info* t);
	info* searchAll(info* t,int x);

};
info* AAdhar::req=NULL;
info* AAdhar::create_info()			//create new record
{
	info* p,*q,*s;
	p=new info();
	scan(p);
	if(head==NULL)
	{
		head=p;	
	}
	else
	{
	q=head;
 	while(q!=NULL)
	{
		s=q;
		if(p->ID>q->ID)
		{
			q=q->right;
		}
		else if(p->ID<q->ID)
		{
			q=q->left;
		}
	
	}
	if(p->ID>s->ID)
	{
		s->right=p;
	}
	else
	{
		s->left=p;
	}
	}
	return p;
}		
void AAdhar::scan(info* a)
{
	cout<<"ENTER DATA\n";
	cout<<"1.First Name\n2.Last Name\n3.Guardians Name\n";
	
	a->ID=IDsearch(head,IDgen());
    cin.ignore(1);
	getline(cin,a->F_name);
	getline(cin,a->L_name);
	getline(cin,a->G_name);	
} 
int AAdhar::IDgen()						//generate unique random ID
{
 srand(time(NULL));
	  int a =rand();
	return a;
}
int AAdhar::IDsearch(info*t,int x)      //generate unique ID
{
	if(t!=NULL)
	{
		IDsearch(t->left,x);
		if(x==t->ID)
		{
			x=IDgen();
			IDsearch(head,x);
		}
		IDsearch(t->right,x);
	}
	return x;
}
void AAdhar::print_all(info* t)			//Print all records
{
	if(t!=NULL)
	{
		print_all(t->left);
		if(!t->blacklist){
		
		cout<<setw(10)<<t->ID<<"\t";
		cout<<setw(15)<<t->F_name<<"\t";
		cout<<setw(15)<<t->L_name<<"\t";
		cout<<setw(15)<<t->G_name<<"\n";
		cout<<setw(55)<<"----------------------------------------------------------------"<<"\t\t\t\n";
	
	}
		print_all(t->right);
	}
}
info* AAdhar::search(info* t,int x)		//Search a particular record
{
	if(t!=NULL)
	{
		if(req!=NULL&&req->ID==x)
		{
			return req;
		}
		if(x==t->ID)
	{
		if(!t->blacklist){
		return t;
	}
	}
			
		req=search(t->left,x);
		req=search(t->right,x);
			
	}
	return req;
}
info* AAdhar::searchAll(info* t,int x)		//search record for blacklist function
{
	if(t!=NULL)
	{
		if(req!=NULL&&req->ID==x)
		{
			return req;
		}
		if(x==t->ID)
	{
		
		return t;
	
	}
			
			req=searchAll(t->left,x);
		req=searchAll(t->right,x);
			
	}
	return req;
}

info* AAdhar::Delete(info* t)				
{
	int x;
	cout<<"enter Id";
	cin>>x;
	t=delete_rec(t,x);
	return t;
}
info* AAdhar::delete_rec(info*t,int x)		
{
	if(t==NULL)
	{
		cout<<"empty";
		return NULL;
	}
	if(x<t->ID)
	{
		t->left=delete_rec(t->left,x);
		return t;
	}
	if(x>t->ID)
	{
		t->right=delete_rec(t->right,x);
		return t;
	}
	if(t->left==NULL&&t->right==NULL)
	{
		delete(t);
		return NULL;
	}
	if(t->left==NULL)
	{
		info*p;
		p=t->right;
		delete t;
		return p;
	}
	if(t->right == NULL)
	{
		info*p;
		p=t->left;
		delete t;
		return p;
	}
	info*p;
	p=find_min(t);
	t->ID=p->ID;
	t->right=delete_rec(t->right,p->ID);
	return t;
}
info* AAdhar::find_min(info*t)
{
	info*p=t->right;
	while(p->left!=NULL)
	{
		p=p->left;
	}
	return p;
	
}
void AAdhar::blacklist(info* t,int x){				//Add or remove from blacklist
	if(t!=NULL)
	{
		info* p;
		p=searchAll(t,x);
		if(!p->blacklist){
			int temp=0;
			cout<<"Add in Blacklist\n1.Yes\n2.No";
			cin>>temp;
			if(temp==1)
			p->blacklist=true;
		
	}
	else if(p->blacklist){
			int temp=0;
			cout<<"Remove from Blacklist\n1.Yes\n2.No";
			cin>>temp;
			if(temp==1)
			p->blacklist=false;
		
	}
	
			
}
}
bool AAdhar :: getinfo(info* head){
	int ID;
	string name;
	cout<<"Enter your ID";
	cin>>ID;
	cout<<"Enter your name";
	cin>>name;
	info * t = search(head,ID);
	
	if(t!=NULL&&(t->F_name.compare(name)==0)&&(t->ID==ID)){
		cout<<"Inside mobile";
		return true;
	}
	return false;	
}
long long AAdhar :: Mobileno()
{
	return ++a;
}
bool AAdhar :: updateentry(info* root ){
	long	int ID;
		cout<<"Enter your ID";
		cin>>ID;
		info * t = search(root,ID);
			
		if(t !=NULL){
			cout<<"Enter:\n1.First Name\n2.Last Name\n3.Guardian's Name\n";
			cin>>t->F_name;
			cin>>t->L_name;
			cin>>t->G_name;
			return true;
		}
		else 
		{
			return false;
	}
}
void AAdhar::print(info* t)
{		cout<<setw(10)<<"Aadhar ID"<<"\t";
	    cout<<setw(15)<<"First Name"<<"\t";
		cout<<setw(15)<<"Last Name"<<"\t";
		cout<<setw(15)<<"Guardian's Name"<<"\n";
		cout<<setw(55)<<"----------------------------------------------------------------"<<"\t\t\t\n";
		cout<<setw(10)<<t->ID<<"\t";
		cout<<setw(15)<<t->F_name<<"\t";
		cout<<setw(15)<<t->L_name<<"\t";
		cout<<setw(15)<<t->G_name<<"\n";
		
}
int main()
{
	AAdhar obj;
	int z=1;
	int ch;
	info* p=NULL;
	info* q=NULL;
	do{
		cout<<"Enter :\n1.To Add an entry\n2.To Delete an entry\n3.Add/Remove from blacklist\n4.To Search an entry\n5.Generate Mobile NO\n6.Update Entry\n7.Print All\n";
		cin>>ch;
		switch(ch){
			case 1:
				if(p==NULL){
					p=obj.create_info();
					obj.print(p);
				}
				else{
					q=obj.create_info();	
						obj.print(q);
				}
				break;
			case 2:
					 p=obj.Delete(p);
					 obj.print_all(p);
					 break;
			case 3:
				int ID;
				cout<<"Enter Id";
				cin>>ID;
					obj.blacklist(p,ID);
					AAdhar::req=NULL;
					break;
			case 4:{
				long int ID;
				cout<<"enter ID\n";
				cin>>ID;
				info *t = obj.search(p,ID);
				if(t!=NULL)
				{
				obj.print(t);
				AAdhar::req=NULL;	
				}
				else
				{
					cout<<"no such entry found or blacklisted\n";
				}
				break;
			}
			case 5:
				{
				
					if(obj.getinfo(p))
					{	cout<<"generated mobile no is\n";
						cout<<obj.Mobileno();
					}
					else
					{
						cout<<"ID does not exist\n";
					}
					break;
				}
			case 6:
				{
					
					if(obj.updateentry(p)){
						
							
					}
					else{
						cout<<"ID does not exist";
					}
					break;
					
				}
				case 7:
					{
						cout<<setw(10)<<"Aadhar ID"<<"\t";
					    cout<<setw(15)<<"First Name"<<"\t";
						cout<<setw(15)<<"Last Name"<<"\t";
						cout<<setw(15)<<"Guardian's Name"<<"\n";
						cout<<setw(55)<<"----------------------------------------------------------------"<<"\t\t\t\n";


						if(p!=NULL)
						obj.print_all(p);
						else
						cout<<"Empty record";
						break;
					}
			default:
				break;

			}
			cout<<"Enter 1 to continue 0 to exit\n";
			cin>>z;
		
	}while(z!=0);

}
