#include<bits/stdc++.h>
using namespace std;

struct node{
   int info;
   struct node *ptr = NULL;
};
typedef struct node *nodeptr;

nodeptr newNode(int inf){
   nodeptr p;
   p=(nodeptr)malloc(sizeof(struct node));
   if(p!=NULL){
       p->info=inf;
   }
   return p;
}
nodeptr createList(int n){
    int i,inf;
    nodeptr start,curr,newPtr;
    cout<<"Enter values\n";
    start=curr=NULL;
    for(i=1;i<=n;i++){
      cin>>inf;
      newPtr = newNode(inf);
      if(newPtr==NULL){cout<<"Memory Limit Exit\n";}
      else{
         if(start==NULL){
            start=curr=newPtr;
         }
         else{
            curr->ptr = newPtr;
            curr=newPtr;
         }
      }
    }
    return start;
}
void traverse(nodeptr start){
    nodeptr curr,newPtr;
    cout<<"Given infos:\n";
    curr=start;
    while(curr!=NULL){
      cout<<curr->info<<" ";
      curr=curr->ptr;
    }
    cout<<"\n";
}
int search(int value,nodeptr start){
    int pos=1;
    nodeptr curr=start;
    while(curr!=NULL){
        if(curr->info==value){
            cout<<"Position: "<<pos<<"\n";
            return pos;
        }
        curr=curr->ptr;
        pos++;
    }
    cout<<"Not Found!\n";
    return -1;
}
int main(){
    int n,value,pos;
    nodeptr list1;
    cout<<"How many node do you want to add?\n";
    cin>>n;
    list1=createList(n);
    traverse(list1);
    cout<<"Which value do you want to search?\n";
    cin>>value;
    pos=search(value, list1);
    return 0;
}
