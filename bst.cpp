#include <bits/stdc++.h>
using namespace std;
struct Node{
int data;
Node *left=NULL;
Node *right=NULL;
Node(int data){
this->data=data;
}
};
class Btree{
public:
int n;
int x;
int flag;
Node *root;
Btree()
{
root=NULL;
}
Node *insert(Node *root, int val)
{
if(root == NULL){
Node *root = new Node(val);
return root;
}
if(root->data > val){
//left subtree
root->left = insert(root->left, val);
}
else{
//right subtree
root->right = insert(root->right, val);
}
return root;
}
void input()
{
cout<<"\nEnter no of elements in BST: ";
cin>>n;
for(int i=0; i<n; i++)
{
cout<<"\nValue of node= ";
cin>>x;
root=insert(root,x);
}
}
int search(Node *root, int key)
{
if(root==NULL)
{
return 0;
}
if(root->data == key){
return 1;
}
else if(root->data >key){
return search(root->left, key);
}
else{
return search(root->right, key);
}
}
void minvalue(Node *root)
{
while(root->left != NULL)
{
root= root->left ;
}
cout<<"\nMinimum value = "<<root->data;
}
void mirror(Node *root)
{
if(root == NULL)
{
return;
}
else
{
//swapping
Node *ptr;
mirror(root->left);
mirror(root->right);
ptr=root->left;
root->left=root->right;
root->right=ptr;
}
}
void display()
{
cout<<"\n-------- BST in Inorder format---------\n";
inorder(root);
cout<<endl;
}
void inorder(Node *root)
{
if(root != NULL)
{
inorder(root->left);
cout<<root->data<<" ";
inorder(root->right);
}
}
};
int main()
{
Btree obj;
int ch,key;
while(1)
{
cout<<"\n1.Insert new node \n2.Minimum data value node \n3.mirror image \n4.search value \nEnter your choice: ";
cin>>ch;
switch(ch)
{
case 1: obj.input();
obj.display();
break;
case 2: obj.minvalue(obj.root);
break;
case 3: obj.mirror(obj.root);
obj.display();
break;
case 4: cout<<"\nEnter key to be search: ";
cin>>key;
int a = obj.search(obj.root,key);
if(a==0){
cout<<"\nElement not found";
}
else{
cout<<"Element found";
}
break;
}
}
return 0;
}