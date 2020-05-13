Intro: 
  This is a menu driven program for SpreadSheet 

Below is walk through for your ease: 
  The program have 6 sub menus and 1 exit menu. 
  After entering a sub menu one can get back to previous menu by pressing '0'
  *The program also handles invalid menu option.
  Co-ordinate system: 
  	x: column number
  	y: row number
  	A Note about them: 
  		x and y must be greater than equal to 0
  This program also contains buffer:
  	buffer will save certain values for future uses.

  The functionality of submenus are listed below:
    A. Internal Data related functions: 
      1. Will print the length of each column
      2. Will print the total cells present in the spread sheet(will never be 0)  
      3. and 4. Column and Row related function contain MiniMum/Maximum/Avg which will be performed on the inputted column/row.
      	According to the user, avg value can be inserted to SpreadSheet or stored in buffer.
     5.  Addition/ subtraction of values of multiple cells:
      	insert + or - (0 to stop the operation)
      	and the co-ordinate of cells
      	then the value will be added or subtracted from the result(initially 0)
      	and the value will be saved in the buffer.
    B. Search function: 
      will print the position of searched key if present in the spreadsheet
      The function works on approximation concept: 
      	will consider only 2 numbers after decimal. As we are only printing .2f, the value we see will be approximated, so we employed a approximated search.
      The positions listed are strings printed on console, thus it is a void function.
    
    C. Insertion related function:
    	1. Change the value of a cell: 
    		Enter the co-ordinates following which the old value will be replaced with inputted value(accepts float/double)
    	2. Insert at the end of a column:
    		Enter the column no. and element you want to insert.
    	3. Insert a new Cell at specific position: 
    		Again it Contains 2 menus: 
    			Shift all cells by Row: 
    				will insert a cell at that position and will shift the rest along that Row and every row will also have an empty cell at the end.
    				if (x > number of columns)
    					a new cell will be created at the end of that row and will contain the inputted value
    				if(y>length of each column)
    					a new Row will be created at the end of Document and value will be inserted according to x
    			Shift all the cells by Column: works in a similar way as in shifting all cells by Row.
    	4. Insert an empty Column in the front of document(which will have all the 0's in the cells)
    	5. Insert an empty Column at the end of document(which will have all the 0's in the cells)
    	6. Insert an Empty row at the end of document(which will have all the 0's in the cells)
   
 	D. Deletion: 
	    Both option 1&2 should get inputs under range.
	    1. Delete a Column 
	    2. Delete a Row 
	    3. Delete a cell:
	    	Will delete the cell and will ask to shift remainig cell along Row or Column

   E.  Print the document: Will print the whole document. No submenus here.

    F. Buffer Related functions: 
    	Buffer: a variable which stores values after certain operations. 
    	Such as: 
    		Maximum of column/row
    		Minimum of column/row
    		Avg of column/row if you chose not to store it in the document
    		Search key(Even if found)
    		Deleted cell's value
 		The value of buffer can be printed or changed at any point of time.
 		The buffer is a single variable, so after every abovementioned operation you will loose the old value of buffer.
                Buffer value can also be added to the spreadsheet.

    G. Exit:
      Will prompt a choice of saving the data to a .csv file
      if selected, the user will be asked to choose the name of file(we recommend not include extensions or any funny symbol in the file name)
