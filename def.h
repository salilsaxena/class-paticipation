#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int val;
  struct node *U,*D,*L,*R; //up down left right will not be used in the demo
}node;
//double LL carring doubly LL(node)
typedef struct ll_carrier
{
  node *head;
  node *tail;
  int length; // for lenngth of each column
  struct ll_carrier * next;
  struct ll_carrier * prev;
}ll_carrier;
//length related functions
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

//Search functions start here

/*
 *  I didnt see the usage of `search_y`
 */

//int search_y(ll_carrier* node_inp,int ele)
//{
//  if(!node_inp)
//  {
//    printf("Empty Node!\nShouldn't have happened!");
//    exit(0);
//  }
//  int f = 0;
//  node *crt = node_inp->head;
//  while(crt)
//  {
//    if(crt->val == ele)
//    {
//        f = 1;
//        return 1;
//    }
//    crt = crt->D;
//  }
//  return 0;
//}
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
//Search functions end here
void change_ele(int x,int y,ll_carrier* H,int ele)
{
  node* crt = H->head;
  for(int i = 1;i<x;i++)
  {
    if(crt->R)
    {
      crt = crt->R;
    }
    else
    {
      printf("Index out of range\n");
      return ;
    }
  }
 for(int j = 1;j<y;j++)
 {
    if(crt->D)
    {
      crt = crt->D;
    }
    else
    {
      printf("Index out of range\n");
      return ;
    }
 }
 crt->val = ele;
}
//index finding algorightm starts now:

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
  printf("\n");
}
//index finding algoright ends now
ll_carrier* ret_col(ll_carrier* H,int column_no) //it wil return the ll_carrier from the given int 
// Helper function 
{
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
  return tmp;
}
void insert_col(ll_carrier* H,ll_carrier* node_inp,int ele) 
  // only to use it when all the columns ar ebalanced
  // do not use it after init_* it is not designed for NUll nodes
{
  ll_carrier* crt = H;
  node* tmp = NULL;
  while(crt)
  {
    crt->length = crt->length+1;
    tmp = ret_node();
    tmp->D = NULL;
    if(crt == node_inp)
    {
      tmp->val = ele;
    }
    else
      tmp->val = 0;

    tmp->U = crt->tail;
    crt->tail->D = tmp;
    crt->tail = tmp;
    if(crt->prev)//for left
    {
      crt->tail->L = crt->prev->tail;
      crt->prev->tail->R = crt->tail;
    }
    else
    {
        crt->tail->L = NULL;
    }
    //right condition wont be necessary as we are traversing from left there will be no right list so R will always be null 
    crt = crt->next;
  }
}


/*
  Have to define a seprate function for insertion in columns
*/



//to insert LR in insert_end
void insert_end(ll_carrier* H,ll_carrier *node_inp,int ele) // to insert ele at the end of ll_carrier's list(node)
{
  node_inp->length++;
  node* tmp = (node*)malloc(sizeof(node));
  tmp->val = ele;
  tmp->D = NULL;
  if(node_inp->head == NULL)
  {
    //list is empty
    node_inp->head = tmp;
    node_inp->tail = tmp;
    node_inp->head->U = NULL;
    //for left
    if(node_inp->prev != NULL)
    {
      node_inp->head->L = node_inp->prev->head;
      node_inp->prev->head->R = node_inp->head;
    }
    else
    {
      node_inp->head->L =NULL;
    }
    //for right
    if(node_inp->next)
    {
      node_inp->head->R = node_inp->next->head;
      node_inp->next->head->L = node_inp->head;
    }
    else
    {
      node_inp->head->R = NULL;
    }
  }
  else
  {
    node_inp->tail->D = tmp;
    tmp->U = node_inp->tail;
    node_inp->tail = tmp;
    if(node_inp->prev)
    {
      node_inp->tail->L = node_inp->tail->U->L->D;
      node_inp->tail->U->L->D->R = node_inp->tail;
    }
    else
    {
      node_inp->tail->L = NULL;
    }
    if(node_inp->next)
    {
      
      node_inp->tail->R = node_inp->tail->U->R->D;
      node_inp->tail->U->R->D->L = node_inp->tail;
    }
    else
    {
      node_inp->tail->R = NULL;
    }
  }
}
//have to perform a sanity check:
//if you want to insert in  a specific column then you must also run insert_eq()
void init_front(ll_carrier** list_h,ll_carrier** list_t)
{
  ll_carrier* tmp = (ll_carrier*)malloc(sizeof(ll_carrier));
  tmp->head = NULL;
  tmp->tail = NULL;
  tmp->length = 0;
  tmp->prev = NULL;
  if(*list_h == NULL)
  {
    tmp->next = NULL;
    *list_h = tmp;
    *list_t = tmp;
  }
  else
  {
    tmp->next = *list_h;
    (*list_h)->prev = tmp;
    *list_h = tmp;
    for(int i = 0;i<(*list_h)->next->length;i++)
    {
      insert_end(*list_h,tmp,0); // will also update tmp->length
    }
        //insertion of nodes is complete.
    //now comes the connecting part

  }
}
//would you like to build a insert_after?
void init_end(ll_carrier** list_h,ll_carrier** list_t) //it will add a node's h&t at the end of ll_carrier
{
  ll_carrier* tmp  = (ll_carrier*)malloc(sizeof(ll_carrier));
  tmp->head = NULL;
  tmp->tail = NULL;
  tmp->length = 0;
  tmp->next = NULL;
  if(*list_h == NULL) //if th original list was empty
  {
    tmp->prev = NULL;
    *list_h = tmp;
    *list_t = tmp;
  }
  else
  {

    tmp->prev = *list_t;
    (*list_t)->next = tmp;
    *list_t = tmp;
    for(int i = 0;i<(*list_h)->length;i++)
    {
      insert_end(*list_h,tmp,0);
    }
  }
}
//insertions in ll_carrier ends here.

void del_col(ll_carrier** H,ll_carrier** T,ll_carrier* node_inp) //to delete the whole column //perform error handling later
{
  ll_carrier* temp = node_inp;
  node* trav = node_inp->head;
  node *tmp;
  if(node_inp == *H && node_inp == *T)
  {
    //only a singe column is present
    //for now must not delete the whole column as the whole list sheet will becoe empty and have to run init_* again
    while(trav->D)
    {
      tmp = trav; 
      trav = trav->D;
      free(tmp);
    }
    (*H)->head = trav;
    trav->val = 0;//will leave 0 in the last cell 
  }
  else if(node_inp ==  *H || node_inp == *T)
  {
    if(node_inp ==*H)
    {
      *H = node_inp->next;
      node_inp->next->prev = NULL;
      while(trav)
      {
        tmp = trav;
        trav->R->L = NULL;
        trav = trav->D;
        free(tmp);
      }
      free(temp);
    }
    else
    {
      *T = node_inp->prev;
      node_inp->next = NULL;
      while(trav)
      {
        tmp = trav;
        trav->L->R = NULL;
        trav = trav->D;
        free(tmp);
      } 
      free(temp);
    }
  }
  
  else
  {
    node_inp->prev->next = node_inp->next; //error starts from here
    node_inp->next->prev = node_inp->prev;
    while(trav)
    {
      trav->L->R = trav->R;
      trav->R->L = trav->L;
      trav = trav->D;
    }
    //have insterleaved the pointers
    //now will free the pointers
    while(trav)
    {
      tmp = trav;
      trav = trav->D;
      free(tmp);
    }
    free(node_inp);
  }
}

//printing method starts here
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
