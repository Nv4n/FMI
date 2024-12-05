-- Като използвате схемата DB2SAMPLE
--
-- Напишете заявка, която извежда информация за средния брой часове (PRSTAFF) работен по проект (таблицата PROJECTS).  В резултатното множество да се изведе информацията според, номера на отдела (DEPTNO), според отговорния служител по проекта (RESPEMP) и според главния проект (MAJPROJ) и според номера на отдела и главния проект, както и обобщена информация за всички проекти, без значение отдела, главния проект и отговорния служител. Друга информация не трябва да се извежда в резултатното множество.

SET SCHEMA DB2SAMPLE;

SELECT DEPTNO,RESPEMP,MAJPROJ, DECIMAL(AVG(PRSTAFF),10,2) AS AVG_HOURS FROM DB2SAMPLE.PROJECT
GROUP BY GROUPING SETS (DEPTNO, RESPEMP, MAJPROJ,(DEPTNO,MAJPROJ))
UNION ALL
SELECT DEPTNO,RESPEMP,MAJPROJ, DECIMAL(AVG(PRSTAFF),10,2) AS AVG_HOURS FROM DB2SAMPLE.PROJECT
GROUP BY ROLLUP (DEPTNO, RESPEMP, MAJPROJ)
HAVING GROUPING(DEPTNO)=1 AND GROUPING(RESPEMP)=1 AND GROUPING(MAJPROJ)=1;

SET SCHEMA DB2INST1;

SELECT WORKDEPT,SEX,JOB FROM DB2INST1.EMPLOYEE
WHERE WORKDEPT='D11';

SELECT WORKDEPT,SEX,COUNT(*) FROM DB2INST1.EMPLOYEE
WHERE WORKDEPT='D11' AND SEX = 'F' AND JOB = 'DESIGNER'
GROUP BY  SEX, WORKDEPT;

SELECT SEX FROM DB2INST1.EMPLOYEE E
JOIN DB2INST1.DEPARTMENT D on D.DEPTNO = E.WORKDEPT
WHERE D.MGRNO=E.EMPNO AND DEPTNO='D11';

-- Като използвате схемата DB2SAMPLE
--
-- Напишете заявка, която извежда име на  проект (PROJNAME) и имената на служителите (LASTNAME), работили по този проект, само за тези служители, които са наети на работа (HIREDATE) след крайната дата на проекта (PRENDATE)

SELECT DISTINCT P.PROJNAME,E.LASTNAME FROM DB2SAMPLE.EMPPROJACT EA
JOIN DB2SAMPLE.EMPLOYEE E ON E.EMPNO = EA.EMPNO
JOIN DB2SAMPLE.PROJECT P ON P.PROJNO = EA.PROJNO
WHERE E.HIREDATE > P.PRENDATE;

SELECT * FROM DB2SAMPLE.EMPACT