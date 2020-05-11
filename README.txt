Intro: 
  this is a menu driven program for SpreadSheet 
Below  is walk through for your ease: 
  The program have 6 submenus and 1 exit menu. 
  After entering a submenu one can get back to previous menu by presiing '0'
  *The program also handels invalid menu option.
  Co-ordinate system: 
  	x: column number
  	y: row number
  This program also contains buffer:
  	buffer will save certain values for future values.
  All their functionality are listed below:
    Internal Data related functions: 
      1. Will print the length of each column
      2. Will print the total cells present in the spread sheet(will never be 0)  
      Column and Row related function contain MiniMum/Maximum/Avg
      	All three functions will per performed on the inputted column/row.
      	Maximum/Minimum values will be stored in buffer.
      	After Avg calculation, User will be prompted for an option to insert that value to SpreadSheet.
      		If selected no: avg will be stored in buffer.
      Add or substract values of cells:
      	insert + or - 
      	and the co-ordnate of cells
      	and the value will be added or substracted from the result(initially 0)
      	and the value will be saved in the buffer.
    Search function: 
      will print the positon of searched key if present in the spreadsheet
      The fucntion work on appoximation concept: 
      	will consider only 2 numbers after decimal. As we are only printing .2f, the value we see will be aproximated, so we employed a aproximated search.
      The positions listed are strings printed on console, thus it is a void function.
    
    Insertion related function:
    	1. Change the value of a cell: 
    		Enter the co-ordinates and will replace the old value with inputted value(accepts float/double)
    	2. Insert at the end of a column:
    		Enter the column # and element you want to insert.
    	3. Insert a new Cell t specific position: 
    		will insert a new column/row
    		will shift the all the elements column/row
    	4. Insert an empty Column in the front of documnet(which will have all the 0's in the cells)
    	5. Insert an empty Column at the end of doument(which will have all the 0's in the cells)
    	6. Insert an Empty row at the end of document
    Deletion: 
    	Delete a cell:
    		eneter x,y and all the cells below it will be shifted above row/column wise
       
    Deleteion
    
    Print related function:
      Print all: 
        Will print the whole document with indexes on the side and top of document
    Exit:
      Will propt a choice of saving the data to a .csv file
      if selected, will save the whole spreatsheet into saved_data.csv which will be created from the spreadSheet without the indexes on the side or bottom.
