#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "def.h"
#include "search.h"
#include "helper.h"
#include "insert_del.h"
#include "print.h"
#include "helper_main.h"
ll_carrier *T,*H;
double buffer = 0;

void main()
{
  double buffer;
  H = T = NULL;
  init_end(&H,&T);
  insert_end(H,H,0);
  int choice_main;
  int y_n;
  while(1)
  {
    printf("This main menu contains submenus\n");
    printf("Choice of submenus:\n1.Internal data related functions\n2.Search functions\n3.Insertion related function\n4.Deletion\n5.Print Related functions\n6.Buffer Related functions\n7.Exit\n: ");
    scanf("%d",&choice_main);
    switch(choice_main)
    {
      case 1:
        data_related(&H,&T,&buffer);
        break;
      case 2:
        search(&H,&T,&buffer);
        break;
      case 3:
        insert(&H,&T);
        break;
      case 4:
        if(total_cells(H)==1)
        {
          printf("\n\t\"Only one cell left, cant let you delete it!\"\n\n");
          break;
        }
        delete(&H,&T,&buffer);
        break;
      case 5:
        print(&H,&T);
        break;
      case 6:
        buffer_functions(&H,&T,&buffer);
        break;
      case 7:
        printf("\nWould you like to save this SpreadSheet as .csv file 1/0: ");
        scanf("%d",&y_n);
        if(y_n)
          save(H);
        exit(0);
      default:
        printf("Menu not defined!\n");
    }
  }
}
