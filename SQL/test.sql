--表的定义、删除和修改
--定义表
CREATE TABLE students 
    (id INTEGER PRIMARY KEY,
     name CHAR(20),
     age  SMALLINT,
     FOREIGN KEY(id) REFERENCE grade(student_id)
    );


--修改基本表 --> alter table
ALTER TABLE students ADD entrance DATE;
--增加入学时间列
ALTER TABLE students ALTER COLUMN  age INTEGER;
--将年龄由smallint 变为 int型
ALTER TABLE students ADD UNIQUE(id);
--增加学生id必须取唯一值


--删除基本表 --> drop table
DROP TABLE <table_name> [RESTRICT|CASCADE];

/*
* RESTRICT --> 有约束条件, 如不能 被其他表的约束所引用等(如foreign key
* CASCADE  --> 无约束条件
*/


--数据查询
CREATE TABLE orders
    (id INTEGER PRIMARY KEY, 
     name CHAR(20),
     orders TEXT,
     price SMALLINT);

--basic pattern
SELECT id, name /*aimed row*/
FROM orders AS total_price
WHERE id < 100 /*条件表达式*/
GROUP BY name/*row name*/ HAVING total_price > 100;
ORDER BY id DESC /*ACS*/;

--example
SELECT  name, price, id FROM orders;
SELECT * FROM orders;
SELECT name, 2017-age FROM students;
--see like, between p2



--WHERE clause
SELECT id, name
FROM students
WHERE age>15;

SELECT id, name
FROM students
WHERE age BETWEEN 20 AND 23;

SELECT id, name
FROM students 
WHERE age IN (18, 20);

SELECT id, name
FROM students
WHERE name LIKE "王%";
--see like



--ORDER BY clause
--对查询结果升序（asc, default    降序(desc 排列
SELECT id, name, grade
FROM students
ORDER BY grade ASC;


--aggregating function
--see aggregating function
SELECT AVG(grade)
FROM students AS avg_grade;


--GROUP BY clause, and HAVING
--see before


--join
SELECT 
