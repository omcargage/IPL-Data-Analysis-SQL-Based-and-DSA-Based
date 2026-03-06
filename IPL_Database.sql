-- MySQL dump 10.13  Distrib 8.0.41, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: ipl_database
-- ------------------------------------------------------
-- Server version	8.0.40

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `captain_names`
--

DROP TABLE IF EXISTS `captain_names`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `captain_names` (
  `ï»¿Match_ID` int DEFAULT NULL,
  `home_captain` text,
  `away_captain` text
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `captain_names`
--

LOCK TABLES `captain_names` WRITE;
/*!40000 ALTER TABLE `captain_names` DISABLE KEYS */;
INSERT INTO `captain_names` VALUES (1422119,'Ruturaj Gaikwad','Faf du Plessis'),(1422120,'Shikhar Dhawan','Rishabh Pant'),(1422121,'Shreyas Iyer','Pat Cummins'),(1422122,'Sanju Samson','KL Rahul'),(1422123,'Shubman Gill','Hardik Pandya'),(1422124,'Faf du Plessis','Shikhar Dhawan'),(1422125,'Ruturaj Gaikwad','Shubman Gill'),(1422126,'Pat Cummins','Hardik Pandya'),(1422127,'Sanju Samson','Rishabh Pant'),(1422128,'Faf du Plessis','Shreyas Iyer'),(1422129,'Nicholas Pooran','Shikhar Dhawan'),(1422130,'Shubman Gill','Pat Cummins'),(1422131,'Rishabh Pant','Ruturaj Gaikwad'),(1422132,'Hardik Pandya','Sanju Samson'),(1422133,'Faf du Plessis','KL Rahul'),(1422134,'Rishabh Pant','Shreyas Iyer'),(1422135,'Shubman Gill','Shikhar Dhawan'),(1422136,'Pat Cummins','Ruturaj Gaikwad'),(1422137,'Sanju Samson','Faf du Plessis'),(1422138,'Hardik Pandya','Rishabh Pant'),(1422139,'KL Rahul','Shubman Gill'),(1426260,'Ruturaj Gaikwad','Shreyas Iyer'),(1426261,'Shikhar Dhawan','Pat Cummins'),(1426262,'Sanju Samson','Shubman Gill'),(1426263,'Hardik Pandya','Faf du Plessis'),(1426264,'KL Rahul','Rishabh Pant'),(1426265,'Sam Curran','Sanju Samson'),(1426266,'Shreyas Iyer','KL Rahul'),(1426267,'Hardik Pandya','Ruturaj Gaikwad'),(1426268,'Faf du Plessis','Pat Cummins'),(1426269,'Shreyas Iyer','Sanju Samson'),(1426270,'Shubman Gill','Rishabh Pant'),(1426271,'Sam Curran','Hardik Pandya'),(1426272,'KL Rahul','Ruturaj Gaikwad'),(1426273,'Rishabh Pant','Pat Cummins'),(1426274,'Shreyas Iyer','Faf du Plessis'),(1426275,'Sam Curran','Shubman Gill'),(1426276,'Sanju Samson','Hardik Pandya'),(1426277,'Ruturaj Gaikwad','KL Rahul'),(1426278,'Rishabh Pant','Shubman Gill'),(1426279,'Pat Cummins','Faf du Plessis'),(1426280,'Shreyas Iyer','Sam Curran'),(1426281,'Rishabh Pant','Hardik Pandya'),(1426282,'KL Rahul','Sanju Samson'),(1426283,'Shubman Gill','Faf du Plessis'),(1426284,'Ruturaj Gaikwad','Pat Cummins'),(1426285,'Shreyas Iyer','Rishabh Pant'),(1426286,'KL Rahul','Hardik Pandya'),(1426287,'Ruturaj Gaikwad','Sam Curran'),(1426288,'Pat Cummins','Sanju Samson'),(1426289,'Hardik Pandya','Shreyas Iyer'),(1426290,'Faf du Plessis','Shubman Gill'),(1426291,'Sam Curran','Ruturaj Gaikwad'),(1426292,'KL Rahul','Shreyas Iyer'),(1426293,'Hardik Pandya','Pat Cummins'),(1426294,'Rishabh Pant','Sanju Samson'),(1426295,'Pat Cummins','KL Rahul'),(1426296,'Sam Curran','Faf du Plessis');
/*!40000 ALTER TABLE `captain_names` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `key_players`
--

DROP TABLE IF EXISTS `key_players`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `key_players` (
  `ï»¿Match_ID` int DEFAULT NULL,
  `home_key_batsman` text,
  `home_key_bowler` text,
  `away_key_batsman` text,
  `away_key_bowler` text
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `key_players`
--

LOCK TABLES `key_players` WRITE;
/*!40000 ALTER TABLE `key_players` DISABLE KEYS */;
INSERT INTO `key_players` VALUES (1422119,'Rachin Ravindra,Shivam Dube','Mustafizur Rahman,Deepak Chahar','Anuj Rawat,Dinesh Karthik','Cameron Green,Karn Sharma'),(1422120,'Sam Curran,Liam Livingstone','Arshdeep Singh,Harshal Patel','Shai Hope,Abishek Porel','Kuldeep Yadav,Khaleel Ahmed'),(1422121,'Andre Russell,Phil Salt','Harshit Rana,Andre Russell','Heinrich Klaasen,Mayank Agarwal','T Natarajan,Mayank Markande'),(1422122,'Sanju Samson,Riyan Parag','Trent Boult,Sandeep Sharma','Nicholas Pooran,KL Rahul','Naveen-ul-Haq,Ravi Bishnoi'),(1422123,'Sai Sudharsan,Shubman Gill','Azmatullah Omarzai,Spencer Johnson','Dewald Brevis,Rohit Sharma','Jasprit Bumrah,Gerald Coetzee'),(1422124,'Virat Kohli,Dinesh Karthik','Mohammed Siraj,Glenn Maxwell','Shikhar Dhawan,Jitesh Sharma','Harpreet Brar,Kagiso Rabada'),(1422125,'Shivam Dube,Ruturaj Gaikwad','Tushar Deshpande,Deepak Chahar','Sai Sudharsan,Wriddhiman Saha','Rashid Khan,Sai Kishore'),(1422126,'Heinrich Klaasen,Abhishek Sharma','Pat Cummins,Jaydev Unadkat','Tilak Varma,Tim David','Hardik Pandya,Piyush Chawla'),(1422127,'Riyan Parag,Ravichandran Ashwin','Yuzvendra Chahal,Nandre Burger','David Warner,Tristan Stubbs','Axar Patel,Khaleel Ahmed'),(1422128,'Virat Kohli,Cameron Green','Vijaykumar Vyshak,Mayank Dagar','Venkatesh Iyer,Sunil Narine','Andre Russell,Harshit Rana'),(1422129,'Quinton de Kock,Krunal Pandya','Mayank Yadav,Mohsin Khan','Shikhar Dhawan,Jonny Bairstow','Sam Curran,Arshdeep Singh'),(1422130,'Sai Sudharsan,David Miller','Mohit Sharma,Azmatullah Omarzai','Abdul Samad,Abhishek Sharma','Pat Cummins,Shahbaz Ahmed'),(1422131,'David Warner,Rishabh Pant','Mukesh Kumar,Khaleel Ahmed','Ajinkya Rahane,MS Dhoni','Matheesha Pathirana,Ravindra Jadeja'),(1422132,'Hardik Pandya,Tilak Varma','Akash Madhwal,Kwena Maphaka','Riyan Parag,Ravichandran Ashwin','Yuzvendra Chahal,Trent Boult'),(1422133,'Mahipal Lomror,Rajat Patidar','Glenn Maxwell,Yash Dayal','Quinton de Kock,Nicholas Pooran','Mayank Yadav,Naveen-ul-Haq'),(1422134,'Rishabh Pant,Tristan Stubbs','Anrich Nortje,Ishant Sharma','Sunil Narine,Angkrish Raghuvanshi','Vaibhav Arora,Varun Chakravarthy'),(1422135,'Shubman Gill,Sai Sudharsan','Noor Ahmad,Darshan Nalkande','Shashank Singh,Prabhsimran Singh','Kagiso Rabada,Harpreet Brar'),(1422136,'Aiden Markram,Abhishek Sharma','Bhuvneshwar Kumar,Shahbaz Ahmed','Shivam Dube,Ajinkya Rahane','Moeen Ali,Maheesh Theekshana'),(1422137,'Jos Buttler,Sanju Samson','Yuzvendra Chahal,Nandre Burger','Virat Kohli,Faf du Plessis','Reece Topley,Mohammed Siraj'),(1422138,'Rohit Sharma,Tim David','Gerald Coetzee,Jasprit Bumrah','Tristan Stubbs,Prithvi Shaw','Axar Patel,Anrich Nortje'),(1422139,'Marcus Stoinis,KL Rahul','Yash Thakur,Krunal Pandya','Sai Sudharsan,Rahul Tewatia','Umesh Yadav,Darshan Nalkande'),(1426260,'Ruturaj Gaikwad,Shivam Dube','Ravindra Jadeja,Tushar Deshpande','Shreyas Iyer,Sunil Narine','Vaibhav Arora,Sunil Narine'),(1426261,'Shashank Singh,Ashutosh Sharma','Arshdeep Singh,Harshal Patel','Nitish Kumar Reddy,Abdul Samad','Bhuvneshwar Kumar,Pat Cummins'),(1426262,'Riyan Parag,Sanju Samson','Kuldeep Sen,Yuzvendra Chahal','Shubman Gill,Sai Sudharsan','Rashid Khan,Umesh Yadav'),(1426263,'Ishan Kishan,Suryakumar Yadav','Jasprit Bumrah,Shreyas Gopal','Faf du Plessis,Dinesh Karthik','Vijaykumar Vyshak,Will Jacks'),(1426264,'Ayush Badoni,KL Rahul','Ravi Bishnoi,Naveen-ul-Haq','Jake Fraser-McGurk,Rishabh Pant','Kuldeep Yadav,Khaleel Ahmed'),(1426265,'Ashutosh Sharma,Jitesh Sharma','Kagiso Rabada,Sam Curran','Yashasvi Jaiswal,Shimron Hetmyer','Keshav Maharaj,Avesh Khan'),(1426266,'Phil Salt,Shreyas Iyer','Mitchell Starc,Andre Russell','Nicholas Pooran,KL Rahul','Mohsin Khan,Shamar Joseph'),(1426267,'Rohit Sharma,Tilak Varma','Hardik Pandya,Shreyas Gopal','Ruturaj Gaikwad,Shivam Dube','Matheesha Pathirana,Tushar Deshpande'),(1426268,'Dinesh Karthik,Faf du Plessis','Lockie Ferguson,Reece Topley','Travis Head,Heinrich Klaasen','Pat Cummins,Mayank Markande'),(1426269,'Sunil Narine,Angkrish Raghuvanshi','Sunil Narine,Varun Chakravarthy','Jos Buttler,Riyan Parag','Avesh Khan,Kuldeep Sen'),(1426270,'Rashid Khan,Sai Sudharsan','Sandeep Warrier,Rashid Khan','Jake Fraser-McGurk,Shai Hope','Mukesh Kumar,Ishant Sharma'),(1426271,'Ashutosh Sharma,Shashank Singh','Harshal Patel,Sam Curran','Suryakumar Yadav,Rohit Sharma','Jasprit Bumrah,Gerald Coetzee'),(1426272,'KL Rahul,Quinton de Kock','Krunal Pandya,Marcus Stoinis','Ravindra Jadeja,Ajinkya Rahane','Matheesha Pathirana,Mustafizur Rahman'),(1426273,'Jake Fraser-McGurk,Rishabh Pant','Kuldeep Yadav,Axar Patel','Travis Head,Shahbaz Ahmed','T Natarajan,Nitish Kumar Reddy'),(1426274,'Shreyas Iyer,Phil Salt','Andre Russell,Harshit Rana','Will Jacks,Rajat Patidar','Cameron Green,Yash Dayal'),(1426275,'Prabhsimran Singh,Harpreet Brar','Harshal Patel,Liam Livingstone','Rahul Tewatia,Shubman Gill','Sai Kishore,Noor Ahmad'),(1426276,'Yashasvi Jaiswal,Sanju Samson','Sandeep Sharma,Trent Boult','Tilak Varma,Nehal Wadhera','Piyush Chawla,Mohammad Nabi'),(1426277,'Ruturaj Gaikwad,Shivam Dube','Matheesha Pathirana,Deepak Chahar','Marcus Stoinis,Nicholas Pooran','Matt Henry,Yash Thakur'),(1426278,'Rishabh Pant,Axar Patel','Rasikh Salam,Kuldeep Yadav','Sai Sudharsan,David Miller','Sandeep Warrier,Noor Ahmad'),(1426279,'Shahbaz Ahmed,Abhishek Sharma','Jaydev Unadkat,T Natarajan','Virat Kohli,Rajat Patidar','Cameron Green,Karn Sharma'),(1426280,'Phil Salt,Sunil Narine','Sunil Narine,Ramandeep Singh','Jonny Bairstow,Shashank Singh','Arshdeep Singh,Rahul Chahar'),(1426281,'Jake Fraser-McGurk,Tristan Stubbs','Rasikh Salam,Mukesh Kumar','Tilak Varma,Hardik Pandya','Jasprit Bumrah,Mohammad Nabi'),(1426282,'KL Rahul,Deepak Hooda','Marcus Stoinis,Amit Mishra','Sanju Samson,Dhruv Jurel','Sandeep Sharma,Ravichandran Ashwin'),(1426283,'Sai Sudharsan,M Shahrukh Khan','Sai Kishore,Noor Ahmad','Will Jacks,Virat Kohli','Swapnil Singh,Glenn Maxwell'),(1426284,'Ruturaj Gaikwad,Daryl Mitchell','Tushar Deshpande,Matheesha Pathirana','Aiden Markram,Heinrich Klaasen','Bhuvneshwar Kumar,Jaydev Unadkat'),(1426285,'Phil Salt,Shreyas Iyer','Varun Chakravarthy,Harshit Rana','Kuldeep Yadav,Rishabh Pant','Axar Patel,Lizaad Williams'),(1426286,'Marcus Stoinis,KL Rahul','Mohsin Khan,Naveen-ul-Haq','Nehal Wadhera,Tim David','Hardik Pandya,Mohammad Nabi'),(1426287,'Ruturaj Gaikwad,Ajinkya Rahane','Richard Gleeson,Shivam Dube','Jonny Bairstow,Rilee Rossouw','Rahul Chahar,Harpreet Brar'),(1426288,'Nitish Kumar Reddy,Travis Head','Bhuvneshwar Kumar,Pat Cummins','Riyan Parag,Yashasvi Jaiswal','Avesh Khan,Sandeep Sharma'),(1426289,'Suryakumar Yadav,Tim David','Jasprit Bumrah,Nuwan Thushara','Venkatesh Iyer,Manish Pandey','Mitchell Starc,Varun Chakravarthy'),(1426290,'Faf du Plessis,Virat Kohli','Yash Dayal,Vijaykumar Vyshak','M Shahrukh Khan,Rahul Tewatia','Josh Little,Noor Ahmad'),(1426291,'Prabhsimran Singh,Shashank Singh','Rahul Chahar,Harshal Patel','Ravindra Jadeja,Ruturaj Gaikwad','Ravindra Jadeja,Simarjeet Singh'),(1426292,'Marcus Stoinis,KL Rahul','Naveen-ul-Haq,Yudhvir Singh','Sunil Narine,Phil Salt','Harshit Rana,Varun Chakravarthy'),(1426293,'Suryakumar Yadav,Tilak Varma','Hardik Pandya,Piyush Chawla','Travis Head,Pat Cummins','Bhuvneshwar Kumar,Pat Cummins'),(1426294,'Abishek Porel,Jake Fraser-McGurk','Kuldeep Yadav,Mukesh Kumar','Sanju Samson,Riyan Parag','Ravichandran Ashwin,Sandeep Sharma'),(1426295,'Travis Head,Abhishek Sharma','Bhuvneshwar Kumar,Pat Cummins','Ayush Badoni,Nicholas Pooran','Krishnappa Gowtham,Ravi Bishnoi'),(1426296,'Rilee Rossouw,Shashank Singh','Harshal Patel,Vidwath Kaverappa','Virat Kohli,Rajat Patidar','Mohammed Siraj,Swapnil Singh');
/*!40000 ALTER TABLE `key_players` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `match_details`
--

DROP TABLE IF EXISTS `match_details`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `match_details` (
  `ï»¿season` int DEFAULT NULL,
  `Match_ID` int DEFAULT NULL,
  `match_name` text,
  `home_team` text,
  `away_team` text,
  `toss_won` text,
  `decision` text,
  `1st_inning_score` bigint DEFAULT NULL,
  `2nd_inning_score` bigint DEFAULT NULL,
  `home_score` bigint DEFAULT NULL,
  `away_score` bigint DEFAULT NULL,
  `winner` text,
  `result` text
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `match_details`
--

LOCK TABLES `match_details` WRITE;
/*!40000 ALTER TABLE `match_details` DISABLE KEYS */;
INSERT INTO `match_details` VALUES (2024,1426289,'Mumbai Indians v Kolkata Knight Riders','MI','KKR','MI','BOWL FIRST',169,145,145,169,'KKR','KKR won by 24 runs');
/*!40000 ALTER TABLE `match_details` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `score_details`
--

DROP TABLE IF EXISTS `score_details`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `score_details` (
  `ï»¿venue_id` int DEFAULT NULL,
  `match_name` text,
  `Player_of_the_Match` text,
  `home_overs` double DEFAULT NULL,
  `home_runs` int DEFAULT NULL,
  `home_wickets` int DEFAULT NULL,
  `home_boundaries` int DEFAULT NULL,
  `away_overs` int DEFAULT NULL,
  `away_runs` int DEFAULT NULL,
  `away_wickets` int DEFAULT NULL,
  `away_boundaries` int DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `score_details`
--

LOCK TABLES `score_details` WRITE;
/*!40000 ALTER TABLE `score_details` DISABLE KEYS */;
INSERT INTO `score_details` VALUES (58008,'Chennai Super Kings v Royal Challengers Bengaluru','Mustafizur Rahman',18.4,176,4,19,20,173,6,22),(1290799,'Punjab Kings v Delhi Capitals','Sam Curran',19.2,177,6,24,20,174,9,24),(57980,'Kolkata Knight Riders v Sunrisers Hyderabad','Andre Russell',20,208,7,27,20,204,7,27),(58162,'Rajasthan Royals v Lucknow Super Giants','Sanju Samson',20,193,4,21,20,173,6,19),(57851,'Gujarat Titans v Mumbai Indians','Sai Sudharsan',20,168,6,18,20,162,9,22),(57897,'Royal Challengers Bengaluru v Punjab Kings','Virat Kohli',19.2,178,6,24,20,176,6,23),(58008,'Chennai Super Kings v Gujarat Titans','Shivam Dube',20,206,6,27,20,143,8,16),(58142,'Sunrisers Hyderabad v Mumbai Indians','Abhishek Sharma',20,277,3,37,20,246,5,32),(58162,'Rajasthan Royals v Delhi Capitals','Riyan Parag',20,185,5,25,20,173,5,22),(57897,'Royal Challengers Bengaluru v Kolkata Knight Riders','Sunil Narine',20,182,6,22,17,186,3,22),(1070094,'Lucknow Super Giants v Punjab Kings','Mayank Yadav',20,199,8,25,20,178,5,25),(57851,'Gujarat Titans v Sunrisers Hyderabad','Mohit Sharma',19.1,168,3,19,20,162,8,18),(58547,'Delhi Capitals v Chennai Super Kings','Khaleel Ahmed',20,191,5,25,20,171,6,20),(58324,'Mumbai Indians v Rajasthan Royals','Trent Boult',20,125,9,13,15,127,4,17),(57897,'Royal Challengers Bengaluru v Lucknow Super Giants','Mayank Yadav',19.4,153,10,19,20,181,5,24),(58547,'Delhi Capitals v Kolkata Knight Riders','Sunil Narine',17.2,166,10,23,20,272,7,40),(57851,'Gujarat Titans v Punjab Kings','Shashank Singh',20,199,4,26,20,200,7,26),(58142,'Sunrisers Hyderabad v Chennai Super Kings','Abhishek Sharma',18.1,166,4,20,20,165,5,20),(58162,'Rajasthan Royals v Royal Challengers Bengaluru','Jos Buttler',19.1,189,4,26,20,183,3,21),(58324,'Mumbai Indians v Delhi Capitals','Romario Shepherd',20,234,5,33,20,205,8,29),(1070094,'Lucknow Super Giants v Gujarat Titans','Yash Thakur',20,163,5,17,19,130,10,13),(58008,'Chennai Super Kings v Kolkata Knight Riders','Ravindra Jadeja',17.4,141,3,18,20,137,9,15),(1290799,'Punjab Kings v Sunrisers Hyderabad','Nitish Kumar Reddy',20,180,6,25,20,182,9,26),(58162,'Rajasthan Royals v Gujarat Titans','Rashid Khan',20,196,3,24,20,199,7,24),(58324,'Mumbai Indians v Royal Challengers Bengaluru','Jasprit Bumrah',15.3,199,3,33,20,196,8,26),(1070094,'Lucknow Super Giants v Delhi Capitals','Kuldeep Yadav',20,167,7,19,18,170,4,22),(1290799,'Punjab Kings v Rajasthan Royals','Shimron Hetmyer',20,147,8,15,20,152,7,17),(57980,'Kolkata Knight Riders v Lucknow Super Giants','Phil Salt',15.4,162,2,25,20,161,7,20),(58324,'Mumbai Indians v Chennai Super Kings','Matheesha Pathirana',20,186,6,27,20,206,4,30),(57897,'Royal Challengers Bengaluru v Sunrisers Hyderabad','Travis Head',20,262,7,40,20,287,3,41),(57980,'Kolkata Knight Riders v Rajasthan Royals','Jos Buttler',20,223,6,33,20,224,8,32),(57851,'Gujarat Titans v Delhi Capitals','Rishabh Pant',17.3,89,10,9,9,92,4,15),(1290799,'Punjab Kings v Mumbai Indians','Jasprit Bumrah',19.1,183,10,22,20,192,7,24),(1070094,'Lucknow Super Giants v Chennai Super Kings','KL Rahul',19,180,2,23,20,176,6,21),(58040,'Delhi Capitals v Sunrisers Hyderabad','Travis Head',19.1,199,10,31,20,266,7,40),(57980,'Kolkata Knight Riders v Royal Challengers Bengaluru','Andre Russell',20,222,6,34,20,221,10,33),(1290799,'Punjab Kings v Gujarat Titans','Sai Kishore',20,142,10,17,19,146,7,18),(58162,'Rajasthan Royals v Mumbai Indians','Sandeep Sharma',18.4,183,1,26,20,179,9,22),(58008,'Chennai Super Kings v Lucknow Super Giants','Marcus Stoinis',20,210,4,29,19,213,4,29),(58040,'Delhi Capitals v Gujarat Titans','Rishabh Pant',20,224,4,34,20,220,8,32),(58142,'Sunrisers Hyderabad v Royal Challengers Bengaluru','Rajat Patidar',20,171,8,19,20,206,7,26),(57980,'Kolkata Knight Riders v Punjab Kings','Jonny Bairstow',20,261,6,40,18,262,2,39),(58040,'Delhi Capitals v Mumbai Indians','Jake Fraser-McGurk',20,257,4,39,20,247,9,35),(1070094,'Lucknow Super Giants v Rajasthan Royals','Sanju Samson',20,196,5,22,19,199,3,28),(57851,'Gujarat Titans v Royal Challengers Bengaluru','Will Jacks',20,200,3,25,16,206,1,28),(58008,'Chennai Super Kings v Sunrisers Hyderabad','Ruturaj Gaikwad',20,212,3,28,19,134,10,13),(57980,'Kolkata Knight Riders v Delhi Capitals','Varun Chakravarthy',16.3,157,3,23,20,153,9,21),(1070094,'Lucknow Super Giants v Mumbai Indians','Marcus Stoinis',19.2,145,6,17,20,144,7,16),(58008,'Chennai Super Kings v Punjab Kings','Harpreet Brar',20,162,7,17,18,163,3,22),(58142,'Sunrisers Hyderabad v Rajasthan Royals','Bhuvneshwar Kumar',20,201,3,28,20,200,7,27),(58324,'Mumbai Indians v Kolkata Knight Riders','Venkatesh Iyer',18.5,145,10,17,20,169,10,21),(57897,'Royal Challengers Bengaluru v Gujarat Titans','Mohammed Siraj',13.4,152,6,26,19,147,10,22),(58056,'Punjab Kings v Chennai Super Kings','Ravindra Jadeja',20,139,9,17,20,167,9,20),(1070094,'Lucknow Super Giants v Kolkata Knight Riders','Sunil Narine',16.1,137,10,17,20,235,6,34),(58324,'Mumbai Indians v Sunrisers Hyderabad','Suryakumar Yadav',17.2,174,3,27,20,173,8,18),(58040,'Delhi Capitals v Rajasthan Royals','Kuldeep Yadav',20,221,8,34,20,201,8,29),(58142,'Sunrisers Hyderabad v Lucknow Super Giants','Travis Head',9.4,167,0,30,20,165,4,20),(58056,'Punjab Kings v Royal Challengers Bengaluru','Virat Kohli',17,181,10,30,20,241,7,35);
/*!40000 ALTER TABLE `score_details` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `umpire_details`
--

DROP TABLE IF EXISTS `umpire_details`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `umpire_details` (
  `ï»¿venue_id` int DEFAULT NULL,
  `umpire1` text,
  `umpire2` text,
  `tv_umpire` text,
  `referee` text,
  `reserve_umpire` text
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `umpire_details`
--

LOCK TABLES `umpire_details` WRITE;
/*!40000 ALTER TABLE `umpire_details` DISABLE KEYS */;
INSERT INTO `umpire_details` VALUES (58008,'Saiyed Khalid','Virender Sharma','Nitin Menon','Javagal Srinath','Madanagopal Kuppuraj'),(1290799,'Jayaraman Madanagopal','Nikhil Patwardhan','Alex Wharf','Narayanan Kutty','Pranav Joshi'),(57980,'Yeshwant Barde','Rohan Pandit','Bruce Oxenford','Manu Nayar','Mohit Krishnadas'),(58162,'Kumar Dharmasena','Akshay Totre','KN Ananthapadmanabhan','Prakash Bhatt','Vaibhav Dhokre'),(57851,'Vineet Kulkarni','Virender Sharma','Nitin Menon','Javagal Srinath','Madanagopal Kuppuraj'),(57897,'Anil Chaudhary','Saidharshan Kumar','Bruce Oxenford','Manu Nayar','Mohit Krishnadas'),(58008,'Tapan Sharma','Alex Wharf','Jayaraman Madanagopal','Narayanan Kutty','Pranav Joshi'),(58142,'KN Ananthapadmanabhan','Ulhas Gandhe','Kumar Dharmasena','Prakash Bhatt','Vaibhav Dhokre'),(58162,'Nitin Menon','Nand Kishore','Virender Sharma','Javagal Srinath','Madanagopal Kuppuraj'),(57897,'Anil Chaudhary','Rohan Pandit','Bruce Oxenford','Manu Nayar','Mohit Krishnadas'),(1070094,'Jayaraman Madanagopal','Navdeep Singh','Alex Wharf','Narayanan Kutty','Pranav Joshi'),(57851,'Saiyed Khalid','Virender Sharma','None','Javagal Srinath','Madanagopal Kuppuraj'),(58547,'Kumar Dharmasena','Vinod Seshan','KN Ananthapadmanabhan','Prakash Bhatt','Vaibhav Dhokre'),(58324,'Yeshwant Barde','Saidharshan Kumar','Bruce Oxenford','Manu Nayar','Mohit Krishnadas'),(57897,'Jayaraman Madanagopal','Nikhil Patwardhan','Alex Wharf','Narayanan Kutty','Pranav Joshi'),(58547,'Ulhas Gandhe','Akshay Totre','Kumar Dharmasena','Prakash Bhatt','Vaibhav Dhokre'),(57851,'Vineet Kulkarni','Nitin Menon','Virender Sharma','Javagal Srinath','Madanagopal Kuppuraj'),(58142,'Yeshwant Barde','Rohan Pandit','Bruce Oxenford','Manu Nayar','Mohit Krishnadas'),(58162,'Tapan Sharma','Alex Wharf','Jayaraman Madanagopal','Narayanan Kutty','Pranav Joshi'),(58324,'Kumar Dharmasena','Ulhas Gandhe','KN Ananthapadmanabhan','Prakash Bhatt','Vaibhav Dhokre'),(1070094,'Nand Kishore','Virender Sharma','Nitin Menon','Javagal Srinath','Madanagopal Kuppuraj'),(58008,'Anil Chaudhary','Saidharshan Kumar','Bruce Oxenford','Manu Nayar','Mohit Krishnadas'),(1290799,'Navdeep Singh','Nikhil Patwardhan','Alex Wharf','Narayanan Kutty','Pranav Joshi'),(58162,'Kumar Dharmasena','Vinod Seshan','KN Ananthapadmanabhan','Prakash Bhatt','Vaibhav Dhokre'),(58324,'Vineet Kulkarni','Nitin Menon','Virender Sharma','Javagal Srinath','Madanagopal Kuppuraj'),(1070094,'Yeshwant Barde','Rohan Pandit','Bruce Oxenford','Manu Nayar','Mohit Krishnadas'),(1290799,'Anil Chaudhary','Tapan Sharma','Jayaraman Madanagopal','Narayanan Kutty','Pranav Joshi'),(57980,'Akshay Totre','Vinod Seshan','KN Ananthapadmanabhan','Amit Sharma','Vaibhav Dhokre'),(58324,'Saiyed Khalid','Nitin Menon','Virender Sharma','Javagal Srinath','Madanagopal Kuppuraj'),(57897,'Anil Chaudhary','Rohan Pandit','Bruce Oxenford','Manu Nayar','Mohit Krishnadas'),(57980,'Ulhas Gandhe','Michael Gough','KN Ananthapadmanabhan','Amit Sharma','Vaibhav Dhokre'),(57851,'Nikhil Patwardhan','Virender Sharma','Jayaraman Madanagopal','Narayanan Kutty','Pranav Joshi'),(1290799,'Vineet Kulkarni','Nand Kishore','Nitin Menon','Sanjay Verma','Keyur Kelkar'),(1070094,'Anil Chaudhary','Rohan Pandit','Bruce Oxenford','Manu Nayar','Rajesh Kannan'),(58040,'Jayaraman Madanagopal','Navdeep Singh','Tapan Sharma','Sanjay Verma','Kannur Swaroopanand'),(57980,'Akshay Totre','Vinod Seshan','Michael Gough','Amit Sharma','Abhijeet Bengeri'),(1290799,'Vineet Kulkarni','Nand Kishore','Saiyed Khalid','Javagal Srinath','Keyur Kelkar'),(58162,'Anil Chaudhary','Saidharshan Kumar','Bruce Oxenford','Manu Nayar','Rajesh Kannan'),(58008,'Nikhil Patwardhan','Tapan Sharma','Jayaraman Madanagopal','Sanjay Verma','Kannur Swaroopanand'),(58040,'KN Ananthapadmanabhan','Ulhas Gandhe','Akshay Totre','Amit Sharma','Abhijeet Bengeri'),(58142,'Saiyed Khalid','Nitin Menon','Virender Sharma','Javagal Srinath','Keyur Kelkar'),(57980,'Yeshwant Barde','Anil Chaudhary','Rohan Pandit','Sanjay Verma','Rajesh Kannan'),(58040,'Navdeep Singh','Nikhil Patwardhan','Jayaraman Madanagopal','Narayanan Kutty','Kannur Swaroopanand'),(1070094,'KN Ananthapadmanabhan','Michael Gough','Vinod Seshan','Amit Sharma','Abhijeet Bengeri'),(57851,'Nitin Menon','Virender Sharma','Vineet Kulkarni','Javagal Srinath','Bhavesh Patel'),(58008,'Rohan Pandit','Saidharshan Kumar','Anil Chaudhary','Sanjay Verma','Keyur Kelkar'),(57980,'Navdeep Singh','Tapan Sharma','Nikhil Patwardhan','Narayanan Kutty','Kannur Swaroopanand'),(1070094,'Ulhas Gandhe','Michael Gough','KN Ananthapadmanabhan','Daniel Manohar','Abhijeet Bengeri'),(58008,'Saiyed Khalid','Virender Sharma','Nand Kishore','Rajiv Seth','Bhavesh Patel'),(58142,'Yeshwant Barde','Anil Chaudhary','Rohan Pandit','Shakti Singh','Keyur Kelkar'),(58324,'Jayaraman Madanagopal','Tapan Sharma','Michael Gough','Pankaj Dharmani','Kannur Swaroopanand'),(57897,'Akshay Totre','Vinod Seshan','KN Ananthapadmanabhan','Daniel Manohar','Keyur Kelkar'),(58056,'Vineet Kulkarni','Nand Kishore','Nitin Menon','Rajiv Seth','Bhavesh Patel'),(1070094,'Yeshwant Barde','Saidharshan Kumar','Anil Chaudhary','Shakti Singh','Rajesh Kannan'),(58324,'Navdeep Singh','Tapan Sharma','Jayaraman Madanagopal','Pankaj Dharmani','Keyur Kelkar'),(58040,'KN Ananthapadmanabhan','Ulhas Gandhe','Michael Gough','Daniel Manohar','Abhijeet Bengeri'),(58142,'Yeshwant Barde','Saidharshan Kumar','Anil Chaudhary','Shakti Singh','Rohan Pandit'),(58056,'Saiyed Khalid','Nitin Menon','Virender Sharma','Rajiv Seth','Bhavesh Patel');
/*!40000 ALTER TABLE `umpire_details` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `venue_details`
--

DROP TABLE IF EXISTS `venue_details`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `venue_details` (
  `ï»¿Match_ID` int DEFAULT NULL,
  `venue_id` int DEFAULT NULL,
  `venue_name` text
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `venue_details`
--

LOCK TABLES `venue_details` WRITE;
/*!40000 ALTER TABLE `venue_details` DISABLE KEYS */;
INSERT INTO `venue_details` VALUES (1422119,58008,'MA Chidambaram Stadium, Chepauk, Chennai'),(1422120,1290799,'Maharaja Yadavindra Singh International Cricket Stadium, Mullanpur'),(1422121,57980,'Eden Gardens, Kolkata'),(1422122,58162,'Sawai Mansingh Stadium, Jaipur'),(1422123,57851,'Narendra Modi Stadium, Motera, Ahmedabad'),(1422124,57897,'M.Chinnaswamy Stadium, Bengaluru'),(1422125,58008,'MA Chidambaram Stadium, Chepauk, Chennai'),(1422126,58142,'Rajiv Gandhi International Stadium, Uppal, Hyderabad'),(1422127,58162,'Sawai Mansingh Stadium, Jaipur'),(1422128,57897,'M.Chinnaswamy Stadium, Bengaluru'),(1422129,1070094,'Bharat Ratna Shri Atal Bihari Vajpayee Ekana Cricket Stadium, Lucknow'),(1422130,57851,'Narendra Modi Stadium, Motera, Ahmedabad'),(1422131,58547,'Dr. Y.S. Rajasekhara Reddy ACA-VDCA Cricket Stadium, Visakhapatnam'),(1422132,58324,'Wankhede Stadium, Mumbai'),(1422133,57897,'M.Chinnaswamy Stadium, Bengaluru'),(1422134,58547,'Dr. Y.S. Rajasekhara Reddy ACA-VDCA Cricket Stadium, Visakhapatnam'),(1422135,57851,'Narendra Modi Stadium, Motera, Ahmedabad'),(1422136,58142,'Rajiv Gandhi International Stadium, Uppal, Hyderabad'),(1422137,58162,'Sawai Mansingh Stadium, Jaipur'),(1422138,58324,'Wankhede Stadium, Mumbai'),(1422139,1070094,'Bharat Ratna Shri Atal Bihari Vajpayee Ekana Cricket Stadium, Lucknow'),(1426260,58008,'MA Chidambaram Stadium, Chepauk, Chennai'),(1426261,1290799,'Maharaja Yadavindra Singh International Cricket Stadium, Mullanpur'),(1426262,58162,'Sawai Mansingh Stadium, Jaipur'),(1426263,58324,'Wankhede Stadium, Mumbai'),(1426264,1070094,'Bharat Ratna Shri Atal Bihari Vajpayee Ekana Cricket Stadium, Lucknow'),(1426265,1290799,'Maharaja Yadavindra Singh International Cricket Stadium, Mullanpur'),(1426266,57980,'Eden Gardens, Kolkata'),(1426267,58324,'Wankhede Stadium, Mumbai'),(1426268,57897,'M.Chinnaswamy Stadium, Bengaluru'),(1426269,57980,'Eden Gardens, Kolkata'),(1426270,57851,'Narendra Modi Stadium, Motera, Ahmedabad'),(1426271,1290799,'Maharaja Yadavindra Singh International Cricket Stadium, Mullanpur'),(1426272,1070094,'Bharat Ratna Shri Atal Bihari Vajpayee Ekana Cricket Stadium, Lucknow'),(1426273,58040,'Arun Jaitley Stadium, Delhi'),(1426274,57980,'Eden Gardens, Kolkata'),(1426275,1290799,'Maharaja Yadavindra Singh International Cricket Stadium, Mullanpur'),(1426276,58162,'Sawai Mansingh Stadium, Jaipur'),(1426277,58008,'MA Chidambaram Stadium, Chepauk, Chennai'),(1426278,58040,'Arun Jaitley Stadium, Delhi'),(1426279,58142,'Rajiv Gandhi International Stadium, Uppal, Hyderabad'),(1426280,57980,'Eden Gardens, Kolkata'),(1426281,58040,'Arun Jaitley Stadium, Delhi'),(1426282,1070094,'Bharat Ratna Shri Atal Bihari Vajpayee Ekana Cricket Stadium, Lucknow'),(1426283,57851,'Narendra Modi Stadium, Motera, Ahmedabad'),(1426284,58008,'MA Chidambaram Stadium, Chepauk, Chennai'),(1426285,57980,'Eden Gardens, Kolkata'),(1426286,1070094,'Bharat Ratna Shri Atal Bihari Vajpayee Ekana Cricket Stadium, Lucknow'),(1426287,58008,'MA Chidambaram Stadium, Chepauk, Chennai'),(1426288,58142,'Rajiv Gandhi International Stadium, Uppal, Hyderabad'),(1426289,58324,'Wankhede Stadium, Mumbai'),(1426290,57897,'M.Chinnaswamy Stadium, Bengaluru'),(1426291,58056,'Himachal Pradesh Cricket Association Stadium, Dharamsala'),(1426292,1070094,'Bharat Ratna Shri Atal Bihari Vajpayee Ekana Cricket Stadium, Lucknow'),(1426293,58324,'Wankhede Stadium, Mumbai'),(1426294,58040,'Arun Jaitley Stadium, Delhi'),(1426295,58142,'Rajiv Gandhi International Stadium, Uppal, Hyderabad'),(1426296,58056,'Himachal Pradesh Cricket Association Stadium, Dharamsala');
/*!40000 ALTER TABLE `venue_details` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2025-04-11  0:32:01
