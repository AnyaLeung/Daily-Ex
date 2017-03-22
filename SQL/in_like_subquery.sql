CREATE TABLE artists (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT,
    country TEXT,
    genre TEXT);

INSERT INTO artists (name, country, genre)
    VALUES ("Taylor Swift", "US", "Pop");
INSERT INTO artists (name, country, genre)
    VALUES ("Led Zeppelin", "US", "Hard rock");
INSERT INTO artists (name, country, genre)
    VALUES ("ABBA", "Sweden", "Disco");
INSERT INTO artists (name, country, genre)
    VALUES ("Queen", "UK", "Rock");
INSERT INTO artists (name, country, genre)
    VALUES ("Celine Dion", "Canada", "Pop");
INSERT INTO artists (name, country, genre)
    VALUES ("Meatloaf", "US", "Hard rock");
INSERT INTO artists (name, country, genre)
    VALUES ("Garth Brooks", "US", "Country");
INSERT INTO artists (name, country, genre)
    VALUES ("Shania Twain", "Canada", "Country");
INSERT INTO artists (name, country, genre)
    VALUES ("Rihanna", "US", "Pop");
INSERT INTO artists (name, country, genre)
    VALUES ("Guns N' Roses", "US", "Hard rock");
INSERT INTO artists (name, country, genre)
    VALUES ("Gloria Estefan", "US", "Pop");
INSERT INTO artists (name, country, genre)
    VALUES ("Bob Marley", "Jamaica", "Reggae");

CREATE TABLE songs (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    artist TEXT,
    title TEXT);

INSERT INTO songs (artist, title)
    VALUES ("Taylor Swift", "Shake it off");
INSERT INTO songs (artist, title)
    VALUES ("Rihanna", "Stay");
INSERT INTO songs (artist, title)
    VALUES ("Celine Dion", "My heart will go on");
INSERT INTO songs (artist, title)
    VALUES ("Celine Dion", "A new day has come");
INSERT INTO songs (artist, title)
    VALUES ("Shania Twain", "Party for two");
INSERT INTO songs (artist, title)
    VALUES ("Gloria Estefan", "Conga");
INSERT INTO songs (artist, title)
    VALUES ("Led Zeppelin", "Stairway to heaven");
INSERT INTO songs (artist, title)
    VALUES ("ABBA", "Mamma mia");
INSERT INTO songs (artist, title)
    VALUES ("Queen", "Bicycle Race");
INSERT INTO songs (artist, title)
VALUES ("Queen", "Bohemian Rhapsody");
INSERT INTO songs (artist, title)
VALUES ("Guns N' Roses", "Don't cry");

--from here    
SELECT title FROM songs WHERE artist = 'Queen';
SELECT name FROM artists WHERE genre = 'Pop';
SELECT title FROM songs WHERE ARTIST IN (
    SELECT name FROM artists WHERE genre = 'Pop');

/* IN and subqueries:
    for ```WHERE column_name IN column_value```

    ```...WHERE column_name IN (SELECT subcolumn_name...) ```
    the column_name should correspond to the subcolumn_name
*/

/*LIKE:
    use like IN 
    “Select column FROM table Where column LIKE 'pattern'”

    patterns:

        % 表示任意0个或多个字符
        _ 表示任意单个字符
        [ ] 表示括号内所列字符中的一个 (like regix)
        [^ ] 表示不在括号所列之内的单个字符  
        * 表示查找的是所有信息

        []
        由于通配符的缘故，导致我们查询特殊字符“%”、“_”、“[”、“';”的语句无法正常实现，而把特殊字符用“[ ]”括起便可正常查询。据此我们写出以下函数： 
        
        function sqlencode(str) str=replace(str,"';","';';") str=replace(str,"[","[[]") ';
        此句一定要在最先 str=replace(str,"_","[_]") str=replace(str,"%","[%]") sqlencode=str end function 在查询前将待查字符串先经该函数处理即可，并且在网页上连接数据库用到这类的查询语句时侯要注意：如Select * FROM user Where name LIKE '老[^1-4]';上面《'》老[^1-4]《'》是要有单引号的，

        我也不知道上面一段啥意思。。
        */
