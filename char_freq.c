typedef struct node{
 char c;
 int freq;
 struct node *left;
 struct node *right;
}tree_node;

#define INITIAL_FREQ_VAL 1

#include<stdio.h>
#include<stdlib.h>

tree_node* new_node(char c,int freq){
  tree_node *node=(tree_node *)malloc(sizeof(tree_node));
  node->c=c;
  node->freq=freq;
  node->left=NULL;
  node->right=NULL;
  return node;
}

void add_node(tree_node *node,char c){
 if(c==node->c)
     node->freq++;
 else if(c<node->c){          
        if(node->left==NULL)
           node->left=new_node(c,INITIAL_FREQ_VAL);
        else
           add_node(node->left,c);
 }
 else{
     if(node->right==NULL)
       node->right=new_node(c,INITIAL_FREQ_VAL);
     else
       add_node(node->right,c);
 } 
}

int count=0;
void preorder(tree_node *node){
  if(node!=NULL){
      printf("%c --- %d\n",node->c,node->freq);
      count+=node->freq;
      preorder(node->left);
      preorder(node->right); 
  }
}

int main(){
 tree_node root_node;
 scanf("%c",&root_node.c);
 root_node.freq=INITIAL_FREQ_VAL;
 root_node.left=NULL;
 root_node.right=NULL;
 char c;
 do{
    scanf("%c",&c);
 }while(c=='\n');

 while(c!=';'){
    if(c!='\n')
       add_node(&root_node,c); 
    scanf("%c",&c);
 }
 preorder(&root_node);
}

