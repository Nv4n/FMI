SET SCHEMA DB2SAMPLE;

-- T01
SELECT EMPNO, LASTNAME, SALARY, WORKDEPT
FROM EMP
WHERE SALARY BETWEEN 22000 AND 24000
    AND WORKDEPT = 'D11'
   OR WORKDEPT = 'D21';

-- T02
SELECT COUNT(EMPNO)                AS EMP_COUNT,
       MIN(SALARY)                 AS MIN_SALARY,
       MAX(SALARY)                 AS MAX_SALARY,
       DECIMAL(AVG(SALARY), 10, 2) AS AVG_SALARY,
       EDLEVEL
FROM EMP
WHERE EDLEVEL = 16
GROUP BY EDLEVEL;

-- T03
SELECT COUNT(EMPNO)                AS EMP_COUNT,
       MIN(SALARY)                 AS MIN_SALARY,
       MAX(SALARY)                 AS MAX_SALARY,
       DECIMAL(AVG(SALARY), 10, 2) AS AVG_SALARY,
       WORKDEPT
FROM EMP
WHERE EDLEVEL = 16
GROUP BY WORKDEPT
HAVING COUNT(EMPNO) >= 5;

-- T04
SELECT WORKDEPT, SEX, SUM(SALARY) AS TOTAL, MIN(SALARY) AS MIN_SALARY, MAX(SALARY) AS MAX_SALARY
FROM EMP
WHERE WORKDEPT LIKE 'D%'
GROUP BY GROUPING SETS ( (WORKDEPT),
                         (SEX),
                         (WORKDEPT, SEX)
    );

-- T05
SELECT WORKDEPT,
       DECIMAL(AVG(SALARY), 10, 2)             AS AVG,
       RANK() OVER (ORDER BY AVG(SALARY) DESC ) AS Salary_Rank
FROM EMP
GROUP BY WORKDEPT
ORDER BY WORKDEPT;