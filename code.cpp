#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
typedef long long int ll;

struct node
{
	int data;
	node *left, *right;
};

node* build_tree(int root, int a[], int left_child[], int right_child[])
{
	if(root == -1)
		return NULL;

	node* temp = new node;

	temp->data = a[root];

	temp->left = build_tree(left_child[root], a, left_child, right_child);

	temp->right = build_tree(right_child[root], a, left_child, right_child);

	return temp;
}

node* build(int a[], int n)
{
	int parent[n], left_child[n], right_child[n];

	memset(parent, -1, sizeof(parent));
	memset(left_child, -1, sizeof(left_child));
	memset(right_child, -1, sizeof(right_child));

	int root = 0;
	int last = 0;

	for(int i = 1; i < n; i++)
	{
		last = i-1;
		right_child[i] = -1;

		while(a[last] <= a[i] and last != root)
		{
			last = parent[last];
		}

		if(a[last] <= a[i])
		{
			parent[root] = i;
			left_child[i] = root;
			root = i;
		}
		else if(right_child[last] == -1)
		{
			right_child[last] = i;
			parent[i] = last;
			left_child[i] = -1;
		}
		else 
		{
			parent[ right_child[last] ] = i;
			left_child[i] = right_child[last];
			right_child[last] = i;
			parent[i] = last;
		}
	}

	return build_tree(root, a, left_child, right_child);
}

void inorder(node *root)
{
	if(root == NULL)
		return;

	inorder(root->left);
	cout << root->data << ' ';
	inorder(root->right);
}

int main()
{
    fast
 	
 	int n;
 	cin >> n;

 	int a[n];
 	for(int i = 0; i < n; i++)
 	{
 		cin >> a[i];
 	}

 	node *root = build(a,n);

 	inorder(root);
}
