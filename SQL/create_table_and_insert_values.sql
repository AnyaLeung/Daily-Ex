CREATE TABLE books (id INTEGER PRIMARY KEY, name TEXT, rating INTEGER);

--插入元组
INSERT  
INTO books 
VALUES (1, "Walden Lake", 1);

INSERT  
INTO books 
VALUES (2, "Gone with the Wind", 2);

INSERT 
INTO books 
VALUES (3, "Amuse to Death", 3);


--修改数据
UPDATE student 
SET grade = 100
/*where id = 1*/;

--删除数据
DELETE 
FROM students
WHERE id = 1;
