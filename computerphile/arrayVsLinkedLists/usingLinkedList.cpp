
#include <stdio.h>
#include <stdlib.h>

struct linkedListItem{
  int p, q;
  linkedListItem *next;
  linkedListItem(int a=0, int b=0){
    this->p = a;
    this->q = b;
    this->next = NULL;
  }
};

int sumLinkedList(linkedListItem *head){
  int sum = 0;
  while (head!=NULL){
    sum+=head->p;
    head = head->next;
  }
  return sum;
}

int main(int argc, char **argv){
  int n = 100;
  linkedListItem *head = new linkedListItem;
  linkedListItem *curr = head;
  for (int i=0; i<n; i++){
    curr->next = new linkedListItem;
    curr = curr->next;
    curr->p = rand();
  }
  printf("%d\n", sumLinkedList(head->next));
  return 0;
}
