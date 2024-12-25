SET SCHEMA FN24_3MI0700035;
INSERT INTO EMPLOYEE
SELECT *
FROM DB2SAMPLE.EMPLOYEE;

-- TASK01
SELECT *
FROM EMPLOYEE
WHERE HIREDATE <= BIRTHDATE + 18 YEARS;

CREATE OR REPLACE PROCEDURE CORRECT_HIREDATE(IN EMP_ID INT)
BEGIN
    FOR E AS E1 CURSOR FOR (SELECT HIREDATE, BIRTHDATE FROM EMPLOYEE E WHERE EMPNO = EMP_ID)
        DO
            IF (E.HIREDATE <= (E.BIRTHDATE + 18 YEARS))
            THEN
                UPDATE EMPLOYEE
                SET HIREDATE = CURRENT_DATE
                WHERE EMPNO = EMP_ID;
                CALL DBMS_OUTPUT.PUT_LINE('HERE');
            END IF;
        end for;
end;

BEGIN
    FOR E AS E1 CURSOR FOR (SELECT EMPNO FROM EMPLOYEE)
        DO
            CALL FN24_3MI0700035.CORRECT_HIREDATE(E.EMPNO);
        end for;
end;

-- TASK02
DELETE
FROM PROJECT;
INSERT INTO PROJECT
SELECT *
FROM DB2SAMPLE.PROJECT;

CREATE OR REPLACE PROCEDURE CORRECT_PRENDATE()
BEGIN
    FOR P AS P1 CURSOR FOR (SELECT PRENDATE, PRSTDATE, PROJNO FROM PROJECT)
        DO
            IF (P.PRSTDATE < P.PRENDATE)
            THEN
                UPDATE PROJECT
                SET PRENDATE = NULL
                WHERE PROJNO = P.PROJNO;
                CALL DBMS_OUTPUT.PUT_LINE('HERE');
            END IF;
        end for;
end;
BEGIN
    CALL FN24_3MI0700035.CORRECT_PRENDATE();
end;

-- TASK03
SELECT *
FROM DEPARTMENT;

CREATE OR REPLACE PROCEDURE GET_DEPT_INFO(IN DEPT_ID CHARACTER(3))
BEGIN
    FOR E AS E1 CURSOR FOR (SELECT EMPNO,
                                   (FIRSTNME || ' ' || LASTNAME)                                 AS FULLNAME,
                                   (COALESCE(SALARY, 0) + COALESCE(BONUS, 0)+ COALESCE(COMM, 0)) AS INCOME
                            FROM EMPLOYEE
                            WHERE WORKDEPT = DEPT_ID)
        DO
            CALL DBMS_OUTPUT.PUT_LINE('ID: ' || E.EMPNO || ', NAME: ' || E.FULLNAME || ', INCOME: ' || E.INCOME);
        end for;
end;

BEGIN
    CALL FN24_3MI0700035.GET_DEPT_INFO('C01');
end;

-- TASK04



-- 04.12.2024

-- 1. Да се напише процедура, която по подаден номер на служител, проверява дали HIREDATE <= BIRTHDATE + 18
-- и ако това не е изпълнено да променя HIREDATE на този служител на CURRENT_DATE

SET SCHEMA FN77777;

SELECT * FROM EMP
WHERE HIREDATE <= BIRTHDATE + 18 YEARS;

    CREATE OR REPLACE PROCEDURE PROC_CHECK_HDATE_EMP(IN P_WORKDEPT ANCHOR EMP.WORKDEPT)
    BEGIN
        DECLARE V_NAME ANCHOR EMP.LASTNAME;
        DECLARE V_BDATE DATE;
        DECLARE V_HDATE DATE;
        DECLARE SQLSTATE CHAR(5) DEFAULT '00000';
        DECLARE C CURSOR FOR SELECT LASTNAME, BIRTHDATE, HIREDATE FROM EMP
                  WHERE HIREDATE <= BIRTHDATE + 18 YEARS AND WORKDEPT = P_WORKDEPT;

        OPEN C;

        REPEAT
               FETCH C INTO V_NAME, V_BDATE, V_HDATE;
               CALL DBMS_OUTPUT.PUT_LINE('Emp: ' || V_NAME || ', ' || V_BDATE || ', ' || V_HDATE);
        until SQLSTATE = '00000'
        end repeat;

        UPDATE EMP
        SET HIREDATE = CURRENT_DATE
        WHERE HIREDATE <= BIRTHDATE + 18 YEARS
        AND   WORKDEPT = P_WORKDEPT;
    end;

