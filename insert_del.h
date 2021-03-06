#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void init_end(ll_carrier**,ll_carrier**);
void init_front(ll_carrier**,ll_carrier**);

void change_ele(int x,int y,ll_carrier* H,double ele)
{
  //if(!pos_checker(x,y,H))
  //{
  //  printf("Out of Range!\n");
  //  return ;
  //}
  node* crt = H->head;
  for(int i = 1;i<x;i++)
  {
    crt = crt->R;
  }
  for(int j = 1;j<y;j++)
  {
    crt = crt->D;
  }
  crt->val = ele;
}
void insert_col(ll_carrier* H,int x,double ele)
{
  if(x > no_column(H))
  {
    printf("Out of Range!");
    return ;
  }
  ll_carrier* ref = ret_col(H,x);
  ll_carrier* crt = H;
  node* tmp = NULL;
  while(crt)
  {
    crt->length = crt->length+1;
    tmp = ret_node();
    tmp->D = NULL;
    if(crt == ref)
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
void insert_pos_col(int x,int y,ll_carrier* H,ll_carrier* T,double ele)
{
  ll_carrier* crt = H;
  if(x>no_column(H))
  {
    init_end(&H,&T);
    x = no_column(H);
    crt = T;
  }
  else
  {
    crt = ret_col(H,x);
  }
  if(y>H->length)
  {
    y = H->length+1;
  }
  insert_col(H,1,0);
  double temp,t;
  node* tmp = H->head;
  tmp = crt->head;
  for(int j = 0; j<y-1;j++)
  {
    tmp = tmp->D;
  }
  temp = tmp->val;
  tmp->val = ele;
  tmp = tmp->D;
  while(tmp)
  {
    t = tmp->val;
    tmp->val = temp;
    temp = t;
    tmp = tmp->D;
  }
}
void insert_pos_row(int x,int y,ll_carrier* H,ll_carrier* T,double ele)
{
  ll_carrier* crt = H;
  init_end(&H,&T);
  if(x>no_column(H))
  {
    x = no_column(H)+1;
    crt = T;
  }
  else
  {
    crt = ret_col(H,x);
  }
  if(y>H->length)
  {
    insert_col(H,1,0);
    y = H->length;
  }
  double temp,t;
  node* tmp = H->head;
  tmp = crt->head;//tmp will reach till the position 
  for(int j = 0;j<y-1;j++)
  {
    tmp = tmp->D;
  }
  temp = tmp->val;
  tmp->val = ele;
  tmp = tmp->R;
  while(tmp)
  {
    t = tmp->val;
    tmp->val = temp;
    temp = t;
    tmp = tmp->R;
  }

}
void insert_end(ll_carrier* H,ll_carrier *node_inp,double ele) // to insert ele at the end of ll_carrier's list(node)
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
    (*list_h)->no_col = 1;
  }
  else
  {
    int temp = (*list_h)->no_col;
    tmp->next = *list_h;
    (*list_h)->prev = tmp;
    *list_h = tmp;
    for(int i = 0;i<(*list_h)->next->length;i++)
    {
      insert_end(*list_h,tmp,0); // will also update tmp->length
    }
    //insertion of nodes is complete.
    //now comes the connecting part
    (*list_h)->no_col = temp+1;

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
    (*list_h)->no_col = 1;
  }
  else
  {
    (*list_h)->no_col++;
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
   //check if: when invalid input:-> does it go till the end.
  if(!node_inp)
  {
    //printf("Wrong input\n");
    return ;
  }
  int t = (*H)->no_col;
  ll_carrier* temp = node_inp;
  node* trav = node_inp->head;
  node *tmp;
  if(node_inp == *H && node_inp == *T)//was not our initial motive, but let it stay 
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
    (*H)->no_col = 1;
    return ;
  }
  else if(node_inp ==  *H || node_inp == *T)
  {
    if(node_inp ==*H)
    {
      *H = node_inp->next;
      while(trav)
      {
        tmp = trav;
        trav->R->L = NULL;
        trav = trav->D;
        free(tmp);
      }
      free(temp);
      (*H)->prev = NULL;
    }
    else
    {
      *T = node_inp->prev;
      while(trav)
      {
        tmp = trav;
        trav->L->R = NULL;
        trav = trav->D;
        free(tmp);
      }
      free(temp);
      (*T)->next = NULL;
    }
    // (*H)->no_col = t-1;
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
  (*H)->no_col = t-1;
}
void del_row(ll_carrier** H,ll_carrier** T,int y)
{
	node* crt = (*H)->head;
	node* free_temp;
	ll_carrier* temp = *H;

	if((*H)->head == (*H)->tail) // if only one row is there
	{
    *H = *T = NULL;
    init_end(H,T);
    insert_end(*H,*H,0);
		//while(crt)
		//{
		//	crt->val = 0;
		//	crt = crt->R;
		//}
	}
	else if(y==1) //first row
	{
    (*H)->length--;
		while(crt)
		{
			free_temp = crt;
			crt->D->U = NULL;
			temp->head = crt->D;
			crt = crt->R;
			temp = temp->next;
			free(free_temp);
		}
	}
	else if(y==(*H)->length)//last row
	{    
    (*H)->length--;
    crt = (*H)->tail;
		while(crt)
		{
			free_temp = crt;
			crt->U->D = NULL;
			temp->tail = crt->U;
			crt = crt->R;
			temp = temp->next;
			free(free_temp);
		}
	}	

	else // adny other row
	{
    for(int i = 1;i<y;i++)
	  {	
		  crt = crt->D;
	  }//readched the row
    (*H)->length--;
		while(crt)
		{
			free_temp = crt;
			crt->U->D = crt->D;
			crt->D->U = crt->U;
			crt = crt->R;
			free(free_temp);
		}
	}

}
double del_cell_pos_col(int x,int y,ll_carrier* H)
{
  double ret = 0;
  //if(!pos_checker(x,y,H))
  //{
  //  printf("\nOut of Range!\n");
  //  return INT_MAX;//INT_MAX;
  //}
  ll_carrier* col = ret_col(H,x);
  node* crt = col->head;
  for(int i=0;i<y-1;i++)
  {
    crt = crt->D;
  }
  ret = crt->val;
  while(crt->D)
  {
    crt->val = crt->D->val;
    crt = crt->D;
  }
  //col->tail->val = 0;
  crt->val = 0;
  return ret;
}
double del_cell_pos_row(int x,int y,ll_carrier* H)
{
  double ret = 0;
  ll_carrier* col= ret_col(H,x);
  node* crt = col->head;
  for(int i = 0;i<y-1;i++)
  { 
    crt = crt->D;
  }
  ret = crt->val;
  while(crt->R)
  {
    crt->val = crt->R->val;
    crt = crt->R;
  }
  crt->val = 0;
  return ret;
}
