#include<stdio.h>
#include<stdlib.h>
char* itoa(int val, int base)
{
	static char buf[32] = {0};
	int i = 30;
	for(; val && i ; --i, val /= base)
		buf[i] = "0123456789abcdef"[val % base];
	return &buf[i+1];
}
int no_column(ll_carrier* H)
{
  int c = 0;
  ll_carrier* crt = H;
  while(crt)
  {
    c++;
    crt = crt->next;
  }
  return c;
}
int total_cells(ll_carrier* H) 
{
  int c = H->length;
  c = c*no_column(H);
  return c;
}
int max_length(ll_carrier* H)
{
  int len = 0;
  if(!H)
  {
    return 0;
  }
  else
  {
    ll_carrier* crt = H;
    while(crt)
    {
      if(len<crt->length)
      {
       len = crt->length;
      }
      crt = crt->next;
    }
    return len;
  }
}
ll_carrier* ret_col(ll_carrier* H,int column_no) //it wil return the ll_carrier from the given int 
// Helper function 
{
  if(column_no > no_column(H))
  {
    printf("Out of Range\n");
    return NULL;
  }
  ll_carrier* crt = H;
  for(int i = 1;i<column_no;i++)
  {
    crt = crt->next;
  }
  return crt;
}
node* ret_node()//helper function 
{
  node* tmp = (node*)malloc(sizeof(node));
  tmp->R = tmp->L = tmp->U = tmp->D = NULL;
  return tmp;
}
int pos_checker(int x,int y,ll_carrier* H)
{
  if(x > no_column(H) || y > H->length)
    return 0;
  else if(x < 0 || y < 0)
    return 0;
  else 
    return 1;
}
