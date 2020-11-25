#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *nextNode;
}n;
n *store;
void deleteByData(n *head,int key){
    n * deletableNode = head;
    n *previousNode;
​
    if(deletableNode->data==key){
        head= deletableNode->nextNode;
        free(deletableNode);
        return;
    }
    while (deletableNode!=NULL&&deletableNode->data!=key)
    {
        previousNode=deletableNode;
        deletableNode=deletableNode->nextNode;
    }
    if(deletableNode==NULL)
    return;
    previousNode->nextNode=deletableNode->nextNode;
    free(deletableNode);
}
void deleteByPosition(n *head, int position){
​
n* tempNode, *previousNode;
tempNode = head;
​
if(position==0){
head=tempNode->nextNode;
free(tempNode);
return;
}
​
for(int i=0; tempNode!=NULL&&i<position-1;i++){
    tempNode=tempNode->nextNode;
} 
if(tempNode==NULL||tempNode->nextNode==NULL)
{
    return;
}
n* nextNextNode= tempNode->nextNode->nextNode;
free(tempNode->nextNode);
tempNode->nextNode=nextNextNode;
​
​
​
}
​
int main(){
​
n *headNode=(n*)malloc(sizeof(n));
headNode->data=1;
​
​
n *secondNode=(n*)malloc(sizeof(n));
secondNode->data=2;
headNode->nextNode=secondNode;
​
​
n *thirdNode=(n*)malloc(sizeof(n));
thirdNode->data=3;
secondNode->nextNode=thirdNode;
​
​
n *fourthNode=(n*)malloc(sizeof(n));
fourthNode->data=4;
thirdNode->nextNode=fourthNode;
int choice,delete;
​
for(int inf=1;;inf++){
    printf("\nWHAT DO YOU WANT TO DO?\n1.display nodes\n2.delete Nodes by data\n3.delete by position\n4.exit program\n");
    scanf("%d",&choice);
​
    switch (choice)
    {
    case 1:
    store=headNode;
        while (headNode!=NULL)
{
printf("Value= %d \n\n",headNode->data);
headNode=headNode->nextNode;
}
headNode=store;
        break;
    case 2:
    printf("Delete node with which data?\n");
    scanf("%d",&delete);
        deleteByData(headNode,delete);
        break;
    case 3:
    printf("Delete node with which position?\n");
    scanf("%d",&delete);
    deleteByPosition(headNode,(delete-1));
        break;
    case 4:
        exit(1);
        break;
    default:
        break;
    }
​
}
​
​
​
/* Traversing */
​
​
​
​
​
}
