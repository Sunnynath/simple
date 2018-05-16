#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}slist;

//adding element in linked list

slist* add_element(slist * head,int val){
    
    slist* ptr=head,*new=NULL;
    if(head==NULL){
        new=malloc(sizeof(slist));
        new->data=val;
        new->next=NULL;
        head=new;
        return head;
    }
    while(ptr->next!=NULL){
        ptr=ptr->next;
        
    }
    new=malloc(sizeof(slist));
    new->data=val;
    new->next=NULL;
    ptr->next=new;
    return head;
}

slist* sort_link(slist* head){

    slist* start=head;
    slist* tmp=head,*prev=NULL;
    
    while(head!=NULL){
        tmp=head;
        while(tmp!=NULL && tmp->next!=NULL){
            if(tmp->next->data<head->data){
                slist* t1=tmp->next;
                tmp->next=tmp->next->next;
                t1->next=head;
                head=t1;
            }
            else{
                tmp=tmp->next;
            }
        }
        if(prev !=NULL){
            prev->next=head;
        }
        prev=head;
        head=head->next;
    }
    
    return start;
}

void print_list(slist* head){
        
        slist* ptr=head;
        if(head==NULL){
            printf("list is empty\n");
            return;
        }else{
            while(ptr!=NULL){
                
                printf("%d ",ptr->data);
                ptr=ptr->next;
            }
            printf("\n");
        }
        
    }

int main(){
    
    slist* head=NULL;
    head=add_element(head,50);
    head=add_element(head,40);
    head=add_element(head,30);
    head=add_element(head,20);
    head=add_element(head,10);
    
    print_list(head);
     head=sort_link(head);
    print_list(head);
}

