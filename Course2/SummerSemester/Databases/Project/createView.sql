SET SCHEMA FN3MI0700035;
DROP VIEW V_TAKENEXAM_STUD_INFO;
CREATE VIEW V_TAKENEXAM_STUD_INFO
AS
SELECT S.FNAME, S.LNAME, E.TITLE, E.SCIENCE_FIELD, TE.GRADE
FROM STUDENTS S,
     EXAMS E,
     TAKENEXAMS TE
WHERE TE.NEXAM = E.NEXAM
  AND TE.FN = S.FN;

SELECT *
FROM V_TAKENEXAM_STUD_INFO;

DROP VIEW V_STUDENTS_ALL;
CREATE VIEW V_STUDENTS_ALL
AS
SELECT FN, FNAME, LNAME, FACULTY, COURSE
FROM STUDENTS
WHERE COURSE = '3';

SELECT *
FROM V_STUDENTS_ALL;

INSERT INTO V_STUDENTS_ALL(FN, FNAME, LNAME, FACULTY, COURSE)
VALUES ('FHG3T6KL9P', 'Гошо', 'Петров', 'Факултет по Глобално стопанство', 3);

SELECT *
FROM V_STUDENTS_ALL;

DROP VIEW V_STUDENTS_ALL_WITH_CK;
CREATE VIEW V_STUDENTS_ALL_WITH_CK
AS
SELECT FN, FNAME, LNAME, FACULTY, COURSE
FROM STUDENTS
WHERE COURSE = '4'
WITH CHECK OPTION;

SELECT *
FROM V_STUDENTS_ALL_WITH_CK;

DELETE
FROM V_STUDENTS_ALL_WITH_CK
WHERE FN = 'M5N8D3K7T9';

INSERT INTO V_STUDENTS_ALL_WITH_CK(FN, FNAME, LNAME, FACULTY, COURSE)
VALUES ('M5N8D3K7T9', 'Калина', 'Марипосова', 'Факултет по кулинарни изкуства', 4); -- ОК

SELECT *
FROM V_STUDENTS_ALL_WITH_CK;

INSERT INTO V_STUDENTS_ALL_WITH_CK(FN, FNAME, LNAME, FACULTY, COURSE)
VALUES ('H9F2J5L6P8', 'Йоан', 'Айрянов', 'Богословски факултет', 2); -- NOT ОК

SELECT *
FROM V_STUDENTS_ALL_WITH_CK;