CALL FN77777.PROC_CHECK_HDATE_EMP('D21');

-- 2. Да се напише процедура, която за всички проекти, проверява дали
-- PRSTDATE < PRENDATE и ако това
-- не е така променя PRENDATE на NULL

CREATE TABLE PROJ LIKE DB2SAMPLE.PROJECT;

ALTER TABLE PROJ ADD PRIMARY KEY(PROJNO);

INSERT INTO PROJ SELECT * FROM DB2SAMPLE.PROJ;


    CREATE OR REPLACE PROCEDURE PROC_PROJ_DATE()
    BEGIN

        UPDATE PROJ
        SET PRENDATE = NULL
        WHERE PRSTDATE > PRENDATE;

    end;

SELECT * FROM PROJ WHERE PRSTDATE > PRENDATE;

CALL FN77777.PROC_PROJ_DATE();


-- 3. Да се напише процедура, която по номер на отдел подаден като входен параметър,
-- връща броя на служителите в отдела като изходен параметър, както и резултатно
-- множество с информация за номерата на служителите, имената и сумарно - заплата,
-- бонус и комисионна за всеки служител, към отдела.
-- Да се има предвид че заплата, бонус и комисиона могат да бъдат NULL,
-- както и че подадения номер на отдел може да не съществува.

CREATE TABLE DEPT LIKE DB2SAMPLE.DEPT;

ALTER TABLE DEPT ADD PRIMARY KEY(DEPTNO);

INSERT INTO DEPT SELECT * FROM DB2SAMPLE.DEPT;

    CREATE OR REPLACE PROCEDURE PROC_LIST_EMP(IN P_DEPTNO ANCHOR EMP.WORKDEPT)
    RESULT SETS 1
    BEGIN
        DECLARE V_EMP_CNT INT;
        DECLARE V_DEPT_EXISTS INT;
        DECLARE C CURSOR WITH RETURN FOR
                                        SELECT EMPNO, FIRSTNME || ' ' || LASTNAME AS NAME,
                                               COALESCE(SALARY, 0) + COALESCE(COMM, 0) +
                                               COALESCE(BONUS, 0) AS INCOME
                                        FROM EMP
                                        WHERE WORKDEPT = P_DEPTNO;
        SET V_EMP_CNT = (SELECT COUNT(*) FROM EMP WHERE WORKDEPT = P_DEPTNO);
        IF V_EMP_CNT > 0 THEN
            CALL DBMS_OUTPUT.PUT_LINE('Number of employees is: ' || V_EMP_CNT);
        ELSEIF V_EMP_CNT = 0 THEN
             SET V_DEPT_EXISTS = (SELECT COUNT(*) FROM DEPT WHERE DEPTNO = P_DEPTNO);
             IF V_DEPT_EXISTS > 0 THEN
                 CALL DBMS_OUTPUT.PUT_LINE('Number of employees is: ' || V_EMP_CNT);
             ELSE
                 CALL DBMS_OUTPUT.PUT_LINE('Dept not exist: ' || P_DEPTNO);
             end if;
        end if;

        OPEN C;
    end;

CALL FN77777.PROC_LIST_EMP('J22');


-- 4. По подаден номер на служител да се провери колко време е
-- работил по всеки проект. Ако е работил по-малко от 1.0 по
-- проект да се запише в предварително създадена за целта таблица, информация за служителя, за номера на проекта и
-- текущата дата и време на вмъкване на записа.

-- 05.12.2024

По подаден входен параметър отдел извежда име на отдела
и име на служител и телефонен номер, подредени по име

CREATE TABLE DEPT LIKE DB2SAMPLE.DEPARTMENT;
ALTER TABLE DEPT ADD PRIMARY KEY (DEPTNO);
INSERT INTO DEPT SELECT * FROM DB2SAMPLE.DEPARTMENT;

CREATE OR REPLACE PROCEDURE
    PROC_LIST_EMP_BY_DEPTNO(IN P_DEPTNO ANCHOR DEPT.DEPTNO)
