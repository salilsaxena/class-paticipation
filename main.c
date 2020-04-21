#include<stdio.h>
#include<stdlib.h>
#include"def.h"
void menu();
//newly added function: insert_pos del_col del_cell 
void main() 
{
  int choice;
  int x,y;//for coordinate;
  int key;//for search key;
  int ele;//element you want to insert
  ll_carrier *H,*T;
  H = T = NULL;
  init_end(&H,&T);
  insert_end(H,H,0);//BY default the sheet will contain only one cell with default value of 0
                    //This will definately change.
  while(1)
  {
    menu();
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        init_front(&H,&T);
        break;
      case 2:
        init_end(&H,&T);
        break;
      case 3:
        printf("Enter the x: ");
        scanf("%d",&x);
        printf("Enter the y");
        scanf("%d",&y);
        printf("Enter the element you want to insert: ");
        scanf("%d",&ele);
        change_ele(x,y,H,ele);
        break;
      case 4:
        printf("The x co-ordinate you want: ");
        scanf("%d",&x);
        printf("The y co-ordinate you want: ");
        scanf("%d",&y);
        printf("Enter the elemt you want to insert: ");
        scanf("%d",&ele);
        insert_pos(x,y,H,ele);
        break;
      case 5: 
        printf("Lenght of each column: %d\n",H->length);
        break;
      case 6: 
        printf("Number of cloumns: %d\n",no_column(H));
        break;
      case 7:
        printf("Enter the element you want to search: ");
        scanf("%d",&ele);
        pos(H,ele,1);
        break;
      case 8:
        printf("Enter the column number you want to print: ");
        scanf("%d",&x);
        print_node(ret_col(H,x));
        break;
      case 9: 
        print_block(H);
        break;
      case 10:
        exit(0);
      default: 
        exit(0);
    }
  }  
}
void menu()
{
  printf("Menu:\n1.insert a row at front\n2.Insert a row at back\n3.Change element with given Co-orinate\n4.Insert at the end of column\n5.length of each row\n6.No of cloumns\n6.No. of total cellsn");
  printf("7.Position of given element\n8.print a columns\n9.print the whole sheet\n10.Exit\n:");
}
