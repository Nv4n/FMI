SET SCHEMA FN24_3MI0700035;

-- T01
CREATE FUNCTION EMP_AGE(EMP_NO INT)
    RETURNS TABLE
            (
                EMPNO CHAR(6),
                AGE   INT
            )
    SPECIFIC EMP_AGE
    RETURN SELECT EMPNO, YEAR( CURRENT_DATE - BIRTHDATE) AS AGE
           FROM DB2SAMPLE.EMP
           WHERE EMPNO = EMP_NO;

SELECT * FROM TABLE (FN24_3MI0700035.EMP_AGE('000010'));
