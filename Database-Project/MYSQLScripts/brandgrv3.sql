CREATE TABLE bride_parents(
id MEDIUMINT NOT NULL AUTO_INCREMENT, 
mother_first_name VARCHAR(30) NOT NULL,
mother_last_name VARCHAR(30) NOT NULL,
mother_birthdate DATE NOT NULL,
father_first_name VARCHAR(30) NOT NULL,
last_name VARCHAR(30) NOT NULL,
father_birthdate DATE NOT NULL,
PRIMARY KEY(id, mother_first_name, father_first_name)
)ENGINE=INNODB;


CREATE TABLE bride (
id MEDIUMINT UNSIGNED NOT NULL AUTO_INCREMENT, 
first_name VARCHAR(30) NOT NULL,
last_name VARCHAR(30) NOT NULL,
birthdate DATE NOT NULL,
username VARCHAR(30) NOT NULL,
password VARCHAR(30) NOT NULL,
email VARCHAR(40) DEFAULT NULL,
phone VARCHAR(12) NOT NULL,
hiv_status ENUM('positive', 'negative') NULL DEFAULT 'negative',
role INT UNSIGNED NOT NULL DEFAULT 2,
par_id MEDIUMINT NOT NULL,
motherFN VARCHAR(30) NULL,
fatherFN VARCHAR(30) NULL,
UNIQUE(username),
INDEX(par_id, motherFN, fatherFN),
FOREIGN KEY (par_id, motherFN, fatherFN)
REFERENCES bride_parents(id, mother_first_name, father_first_name),
PRIMARY KEY(id)
)ENGINE=INNODB;

CREATE TABLE groom_parents(
id MEDIUMINT NOT NULL AUTO_INCREMENT, 
mother_first_name VARCHAR(30) NOT NULL,
mother_last_name VARCHAR(30) NOT NULL,
mother_birthdate DATE NOT NULL,
father_first_name VARCHAR(30) NOT NULL,
last_name VARCHAR(30) NOT NULL,
father_birthdate DATE NOT NULL,
PRIMARY KEY(id, mother_first_name, father_first_name)
)ENGINE=INNODB;


CREATE TABLE groom (
id MEDIUMINT UNSIGNED NOT NULL AUTO_INCREMENT, 
first_name VARCHAR(30) NOT NULL,
last_name VARCHAR(30) NOT NULL,
birthdate DATE NOT NULL,
username VARCHAR(30) NOT NULL,
password VARCHAR(30) NOT NULL,
email VARCHAR(40) DEFAULT NULL,
phone VARCHAR(12) NOT NULL,
hiv_status ENUM('positive', 'negative') NULL DEFAULT 'negative',
role INT UNSIGNED NOT NULL DEFAULT 2,
par_id MEDIUMINT NOT NULL,
motherFN VARCHAR(30) NULL,
fatherFN VARCHAR(30) NULL,
UNIQUE(username),
INDEX(par_id, motherFN, fatherFN),
FOREIGN KEY (par_id, motherFN, fatherFN)
REFERENCES groom_parents(id, mother_first_name, father_first_name),
PRIMARY KEY(id)
)ENGINE=INNODB;

CREATE TABLE official(
id MEDIUMINT NOT NULL AUTO_INCREMENT, 
first_name VARCHAR(30) NOT NULL,
last_name VARCHAR(30) NOT NULL,
birthdate DATE NOT NULL,
username VARCHAR(30) NOT NULL,
password VARCHAR(30) NOT NULL,
email VARCHAR(40) DEFAULT NULL,
phone VARCHAR(12) NOT NULL,
role INT  NOT NULL DEFAULT 3,
UNIQUE(username),
PRIMARY KEY(id)
)ENGINE=INNODB;

CREATE TABLE wedding(
wed_id MEDIUMINT NOT NULL AUTO_INCREMENT,
date DATE NOT NULL,
bride MEDIUMINT UNSIGNED NULL, 
groom MEDIUMINT UNSIGNED NULL,
official MEDIUMINT UNSIGNED NULL,
PRIMARY KEY(wed_id),
INDEX(bride),
INDEX(groom),
FOREIGN KEY(bride)
REFERENCES bride(id),
FOREIGN KEY(groom)
REFERENCES groom(id)
)ENGINE=INNODB;