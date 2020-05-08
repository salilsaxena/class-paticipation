#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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
  int choice=-1,col;
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
      printf("\n\tEnter the column you want to print: ");
      scanf("%d",&col);
      print_node(ret_col(H,col));
      break;
    default:
      printf("\nWrong input\n");
  }
}
//so we have Max/Min/avg for column and row
void for_column()
{
  int y,choice2,y_n;
  float max,min,avg;
  printf("\t\t0.Back\n\t\t1.Minumum\n\t\t2.Maximum\n\t\t3.Avg\n\t\t:");
  scanf("%d",&choice2);
  switch(choice2)
  {
    case 0:
      break;
    case 1:
      printf("\t\tEnter the Coulmn number: ");
      scanf("%d",&y);
      min = minimum(y,H,0);
      if(min==INT_MAX)
      {
        printf("\tOut of Range\n");
        break;
      }
      printf("\t\tThe minimum value of Column %d is %.2f\n",y,min);
      break;
    case 2:
      print("\t\tEnter the Coulmn number: ");
      scanf("%d",&y);
      max = maximum(y,H,0);
      if(max==INT_MIN)
      {
        printf("\tOut of Range\n");
        break;
      }
      printf("\t\tThe maximum value of Column %d is %.2f\n",y,max);
      break;
    case 3:
      printf("\t\tEnter the Column number for avg: ");
      scanf("%d",&y);
      if(y>no_column(H))
      {
        printf("\tOut of range\n");
        break;
      }
      printf("\t\tWould you like to add it in the spreadsheet 1\\0: ");
      scanf("%d",&y_n); //y_n is not getting accepted.
      avg = avg_col(H,y);
      int choice2;
      printf("\t\tAvg of %d Column is: %.2f\n",y,avg);
      if(y_n==1)
      {
        printf("\t\tChoice:\n\t\t0.Back\n\t\t1.Add it to the End of Column\n\t\t2.Change the value of end of Column\n\t\t:");
        scanf("%d",&choice2);
        switch(choice2)
        {
          case 0:
            break;
          case 1:
            insert_col(H,y,avg);
            break;
          case 2:
            change_ele(y,H->length,H,avg);
            break;
          default:
            printf("No choice avliable\n");
        }
      }
      break;
  }
}
void for_row()
{
  int x,choice,y_n;
  float max,min,avg;
  printf("\t\t0.Back\n\t\t1.Maximum\n\t\t2.Minumum\n\t\t3.Avg");
  scanf("%d",&choice);
  switch(choice)
  {
    case 0:
      break;
    case 1:
      printf("\t\tEnter the Row number: ");
      scanf("%d",&x);
      min = minimum(x,H,1);
      if(min==INT_MAX)
      {
        printf("\tOut of Range\n");
        break;
      }
      printf("\t\tThe minimum value of Row %d is %.2f\n",x,min);
      break;
    case 2:
      print("\t\tEnter the Row number: ");
      scanf("%d",&x);
      max = maximum(x,H,1);
      if(max==INT_MIN)
      {
        printf("\tOut of Range\n");
        break;
      }
      printf("\t\tThe maximum value of Row %d is %.2f\n",x,max);
      break;
    case 3:
      printf("\t\tEnter the Row number for avg: ");
      scanf("%d",&x);
      if(x>no_column(H))
      {
        printf("\tOut of range\n");
        break;
      }
      printf("\t\tWould you like to add it in the spreadsheet 1\\0: ");
      scanf("%d",&y_n); //y_n is not getting accepted.
      avg = avg_row(H,x);
      int choice2;
      printf("\t\tAvg of %d column is: %.2f\n",x,avg);
      if(y_n==1)
      {
        printf("\t\tChoice:\n\t\t0.Back\n\t\t1.Add it to the End of Row\n\t\t2.Change the value of end of Row\n\t\t:");
        scanf("%d",&choice2);
        switch(choice2)
        {
          case 0:
            break;
          case 1:
            init_end(&H,&T);
            change_ele(no_column(H),x,H,avg);
            break;
          case 2:
            change_ele(no_column(H),x,H,avg);
            break;
          default:
            printf("No choice avliable\n");
        }
      }
      break;
  }
}
void data_related()
{
  int choice,x,y;
  printf("\n\tChoice:\n\t0.Back\n\t1.Length of each column\n\t2.Total no. of cells\n\t3.Column related data\n\t4.Row related Data\n\t:");
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
    case 3:
      for_column();
      break;
    case 4:
      for_row();
      break;
    default:
      printf("\tWrong input\n");
    }
}
void insert()
{
  int x,y,choice=-1,ele;
  while(choice!=0)
  {
    printf("\n\tChoice:\n\t0.back\n\t1.Change the value of cell\n\t2.Insert at the end of the column\n\t3.Insert a cell at specific position\n\t4.Insert an empty column at the front of Document\n\t");
    printf("5.Insert an empty column at the end of Document\n\t:");
    float av;
    //char y_n;
    int y_n;
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
        if(!pos_checker(x,y,H))
        {
          printf("Out of range\n");
          break;
        }
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
        //if(x>no_column(H))
        //{
        //  printf("Out of range\n");
        //  break;
        //}
        printf("\tEnter the y cordinate: ");
        scanf("%d",&y);
        //if(y>H->length)
        //{
        //  printf("Out of range\n");
        //  break;
        //}
        printf("\tEnter the value you want in that cell: ");
        scanf("%d",&ele);
        insert_pos(x,y,H,T,ele);
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
}
void delete()
{
  int choice,x,y;
  while(choice!=0) //a single cell case will never arrive
  {
    printf("\n\tChoice: \n\t0.Back\n\t1.Delete a column\n\t2.Delete a cell\n\t:");
    scanf("%d",&choice);
    switch(choice)
    {
      case 0:
        printf("\n");
        break;
      case 1:
        if(!H->next)
        {
          printf("\n\t\"Only one Column left, cant let you delete it\"\n\n");
          break;
        }
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
}
void main()
{
  H = T = NULL;
  init_end(&H,&T);
  insert_end(H,H,0);
  int choice_main;
  int y_n;
  while(1)
  {
    printf("This main menu contains submenus\n");
    printf("Choice of submenus:\n1.Internal data related functions\n2.Search functions\n3.Insertion related function\n4.Deletion\n5.Print Related functions\n6.Exit\n: ");
    scanf("%d",&choice_main);
    switch(choice_main)
    {
      case 1:
        data_related();
        break;
      case 2:
        search();
        break;
      case 3:
        insert();
        break;
      case 4:
        if(total_cells(H)==1)
        {
          printf("\n\t\"Only one cell left, cant let you delete it!\"\n\n");
          break;
        }
        delete();
        break;
      case 5:
        print();
        break;
      case 6:
        printf("\nWould you like to save this SpreadSheet as .csv file: ");
        scanf("%d",&y_n);
        if(y_n)
          save(H);
        exit(0);
      default:
        printf("Menu not defined!\n");
    }
  }
}
