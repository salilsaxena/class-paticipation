#include<stdio.h>
#include<stdlib.h>
int search_helper(ll_carrier* H,double ele)//tryng to give .2 digit precision only
{
  int f =  0;
  ll_carrier* right_trav = H;
  node* down_trav;
  while(right_trav)
  {
    down_trav = right_trav->head;
    while(down_trav)
    {
      if(down_trav->val <= ele+0.1 && down_trav->val >= ele-0.1)//only consider .1f
      {
        f = 1;
        return f;
      }
      down_trav = down_trav->D;
    }
    right_trav = right_trav->next;
  }
  return 0;//not found  
}
void pos(ll_carrier * H,double ele,int flag_all) //we will directly change the values of column and row
{
  // if flag_all == 0  the first position will only be printed out;
  int f = search_helper(H,ele);
  if(f==0)
  {
    printf("\t\'Not found\'\n");
    return ;
  }
  if(flag_all)
  {
    printf("\t[");
  }
  else
  {
    printf("\t");
  }
  int c=0,r=0;
  ll_carrier* right_trav = H;
  node* down_trav;
  while(right_trav)
  {
    c++;
    down_trav = right_trav->head;
    while(down_trav)
    {
        r++;
        //if((int)down_trav->val>=((int)ele)-1 && (int)down_trav->val <= ((int)ele)+1 )
        if(down_trav->val <= ele+0.1 && down_trav->val >= ele-0.1) 
        {
          printf("(%d,%d)",c,r);
          if(flag_all==0)
          {
            printf("\n");
            return;
          }
          printf(",");
        }
        down_trav = down_trav->D;
    }
    r = 0;
    right_trav = right_trav->next;
  }
  printf("]\n");
}

