#include<stdio.h>
#include<stdlib.h>
#include"def.h"
void main()
{
  ll_carrier *H,*T;
  H = T = NULL;
  init_front(&H,&T);
  insert_end(H,H,1);
  for(int i = 0;i<9;i++)
  {
    insert_col(H,H,i+2);
  }
  print_block(H);
  init_end(&H,&T);
  init_front(&H,&T);
  change_ele(1,6,H,12);
  change_ele(3,3,H,13);
  change_ele(1,2,H,14);
  change_ele(3,9,H,15);
  print_block(H);
  del_col(&H,&T,H);//doesnt work with ends of ll_carrier
  //print_node(H->next->next);
  //print_block(H->next);
  print_block(H);
  insert_col(H,H,17);
  print_block(H);
  //pos(H,7,1);
  printf("%p\n",T->tail->R);
}

