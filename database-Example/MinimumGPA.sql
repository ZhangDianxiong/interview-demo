SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";

CREATE TABLE `MinimumGPA`(
    `cName` char(20) NOT NULL,
    `major` char(20) NOT NULL,
    `minGPA` DECIMAL(3,2) DEFAULT NULL

) ENGINE=InnoDB DEFAULT CHARSET=latin1;

INSERT INTO `MinimumGPA` (`cName`, `major`, `minGPA`) VALUES
('OSU', 'CS', '3.75'),
('OSU', 'EE', '3.5'),
('OSU', 'history', '2.8'),
('U of O', 'CS', '3.6'),
('U of O', 'biology', '3.75'),
('Cornell', 'bioengineering', '3.8'),
('Cornell', 'CS', '3.4'),
('Cornell', 'EE', '3.6'),
('Cornell', 'history', '3.6'),
('Cornell', 'psychology', '2.8'),
('MIT', 'biology', '3.5'),
('MIT', 'bioengineering', '3.5'),
('MIT', 'CS', '3.9'),
('MIT', 'marine biology', '3.5');

ALTER TABLE `MinimumGPA`
    ADD PRIMARY Key (cName,major);


-- q1.	(a)  List the sID, name and number of applications (as Number of Apps) that each student submitt
-- If the students did not make any applications the Number of Apps is 0.
SELECT sID, sName, count(decision)
FROM(
    SELECT S.sID, S.sName, A.decision
    FROM Student S LEFT JOIN Apply A ON S.sID = A.sID
)AS t
GROUP BY sID

-- (b) List the sID, name and number of applications (as Number of Apps) 
-- for each student that submitted three or more applications.
SELECT sID, sName, offer
FROM(
    SELECT sID, sName, count(decision) AS offer
    FROM(
        SELECT S.sID, S.sName, A.decision
        FROM Student S LEFT JOIN Apply A ON S.sID = A.sID
    )AS t
    GROUP BY sID
)As p
WHERE offer >= 3
-- 2)	List the sID and name of each student from a small HS 
-- (less than 600 students) who is applying to a CS major. 
SELECT S.sID, S.sName  FROM Apply A, Student S
WHERE S.sID = A.sID and S.sizeHS <=600 and A.major = 'CS'

-- 3)	(a) Determine the average minimum GPA requirement for each college.
SELECT M.cName, AVG(minGPA)    
FROM MinimumGPA M GROUP BY M.cName
-- (b) Determine the name of the college with the greatest average 
-- minimum GPA requirement.

SELECT t.cName, avgVal
FROM(
    SELECT M.cName , AVG(minGPA) AS avgVal
    FROM MinimumGPA M 
    GROUP BY M.cName
) AS t
WHERE avgVal = (select max(avgVal) 
                FROM (select M.cName,AVG(minGPA) AS avgVal 
                from MinimumGPA M GROUP BY M.cName) as p)


-- 4)	List the name and id of the students that applied to OSU 
-- but did not apply to U of O.
SELECT t.sName, t.sID
FROM(
	SELECT S.sName, S.sID 
	FROM Student S, Apply A
	WHERE S.sID = A.sID AND A.cName = 'OSU'
	GROUP BY S.sName
)AS t
WHERE t.sID Not In (	
	SELECT S.sID
	FROM Student S, Apply A
	WHERE S.sID = A.sID AND A.cName = 'U of O')

-- 5)	For students with GPA’s higher than the minimum requirements 
-- for the major they applied for, give the student’s name, GPA, college name and major. 
-- SELECT S.sName, S.sID, S.cName, S.major -- not correct 
-- FROM(
--     SELECT S.sName, S.sID, S.GPA, A.cName, A.major
--     FROM Student S, Apply A
--     WHERE S.sID = A.sID
-- ) AS S
-- WHERE k = (
--     SELECT *
--     FROM MinimumGPA AS M
--     WHERE S.GPA >= M.mimGPA
-- )
SELECT sName, sID, cName, GPA, major
FROM Student NATURAL JOIN Apply NATURAL JOIN MinimumGPA
WHERE GPA > minGPA

-- 6)	List the name and id of the students that applied 
-- to all schools. Do not use the names of the schools in your query.

-- SELECT S.sName, S.sID, count(DISTINCT A.cName) AS t, count(C.cName) AS p
-- FROM Student S, Apply A,College C
-- WHERE p = t and S.sID = A.sID
SELECT S.sName, A.sID
FROM Student S, (
    SELECT A.sID, Count(DISTINCT A.cName) AS count1, Count(DISTINCT C.cName) AS count2
    FROM Apply A, College C
    GROUP BY A.sID
)AS A
WHERE S.sID = A.sID and A.count1 = A.count2

-- SELECT A.sID, Count(DISTINCT A.cName), Count(DISTINCT C.cName)
-- FROM Apply A, College C
-- GROUP BY A.sID
