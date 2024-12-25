SET SCHEMA FN24_3MI0700035;

-- Ползваме таблиците по образец на DB2HR

CREATE OR REPLACE PROCEDURE DEPT_ID_TO_DEPT_INFO(IN ID INT)
BEGIN
    DECLARE DEPT_NAME VARCHAR(30);
    DECLARE MIN_SAL,MAX_SAL,AVG_SAL,AVG_ABOVE_AVG_SAL DEC(8, 2);
    DECLARE SQLCODE INT;
    SET AVG_SAL = (SELECT DEC(AVG(SALARY), 8, 2) FROM EMPLOYEES WHERE DEPARTMENT_ID = ID GROUP BY DEPARTMENT_ID);
    CALL DBMS_OUTPUT.PUT_LINE(AVG_SAL);
    IF NOT EXISTS (SELECT 1 FROM DEPARTMENTS WHERE DEPARTMENT_ID = ID) THEN
        SIGNAL SQLSTATE '02000'
            SET MESSAGE_TEXT = 'Department not found';
    ELSE
        SET (DEPT_NAME, MIN_SAL, MAX_SAL, AVG_ABOVE_AVG_SAL) = (SELECT D.DEPARTMENT_NAME,
                                                                       MIN(E.SALARY)                                                   AS MIN_SALARY,
                                                                       MAX(E.SALARY)                                                   AS MAX_SALARY,
                                                                       DEC(AVG(CASE WHEN E.SALARY >= AVG_SAL THEN E.SALARY END), 8, 2) AS AVG_ABOVE_AVG_SAL
                                                                FROM DEPARTMENTS D
                                                                         JOIN EMPLOYEES E ON E.DEPARTMENT_ID = D.DEPARTMENT_ID

                                                                WHERE D.DEPARTMENT_ID = ID
                                                                GROUP BY D.DEPARTMENT_ID, D.DEPARTMENT_NAME);
        CALL DBMS_OUTPUT.PUT_LINE('DEPT_NAME: ' || DEPT_NAME ||
                                  ', MIN: ' || MIN_SAL || ', MAX: ' || MAX_SAL || ', AVG_ABOVE_AVG: ' ||
                                  AVG_ABOVE_AVG_SAL);
    END IF;
end;

BEGIN
    CALL FN24_3MI0700035.DEPT_ID_TO_DEPT_INFO(50);
end;