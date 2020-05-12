Intro: 
  this is a menu driven program for SpreadSheet 

Below  is walk through for your ease: 
  The program have 6 sub menus and 1 exit menu. 
  After entering a sub menu one can get back to previous menu by presiing '0'
  *The program also handles invalid menu option.
  Co-ordinate system: 
  	x: column number
  	y: row number
  	A Note about them: 
  		x and y must smaller than equal to 0
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
      Add or subtract values of cells:
      	insert + or - 
      	and the co-ordinate of cells
      	and the value will be added or subtracted from the result(initially 0)
      	and the value will be saved in the buffer.
    Search function: 
      will print the position of searched key if present in the spreadsheet
      The function work on approximation concept: 
      	will consider only 2 numbers after decimal. As we are only printing .2f, the value we see will be approximated, so we employed a approximated search.
      The positions listed are strings printed on console, thus it is a void function.
    
    Insertion related function:
    	1. Change the value of a cell: 
    		Enter the co-ordinates and will replace the old value with inputted value(accepts float/double)
    	2. Insert at the end of a column:
    		Enter the column # and element you want to insert.
    	3. Insert a new Cell at specific position: 
    		Again it Contain 2 menus: 
    			Shift all cells by Row: 
    				will insert a cell at that position and will shift the rest along that Row and every row will also have an empty cell at the end.
    				if (x > number of columns)
    					a new cell will be created at the end of that row and will contain the inputted value
    				if(y>length of each column)
    					a new Row will be created at the end of Document and value will be inserted according to x
    			Shift all the cells by Column: 
    				will insert a cell at that position and will shift the rest along that Column and every row will also have every column will a have an empty cell(0) at the end.
    				if(x > number of columns)
    					a new column will be inserted and the cell will inserted according to y and evry row
    				if(y> length of each column)
    					the element will insert in a new row(at the end).
    	4. Insert an empty Column in the front of document(which will have all the 0's in the cells)
    	5. Insert an empty Column at the end of document(which will have all the 0's in the cells)
    	6. Insert an Empty row at the end of document
    Deletion: 
    Both option 1&2 should get inputs under range.
      1. Delete a Column 
      2. Delete a Row 
      3. Delete a cell:
      	Will delete the cell and will ask to shift remainig cell along Row or Column
    Print related function:
      Print all: 
        Will print the whole document with indexes on the side and top of document,

    Buffer Related functions: 
    	Buffer: a variable which stores values after certain operations. 
    	Such as: 
    		Maximum of column/row
    		Minimum of column/row
    		Avg of column/row if you chose not to store it in the document
    		Search key(Even if found)
    		Deleted cell's value
 		The value of buffer can be printed or changed at any point of time.
 		The buffer is a single variable, so after every above operation you will loose the old value of buffer.

    Exit:
      Will prompt a choice of saving the data to a .csv file
      if selected, the user will asked to choose the name of file(we recommend not include extensions or funny symbol in the file name)
