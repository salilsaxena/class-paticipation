#include<stdio.h>
#include<stdlib.h>
void print_node(ll_carrier* node_inp) // to print a list(node) carried inside ll_carrier.
{
  for(int i = 0 ;i<50;i++)
  {
    printf("-");
  }
  printf("\n");
  node* crt = node_inp->head;
  if(!crt)
    printf("Empty\n");
  else
  {
    while(crt)
    {
      printf("%.2f,",crt->val);
      crt = crt->D;
    }
    printf("\n");
  }
  for(int i = 0 ;i<50;i++)
  {
    printf("-");
  }
  printf("\n");
}
void print_block(ll_carrier* H)
{
  for(int i = 0 ;i<50;i++)
  {
    printf("-");
  }
  printf("\n");
  node* crt_v = H->head;
  node* crt_h = NULL;
  int upper_ind=1,left_ind=1;
  int flag_v = 0,flag_h = 0;
  printf("   \t");
  for(int i = 0;i<no_column(H);i++)
  {
    printf("%d\t",i+1);
  }
  printf("\n");
  //
  for(int i = 0;i<5+9*no_column(H);i++)
  {
    printf("-");
  }
  printf("\n");
  while(crt_v)
  {
    printf("%-4s|\t",int2str(left_ind,10)); //itoa is a self made fuction which converts int to str, can be found in helper.h
    left_ind++;
    crt_h = crt_v;
    while(crt_h)
    {
      printf("%.2f\t",crt_h->val);
      crt_h = crt_h->R;
    }
    printf("\n");
    crt_v = crt_v->D;
  }
  for(int i = 0 ;i<50;i++)
  {
    printf("-");
  }
  printf("\n");
}
