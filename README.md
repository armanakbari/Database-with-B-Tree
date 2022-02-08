# Database-with-B-Tree
I implement a simplistic relational database purly in C++
A database application is a computer program whose primary purpose is retrieving information from a computerized database. One of the most popular databases are relational databases. Data items in relational databases has pre-defined relationships between them.
![image](https://user-images.githubusercontent.com/24752756/152966481-e0d4f7ea-8616-48a3-b976-c6b62296eb5e.png)
## Building a Table:
```
CREATE TABLE {table name} (column1 type,column2 type,...)
```
#### For instance:
```
CREATE TABLE employee (name string,joinDate timestamp,income int)
```
## Inserting into tables:
```
INSERT INTO {table name} VALUES (field1,field2,...)
```
#### For instance:
```
INSERT INTO employee VALUES ("Hamid",2022/8/6,45000)
```
## Removing from from table:
```
DELETE FROM {table name} WHERE {condition}
```
#### For instance:
```
DELETE FROM employee WHERE name=="Hamid"
```
```
DELETE FROM employee WHERE income>40000
```
```
DELETE FROM employee WHERE joinDate<2022/5/7
```
###### Conditions must only consist of == or <>.
## Update a record:
```
UPDATE {table name} SET ("Hamid",2022/8/7,50000) WHERE {condition}
```
#### For instance:
```
UPDATE employee SET ("Hamid",2022/8/7,50000) WHERE name=="Hamid"
```
## Listing records:
```
SELECT {(column1,column2,...) or *} FROM {table name} WHERE condition
```
#### For instance:
```
SELECT * FROM employee WHERE income>45000
SELECT (name,income) FROM employee WHERE income>45000
```
### Take a look at this example:
```
CREATE TABLE employee (name string,joinDate timestamp,income int)
INSERT INTO employee VALUES ("Atena",2019/7/6,55000)
INSERT INTO employee VALUES ("Sajede",2020/5/24,20000)
INSERT INTO employee VALUES ("Zahra",2019/4/5,70000)
INSERT INTO employee VALUES ("Narges",2018/4/5,40000)
INSERT INTO employee VALUES ("Mohammad",2020/1/1,67000)
```
![image](https://user-images.githubusercontent.com/24752756/152968240-aebf844a-a13b-48f9-8da7-a0ad4fc9b715.png)




