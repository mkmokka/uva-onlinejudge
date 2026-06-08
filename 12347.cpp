/*
12347 - Binary Search Tree
*/

#include<bits/stdc++.h>
using namespace std;

typedef struct node Node;
struct node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;

    return(temp);
}
void createBST(Node *&root, int val)
{
    if(root==NULL)
    {
        root=newNode(val);
        root->left=NULL;
        root->right-NULL;

    }
    else
    {
        if(root->data<val)
            createBST(root->right,val);
        else if(root->data>val)
            createBST(root->left,val);
    }
}



void printPostorder(Node* nod)
{
    if(nod==NULL)return;
    printPostorder(nod->left);
    printPostorder(nod->right);
    printf("%d\n",nod->data);

}

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int num;
    Node *root = NULL;
    while(scanf("%d",&num)!=EOF)
    {
        createBST(root,num);
    }

    printPostorder(root);
    return 0;
}

/*
    Use these two lines for output
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);

Sample Input
50
30
24
5
28
45
98
52
60

Sample Output
5
28
24
45
30
60
52
98
50
*/

