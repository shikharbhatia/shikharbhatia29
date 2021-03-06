#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/*Function protoypes*/
void printGivenLevel(struct node* root, int level);
int height(struct node* node);
struct node* newNode(int data);

void reverseLevelOrder(struct node *node){
    //for(int i = height(node); i >= 0; i--){
       for(int i = 1; i <= height(node); i++){
        printGivenLevel(node, i);
    }
}
void printGivenLevel(struct node *root, int level){
    if(root == NULL)
        return;
    if(level == 1){
        cout<<root->data;
        return;
    }
    if(level > 1){
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}
int height(struct node *node){
    if(node == NULL)
        return 0;
    int lheight = height(node->left);
    int rheight = height(node->right);

    if(lheight>rheight)
        return lheight+1;
    return rheight+1;
}
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

/* Driver program to test above functions*/
int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    printf("Level Order traversal of binary tree is \n");
    reverseLevelOrder(root);

    return 0;
}
