#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void search(ll_carrier** H,ll_carrier ** T,double* buffer)
{
  double ele;
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
      scanf("%lf",&ele);
      *buffer = ele;
      pos(*H,ele,0);
      printf("\tValue saved to Bufer\n");
      break;
    case 2:
      printf("\tEnter the element you want to search: ");
      scanf("%lf",&ele);
      *buffer = ele;
      pos(*H,ele,1);      
      printf("\tValue saved to Bufer\n");
      break;
    default:
      printf("\tWorng input\n");
  }
}
void print(ll_carrier** H,ll_carrier ** T)
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
      print_block(*H);
      break;
    case 2:
      printf("\n\tEnter the column you want to print: ");
      scanf("%d",&col);
      if(col<=0 || col>no_column(*H))
      {
        printf("Out of Range\n");
        break; 
      }
      print_node(ret_col(*H,col));
      break;
    default:
      printf("\nWrong input\n");
  }
}
//so we have Max/Min/avg for column and row
void for_column(ll_carrier** H,ll_carrier ** T,double * buffer)
{
  int x,choice2,y_n;
  double max,min,avg;
  printf("\t\t0.Back\n\t\t1.Minumum\n\t\t2.Maximum\n\t\t3.Avg\n\t\t:");
  scanf("%d",&choice2);
  switch(choice2)
  {
    case 0:
      break;
    case 1:
      printf("\t\tEnter the Coulmn number: ");
      scanf("%d",&x);
      min = minimum(x,*H,0);
      if(min==INT_MAX)
      {
        printf("\tOut of Range\n");
        break;
      }
      *buffer = min;//buffer!=INT_MAX
      printf("\t\tThe minimum value of Column %d is %.2lf\n",x,min);      
      printf("\t\tValue saved to Bufer\n");
      break;
    case 2:
      printf("\t\tEnter the Coulmn number: ");
      scanf("%d",&x);
      max = maximum(x,*H,0);
      if(max==INT_MIN)
      {
        printf("\tOut of Range\n");
        break;
      }
      *buffer = max;
      printf("\t\tThe maximum value of Column %d is %.2lf\n",x,max);
      printf("\t\tValue saved to Bufer\n");
      break;
    case 3:
      printf("\t\tEnter the Column number for avg: ");
      scanf("%d",&x);
      if(x>no_column(*H) || x<=0)
      {
        printf("\tOut of range\n");
        break;
      }
      avg = avg_col(*H,x);
      printf("\t\tAvg of %d Column is: %.2lf\n",x,avg);
      printf("\t\tWould you like to add it in the spreadsheet 1\\0: ");
      scanf("%d",&y_n); //y_n is not getting accepted.
      int choice2;
      if(y_n==1)
      {
        printf("\t\tChoice:\n\t\t0.Back\n\t\t1.Add it to the End of Column\n\t\t2.Change the value of end of Column\n\t\t:");
        scanf("%d",&choice2);
        switch(choice2)
        {
          case 0:
            *buffer = avg;
            printf("\t\tValue saved to Bufer\n");
            break;
          case 1:
            insert_col(*H,x,avg);
            break;
          case 2:
            change_ele(x,(*H)->length,*H,avg);
            break;
          default:
            printf("No choice avliable\n");
        }
      }
      else
      {
        *buffer = avg;
        printf("\t\tValue saved to Bufer\n");
      }
      break;
    default: 
      printf("\tInvalid SubMenu\n");
  }
}
void for_row(ll_carrier** H,ll_carrier ** T,double* buffer)
{
  int y,choice,y_n;
  double max,min,avg;
  printf("\t\t0.Back\n\t\t1.Minumum\n\t\t2.Maximum\n\t\t3.Avg\n\t\t:");
  scanf("%d",&choice);
  switch(choice)
  {
    case 0:
      break;
    case 1:
      printf("\t\tEnter the Row number: ");
      scanf("%d",&y);
      min = minimum(y,*H,1);
      if(min==INT_MAX)
      {
        printf("\tOut of Range\n");
        break;
      }
      *buffer = min;
      printf("\t\tThe minimum value of Row %d is %.2lf\n",y,min);
      printf("\t\tValue saved to Bufer\n");
      break;
    case 2:
      printf("\t\tEnter the Row number: ");
      scanf("%d",&y);
      max = maximum(y,*H,1);
      if(max==INT_MIN)
      {
        printf("\tOut of Range\n");
        break;
      }
      *buffer = max;
      printf("\t\tThe maximum value of Row %d is %.2lf\n",y,max);
      printf("\t\tValue saved to Bufer\n");
      break;
    case 3:
      printf("\t\tEnter the Row number for avg: ");
      scanf("%d",&y);
      if(y>(*H)->length || y<=0)
      {
        printf("\tOut of range\n");
        break;
      }
      avg = avg_row(*H,y);
      printf("\t\tAvg of %d Row is: %.2lf\n",y,avg);
      printf("\t\tWould you like to add it in the spreadsheet 1\\0: ");
      scanf("%d",&y_n); //y_n is not getting accepted.
      int choice2;
      if(y_n==1)
      {
        printf("\t\tChoice:\n\t\t0.Back\n\t\t1.Add it to a new cell at the end of Row\n\t\t2.Change the value of end of Row\n\t\t:");
        scanf("%d",&choice2);
        switch(choice2)
        {
          case 0:
            *buffer = avg;
            printf("\t\tValue saved to Bufer\n");
            break;
          case 1:
            init_end(H,T);
            change_ele(no_column(*H),y,*H,avg);
            break;
          case 2:
            change_ele(no_column(*H),y,*H,avg);
            break;
          default:
            printf("No choice avliable\n");
        }
      }
      else
      {
        *buffer = avg;
        printf("\t\tValue saved to Bufer\n");
      }
      break;
    default: 
      printf("\tInvalid SubMenu\n");
  }
}
void data_related(ll_carrier** H,ll_carrier ** T,double* buffer)
{
  int choice,x,y;
  printf("\n\tChoice:\n\t0.Back\n\t1.Length of each column\n\t2.Total no. of cells\n\t3.Column related data\n\t4.Row related Data\n\t5.Add or substract values of cells\n\t:");
  scanf("%d",&choice);
  switch(choice)
  {
    case 0:
      printf("\n");
      break;
    case 1:
      printf("\n\t\"Length of each colummn is: %d\"\n\n",(*H)->length);
      break;
    case 2:
      printf("\n\t\"Total number of Cells: %d\"\n\n",(*H)->length * no_column(*H));
      break;
    case 3:
      for_column(H,T,buffer);
      break;
    case 4:
      for_row(H,T,buffer);
      break;
    case 5: 
      print_block(*H);
      sum_sub_cell(*H,buffer);
      break;
    default:
      printf("\tWrong input\n");
    }
}
void insert(ll_carrier** H,ll_carrier ** T)
{
  int x,y,choice=-1;
  double ele;
  while(choice!=0)
  {
    printf("\n\tChoice:\n\t0.back\n\t1.Change the value of cell\n\t2.Insert at the end of the column\n\t3.Insert a new cell at specific position\n\t4.Insert an empty column at the front of Document\n\t");
    printf("5.Insert an empty column at the end of Document\n\t6.Insert a new row at the the end of SpreadSheet\n\t:");
    double av;
    //char y_n;
    int y_n;
    int choice2;
    scanf("%d",&choice);
    switch(choice)
    {
      case 0:
        printf("\n");
        break;
      case 1:
        printf("\tEnter the x cordinate: ");
        scanf("%d",&x);
        if(x<=0 || x>no_column(*H))
        {
          printf("Out of Range\n");
          break;
        }
        printf("\tEnter the y cordinate: ");
        scanf("%d",&y);
        if(y<=0 || y>(*H)->length)
        {
          printf("Out of Range\n");
          break;
        }
        printf("\tEneter the value you want to replace with: ");
        scanf("%lf",&ele);
        if(!pos_checker(x,y,*H))
        {
          printf("Out of range\n");
          break;
        }
        change_ele(x,y,*H,ele);
        break;
      case 2:
        printf("\tEnter the column number: ");
        scanf("%d",&x);
        if(x<=0 || x>no_column(*H))
        {
          printf("Out of Range\n");
          break;
        }
        printf("\tEnter element you want to insert: ");
        scanf("%lf",&ele);
        insert_col(*H,x,ele);
        break;
      case 3:
        printf("\t\t0.Back\n\t\t1.Shift All cells Row Wise\n\t\t2.Shift All cells Column Wise\n\t\t:");
        scanf("%d",&choice2);
        switch(choice2)
        {
          case 0:
            break;
          case 1: 
            printf("\tEnter the x cordinate: ");
            scanf("%d",&x);
            printf("\tEnter the y cordinate: ");
            scanf("%d",&y);
            printf("\tEnter the value you want in that cell: ");
            scanf("%lf",&ele);
            insert_pos_row(x,y,*H,*T,ele);
            break;
          case 2:
            printf("\tEnter the x cordinate: ");
            scanf("%d",&x);
            printf("\tEnter the y cordinate: ");
            scanf("%d",&y);
            printf("\tEnter the value you want in that cell: ");
            scanf("%lf",&ele);
            insert_pos_col(x,y,*H,*T,ele);
            break;
        }
        //insert_pos(x,y,*H,*T,ele);
        break;
      case 4:
        init_front(H,T);
        break;
      case 5:
        init_end(H,T);
        break;
      case 6:
        insert_col(*H,1,0);
        break;
      default:
        printf("\tWorng input\n");
    }
  }
}
void delete(ll_carrier** H,ll_carrier ** T,double* buffer)
{
  int choice=-1,x,y,choice2;
  double temp;
  while(choice!=0) //a single cell case will never arrive
  {
    printf("\n\tChoice: \n\t0.Back\n\t1.Delete a column\n\t2.Delete a row\n\t3.Delete a cell\n\t:");
    scanf("%d",&choice);
    switch(choice)
    {
      case 0:
        printf("\n");
        break;
      case 1:
        printf("\tEnter the column number you want to delete: ");
        scanf("%d",&x);
        if(x<=0 || x>no_column(*H))
        {
          printf("Out Of Range\n");
        }
        del_col(H,T,ret_col(*H,x));
        break;
      case 2: 
        printf("\tEnter the row number: ");
        scanf("%d",&y);
        if(y>(*H)->length || y<=0)
        {
          printf("Out of Range\n");
          break;
        }
        del_row(H,T,y);
        break;
      case 3:
        printf("\tEnter the x cordinate: ");
        scanf("%d",&x);
        if(x<=0 || x>no_column(*H))
        {
          printf("Out Of Range\n");
        }
        printf("\tEnter the y cordinate: ");
        scanf("%d",&y);
        if(y<=0 || y>(*H)->length)
        {
          printf("Out Of Range\n");
        }
        printf("\t\tMenu:\n\t\t0.Back\n\t\t1.Shift all the cells Row Wise\n\t\t2.Shift all the cells Column Wise\n\t\t:");
        scanf("%d",&choice2);
        switch(choice2)
        {
          case 0: 
            break;
          case 1: 
            temp = del_cell_pos_row(x,y,*H);
            break;
          case 2: 
            temp = del_cell_pos_col(x,y,*H);
            break;
          default: 
            printf("\t\tWrong Choice\n");
        }
        if(temp!=INT_MAX)
        {
          *buffer = temp;
          printf("\tValue saved to Bufer\n");
        }
        break;
      default:
        printf("\tWorng input\n");
    }
  }
}
void buffer_functions(ll_carrier** H,ll_carrier ** T,double* buffer)
{
  int choice,x,y;
  int choice2;
  printf("\n\tChoice:\n\t0.Back\n\t1.Print the value of buffer\n\t2.Change value of cell with the buffer\n\t3.Add Buffer to a new cell of SpredSheet\n\t:");
  scanf("%d",&choice);
  switch(choice)
  {
    case 0:
      break;
    case 1:
      printf("\tValue of Buffer: %.2lf\n",*buffer);
      break;
    case 2: 
      printf("\tEnter the value of x: ");
      scanf("%d",&x);
      if(x>no_column(*H) || x<=0)
      {
        printf("Out of Rnage\n");
        break;
      }
      printf("\tEnter the value of y: ");
      scanf("%d",&y);
      if(y>(*H)->length || y<=0)
      {
        printf("Out of Range\n");
        break;
      }
      change_ele(x,y,*H,*buffer);
      break;
    case 3: 
        printf("\t\t0.Back\n\t\t1.Shift All cells Row Wise\n\t\t2.Shift All cells Column Wise\n\t\t:");
        scanf("%d",&choice2);
        switch(choice2)
        {
          case 0:
            break;
          case 1: 
            printf("\tEnter the x cordinate: ");
            scanf("%d",&x);
            printf("\tEnter the y cordinate: ");
            scanf("%d",&y);
            insert_pos_row(x,y,*H,*T,*buffer);
            break;
          case 2:
            printf("\tEnter the x cordinate: ");
            scanf("%d",&x);
            printf("\tEnter the y cordinate: ");
            scanf("%d",&y);
            insert_pos_col(x,y,*H,*T,*buffer);
            break;
        }
    default: 
    printf("\tWorng input\n");
  }
}
