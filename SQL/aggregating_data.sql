CREATE TABLE todo_list (id INTEGER PRIMARY KEY, item TEXT, minutes INTEGER);
INSERT INTO todo_list VALUES (1, "Wash the dishes", 15);
INSERT INTO todo_list VALUES (2, "vacuuming", 20);
INSERT INTO todo_list VALUES (3, "Learn some stuff on KA", 30);
INSERT INTO todo_list VALUES (4, "Read Books", 20);

--from here: aggreagating data

SELECT SUM(minutes) FROM todo_list;
SELECT AVG(minutes) FROM todo_list;


/* 
MIN     	
MAX     
SUM    
AVG   
COUNT	    returns the total number of VALUES in a given COLUMN 
COUNT(*)	returns the number of ROWS in a TABLE 
*

/*
round() 取整， 为5时机率分半
*/
