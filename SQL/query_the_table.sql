CREATE TABLE movies (id INTEGER PRIMARY KEY, name TEXT, release_year INTEGER);
INSERT INTO movies VALUES (1, "Avatar", 2009);
INSERT INTO movies VALUES (2, "Titanic", 1997);
INSERT INTO movies VALUES (3, "Star Wars: Episode IV - A New Hope", 1977);
INSERT INTO movies VALUES (4, "Shrek 2", 2004);
INSERT INTO movies VALUES (5, "The Lion King", 1994);
INSERT INTO movies VALUES (6, "Disney's Up", 2009);
 
--from here
SELECT * FROM movies;
SELECT * FROM movies WHERE release_year >= 2000 ORDER BY release_year;
--select            filter                      order

-- != ( Is not equal to ) For example, item != "Bananas" shows everything but bananas. 

/*
* order matter in sql statements, 
* as follows:
*1.SELECT
*2.FROM (+ JOIN-Statements)
*3.WHERE
*4.GROUP BY
*5. HAVING (in conjunction with GROUP BY)
*6.ORDER BY
*/
