#include<stdio.h>
#include<stdlib.h>
#include "def.h"
#include "search.h"
#include "helper.h"
#include "insert_del.h"
#include "print.h"
ll_carrier *T,*H;
void search()
{
  float ele;
  int choice;
  printf("\n\tChoice: \n\t0.Back\n\t1.search first position of an element\n\t2.Search the whole block for an element\n\t:");
  scanf("%d",&choice);
  switch(choice)
  {
    case 0:
      printf("\n");
      break;
    case 1:
      printf("\tEnter the element you want to search: ");
      scanf("%f",&ele);
      pos(H,ele,0);
      break;
    case 2:
      printf("\tEnter the element you want to search: ");
      scanf("%f",&ele);
      pos(H,ele,1);
      break;
    default:
      printf("\tWorng input\n");
  }
}
void print()
{
  int choice,col;
  printf("\n\tChoice:\n\t0.Back\n\t1.Print the whole document\n\t2.Print a whole column\n\t:");
  scanf("%d",&choice);
  switch(choice)
  {
    case 0:
      printf("\n");
      break;
    case 1:
      print_block(H);
      break;
    case 2:
      printf("\nEnter the column you want to print: ");
      scanf("%d",&col);
      print_node(ret_col(H,col));
      break;
    default:
      printf("\nWrong input\n");
  }
}
void length_data()
{
  int choice;
  printf("\n\tChoice:\n\t0.Back\n\t1.Length of each column\n\t2.Total no. of cells\n\t:");
  scanf("%d",&choice);
  switch(choice)
  {
    case 0:
      printf("\n");
      break;
    case 1:
      printf("\n\t\"Length of each colummn is: %d\"\n\n",H->length);
      break;
    case 2:
      printf("\n\t\"Total number of Cells: %d\"\n\n",H->length * no_column(H));
      break;
    default:
      printf("\tWrong input\n");
    }
}
void insert()
{
  printf("\n\tChoice:\n\t0.back\n\t1.Change the value of cell\n\t2.Insert at the end of the column\n\t3.Insert a cell at specific position\n\t4.Insert an empty column at the front of Document\n\t");
  printf("5.Insert an empty column at end the of Document\n\t:");
  int x,y,choice,ele;
  scanf("%d",&choice);
  switch(choice)
  {
    case 0:
      printf("\n");
      break;
    case 1:
      printf("\tEnter the x cordinate: ");
      scanf("%d",&x);
      printf("\tEnter the y cordinate: ");
      scanf("%d",&y);
      printf("\tEneter the value you want to replace with: ");
      scanf("%d",&ele);
      change_ele(x,y,H,ele);
      break;
    case 2:
      printf("\tEnter the column number: ");
      scanf("%d",&x);
      printf("\tEnter element you want to insert: ");
      scanf("%d",&ele);
      insert_col(H,x,ele);
      break;
    case 3:
      printf("\tEnter the x cordinate: ");
      scanf("%d",&x);
      printf("\tEnter the y cordinate: ");
      scanf("%d",&y);
      printf("\tEnter the value you want in that cell: ");
      scanf("%d",&ele);
      insert_pos(x,y,H,ele);
      break;
    case 4:
      init_front(&H,&T);
      break;
    case 5:
      init_end(&H,&T);
      break;
    default:
      printf("\tWorng input\n");
  }
}
void delete()
{
  int choice,x,y;
  printf("\n\tChoice: \n\t0.Back\n\t1.Delete a column\n\t2.Delete a cell\n\t:");
  scanf("%d",&choice);
  switch(choice)
  {
    case 0:
      printf("\n");
      break;
    case 1:
      printf("\tEnter the column number you want to delete: ");
      scanf("%d",&x);
      del_col(&H,&T,ret_col(H,x));
      break;
    case 2:
      printf("\tEnter the x cordinate: ");
      scanf("%d",&x);
      printf("\tEnter the y cordinate: ");
      scanf("%d",&y);
      del_cell_pos(x,y,H);
      break;
    default:
      printf("\tWorng input\n");
  }
}
void main()
{
  H = T = NULL;
  init_end(&H,&T);
  insert_end(H,H,0);
  int choice_main;
  while(1)
  {
    printf("This main menu contains submenus\n");
    printf("Choice of submenus:\n1.Internal data related functions\n2.Search functions\n3.Insertion related function\n4.Deletion\n5.Print Related functions\n6.Exit\n: ");
    scanf("%d",&choice_main);
    switch(choice_main)
    {
      case 1:
        length_data();
        break;
      case 2:
        search();
        break;
      case 3:
        insert();
        break;
      case 4:
        delete();
        break;
      case 5:
        print();
        break;
      case 6:
        exit(0);
      default:
        printf("Menu not defined!\n");
    }
  }
}
