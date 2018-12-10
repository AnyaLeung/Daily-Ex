USE master
GO
/*
 
 
 
$建库
 
 
 
 
 
 
*/  
--检验数据库是否存在，如果为真，删除此数据库--  
IF exists(SELECT * FROM sysdatabases WHERE name='CLUB_DB')  
  declare @dbname sysname   
  set @dbname = 'CLUB_DB' --这个是要删除的数据库库名   
      
  declare @s nvarchar(1000)   
  declare tb cursor local  
  for 
      select s = 'kill   ' + cast(spid as varchar) 
      from   master.dbo.sysprocesses 
      where  dbid = DB_ID(@dbname)   
      
  open   tb     
  fetch   next   from   tb   into   @s   
  while @@fetch_status = 0 
  begin 
      exec (@s)  
      fetch next from tb into @s 
  end   
  close   tb   
  deallocate   tb   
   
  exec ('drop   database   [' + @dbname + ']')  
GO  

--create new database named CLUB--
CREATE DATABASE CLUB_DB 
GO  
  
--create tables--
USE CLUB_DB  
GO  

create Table club
(clubID int IDENTITY(1,1) NOT NULL,
clubName varchar(50) NOT NULL,
clubCategoryID int NOT NULL,
clubIntro varchar(MAX) NOT NULL,
clubCD date NOT NULL,
proName varchar(50) NOT NULL,
PRIMARY KEY (clubID),
UNIQUE(clubName)
);

create Table pro
(proID int IDENTITY(1,1) NOT NULL,
proName varchar(50) NOT NULL,
proIntro varchar(MAX) NOT NULL,
employDate date NOT NULL,
clubName varchar(50) NOT NULL,
PRIMARY KEY (proID),
UNIQUE(proName)
--FOREIGN KEY(clubName) REFERENCES club(clubName)
);

create Table activity
(actID int IDENTITY(1,1) NOT NULL,
clubName varchar(50) NOT NULL,
actTheme varchar(50) NOT NULL,
actSite varchar(50) NOT NULL,
actDate smalldatetime NOT NULL,
PRIMARY KEY (actID),
FOREIGN KEY (clubName) REFERENCES club(clubName) ON DELETE CASCADE ON UPDATE CASCADE
);

create Table news
(newsID int IDENTITY(1,1) NOT NULL,
newsTitle varchar(50) NOT NULL ,
newsCategoryID int NOT NULL,
newsAuthor varchar(50) NOT NULL,
newsContent varchar(MAX) NOT NULL,
newsCD smalldatetime default getdate() NOT NULL,
PRIMARY KEY (newsID)
);

create Table student
(stuID int IDENTITY(1, 1) NOT NULL, --new
stuName varchar(50) NOT NULL,
stuCollege varchar(50) NOT NULL,
stuGrade int NOT NULL,
stuTel varchar(50) NOT NULL,
clubName varchar(50) NOT NULL,
PRIMARY KEY (stuID),
FOREIGN KEY (clubName) REFERENCES club(clubName) ON DELETE CASCADE ON UPDATE CASCADE
);

create Table appli
(appliID int IDENTITY(1,1) NOT NULL,
clubName varchar(50) NOT NULL,
appliName varchar(50) NOT NULL,
appliTel varchar(50) NOT NULL,
appliGrade int NOT NULL,
appliCollege varchar(50) NOT NULL, --new add
appliIntro varchar(MAX) NOT NULL,
appliReason varchar(50) NOT NULL,
appliDate smalldatetime default getdate() NOT NULL,
PRIMARY KEY (appliID),
FOREIGN KEY (clubName) REFERENCES club(clubName) ON DELETE CASCADE ON UPDATE CASCADE
);
create Table admin
(adminID int NOT NULL,
adminName varchar(50) NOT NULL,
password varchar(50) NOT NULL,
PRIMARY KEY (adminID)
);



