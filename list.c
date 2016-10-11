#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next; };

void print_list( struct node *n ){
  struct node *cur = n;
  while (cur){
    printf("%d ",cur->i);
    cur = cur->next;
  }
  printf("\n");
}

struct node *insert_front(int j, struct node *n){
  struct node *head = (struct node *)malloc(sizeof(struct node));
  head->i = j;
  head->next = n;
  return head;
}

struct node* free_list(struct node *n) {
  if (n->next)
    free_list(n->next);
  free(n);
  return NULL;
}

int main(){
  printf("---RUN---\n");
  struct node *noo;
  noo = (struct node *)malloc(sizeof(struct node));
  noo->i = 1;    
  noo->next = NULL;
  printf("node noo: ");
  print_list(noo);
  int h = 0;
  printf("insert_front(int h = %d, noo)\n",h);
  struct node *hoo = insert_front(h,noo);
  printf("new node hoo: ");
  print_list(hoo);
  printf("free_list(hoo)\n");  
  //print_list(free_list(hoo)); //  segmentation fault
  free_list(hoo);
  printf("print_list(hoo): seg fault\n");
  //print_list(hoo);
  return 0;
}
