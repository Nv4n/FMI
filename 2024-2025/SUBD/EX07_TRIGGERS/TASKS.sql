SET SCHEMA FN24_3MI0700035;

create table CLASSES_DB
(
    EDUYEAR     CHARACTER(9) not null,
    EDUSEMESTER CHARACTER(1) not null,
    CLASSDAY    VARCHAR(10),
    STARTHOUR   TIME         not null,
    ENDHOUR     TIME         not null
);

create trigger TRIG_BEFORE_INSERT_CLASSES
    BEFORE INSERT
    ON CLASSES_DB
    REFERENCING NEW AS N
    FOR EACH ROW
    WHEN (N.ENDHOUR IS NULL)
    SET N.ENDHOUR = N.STARTHOUR + 1 HOUR + 45 MINUTES;

INSERT INTO CLASSES_DB VALUES ('2024','1','IS','12:32',NULL);
select * from CLASSES_DB;