BEGIN
    DECLARE V_DEPTNAME ANCHOR DEPT.DEPTNAME;
    DECLARE V_NAME VARCHAR(30);
    DECLARE V_PHONE ANCHOR EMP.PHONENO;
    DECLARE SQLSTATE CHAR(5) DEFAULT '00000';
    DECLARE SQLCODE INT DEFAULT 0;
    DECLARE C CURSOR FOR SELECT FIRSTNME || ' ' || LASTNAME AS NAME, PHONENO
                         FROM EMP WHERE WORKDEPT = P_DEPTNO
                         ORDER BY NAME;

    SET V_DEPTNAME = (SELECT DEPTNAME FROM DEPT WHERE DEPTNO = P_DEPTNO);

    IF V_DEPTNAME IS NOT NULL THEN
    BEGIN
    CALL DBMS_OUTPUT.PUT_LINE('--------------------');
    CALL DBMS_OUTPUT.PUT_LINE(V_DEPTNAME);
    CALL DBMS_OUTPUT.PUT_LINE('--------------------');

    OPEN C;
    FETCH C INTO V_NAME, V_PHONE;
    WHILE SQLSTATE = '00000' DO
      CALL DBMS_OUTPUT.PUT_LINE(V_NAME || ': ' || V_PHONE);
      FETCH C INTO V_NAME, V_PHONE;
    end while;

    CLOSE C;
    END;
    ELSE
     CALL DBMS_OUTPUT.PUT_LINE('--------------------');
     CALL DBMS_OUTPUT.PUT_LINE('NO SUCH DEPARTMENT: ' || P_DEPTNO);
     CALL DBMS_OUTPUT.PUT_LINE('--------------------');
   END IF;
end;

CALL FN77777.PROC_LIST_EMP_BY_DEPTNO('234');


CREATE OR REPLACE FUNCTION F_GET_NAME_BY_EMPNO (P_EMPNO CHAR(6))
RETURNS VARCHAR(30)
   RETURN SELECT FIRSTNME || ' ' || LASTNAME FROM EMP WHERE EMPNO = P_EMPNO;

VALUES FN77777.F_GET_NAME_BY_EMPNO('000010');

-- Име на отдел, брой служители в отдела, информация за служителите в отдела - име, заплата, длъжност, телефон,
-- информация за проектите в отдела - име на проект, началан дата, крайна дата, име на отговорник на проекта.

CREATE TABLE PROJ LIKE DB2SAMPLE.PROJ;
ALTER TABLE PROJ ADD PRIMARY KEY (PROJNO);
INSERT INTO PROJ SELECT * FROM DB2SAMPLE.PROJ;


CREATE OR REPLACE PROCEDURE PROC_INFO(IN P_DEPTNO CHAR(3))
    RESULT SETS 2
BEGIN
    DECLARE V_DEPTNAME ANCHOR DEPT.DEPTNAME;
    DECLARE V_CNT_EMP INT DEFAULT 0;
    DECLARE C_EMP CURSOR WITH RETURN FOR SELECT FIRSTNME || ' ' || LASTNAME AS NAME,
                                                JOB, PHONENO, SALARY
                                         FROM EMP
                                         WHERE WORKDEPT = P_DEPTNO;

    DECLARE C_PROJ CURSOR WITH RETURN FOR SELECT PROJNAME, PRSTDATE, PRENDATE,
                                          FN77777.F_GET_NAME_BY_EMPNO(RESPEMP)  AS RESPEMP
                                          FROM PROJ
                                          WHERE DEPTNO = P_DEPTNO;

    SET V_DEPTNAME = (SELECT DEPTNAME FROM DEPT WHERE DEPTNO = P_DEPTNO);
    SET V_CNT_EMP = (SELECT COUNT (*) FROM EMP WHERE WORKDEPT = P_DEPTNO);

    IF V_CNT_EMP > 0 THEN
        OPEN C_EMP;
        OPEN C_PROJ;
        CALL DBMS_OUTPUT.PUT_LINE('DEPARTMENT: ' || V_DEPTNAME || ', Employees: ' || V_CNT_EMP);
    ELSE
        CALL DBMS_OUTPUT.PUT_LINE('NO SUCH DEPARTMENT: ' || P_DEPTNO);
    end if;
end;

CALL FN77777.PROC_INFO('C01');