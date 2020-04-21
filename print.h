#include<stdio.h>
#include<stdlib.h>
void print_node(ll_carrier* node_inp) // to print a list(node) carried inside ll_carrier.
{
  node* crt = node_inp->head;
  if(!crt)
    printf("Empty\n");
  else
  {
    while(crt)
    {
      printf("%d,",crt->val);
      crt = crt->D;
    }
    printf("\n");
  }
}
void print_block(ll_carrier* H)
{
  printf("\n\n");
  node* crt_v = H->head;
  node* crt_h = NULL;
  //printf("\n%d\'\n",crt_v->val);
  while(crt_v)
  {
    crt_h = crt_v;
    while(crt_h)
    {
      printf("%d\t",crt_h->val);
      crt_h = crt_h->R;
    }
    printf("\n");
    crt_v = crt_v->D;
  }
  printf("\n\n");
}
