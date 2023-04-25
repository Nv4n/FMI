set schema FN3MI0700035;

create table FN3MI0700035.EXAMS
(
    NEXAM         INTEGER generated always as identity
        constraint PK_EXAMS
            primary key,
    TITLE         VARCHAR(255) not null,
    MINPOINTS     SMALLINT default 1,
    MAXPOINTS     SMALLINT default 1,
    SCIENCE_FIELD VARCHAR(255),
    NEEDED_EXAM   INTEGER
        references FN3MI0700035.EXAMS,
    check ( EXAMS.MINPOINTS > 0 ),
    check ( EXAMS.MINPOINTS <= EXAMS.MAXPOINTS )
);


create table FN3MI0700035.QUESTIONS
(
    NQUESTION INTEGER not null GENERATED ALWAYS AS IDENTITY (START WITH 1 INCREMENT BY 1)
        CONSTRAINT PK_QUESTIONS primary key
);

create table FN3MI0700035.ANSWERS
(
    NANSWER         INTEGER      not null UNIQUE GENERATED ALWAYS AS IDENTITY (START WITH 1 INCREMENT BY 1),
    NQUESTION       INTEGER      not null
        references FN3MI0700035.QUESTIONS,
    TEXT            VARCHAR(100) NOT NULL,
    IS_RIGHT_ANSWER CHARACTER(1) default '0',
    CONSTRAINT PK_ANSWERS primary key (NANSWER, NQUESTION)
);

create table FN3MI0700035.CALCULATIONQUESTIONS
(
    NQUESTION INTEGER      not null
        CONSTRAINT PK_CALC_QUESTIONS primary key
        references FN3MI0700035.QUESTIONS,
    CONDITION VARCHAR(255) NOT NULL
);

create table FN3MI0700035.CLOSEDQUESTIONS
(
    NQUESTION INTEGER      not null
        CONSTRAINT PK_CLOSED_QUESTIONS primary key
        references FN3MI0700035.QUESTIONS,
    CONDITION VARCHAR(255) NOT NULL
);

create table FN3MI0700035.CONSISTSOF
(
    NEXAM     INTEGER not null
        references FN3MI0700035.EXAMS,
    NQUESTION INTEGER not null
        references FN3MI0700035.QUESTIONS,
    POINTS    REAL DEFAULT 1,
    CONSTRAINT PK_CONSISTS_OF primary key (NEXAM, NQUESTION),
    check ( POINTS > 0 )
);

create table FN3MI0700035.ESSAYS
(
    NQUESTION  INTEGER      not null
        CONSTRAINT PK_ESSAYS primary key
        references FN3MI0700035.QUESTIONS,
    CONDITION  VARCHAR(255) NOT NULL,
    MIN_LENGTH INTEGER,
    MAX_LENGTH INTEGER,
    CHECK ( MIN_LENGTH <= ESSAYS.MAX_LENGTH ),
    CHECK ( MIN_LENGTH > 0 )
);

create table FN3MI0700035.STUDENTS
(
    FN      CHAR(10)     not null
        CONSTRAINT PK_STUDENTS primary key,
    FNAME   VARCHAR(50)  NOT NULL,
    LNAME   VARCHAR(50)  NOT NULL,
    FACULTY VARCHAR(100) NOT NULL,
    COURSE  SMALLINT default 1,
    check ( STUDENTS.COURSE > 0 )
);

create table FN3MI0700035.TAKENEXAMS
(
    FN    CHAR(10) not null
        references FN3MI0700035.STUDENTS,
    NEXAM INTEGER  not null
        references FN3MI0700035.EXAMS,
    GRADE REAL default 2,
    CONSTRAINT PK_TAKEN_EXAMS primary key (FN, NEXAM),
    check ( GRADE >= 2 )
);

create table FN3MI0700035.TAKESEXAM
(
    FN    CHAR(10) not null
        references FN3MI0700035.STUDENTS,
    NEXAM INTEGER  not null
        references FN3MI0700035.EXAMS,
    DATE  DATE default CURRENT DATE,
    CONSTRAINT PK_TAKES_EXAM primary key (FN, NEXAM)
);

