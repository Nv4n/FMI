SET SCHEMA FN24_3MI0700035;

SELECT *
FROM DB2INST1.EMPLOYEE;

CREATE TABLE DB2INST_EMPLOYEE LIKE DB2INST1.EMPLOYEE;
ALTER TABLE DB2INST_EMPLOYEE
    ADD PRIMARY KEY (EMPNO);

INSERT INTO DB2INST_EMPLOYEE
SELECT *
FROM DB2INST1.EMPLOYEE
WHERE SALARY > 50000;

SELECT *
FROM DB2INST_EMPLOYEE;

SET SCHEMA FN24_3MI0700035;

SELECT *
FROM EMPLOYEE;

CREATE OR REPLACE FUNCTION MAX_DEPT_SAL(DEPT_ID VARCHAR(6))
    RETURNS DEC(9, 2)
    RETURN SELECT MAX(SALARY)
           FROM EMPLOYEE
           WHERE WORKDEPT = DEPT_ID;

BEGIN
    VALUES (FN24_3MI0700035.MAX_DEPT_SAL('D11'));
end;

CREATE OR REPLACE TRIGGER TRIG_AFTER_INS_EMP_HIRE
    BEFORE INSERT
    ON DB2INST_EMPLOYEE
    REFERENCING NEW AS N
    FOR EACH ROW
    WHEN ( N.HIREDATE < (N.BIRTHDATE + 21 YEARS) )
    SET N.HIREDATE = NULL;

UPDATE DB2INST_EMPLOYEE

INSERT INTO EMPLOYEE VALUES ('000060','IRVING','F','STERN','D11',6423,'2003-09-14','MANAGER' ,16,'M','2001-07-07',72250.00,NULL,500.00
)