#include<stdio.h>
#include<stdlib.h>
//Search functions start here
int search_All(ll_carrier* H,int ele)
//complexity would be n**2
// any suggestions for lowering it. PLS note we cant sort the LLs
{
  //first right and then downward
  if(H)
  {
    int f = 0;
    ll_carrier* right_trav = H;
    node* down_trav;
    while(right_trav && !f)
    {
      // printf("%d\n",)
      down_trav = right_trav->head;
      while(down_trav && !f)
      {
          if(down_trav->val == ele)
          {
            f = 1;
          }
          down_trav = down_trav->D;
      }
      right_trav = right_trav->next;
    }
    return f;
  }
}
void pos(ll_carrier * H,int ele,int flag_all) //we will directly change the values of column and row
{
  // if flag_all == 0  the first position will only be printed out;
  int f = search_All(H,ele);
  if(f==0)
  {
    printf("Not found\n");
    return ;
  }
  if(flag_all)
  {
    printf("\n[");
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
        if(down_trav->val == ele)
        {
          printf("(%d,%d)",r,c);
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