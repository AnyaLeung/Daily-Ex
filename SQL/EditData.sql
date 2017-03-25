CREATE TABLE students 
    (id INTEGER PRIMARY KEY, 
     name TEXT, 
     age SMALLINT,
     no INTEGER, 
     grade SMALLINT
);


--EDIT DATA--

--插入元组
INSERT  
INTO students (name, age, no)
VALUES ("stu_1", 15, 1);

INSERT  
INTO students (name, age, no)
VALUES ("stu_2", 16, 2);


--修改数据
UPDATE student 
SET grade = 100
where id = 1;

UPDATE student
SET grade +=10;


--删除数据
DELETE 
FROM students
WHERE id = 1;
