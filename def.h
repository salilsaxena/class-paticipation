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
//function defination:
// int no_column(ll_carrier* H);
// int total_cells(ll_carrier* H);
// int max_length(ll_carrier* H);
// ll_carrier* ret_col(ll_carrier* H,int column_no);
// node* ret_node();
// int pos_checker(int x,int y,ll_carrier* H);
// //length + helper
//
// //serach
// int search_All(ll_carrier* H,int ele);
// void pos(ll_carrier * H,int ele,int flag_all);
// //search
//
// //insert_del
// void change_ele(int x,int y,ll_carrier* H,int ele);
// void insert_pos(int x,int y,ll_carrier* H,int ele);
// void insert_end(ll_carrier* H,ll_carrier *node_inp,int ele);
// void init_front(ll_carrier** list_h,ll_carrier** list_t);
// void init_end(ll_carrier** list_h,ll_carrier** list_t);
// void del_col(ll_carrier** H,ll_carrier** T,ll_carrier* node_inp);
// void del_cell_pos(int x,int y,ll_carrier* H);
// void insert_col(ll_carrier* H,ll_carrier* node_inp,int ele);
// //insert_del
//
// //print
// void print_block(ll_carrier* H);
// void print_node(ll_carrier* node_inp);
//print
