create table FN3MI0700035.EXAMS
(
    NEXAM       INTEGER generated always as identity
        constraint PK_EXAMS
            primary key,
    TITLE       VARCHAR(100) not null,
    MINPOINTS   SMALLINT default 1,
    MAXPOINTS   SMALLINT default 1,
    NEEDED_EXAM INTEGER
        references FN3MI0700035.EXAMS,
    check ( EXAMS.MINPOINTS > 0 ),
    check ( EXAMS.MINPOINTS <= EXAMS.MAXPOINTS )
);

create table FN3MI0700035.QUESTIONS
(
    NQUESTION INTEGER not null
        constraint PK_QUESTIONS
            primary key
);

create table FN3MI0700035.ANSWERS
(
    NANSWER         INTEGER      not null
        unique,
    NQUESTION       INTEGER      not null
        references FN3MI0700035.QUESTIONS,
    TEXT            VARCHAR(100) not null,
    IS_RIGHT_ANSWER CHARACTER(1) default '0',
    constraint PK_ANSWERS
        primary key (NANSWER, NQUESTION)
);

create table FN3MI0700035.CALCULATIONQUESTIONS
(
    NQUESTION INTEGER      not null
        constraint PK_CALC_QUESTIONS
            primary key
        references FN3MI0700035.QUESTIONS,
    CONDITION VARCHAR(100) not null
);

create table FN3MI0700035.CLOSEDQUESTIONS
(
    NQUESTION INTEGER      not null
        constraint PK_CLOSED_QUESTIONS
            primary key
        references FN3MI0700035.QUESTIONS,
    CONDITION VARCHAR(100) not null
);

create table FN3MI0700035.CONSISTSOF
(
    NEXAM     INTEGER not null
        references FN3MI0700035.EXAMS,
    NQUESTION INTEGER not null
        references FN3MI0700035.QUESTIONS,
    POINTS    REAL default 1,
    constraint PK_CONSISTS_OF
        primary key (NEXAM, NQUESTION),
    check ( POINTS > 0 )
);

create table FN3MI0700035.ESSAYS
(
    NQUESTION  INTEGER      not null
        constraint PK_ESSAYS
            primary key
        references FN3MI0700035.QUESTIONS,
    CONDITION  VARCHAR(100) not null,
    MIN_LENGTH INTEGER,
    MAX_LENGTH INTEGER,
    check ( MIN_LENGTH <= ESSAYS.MAX_LENGTH ),
    check ( MIN_LENGTH > 0 )
);

create table FN3MI0700035.STUDENTS
(
    FN      CHARACTER(10) not null
        constraint PK_STUDENTS
            primary key,
    FNAME   VARCHAR(50)   not null,
    LNAME   VARCHAR(50)   not null,
    FACULTY VARCHAR(100)  not null,
    COURSE  SMALLINT default 1,
    check ( STUDENTS.COURSE > 0 )
);

create table FN3MI0700035.TAKENEXAMS
(
    FN    CHARACTER(10) not null
        references FN3MI0700035.STUDENTS,
    NEXAM INTEGER       not null
        references FN3MI0700035.EXAMS,
    GRADE REAL default 2,
    constraint PK_TAKEN_EXAMS
        primary key (FN, NEXAM),
    check ( GRADE >= 2 )
);

create table FN3MI0700035.TAKESEXAM
(
    FN    CHARACTER(10) not null
        references FN3MI0700035.STUDENTS,
    NEXAM INTEGER       not null
        references FN3MI0700035.EXAMS,
    DATE  DATE default CURRENT DATE,
    constraint PK_TAKES_EXAM
        primary key (FN, NEXAM)
);

