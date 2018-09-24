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
mother VARCHAR(30) NULL,
father VARCHAR(30) NULL, 
role INT UNSIGNED NOT NULL DEFAULT 2,
UNIQUE(username),
PRIMARY KEY(id)
);