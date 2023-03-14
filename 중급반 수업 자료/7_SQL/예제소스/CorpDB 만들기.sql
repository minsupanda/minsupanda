--USE master
--GO
----CorpDB 데이터베이스를 생성.
--CREATE DATABASE CorpDB
--GO
USE CorpDB
GO
----DEPARTMENT Table 생성.
--CREATE TABLE DEPARTMENT(
--DNO		int PRIMARY KEY,	-- 부서번호 / 기본키 설정.
--DNAME	nvarchar(20),		-- 부서명.
--LOC		nchar(20)			-- 지역명.
--)
--GO
----DEPARTMENT Table에 데이터 추가.
--INSERT INTO department(dno, dname, loc) VALUES(10, '경리부', '서울')
--INSERT INTO department(dname, loc, dno) VALUES('인사부', '인천', 20)
--INSERT INTO department(loc, dno, dname) VALUES('대전', 30, '영업부')
--INSERT INTO department VALUES(40, '전산부', '부천')
--GO
--EMPLOYEE Table 생성.
CREATE TABLE EMPLOYEE(
ENO			int PRIMARY KEY,	-- 사원번호 / 기본키 설정.
ENAME		nvarchar(20),		-- 사원명.
JOB			nvarchar(20),		-- 업무명.
MANAGER		int,				-- 사수의 사원번호.
HIREDATE	datetime,			-- 입사일.
SALARY		int,				-- 급여.
COMMISION	int,
DNO			int					-- 부서번호.
)
GO
--EMPLOYEE Table에 데이터 추가.
INSERT INTO employee VALUES(1001, '김사랑', '사원', 1013, '2007-03-01', 300, NULL, 20)
INSERT INTO employee VALUES(1002, '한예슬', '대리', 1005, '2007-04-02', 250, 80, 30)
INSERT INTO employee VALUES(1003, '오지호', '과장', 1008, '2005-02-10', 500, 100, 30)
INSERT INTO employee VALUES(1004, '이병헌', '부장', 1005, '2003-09-02', 600, NULL, 20)
INSERT INTO employee VALUES(1005, '신동엽', '과장', 1005, '2005-04-07', 450, 200, 30)
INSERT INTO employee VALUES(1006, '장동건', '부장', 1008, '2003-10-09', 480, NULL, 30)
INSERT INTO employee VALUES(1007, '이문세', '부장', 1008, '2004-01-08', 520, NULL, 10)
INSERT INTO employee VALUES(1008, '감성우', '차장', 1003, '2004-03-08', 500, 0, 30)
INSERT INTO employee VALUES(1009, '안성기', '사장', NULL, '1996-10-04', 1000, NULL, 20)
INSERT INTO employee VALUES(1010, '이병헌', '과장', 1003, '2005-04-07', 500, NULL, 10)
INSERT INTO employee VALUES(1011, '강혜정', '사원', 1006, '2007-08-09', 300, NULL, 20)
INSERT INTO employee VALUES(1012, '박중훈', '부장', 1003, '2002-10-09', 560, NULL, 20)
INSERT INTO employee VALUES(1013, '조인성', '사원', 1006, '2007-11-09', 250, NULL, 10)
GO
--SALGRADE Table 생성.
CREATE TABLE SALGRADE(
GRADE	int PRIMARY KEY,	-- 급여등급.
LOWSAL	int,				-- 급여 하한값.
HIGHSAL	int					-- 급여 상한값.
)
GO
--SALGRADE Table에 데이터 추가.
INSERT INTO salgrade VALUES(1, 901, 1000)
INSERT INTO salgrade VALUES(2, 501, 901)
INSERT INTO salgrade VALUES(3, 401, 500)
INSERT INTO salgrade VALUES(4, 301, 400)
INSERT INTO salgrade VALUES(5, 201, 300)