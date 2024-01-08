-- Q1 Create a database for your comapny name XYZ. 

CREATE DATABASE Pikashow;
USE Pikashow;

-- Q2 Create a Table inside this DB to store employee1 info (id,name , salary)
CREATE TABLE employee1(
	id int PRIMARY KEY,
    name VARCHAR (50),
    salary int 
);

-- Q3 Add the following data in the database.

INSERT INTO employee1 VALUES (4,"adam",2500);
INSERT INTO employee1 VALUES (5, "bob",30000);
INSERT INTO employee1 VALUES (6,"casey",400000);
 

 -- Q4. Select and view all your table data.
 SELECT * FROM employee1;
 
