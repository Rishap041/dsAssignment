#include <stdio.h>
  struct node // stucture declaration of doule linked list.
    {
        int data;
        struct node *left;
        struct node *right;
    }*root=NULL;

  void insert(int n) //function for insert element is BST
{
 struct node *t=root;
 struct node *q,*r;
 if(root==NULL)  // construct tree for root element.
 {
     q=(struct node *)malloc(sizeof(struct node));
     q->data=n;
     q->left=q->right=NULL ;
     root=q;
     return;
 }
 while(t!=NULL) // search loction of elements
 {
     r=t;
     if(n<t->data)
        t=t->left;
   else  if(n>t->data)
        t=t->right ;
     else
        return ;
 }
 q=(struct node *)malloc(sizeof(struct node)); // contruct new node
     q->data=n;
     q->left=q->right=NULL ;
     if(n<r->data)  //insert node at right side
        r->left=q;
     else // insert node at left side
        r->right=q;
}

void inorder(struct node *t) //function for inorder transversal
{
    if(t)
    {
    inorder(t->left);  //recursive call
    printf("%d \t",t->data); //print of data
    inorder(t->right); //recursive call
    }
}

int heightOfTree(struct node *t) //function for find height of tree
{
    int p,r;
    if(t==NULL)
     return 0;
    else
    {
     p=heightOfTree(t->left);
     r=heightOfTree(t->right);
    return (1+(p>r?p:r));
    }
}

 void balance_check(struct node *t) //function to check unbalance node.
 {
     int bf;
     bf=heightOfTree(t->left)-heightOfTree(t->right);
     if(bf==0 || bf==1 || bf==-1 )
        printf("\n node of data %d is balanced \n ",t->data);
     else
        printf("\n node of data %d is not balanced and balacing factor is %d \n",t->data,bf);
 }

 void RRrotation(struct node *t) //  perform rr rotation
 {
     struct node *p=t->right;
     p->left=t;
     t->right=NULL;
     if(t==root)
     {
         root=p;
     }
     else
        root->right=p;
 }
int main()  // calling main functon
{
    int m,n;
for (int i = 1; i < 7;i++)  //insert of data in BST.
	{
		insert(i);
	}
printf("Binary serach tree are created with dara 1 2 3 4 5 6 . \n");
m=heightOfTree(root);
printf("height of tree before rotation are %d \n",m);
printf("inorder transversal of BST are : \n");
inorder(root);
struct node *t=root ;
 for (int i = 1; i < 7;i++)  //insert of data in BST.
	{
		balance_check(t);
		if(t->left!=NULL)
           t= t->left ;
        else
		t=t->right ;
	}
printf("\n RR rotaional is required to balanced the tree \n");
RRrotation(root);
RRrotation(root);
RRrotation(root->right);
printf(" \nBST is created after rotaion \n");
printf("inorder transvesal of created binary search tree after rotation are \n");
inorder(root);
n=heightOfTree(root);
printf("\nheight of tree after rotation are: %d \n",n);
return 0;
}
