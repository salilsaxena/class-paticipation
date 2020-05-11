#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
char* int2str(int val, int base)
{
	static char buf[32] = {0};
	int i = 30;
	for(; val && i ; --i, val /= base)
		buf[i] = "0123456789abcdef"[val % base];
	return &buf[i+1];
}
int no_column(ll_carrier* H)
{
  return H->no_col;
  //int c = 0;
  //ll_carrier* crt = H;
  //while(crt)
  //{
  //  c++;
  //  crt = crt->next;
  //}
  //return c;
}
//int single_cell(ll_carrier* H)
//{
//  if(!H->next && H->length==1)
//  {
//    return 1;
//  }
//  return 0;
//}
int total_cells(ll_carrier* H) 
{
  int c = H->length;
  c = c*no_column(H);
  return c;
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
void insert_col(ll_carrier*,int,double);
void change_ele(int,int,ll_carrier*,double);
//just adding them for safety
double avg_col(ll_carrier* H,int col)
{
  ll_carrier* cols = ret_col(H,col);
  double avg;
  node* crt =cols->head;
  while(crt)
  {
    avg += crt->val;
    crt = crt->D;
  }
  avg = avg/cols->length;
  return avg;
}
double avg_row(ll_carrier* H,int row)
{
  int ref = 0;
  node* crt = H->head;
  while(ref!=row-1)
  {
    ref++;
    crt = crt->D;
  }
  double avg = 0;
  while(crt)
  {
    avg+=crt->val;
    crt = crt->R;
  }
  avg = avg/no_column(H);
  return avg;
}
void save(ll_carrier* H)
{
  char file_name[30];
  printf("Enter the name of the file: ");
  scanf("%s",file_name);
  strcat(file_name,".csv");
  FILE* f = fopen(file_name,"w");
  node* tmp,*crt = H->head;
  while(crt)
  {
    tmp = crt;
    while(tmp)
    {
      if(tmp->R)
      {
        fprintf(f,"%lf,",tmp->val);
      }
      else
      { 
        fprintf(f,"%lf",tmp->val);
      }
      tmp = tmp->R;
    }
    fprintf(f,"\n");
    crt = crt->D;
  }
}
double maximum(int input,ll_carrier* H,int row_flag)//if row_flag==1 then max of row is considered
{
  node* crt = H->head;
  int ref = 0;
  double max = INT_MIN;
  if(row_flag)
  {
    if(input > H->length || input <= 0)
    {
      return INT_MIN;//out of range
    }
    while(ref!=input-1) 
    {
      ref++;
      crt = crt->D;
    }
    while(crt)
    {
      if(max<crt->val)
      {
        max = crt->val;
      }
      crt = crt->R;
    }
  }
  else
  {
    if(input > no_column(H) || input <= 0)
    {
      return INT_MIN;//out of range
    }
    while(ref!=input-1)
    {
      ref++;
      crt = crt->R;
    }
    while(crt)
    {
      if(max<crt->val)
      {
        max = crt->val;
      }
      crt = crt->D;
    }
  }
  return max;
}
double minimum(int input,ll_carrier* H ,int row_flag)//input: maybe row or column
{
  node* crt = H->head;
  int ref = 0;
  double min = INT_MAX;
  if(row_flag)
  {
    if(input > H->length || input <= 0)
    {
      return INT_MAX;//out of range
    }
    while(ref!=input-1 && crt) //just for the sanity check
    {
      ref++;
      crt = crt->D;
    }
    while(crt)
    {
      if(min>crt->val)
      {
        min = crt->val;
      }
      crt = crt->R;
    }
  }
  else
  {
    if(input > no_column(H)|| input <= 0)
    {
      return INT_MAX;//out of range
    }
    while(ref!=input-1 && crt->R)
    {
      ref++;
      crt = crt->R;
    }
    while(crt)
    {
      if(crt->val!=0)
      {
        if(min>crt->val)
        {
          min = crt->val;
        }
      }
      crt = crt->D;
    }
  }
  if(min==INT_MAX)
  {
    return 0;
  }
  return min;
}
double ret_val(int x,int y,ll_carrier* H)
{
  node* crt = H->head;
  for(int i = 1;i<x;i++)
    crt = crt->R;
  for(int j = 1;j<y;j++)
    crt = crt->D;
  return crt->val;
}
void sum_sub_cell(ll_carrier* H,double *buffer)
{
  char op; 
  int x,y;
  double sum=0,temp=0;
  while(op!='0')
  {
    printf("\tEnter the operation you want, \'0\' to stop it: ");
    scanf(" %c",&op);
    if(op=='0')
    {
      printf("\n\tThe final answer is: %.2lf\n",sum);
      *buffer = sum;
      return ;
    }
    printf("\tEnter the postion of cell x: ");
    scanf("%d",&x);
    printf("\tEnter the postion of cell y: ");
    scanf("%d",&y);

    if(!pos_checker(x,y,H))
    {
      op = '0';
      printf("\t\nEntry Out of Range!\n\tSaved in Buffer.\n");
      *buffer = sum;
      return ;
    }
    temp = ret_val(x,y,H); 
    switch(op)
    {
      case '+': 
        sum+=temp;
        break;
      case '-':
        sum-=temp;
        break;
      default: 
        printf("\n\tnot valid\n");  
    }
  }
}
