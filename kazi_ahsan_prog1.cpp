#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <fstream>
#include<iomanip>
#include<sstream>
using namespace std;

string player_name;

void rand_seed(int index, int array[6])
{
	bool random_question [index];
	int user = 1089801;
	for (unsigned int i = 0; i<index; i++)
	{
		random_question[i] = false;
	}
	srand(user);
	
	for (unsigned int i = 0; i<6; i++)
	{
		int random = rand() % index;
		while (random_question[random] == true)
		{
			random = rand() % index;
		}
		array[i] = random;
		
		random_question[random] = true;
	}
}

string toUpper(string answer){
	for(int i=0; i<answer.length();i++){
		answer.at(i) = toupper(answer.at(i));
	}
	return answer;
}

int read_questions1(ifstream& infile, string read_questions[50][5], int index)
{
	if (infile.is_open())
	{
		while(getline(infile, read_questions[index][0], '\n'))
		{
			getline(infile, read_questions[index][1]);
			getline(infile, read_questions[index][2]);
			getline(infile, read_questions[index][3]);
			getline(infile, read_questions[index][4]);
			getline(infile, read_questions[index][5]);
			
			index += 1;
		}
		infile.close();	
	}
	  else{
	  	
	  	cout << "Cannot read the file! " << endl;
	  	
	  	return -1;
	  }
	    return index;
}

int read_answers1 (ifstream & infile1, string read_answers[7], int j)
{
		if (infile1.is_open())
	{
		while(getline(infile1, read_answers[j], '\n'))
		{
			
			for ( int i = 1; i<7; i++)
			{
				getline (infile1, read_answers[i]);
			}
		
			j += 1;
		}
		infile1.close();	
	}
	  else{
	  	
	  	cout << "Cannot read the file! " << endl;
	  	
	  	return 1;
	  }
}

bool player_try(string answer)
{
if (answer == "A" || answer =="B" || answer == "C" || answer == "D")
{
	return true;
}
    return false;
}

int show_questions(string read_questions[50][5],string read_answers[7], int array[6] )
{
	
	int score = 0;
	
	cout << "What's your name? ";
	cin >> player_name;
	
	for( int i = 0; i<6 ; i++){
		
		int question = array[i];
		cout << read_questions[question][0] << endl;
	    cout << "A. " << read_questions[question][1] << endl;
	    cout << "B. " << read_questions[question][2] << endl;
	    cout << "C. " << read_questions[question][3] << endl;
	    cout << "D. " << read_questions[question][4] << endl << endl;
	    
	    cout << "Your choice? > ";
	    
	    string answer;
	    cin >> answer;
	    
	    answer = toUpper(answer);
	    
	    if (player_try(answer) && answer == read_answers[question])
	    {
	    	cout << "Congratulations! The answer is correct" << endl;
	    	if(score == 0){
	    		score = 10;
			} else{
				score *= 10;
			}
	    	
	    	cout << "Your current score is: " << score << endl << endl;
	    	continue;
		}
		else
		{
			cout << "The answer you entered is wrong." << endl;
			cout << "Try Again for the same question " << endl << endl;
			cout << read_questions[question][0] << endl;
			if( answer != "A" ){
			 cout << "A. "<< read_questions[question][1] << endl;	
			}
			if( answer != "B"){
			 cout << "B. " << read_questions[question][2] << endl;	
			}
			if( answer != "C"){
			 cout << "C. " << read_questions[question][3] << endl;	
			}
			if( answer != "D"){
			 cout << "D. " << read_questions[question][4] << endl;	
			}
			
			cout << endl;
			cout << "Enter an answer(A,B,C,D): " << endl;
			cin >> answer;
			
			answer = toUpper(answer);
			
			if (player_try(answer) && answer == read_answers[question]){
				cout << "Congratulations! The answer you entered is correct" << endl;
				if(score == 0){
					score = 5;
			    } else{
			    	score *= 5;
			    }
				cout << "Your current score is: " << score << endl << endl;
	    	    continue;
			} else {
				cout << "The answer you entered is wrong." << endl;
				cout << "The current score is: " << score << endl << endl;
			    cout << "Moving forward with next question: " << endl << endl;
			}
		}		
	}
	return score;

}
int main() 
{
	char filename[] = "questions.txt";
	
	string read_questions[50][5];
	
	int index = 0;
		
	ifstream infile(filename);
	
	
	index = read_questions1(infile, read_questions, index);	
	
	char filename2[] = "answers.txt";
	
	string read_answers[7];
	
	int j = 0;
	
	ifstream infile1(filename2);
	
	j = read_answers1 (infile1, read_answers, j);
	
	    for (int i =0; i<7; i++ )
		{
			read_answers[i] = read_answers[i].substr(0,1);
			read_answers[i] = toUpper(read_answers[i]);
		}
		
		int array[6];
		
		cout << "LET'S START WITH THE QUIZ SHOW!!!!!!!!!!" << endl;
		cout << "========================================" << endl;
		
		rand_seed(index , array);
		
        int score = 0;
        score  = show_questions(read_questions,read_answers,array);
        
        cout << "Your total score is: " << score << endl;
    
        ofstream offile("summary1.txt", ios :: in | ios :: out | ios :: app);
        offile << left<< setw(20) << player_name << setw(20)<< score<< endl;
       
	   ifstream fin; 
       fin.open("summary1.txt");
              
       vector<string> player_lines;
    
       string temp = " ";
       while (getline(fin, temp))
	   {
       	 player_lines.push_back (temp);     	
	   }
	   string names[player_lines.size()];
       int scores[player_lines.size()];     
       for (int i=0; i<player_lines.size(); i++)
       {
       	names[i] = player_lines[i].substr(0,20);
       	scores[i] = stoi(player_lines[i].substr(20,player_lines[i].length()));
	   }
      
      for (int i=0; i<player_lines.size(); i++)
      {
	  string tempString;
	  int temp;	
          for (int j = i+1; j<player_lines.size(); j++ )
          {
          	 if(scores[i]<scores[j]){
          	 	temp = scores[i];
          	 	scores[i] = scores[j];
          	 	scores[j] = temp;
          	 	tempString = names[i];
          	 	names[i] = names[j];
          	 	names[j] = tempString;
			   }
		  }
	  }	  
	  cout << "Printing scores in descending order" << endl << endl;
	
	for (int i=0; i< player_lines.size(); i++){
		cout << names[i] << scores[i] << endl;
	}
       	   					
   return 0;
}

