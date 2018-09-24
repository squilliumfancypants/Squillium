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
no MEDIUMINT UNSIGNED NOT NULL AUTO_INCREMENT, 
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
PRIMARY KEY(no)
)ENGINE=INNODB;