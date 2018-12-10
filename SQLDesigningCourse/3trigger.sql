--====================================
--  Create database trigger template 
--====================================
use club_db
go


--------DML TRIGGER-----------------

------------------------------------
------While delete club,------------
------delete proprieter-------------
------------------------------------
if object_id(N'DeleteProIfDeleteClub', N'tr') is not null
   drop trigger DeleteProIfDeleteClub;
go

create trigger DeleteProIfDeleteClub 
on club
for delete
as
begin
	declare @cname varchar(50)
	select @cname=clubName from deleted
	print @cname
	delete pro where clubName = @cname
	end
go

------------------------------------------------------
-------Student's grade must be 2018/7/6/5, -----------
-------else raise error.------------------------------
------------------------------------------------------
if object_id(N'CheckStudentsGrade', N'tr') is not null
	drop trigger CheckStudentsGrade;
go

create trigger CheckStudentsGrade
on student
for insert
as
begin
    declare @grade int
	declare @invalid bit
	select @grade=stuGrade from inserted 
	if @grade > 2018 or @grade < 2015
		set 
			@invalid = 1
	if @invalid = 1
		 begin
			raiserror('Invalid student grade, cannot insert.', 16, 1)
			rollback
		 end
end


------------DDL TRIGGER-------------

------------------------------------
--judge if triger_DDL_table exists--
------------------------------------
if object_id(N'PreventAlterOrDrop', N'tr') is not null
	drop trigger CheckStudentsGrade;
go

create trigger PreventAlterOrDrop   
on database
for drop_table, alter_table    
as
    print 'Trigger PreventAlterOrDrop has banned DROP / ALTER operation.'
    rollback
go



-------------------------------------------
--if already have pro of particular club,--
--not allowed to add a new pro.------------
-------------------------------------------
if object_id(N'CheckPro', N'tr') is not null
	drop trigger CheckStudentsGrade;
go

create trigger CheckPro
on pro
instead of insert
as 
begin
	declare @cname varchar(50)
	select @cname=clubName from inserted
	if exists(select * from pro where clubName=@cname)
		 raiserror('Cannot insert new pro, because there has already been a pro of this club.', 16, 1)
end
go

create trigger UpdateProClubName
on club
after update
as
begin
	declare @cname_after varchar(50)
	declare @cname_b4 varchar(50)

	select @cname_after=clubName from inserted
	select @cname_b4=clubName from deleted
	if exists(select * from pro where clubName=@cname_b4)
		update pro set clubName=@cname_after where clubName=@cname_b4
end
go