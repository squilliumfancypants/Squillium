/*
-------------------------------------------------------------------------------------------------- ADMINS -------------------------------------------------------------------------------------------
id, first_name VARCHAR, last_name VARCHAR, birthdate DATE, username VARCHAR, password VARCHAR, email VARCHAR, phone VARCHAR, role INT
*/
INSERT INTO test.administrators VALUES
(NULL, 'Steve', 'Aoki', 19820724, 'adminSteve', 'adminPass', 'djsteve@dj.mail', '987-231-6524', 1);


/*
----------------------------------------------------------------------------------------- BRIDE AND GROOM  PARENTS  --------------------------------------------------------------------------------------
id MEDIUMINT, mother_first_name VARCHAR, mother_last_name VARCHAR, mother_birthdate DATE, 
father_first_name VARCHAR, last_name VARCHAR, father_birthdate DATE
*/
INSERT INTO test.bride_parents VALUES
(NULL, 'Sharren', 'Jones', 19320101, 'Rick', 'Jones', 19450302);

INSERT INTO test.groom_parents VALUES
(NULL, 'Sharrese', 'Jackson', 19320101, 'Ron', 'Jackson', 19450302);

/*
----------------------------------------------------------------------------------------- BRIDE AND GROOM --------------------------------------------------------------------------------------
id, first_name VARCHAR, last_name VARCHAR, birthdate DATE (YYYY-MM-DD), username VARCHAR, password VARCHAR, email VARCHAR, phone INT,
id, hiv_status ENUM('positive', 'negative'),  role INT, INDEX par_index, FOREIGN KEY(parent_id), REFERENCES bride_parents(id),
*/
INSERT INTO test.bride VALUES
(NULL ,'Sharry','Jones', 19910227, 'sharry', 'password', 'holds@on.mail', '615-232-2353', 'positive',  2, NULL, NULL, NULL),
(NULL ,'Tina', 'Fey', 19830114, 'tina', 'password', 'tina@fey.mail', '615-123-4231', 'negative', 2, NULL, NULL, NULL);

INSERT INTO test.groom VALUES
( NULL,'Bob','Ross', 19760420, 'bob', 'password', 'bob@saggot.mail', '615-111-2222', 'negative', 2, NULL, NULL, NULL),
(NULL,'Magic', 'Johnson', 19820318, 'magic', 'password','magic@basketball.mail', '615-222-3333', 'positive', 2, NULL, NULL, NULL),
(NULL ,'Leonard', 'Nemoy', 19431214, 'leonard', 'nemoy', 'spak@trek.mail',  '615-333-4444', 'negative', 2, NULL, NULL, NULL);


/*
------------------------------------------------------------------------------------------------- OFFICIALS ------------------------------------------------------------------------------------------
id, first_name VARCHAR, last_name VARCHAR, birthdate DATE, username VARCHAR, password VARCHAR, email VARCHAR, phone VARCHAR, role INT
*/
INSERT INTO test.official VALUES
(NULL, 'Pastor', 'John', 19720923, 'pastor', 'password', 'pastor@john.mail', '872-123-3442', 3);


/*
---------------------------------------------------------------------------------------------- HEALTHCARE ----------------------------------------------------------------------------------------
id, first_name VARCHAR, last_name VARCHAR, birthdate DATE, username VARCHAR, password VARCHAR, email VARCHAR, phone VARCHAR, role INT
*/
INSERT INTO test.healthcare VALUES
(NULL, 'Nurse', 'Lena', 19720923, 'nurse', 'password', 'lena@hospital.mail', '872-123-3442', 4);


/*
----------------------------------------------------------------------------------------------- WEDDING -------------------------------------------------------------------------------------------
id, date DATE, bride INT, groom INT, official INT
*/
INSERT INTO test.wedding VALUES
(NULL, 20020407, 1, 1, 1);

/*
-------------------------------------------------------------------------------------- Bride and Groom Parents ---------------------------------------------------------------------------------
id , first_name VARCHAR, last_name VARCHAR, birthdate DATE
*/