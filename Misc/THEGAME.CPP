#include <iostream>
#include<fstream>
#include <cstdio>
#include<string>
#include <cstdlib>
#include <ctime>
//#include<process.h>
using namespace std;
/*
This program was created by

Suvam Dey
XII, S3
Roll No.12638044 

and

Sayak Ray
XII, S3
Roll No. 12638036

Main Objective: To Create A Program that Simulated a Hand Cricket Game and a Hand Football Game
Between the User and the Computer

Main Function Used:
	Randomise: to create random nos that emulate scores
and bowling sequences.

*/

int usescore=0,compscore=0,totscore=0; char name[20];
fstream f1("stu.txt",ios::app|ios::out);
class Game
{
	int usertoss;
	int comptoss;
	int pass,comppass,c,k,scoreu,scorec;
public:
	void defend();
	void attack();
	void Goals(int k);
	void toss();
	void preferences();
	void getdata()
	{
		scoreu=usescore;scorec=compscore;
	}
	void end();
};
void Game::toss()
{
	unsigned int seedval;
	time_t t;
	cout<<"It's time for the toss"<<endl<<"Press 1 for Heads and 2 for Tails"<<endl;
	cin>>usertoss;
	seedval=(unsigned) time(&t);
	srand(seedval);
	comptoss=(rand()%2)+1;
	cout<<"Coin Flipping.."<<endl;
	if(comptoss==1)
	{
		cout<<"Heads"<<endl;
	}
	else
	{
		cout<<"Tails"<<endl;
	}
	preferences();
};
void Game::preferences()
{
	if(comptoss==usertoss)
	{
		cout<<"You won the toss"<<endl<<"You will Attack first"<<endl;
		cout<<"Your attacking preference should be 7,8,9"<<endl;
		attack();
	}
	else
	{
		cout<<"You lost the toss"<<endl<<"Computer will Attack first"<<endl;
		cout<<"Your defending preference should be 1,2,3"<<endl;
		defend();
	}
};
void Game::attack()
{
	c=0;
		while(c<3)
		{
			cout<<"Choose Attacking Options(7,8,9)"<<endl;
			cin>>pass;
			comppass=(rand()%9)+7;
			if(pass==comppass)
			{
				cout<<"Ball lost, Great tackle by Computer"<<endl;
				defend();
			}
			else
			{
				c+=1;cout<<"User is attacking well"<<endl;
			}
		 }
	if(c==3)
	{
	k=1;Goals(k);
	}
};
void Game::defend()
{
	c=0;
	while(c<3)
	{
		cout<<"Choose Defending Options(1,2,3)"<<endl;
		cin>>pass;
		comppass=(rand()%3)+1;
		if(comppass==pass)
		{
			cout<<"Ball Lost, Great tackle by User"<<endl;
			attack();
		}
		else
		{
			cout<<"Computer is progressing swiftly"<<endl;
			c+=1;
		}
	}
	if(c==3)
	{
		k=0;Goals(k);
	}

};
void Game::Goals(int k)
{
	int useshot,compshot;
	cout<<"Goal Chance"<<endl;
	cout<<"Enter 5 or 6"<<endl;
	cin>>useshot;
	compshot=(rand()%6)+5;
	if(useshot==compshot)
	{
		cout<<"Saved"<<endl;
		if(k==1)
		{
			defend();
		}
		else
		{
			attack();
		}
	}
	else
	{
		cout<<"Goal"<<endl;
		if(k==1)
		{
		usescore+=1;totscore+=1;
		if(totscore==3)
			{
				end();
                exit(0);
			}
		else
			{
			       defend();
			}
		}
		else
		{
		compscore+=1;totscore+=1;
		if(totscore==3)
			{
				end();
                exit(0);
			}
		else
			{
				attack();
			}
		}
	}
};
void Game::end()
{
	cout<<"Game ends"<<endl;
	cout<<"User:"<<usescore<<"Computer:"<<compscore;
	f1<<"Football"<<endl;
	f1<<name<<usescore<<endl;
	f1<<"Computer"<<compscore<<endl;
};






 int main()
 {      //clrscr();
	char red;
	cout<<"Enter your Name";
	cin.getline(name, 20);
	cout<<"Enter choice(Football:F; Cricket:C)\n";
	cin>>red;

	if(red=='C')
	{

	int i=0,Choice,Score=0, ScoreM=0;
//Toss
	cout<<"\n\nCricket Game!!\n\n"
		<<endl
		<<"Now We will Toss. Enter Even(0) or Odd(1). "<<endl;
	cin>>Choice;
  /* initialize random seed: */
  srand (time(NULL));
	if(Choice==(rand() % 2))
	{
		cout<<"Toss WON!!\n";
		//Computer Bowls

			while(i==0) {



				int UsrC;
				cout<<"You are batting.\n"
					<<"Enter your runs(0-6):";
				cin>>UsrC;

				int CBol;
				CBol = rand() % 6 ;
				if(UsrC == CBol){
					cout<<"\tYou are OUT. \tScore is:"<<ScoreM<<endl;
					i++;
				}
				else
				{	cout<<"\tComputer bowled \n"<<CBol;
					ScoreM = ScoreM + UsrC;
					cout<<"\tYour Score is :\t"<<ScoreM<<endl;
				}
			}
			i=0;
			while(i == 0 && (Score <= ScoreM))
			{



				int UsrC;
				cout<<"You are bowling.\n"
					<<"Enter your number(0-6):";
				cin>>UsrC;

				int CBat;
				CBat = rand() % 6 ;
				if(UsrC == CBat){
					cout<<"\tComputer is OUT. \tScore is:"<<Score<<endl
						<<"\nPlayer WINS!";
					i++;
				}
				else
				{
					Score= Score + CBat;
					cout<<"Computer plays \t"<<CBat
						<<"Score is \t"<<Score<<endl;

				}

				if(Score>ScoreM){
					cout<<"\nComputer Wins.\t Player LOSES.";
				}

			}



	}


	else
	{
		cout<<"Toss LOST!\t \t Computer Wins Batting.\n";


// Code for Computer Batting

		while(i==0)
		{



			int UsrC;
			cout<<"You are bowling.\n"
				<<"Enter your number(0-6):";
			cin>>UsrC;

			int CBat;
			CBat = rand() % 6 ;
			if(UsrC == CBat){
				cout<<"\tComputer is OUT. \tScore is:"<<Score<<endl;
				i++;
			}
			else
			{
				Score= Score + CBat;
				cout<<"Computer plays \t"<<CBat
					<<"Score is \t"<<Score<<endl;

			}
		}
//
		i=0;
		while(i==0 && Score>=ScoreM) {



					int UsrC;
					cout<<"You are batting.\n"
						<<"Enter your runs(0-6):";
					cin>>UsrC;

					int CBol;
					CBol = rand() % 6 ;
					if(UsrC == CBol){
						cout<<"You are OUT. \tScore is:"<<ScoreM<<endl;
						i++;
						cout<<"\tYou have lost the game. COMPUTER WINS!!";
					}
					else
					{	cout<<"Computer bowled \n"<<CBol;
						ScoreM = ScoreM + UsrC;
						cout<<"\tYour Score is :\t"<<ScoreM<<endl;
					}
				}
				if(ScoreM>Score){
					cout<<"User wins!! Congrats.\n Computer LOSES.";
				}
		}
		f1<<"Cricket"<<endl;
		f1<<name<<ScoreM<<endl;
		f1<<"Computer"<<Score<<endl;
	}

	else
	if(red=='F')
	{
		Game g1;
		g1.toss();
	}
 //getch();
 return 0;
}

