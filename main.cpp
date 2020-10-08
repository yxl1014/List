#include <iostream>
using namespace std;

typedef struct Node{
    int num;
    char * username;
    char * password;
    Node * next;
} Node,List;

Node * head=NULL;
Node * tail=NULL;

int add_Node(int num,char* username,char* password)
{
    Node * select=head;
    while(1){
        if (select==NULL){
            break;
        }
        if(select->num==num){
            return -1;
        }
        select=select->next;
    }
    if(head==NULL){
        Node * p=(Node *)malloc(sizeof(Node));
        p->num=num;
        p->username=username;
        p->password=password;
        p->next=NULL;
        head=p;
        tail=p;
        return 1;
    }else{
        Node * p=(Node *)malloc(sizeof(Node));
        p->num=num;
        p->username=username;
        p->password=password;
        p->next=NULL;
        tail->next=p;
        tail=p;
        return 1;
    }
}
int delete_node(int num)
{
    Node * t=head;
    Node * tt;
    while(1){
        if (t==NULL){
            return -1;
        }
        if(t->num==num) {
            if (t == head) {
                head = t->next;
                free(t);
                return 1;
            }else if(t == tail){
                tail=tt;
                free(t);
                return 1;
            }else{
                tt->next=t->next;
                free(t);
                return 1;
            }
        }
        tt=t;
        t=t->next;
    }
}
Node * select_num(int num){
    Node * t=head;
    while(1){
        if (t==NULL){
            return NULL;
        }
        if(t->num==num) {
            return t;
        }
        t=t->next;
    }
}
Node * select_up(char * username,char * password){
    Node * t=head;
    while(1){
        if (t==NULL){
            return NULL;
        }
        if(t->username==username&&t->password==password) {
            return t;
        }
        t=t->next;
    }
}
int update_num(int num,Node * update){
    Node * t=head;
    while(1){
        if (t==NULL){
            return -1;
        }
        if(t->num==num) {
            if(update->num!=0)
                t->num=update->num;
            if(update->username!=0)
                t->username=update->username;
            if(update->password!=0)
                t->password=update->password;
            return 1;
        }
        t=t->next;
    }
}
int main() {
    return 0;
}
