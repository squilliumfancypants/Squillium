CREATE TABLE bride_parents(
id MEDIUMINT NOT NULL AUTO_INCREMENT, 
mother_first_name VARCHAR(30) NOT NULL,
mother_last_name VARCHAR(30) NOT NULL,
mother_birthdate DATE NOT NULL,
father_first_name VARCHAR(30) NOT NULL,
last_name VARCHAR(30) NOT NULL,
father_birthdate DATE NOT NULL,
PRIMARY KEY(id)
);