--insert data--


INSERT INTO club(clubName, clubCategoryID, clubIntro, clubCD, proName)
		VALUES ( 'ACM', 1, 'abc', '2017-01-01', 'pro1');
INSERT INTO club(clubName, clubCategoryID, clubIntro, clubCD, proName)
		VALUES ( 'club2', 1, 'abc', '2017-01-01', 'pro2');

INSERT INTO pro(proName, proIntro, employDate, clubName) 
		VALUES ( 'pro1', 'abc', '2018-01-01', 'ACM');
INSERT INTO pro(proName, proIntro, employDate, clubName)
		VALUES ( 'pro2', 'abc', '2018-01-01', 'club2');

INSERT INTO admin VALUES (1, 'admin88', '123456');

INSERT INTO appli VALUES ('ACM', 'app1', '123456789', 2018, 'CS', 'JJJ', 'like', '2018-01-01');