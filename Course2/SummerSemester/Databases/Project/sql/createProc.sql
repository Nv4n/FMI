SET SCHEMA FN3MI0700035;

CREATE OR REPLACE PROCEDURE PROC_CALC_EXAM_POINTS(IN EXAM_ID INT, OUT EXAM_POINTS REAL)
BEGIN
    SET EXAM_POINTS = (SELECT SUM(POINTS)
                       FROM CONSISTSOF
                       WHERE NEXAM = EXAM_ID);
end;

BEGIN
    DECLARE EXAM_POINTS REAL;
    CALL FN3MI0700035.PROC_CALC_EXAM_POINTS(8, EXAM_POINTS);
    CALL DBMS_OUTPUT.PUT_LINE(DEC(EXAM_POINTS, 8, 2));
end;


CREATE OR REPLACE PROCEDURE PROC_EXAM_AVG_GRADE(IN exam_id INTEGER, OUT avg_grade REAL)
BEGIN
    DECLARE DONE SMALLINT DEFAULT 0;
    DECLARE total_grade REAL DEFAULT 0;
    DECLARE student_count INT DEFAULT 0;
    DECLARE grade REAL;

    DECLARE C CURSOR FOR
        SELECT GRADE FROM TAKENEXAMS WHERE NEXAM = exam_id;

    DECLARE CONTINUE HANDLER FOR NOT FOUND
        BEGIN
            SET DONE = 1;
        end;
    OPEN C;

    READ_LOOP:
    LOOP
        FETCH C INTO grade;
        IF DONE = 1 THEN
            LEAVE READ_LOOP;
        END IF;

        SET total_grade = total_grade + grade;
        SET student_count = student_count + 1;
    END LOOP;

    CLOSE C;

    SET avg_grade = CASE WHEN student_count > 0 THEN total_grade / student_count ELSE -1 END;
END;

BEGIN
    DECLARE AVG_GRADE REAL;
    CALL FN3MI0700035.PROC_EXAM_AVG_GRADE(9, AVG_GRADE);
    CALL DBMS_OUTPUT.PUT_LINE('EXAM_ID: 9, AVG_GRADE: ' || DEC(AVG_GRADE, 8, 2));
end;

CREATE OR REPLACE PROCEDURE PROC_UPDATE_EXAM_POINTS()
BEGIN
    DECLARE exam_id INT;
    DECLARE rows_updated INT;
    DECLARE SQLSTATE CHAR (5) DEFAULT '00000';

    DECLARE C CURSOR FOR
        SELECT NEXAM FROM EXAMS;

    OPEN C;

    WHILE SQLSTATE = '00000'
        DO
            UPDATE CONSISTSOF
            SET POINTS = POINTS + 10
            WHERE NEXAM = exam_id;

            SET rows_updated = (SELECT COUNT(*)
                                FROM CONSISTSOF
                                WHERE NEXAM = exam_id);

            UPDATE EXAMS
            SET MAXPOINTS = MAXPOINTS + (rows_updated * 10)
            WHERE NEXAM = exam_id;

            FETCH C INTO exam_id;
        end while;

    CLOSE C;
END;

BEGIN
    CALL FN3MI0700035.PROC_UPDATE_EXAM_POINTS();
end;

CREATE OR REPLACE PROCEDURE PROC_ADD_STUDENT(IN fac CHAR(10), IN fname VARCHAR(50), IN lname VARCHAR(50),
                                             IN faculty VARCHAR(100), IN course SMALLINT)
BEGIN
    DECLARE CONTINUE HANDLER FOR SQLEXCEPTION
        BEGIN
            SIGNAL SQLSTATE '45000'
                SET MESSAGE_TEXT = 'Грешка при създаване на студент';
        END;

    INSERT INTO STUDENTS (FN, FNAME, LNAME, FACULTY, COURSE)
    VALUES (fac, fname, lname, faculty, course);
END;

BEGIN
    CALL FN3MI0700035.PROC_ADD_STUDENT('AB123CD456', 'Драган', 'Драганов', 'Математическия', 3);
end;