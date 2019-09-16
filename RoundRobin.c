
//CODE BY KG
//LAB OS RR
//16 SEP 19
#include <stdio.h>
#include <stdlib.h>
int count=0;
typedef struct process{
    int bt;
    int at;
    int tat;
    int wt;
    int id;
    int lt;
    int status;
    int ft;
    struct process *next;

}process;

void addprocess(process *head,int art,int brt){
    process *temp=head;
    while(temp->next!=head&&temp->next->at<art){
        temp=temp->next;

    }

    process *newp=(process*)malloc(sizeof(process));
    newp->at=art;
    newp->bt=brt;
    newp->lt=brt;
    newp->status=1;
    newp->id=++count;
    process *t2=temp->next;
    temp->next=newp;
    newp->next=t2;




}
void printat(process *head){
    process* temp=head->next;
  while(temp!=head){
    printf("%d\t",temp->bt);
    temp=temp->next;
  }

}
void printft(process *head){
    process* temp=head->next;
  while(temp!=head){
    printf("%d\t",temp->ft);
    temp=temp->next;
  }

}
void performrr(process *head,int quantum){
process *temp=head->next;
int currtime=0;
while(isleft(head)==1){

    if(temp==head||temp->status==0){
        temp=temp->next;

    }
   else{ if(temp->lt<=quantum){

        currtime=currtime+temp->lt;
        temp->lt=0;
        temp->ft=currtime;
        temp->status=0;
    }
    else{
        temp->lt=temp->lt-quantum;
        currtime=currtime+quantum;


    }
    temp=temp->next;}

}


}

int isleft(process *head){
    process *temp=head->next;
 while(temp!=head){
    if(temp->status==1){
        return 1;
    }
    temp=temp->next;
 }
  return 0;


}
void addwttat(process *head){
   process *temp=head->next;
   while(temp!=head){
    temp->tat=temp->ft-temp->at;
    temp->wt=temp->tat-temp->bt;
    temp=temp->next;
   }



}

void printgantt(process *head){
printf("ID\tAT\tBT\tFT\tWT\tTAT\n");
process *temp=head->next;
while(temp!=head){
    printf("%d\t%d\t%d\t%d\t%d\t%d\n",temp->id,temp->at,temp->bt,temp->ft,temp->wt,temp->tat);
    temp=temp->next;
}

}

int main(){
    process *head=(process*)malloc(sizeof(process));
    head->at=-1;
    head->next=head;
    addprocess(head,3,4);
    addprocess(head,2,3);
    addprocess(head,0,6);
    performrr(head,7);
    addwttat(head);
    //printat(head);
   // printft(head);
    printgantt(head);







}
