# School-Projects |
CS 2308 - Foundations of Computer Science II (Texas State University) |
Linux Programming Assignment I (Ziliang Zong)

In this project, we will write a program that controls a quiz show. The program will read in a group of questions and their multiple choice answers, storing them to a 2D array of strings (which can be implemented as a 3D array of type char or a 2D array of C++ strings.) The correct answers will be stored in a separate 1D array of type char.

The rules of play:- • Randomly present a question to the player, followed by its four possible answers (identified as A-D). • Player selects an answer (program validates it’s in range A-D, otherwise prompts for answer again.) • If correct choice, award points (see below). • If incorrect, offer player another chance. If player elects to try again, display the question, omitting the previous incorrect choice. o If player gets second attempt correct, award ½ the points that would be applicable. o If player gets second attempt wrong, game is over, all points forfeited! o If player chooses to skip the missed question, go on to next random question, no penalty. • The maximum number of questions per player round is 6, which will potentially win over a million points.

Scoring:- • Points awarded for each question go up by a multiple of 10 of the points awarded on the previous question, starting out at 10 for the first one. • If a player took a second chance at a question and got it right, the points awarded will be ½ of 10 times the previous award, and future points will build from that amount. • If a player skips a question he missed the first attempt on, points to be awarded on next question remain unchanged (10 time previous points award). • Example sequences of points awarded: o 10 100 1000 10000 100000 1000000 perfect scored = 1,111,110 o 10 100 500 5000 50000 500000 missed one, then perfect = 555,610 o 10 100 0 1000 10000 100000 skipped one = 111,110

The Data Files:- Two files will be used, one containing the questions and responses, the second containing the letters of the correct responses (the answers.) The Question file will be a series of text strings in the form: This is a question that the player must answer. This is the first possible choice. This is the second possible choice
Guess what, this is the third possible choice Finally, the fourth choice (one or more blank lines separate each question group ) (…and more sets of questions follow)

There will be 0 to 50 sets of questions in this format in any data file. Accompanying the question bank will be a file with a series of characters, one for each of the five-line question sets (thus, 0 to 50 characters in the file.) These characters, in the range A-D, will indicate the correct answer for the questions.

For this assignment, you are guaranteed that in the question bank, there will be no incomplete sets of questions. The answer file may, however, not agree with the question file, that is, it may have more or less than the number of questions’ worth of characters. In that event, display a meaningful error message and end the program.

To handle the blank line(s) between question sets, and any blanks that may exist at the end of the file, you should read a line. If the line has a non-zero length, you have found a question. It will be immediately followed by four more valid lines (the responses), which you can assume will be easily handled by a for loop.

The names of the question file and the answer file will be given on the command line, as well as an integer seed for srand. Your program must check that sufficient arguments are present before attempting to open the files. If the argument list is too few or too many, display a meaningful error message and exit. If either of the input files fails to open, display a meaningful error message and exit. If the question file is empty, display an error message and exit.

After the player has answered all questions, store the current player’s name and score to a file named “summary.txt”. Use the append mode so that every player’s score is added to the file – that is, it will become a history of all who’ve played the game. At the end of the program, read in the names and scores of all players from “summary.txt” (the number of players who have played the game will not be known until reading to the end of the file), sort the scores and names accordingly, display the name and score of the player with the highest score, and the rank (1st place, 2nd place, 3rd place, etc) of the current player.

Data Storage:- You will store the questions and responses in a 2D array of strings. No string will be longer than 150 characters. You may use C-style strings (character array based, NULL terminated) which implies you will need a 3D array. You may also use C++ style strings, which will be stored as a 2D array of that type. The answers will be stored in a 1D array of characters.

Displaying a question: - You will display the letters A-D in front of the responses; they are not included in the response text. Your program will randomly select questions from those read in, keeping track of which questions have been used. Do not repeat a question during the course of the game play. When a player is making a second attempt at a question, leave the line of the incorrect selection blank, but keep the same letters
assigned to the responses as in the first attempt. 

Random Number Generation: - Before generating a random number use argv[3] to seed srand() with an integer. 
