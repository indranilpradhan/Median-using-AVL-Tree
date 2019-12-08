#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int value;
	Node *left = NULL;
	Node *right = NULL;
};

Node *root = NULL;
int k =0;
double bef;
double aft;
double result;

int max(int a, int b)
{
	return a>b?a:b;	
}

void display(Node* ptr,int n)
{
	if(ptr != NULL)
	{
	//	cout<<"n "<<n<<endl;
		display(ptr->left,n);
	//	cout<<"k "<<k<<endl;
		if(n == 1)
			cout<<"median "<<ptr->value<<" "<<endl;
		else
		{
			if(n%2 == 1 && k == n/2)
				cout<<"median "<<ptr->value<<" "<<endl;
			if(n%2 == 0)
			{
				if(k == (n/2-1))
				{
		//		cout<<"here "<<ptr->value<<endl;
					bef = ptr->value;
		//		cout<<"bef "<<bef<<endl;
				}
			if(k == n/2)
			{
				aft = ptr->value;
		//		cout<<"bef "<<bef<<endl;
		//		cout<<"aft "<<aft<<endl;
				result = (aft + bef)/2;
				cout<<"median "<<result<<endl;
			}
		}
		}
		k++;
		display(ptr->right,n);
	}
}

void inorder(Node* ptr)
{
	if(ptr != NULL)
	{
		inorder(ptr->left);
		cout<<ptr->value<<" ";
		inorder(ptr->right);
	}
}

int height(Node *ptr)
{
//	cout<<"33"<<endl;
	if(ptr == NULL)
	{
//		cout<<"36"<<endl;
		return 0;
	}
	if(ptr->left == NULL && ptr->right == NULL)
	{
//		cout<<"37"<<endl;
		return 1;
	}
	else
	{
	//	cout<<"46"<<endl;
		return max(1+height(ptr->right),1+height(ptr->left));
	}	
}

Node* insert(int value,Node *ptr)
{
	if(ptr == NULL)
	{
		ptr = new Node();
		ptr->value = value;
		ptr->right = NULL;
		ptr->left = NULL;
		return ptr;
	}
//	cout<<"56"<<endl;
//	cout<<"pvalue "<<ptr->value<<endl;
//	cout<<"value"<<value<<endl;
	if(value < ptr->value)
	{
		ptr->left = insert(value, ptr->left);
	}
	
	if(value >= ptr->value)
	{
		ptr->right = insert(value,ptr->right);
	}
//	cout<<"72"<<endl;
	int rheight = height(ptr->right);
//	cout<<"74"<<endl;
	int lheight = height(ptr->left);
	
//	cout<<"lh"<<lheight<<endl;
//	cout<<"rh"<<rheight<<endl;
	
	if(lheight > 1+rheight)
	{
		int llheight = height(ptr->left->left);
		int lrheight = height(ptr->left->right);
//		cout<<"llh"<<llheight<<endl;
//		cout<<"lrh"<<lrheight<<endl;
		if(llheight > lrheight)
		{
			//rightrotate
//			cout<<"ptr rr"<<ptr->value<<endl;
			Node* newptr = new Node();
			newptr = ptr->left;
			ptr->left = newptr->right;
			newptr->right = ptr;
			ptr = newptr;
		}
		else
		{
			//leftrightrotate
			Node* newptr1 = new Node();
			Node* newptr2 = new Node();
			newptr1 = ptr->left->right;
			ptr->left->right = newptr1->left;
			newptr1->left = ptr->left;
			ptr->left = newptr1;
			newptr2 = ptr->left;
			ptr->left = newptr2->right;
			newptr2->right = ptr;
			ptr = newptr2;
		}
	}
//	cout<<"95"<<endl;
	if(rheight > 1+lheight)
	{
		int rlheight = height(ptr->right->left);
		int rrheight = height(ptr->right->right);
//		cout<<"rlh"<<rlheight<<endl;
//		cout<<"rrh"<<rrheight<<endl;
		if(rrheight > rlheight)
		{
			//leftrotate
			Node* newptr = new Node();
			newptr = ptr->right;
			ptr->right = newptr->left;
			newptr->left=ptr;
			ptr = newptr;
		}
		else
		{
			//rightleftrotate
			Node* newptr1 = new Node();
			Node* newptr2 = new Node();
			newptr1 = ptr->right->left;
			ptr->right->left = newptr1->right;
			newptr1->right = ptr->right;
			ptr->right = newptr1;
			newptr2 = ptr->right;
			ptr->right = newptr2->left;
			newptr2->left = ptr;
			ptr = newptr2;
		}
	}
	return ptr;	
}

int main()
{
	int t;
	cin>>t;
	Node *ptr = NULL;
	int n = 0;
//	double k = 0;
	while(t--)
	{
		int num;
		cin>>num;
	//	if(root == NULL)
	//	{
		n++;
		root = insert(num,root);
	//	}
	//	else
	//	{
		//	ptr = insert(num,root);
	//	}
		k=0;
		display(root,n);
	//	cout<<"here"<<endl;
		k=0;
	}
	
//	inorder(root);
	return 0;
}
