-- ================================================
-- Template generated from Template Explorer using:
-- Create Procedure (New Menu).SQL
--
-- Use the Specify Values for Template Parameters 
-- command (Ctrl-Shift-M) to fill in the parameter 
-- values below.
--
-- This block of comments will not be included in
-- the definition of the procedure.
-- ================================================
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		Qiushi Leung
-- Create date: 12-05-2018
-- Description:	�����û����������Ƿ���ڸ���Ա(with input&output params)
-- =============================================

if object_id (N'IfExistStudent', N'P') is not null 
	drop procedure IfExistStudent
go
-- if exists procedure, delete n' reform

create procedure IfExistStudent
	@sname varchar(50),
	@result varchar(50) output  
as
begin
	if (select COUNT(1) from student s where s.stuName=@sname)>0
	set
		@result = 'exist'
	else
	set
		@result = 'do not exist'
end 
go

--call procedure statements--
declare @result varchar(50)
exec IfExistStudent'pro1',@result output
print @result
go
--call procedure statements--

------------------------------------
--��֤admin���û����������Ƿ�Ϸ�--
------------------------------------
if object_id (N'Authenticate', N'P') is not null 
	drop procedure Authenticate
go

create procedure Authenticate @un varchar(50), @pwd varchar(50), @legal bit output
as 
begin
	if exists(select * FROM admin WHERE  adminName = @un AND password = @pwd) 
	set 
		@legal = 1 
	else
	set
		@legal = 0
end
go

--call procedure statements--
declare @legal bit
exec Authenticate'admin88', '123456', @legal output
print @legal
go
--call procedure statements--

------------------------------------
---������Ա��Ϣ��Ĭ���꼶Ϊ2018��---
------------------------------------
if object_id (N'InsertStudent', N'P') is not null 
	drop procedure InsertStudent
go

create proc InsertStudent
	@name varchar(50),
	@college varchar(50),
	@grade int = 2018,
	@tele varchar(50),
	@cname varchar(50)
as 
begin
	insert into student (stuName, stuCollege, stuGrade, stuTel, clubName)
		values (@name, @college, @grade, @tele, @cname)
end
go
 
--call procedure statements--
exec InsertStudent  @name='stu2', @college='CS', @tele='123456789', @cname='ACM'
go
--call procedure statements--

------------------------------------
-------����������ɾ����Ա��Ϣ-------
-----------------------------------
if object_id (N'DeleteStudent', N'P') is not null 
	drop procedure DeleteStudent
go

create proc DeleteStudent
@name varchar(50)
as
begin
	delete from student where stuName=@name
	return @@rowcount
end
go
 
--call procedure statements--
declare @result varchar(50)
exec @result=DeleteStudent 'stu1'
select @result as 'ɾ������'
print @result
go
--call procedure statements--

--------------------------------------------
--��������תΪ��ʽ��Ա���ṩ����������------
--------------------------------------------
if object_id (N'App2Student', N'P') is not null 
	drop procedure App2Student
go

create procedure App2Student
@name varchar(50)
as 
begin
	insert into student(stuName, stuCollege, stuGrade, stuTel, clubName)
	select appliName, appliCollege, appliGrade, appliTel, clubName from appli where appliName=@name
end
go
 
--call procedure statements--
exec APP2Student @name='app1'
go
--call procedure statements--