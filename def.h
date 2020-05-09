#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  float val;
  struct node *U,*D,*L,*R; //up down left right will not be used in the demo
}node;
//double LL carring doubly LL(node)
typedef struct ll_carrier
{
  node *head;
  node *tail;
  int length,no_col; // for lenngth of each column
  struct ll_carrier * next;
  struct ll_carrier * prev;
}ll_carrier;

