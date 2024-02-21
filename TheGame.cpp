#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string> 
#include <windows.h>   
#include <fstream>


using namespace std;

// Global Variables
	//Printer 12 Segment Variables
		int twelveSegementCodes[37][25] = 
		{
			{0,1,0,1,0, 
			2,0,0,0,2, 
			0,1,0,1,0,
			2,0,0,0,2,
			0,0,0,0,0},//A
			{0,1,0,1,0, 
			0,0,2,0,2, 
			0,0,0,1,0,
			0,0,2,0,2,
			0,1,0,1,0},//B
			{0,1,0,1,0, 
			2,0,0,0,0, 
			0,0,0,0,0,
			2,0,0,0,0,
			0,1,0,1,0},//C
			{0,1,0,1,0, 
			0,0,2,0,2, 
			0,0,0,0,0,
			0,0,2,0,2,
			0,1,0,1,0},//D
			{0,1,0,1,0, 
			2,0,0,0,0, 
			0,1,0,0,0,
			2,0,0,0,0,
			0,1,0,1,0},//E
			{0,1,0,1,0, 
			2,0,0,0,0, 
			0,1,0,1,0,
			2,0,0,0,0,
			0,0,0,0,0},//F
			{0,1,0,1,0, 
			2,0,0,0,0, 
			0,0,0,1,0,
			2,0,0,0,2,
			0,1,0,1,0},//G
			{0,0,0,0,0, 
			2,0,0,0,2, 
			0,1,0,1,0,
			2,0,0,0,2,
			0,0,0,0,0},//H
			{0,1,0,1,0, 
			0,0,2,0,0, 
			0,0,0,0,0,
			0,0,2,0,0,
			0,1,0,1,0},//I
			{0,0,0,0,0, 
			0,0,0,0,2, 
			0,0,0,0,0,
			2,0,0,0,2,
			0,1,0,1,0},//J
			{0,0,0,1,0, 
			2,0,2,0,0, 
			0,1,0,1,0,
			2,0,0,0,2,
			0,0,0,0,0},//K
			{0,0,0,0,0, 
			2,0,0,0,0, 
			0,0,0,0,0,
			2,0,0,0,0,
			0,1,0,1,0},//L
			{0,1,0,1,0, 
			2,0,2,0,2, 
			0,0,0,0,0,
			2,0,0,0,2,
			0,0,0,0,0},//M
			{0,1,0,0,0, 
			2,0,2,0,2, 
			0,0,0,0,0,
			2,0,2,0,2,
			0,0,0,1,0},//N
			{0,1,0,1,0, 
			2,0,0,0,2, 
			0,0,0,0,0,
			2,0,0,0,2,
			0,1,0,1,0},//O
			{0,1,0,1,0, 
			2,0,0,0,2, 
			0,1,0,1,0,
			2,0,0,0,0,
			0,0,0,0,0},//P
			{0,1,0,1,0, 
			2,0,0,0,2, 
			0,1,0,1,0,
			0,0,2,0,0,
			0,0,0,1,0},//Q
			{0,1,0,1,0, 
			2,0,0,0,2, 
			0,1,0,1,0,
			2,0,2,0,0,
			0,0,0,1,0},//R
			{0,0,0,1,0, 
			0,0,2,0,0, 
			0,0,0,0,0,
			0,0,2,0,0,
			0,1,0,0,0},//S
			{0,1,0,1,0, 
			0,0,2,0,0, 
			0,0,0,0,0,
			0,0,2,0,0,
			0,0,0,0,0},//T
			{0,0,0,0,0, 
			2,0,0,0,2, 
			0,0,0,0,0,
			2,0,0,0,2,
			0,1,0,1,0},//U
			{0,0,0,0,0, 
			2,0,0,0,2, 
			0,0,0,1,0,
			2,0,2,0,0,
			0,1,0,0,0},//V
			{0,0,0,0,0, 
			2,0,0,0,2, 
			0,0,0,0,0,
			2,0,2,0,2,
			0,1,0,1,0},//W
			{0,0,0,0,0, 
			2,0,2,0,0, 
			0,1,0,1,0,
			0,0,2,0,2,
			0,0,0,0,0},//X
			{0,0,0,0,0, 
			2,0,0,0,2, 
			0,1,0,1,0,
			0,0,2,0,0,
			0,0,0,0,0},//Y
			{0,1,0,1,0, 
			0,0,0,0,2, 
			0,0,0,1,0,
			0,0,2,0,0,
			0,1,0,1,0},//Z
			{0,1,0,1,0,
			2,0,0,0,2,
			0,0,0,0,0,
			2,0,0,0,2,
			0,1,0,1,0},//0
			{0,1,0,0,0,
			0,0,2,0,0,
			0,0,0,0,0,
			0,0,2,0,0,
			0,1,0,1,0},//1
			{0,1,0,1,0,
			0,0,0,0,2,
			0,1,0,1,0,
			2,0,0,0,0,
			0,1,0,1,0},//2
			{0,1,0,1,0,
			0,0,0,0,2,
			0,0,0,1,0,
			0,0,0,0,2,
			0,1,0,1,0},//3
			{0,0,0,0,0,
			2,0,2,0,0,
			0,1,0,1,0,
			0,0,2,0,0,
			0,0,0,0,0},//4
			{0,1,0,1,0,
			2,0,0,0,0,
			0,1,0,1,0,
			0,0,0,0,2,
			0,1,0,1,0},//5
			{0,1,0,1,0,
			2,0,0,0,0,
			0,1,0,1,0,
			2,0,0,0,2,
			0,1,0,1,0},//6
			{0,1,0,1,0,
			2,0,0,0,2,
			0,0,0,1,0,
			0,0,2,0,0,
			0,0,0,0,0},//7
			{0,1,0,1,0,
			2,0,0,0,2,
			0,1,0,1,0,
			2,0,0,0,2,
			0,1,0,1,0},//8
			{0,1,0,1,0,
			2,0,0,0,2,
			0,1,0,1,0,
			0,0,0,0,2,
			0,1,0,1,0},//9
			{0,0,0,0,0,
			0,0,0,0,0,
			0,0,0,0,0,
			0,0,0,0,0,
			0,0,0,0,0}//[SPACE]
		};

	// COLORS
		HANDLE hConsole;
		int defaultBorderColor = 8;
		int baseNumberColor = 11;
		int bestScoreColor = 103;
		int nowScoreColor = 95;
		int recordScoreColor = 206;
		int optionalColor = 8;
		int wonColor = 2;
		int gameoverColor = 12;
		int nameColor = 12;
		int menuButtonsColor = 7;
		int menuButtonsInnerActiveColor = 95;
		int menuButtonsBorderActiveColor = 13;
	//Initial Space
		string initialSpace = "			";

	//User Variables
		struct User
		{
			string name;
			bool hasWon;
			int boardSize;
			long long score;
		};

		int capacity = 1;
		int currentGameCount = 0;

	//Game Variables
		int maxNumber = 2048;
		int boardSize = 4;
		int tileCounts = 0;
		long long score = 0;
		long long bestScore = 0;
		bool hasWon = false;
		bool hasBrokenRecord = false;
		string playerName = "";
		bool hasMoved = false;

// Function Prototypes
	//Printers
	void PrintLetter(char letter, int lineNumber, int fontSize);
	void CallLine(int letterCount, int i, string text, int fontSize, string theSpace);
	void PrintString12Segment(string text, int fontSize, string theSpace);
	void PrintDramatically(string text);


	void HideCursor()
	{
		CONSOLE_CURSOR_INFO info;
   		info.dwSize = 100;
   		info.bVisible = FALSE;
   		SetConsoleCursorInfo(hConsole, &info);
	}
	//Main Menu
		void ShowMainMenu(int activeOne);
		void ShowLeaderBoard(int boardSize);
		void ShowIntro();
		void AskGameDetails();
		void ShowCredits();
		void AskSizeAndShowLeaderBoard();
		
	//User Manager
		void boubleSort(User *& users);
		void append(User user, User *& users);
		int GetLeaderboard(int boardSize, User *& users);
		long long GetBestScore(int boardSize);
		void SaveUser(User user);
		void StartSandTimer(int n, string defaultText);

// BoardMovements
	void Up(int** board);
	void Down(int** board);
	void Right(int** board);
	void Left(int** board);
	bool CheckIfMoveIsPossible(int** board);
	//Game
	int GetRandomNumber(int from, int to);
	int GetTwoOrFour();
	int CountDigits(int number);
	int AddTile(int** board);
	void Finish();
	void start(int theSize, string name);
	void Pause();
	void Print(int** board);


//The HourGlass and TwelveSegment Printer
	void StartSandTimer(int n, string defaultText)
	{
		int middlePoint = n / 2 + 1;
		int numberOf = (n-3)/2;
		int nowTime = numberOf;
		int emptyUp = 0;
		SetConsoleTextAttribute(hConsole, 15);

		for(int k = 1; k <= numberOf+1; k++)
		{
			system("cls");
			cout<<initialSpace << defaultText<<endl;	

			int counter = (n-1)/2;
			int tempEmpUp = emptyUp;
			for(int i = 1 ; i <= n ; i++)
			{
			cout<<initialSpace;
				
				for(int j = 1 ; j <= n ; j++)
				{	
					if(i == 1 || i == n) {cout <<"*"; continue;}
					if(j >= middlePoint-abs(counter) && j <= middlePoint+abs(counter))
					{
						if(j > middlePoint-abs(counter) && j < middlePoint+abs(counter))
						{
							SetConsoleTextAttribute(hConsole, 14);
							if(counter > 0)
							{	
							
								if(tempEmpUp < 0)
									{cout << "\u2022"; }
								else cout<<" ";
							}
							else
							{
								
								if(i > n - k)
									cout << "\u2022";
								else cout<<" ";
							}					
							SetConsoleTextAttribute(hConsole, 15);
						}	
						else cout<<"*";
					}else cout << " ";
				}
				
				tempEmpUp--;
				
				counter--;
				if(i != n) cout<<endl; 
			}
		
			if(k != numberOf+1) cout<<endl<<endl;

			emptyUp++;
			Sleep(600);
		}
	}
	void PrintLetter(char letter, int lineNumber, int fontSize)
	{
		cout<<" ";
		int letterIndex;
		if((int)letter >= 97 && (int)letter <= 122)
		{
			letterIndex = (int)letter - 97;
		} else if((int)letter >= 48 && (int)letter <= 57)
		{
			letterIndex = (int)letter - 48 + 26;
		} else {letterIndex = 36;}


		for(int i = 0; i < 5; i++)
		{
			int a = twelveSegementCodes[letterIndex][lineNumber*5 + i];
			if(i == 0 || i == 2 || i == 4) {if(a == 2) cout<<"┃"; else cout<<" ";}
			else
			{
				for(int k = 0; k < fontSize; k++)
				{
					if(a==0) cout<<" ";
					if(a == 1) 
					{
						if(i == 1 || fontSize%2==1)
							if(k % 2 == 0) cout<<"━"; else cout << " ";	
						else 
							if(k % 2 == 0) cout<<" "; else cout << "━";
					}
					
				}
			}
		}
		cout<<" ";
	}
	void CallLine(int letterCount, int i, string text, int fontSize, string theSpace = " ")
	{
		cout << theSpace;
		for(int j = 0; j < letterCount; j++)
		{
			PrintLetter(text[j],i, fontSize);
		}
	}

	void PrintString12Segment(string text, int fontSize, string theSpace = " ")
	{
		int letterCount = text.length();
		for(int i = 0; i < 5; i++)
		{
			if(i%2 == 0 || i == 4) {CallLine(letterCount, i, text,fontSize, theSpace);}			
			else for(int k = 0 ; k < fontSize; k++)  { CallLine(letterCount, i, text,fontSize, theSpace); if(k!= fontSize-1)cout<<endl;}	
			cout<<endl;	
		}
	}

	void PrintDramatically(string text)
	{
		int len =  text.length();
		for(int i = 0; i < len; i++)
		{
			cout << text[i];
			if(i != len - 1) Sleep(100); 
		}
	}

//Main Menu Functions 
	void ShowMainMenu(int activeOne)
	{
		string menuOptions[4] = {"Play", "Leaderboard", "Credits", "Exit"};

		system("cls");\

		SetConsoleTextAttribute(hConsole, 13);
		PrintString12Segment("2048", 1, initialSpace);

		SetConsoleTextAttribute(hConsole, optionalColor);
		cout << initialSpace << "* use w / s to move up and down" << endl;
		cout << initialSpace << "* use enter to select the option" << endl;

		int innerWidth = 30;	
		for(int i = 0; i < 4; i++)
		{
			cout << initialSpace;
			SetConsoleTextAttribute(hConsole, (i == activeOne)?menuButtonsBorderActiveColor:menuButtonsColor);
			//Drawing Boxes
			cout << "\u256d";
			for(int k = 0; k < innerWidth; k++)
			{
				cout << "\u2500"; 
			}
			cout << "\u256e";
			cout << endl<< initialSpace;

			cout << "\u2502";
			SetConsoleTextAttribute(hConsole, (i == activeOne)?menuButtonsInnerActiveColor:menuButtonsColor);
			for(int k = 0; k < innerWidth; k++)
			{
				cout << " "; 
			}
			SetConsoleTextAttribute(hConsole, (i == activeOne)?menuButtonsBorderActiveColor:menuButtonsColor);


			cout << "\u2502";
			cout << endl << initialSpace;

			cout << "\u2502";
			SetConsoleTextAttribute(hConsole, (i == activeOne)?menuButtonsInnerActiveColor:menuButtonsColor);
			int thePlace = (innerWidth - menuOptions[i].length())/2;
			for(int j = 0; j < innerWidth; j++)
			{
				//Writing the texts
				if(j == thePlace) {cout <<menuOptions[i]; j+=menuOptions[i].length()-1; continue; };
				cout<<" ";
			}
			SetConsoleTextAttribute(hConsole, (i == activeOne)?menuButtonsBorderActiveColor:menuButtonsColor);

			cout << "\u2502";
			cout << endl << initialSpace;;
			
			cout << "\u2502";
			SetConsoleTextAttribute(hConsole, (i == activeOne)?menuButtonsInnerActiveColor:menuButtonsColor);
			for(int k = 0; k < innerWidth; k++)
			{
				cout << " "; 
			}
			SetConsoleTextAttribute(hConsole, (i == activeOne)?menuButtonsBorderActiveColor:menuButtonsColor);
			cout << "\u2502";

			cout << endl << initialSpace;;

			cout << "\u2570";
			for(int k = 0; k < innerWidth; k++)
			{
				cout << "\u2500"; 
			}
			cout << "\u256f" << endl;		
		}
	}

	void ShowLeaderBoard(int boardSize)
	{
		system("cls");
		SetConsoleTextAttribute(hConsole, baseNumberColor);
		cout << initialSpace << "Leader Board - " << boardSize << "*" << boardSize << " " << endl;
		SetConsoleTextAttribute(hConsole, optionalColor);
		cout << initialSpace << "\u2190 press b to get back" << endl;
		SetConsoleTextAttribute(hConsole, menuButtonsColor);

		int innerWidth = 42;

		User * users = new User[1];
		int length = GetLeaderboard(boardSize, users);
		if(length == 0) 
		{ 	   
			SetConsoleTextAttribute(hConsole, gameoverColor); 
			cout << endl<< initialSpace << "There is no data to be shown for this board size.";
			SetConsoleTextAttribute(hConsole, menuButtonsColor);
		}
		
		int rankNumber = 1;
		int lastRank = 1;
		for(int i = 0; i < length; i++)
		{
			//Ranking 
			cout << initialSpace;
			if(i > 0 && users[i-1].score == users[i].score) 
			{
				rankNumber = lastRank;
			}
			else
			{
				rankNumber = i + 1;
				lastRank = rankNumber;
			}

			// Coloring the leaderboard		
			int color;
			switch(lastRank)
			{
				case 1: color = 14;break;
				case 2: color = 15;break;
				case 3: color = 4; break;
				default: color = 8; break;
			}

			SetConsoleTextAttribute(hConsole, color);
			cout << "\u256d";
			for(int k = 0; k < innerWidth; k++)
			{
				cout << "\u2500"; 
			}
			cout << "\u256e";

			cout << endl<< initialSpace;

			cout << "\u2502";
			for(int k = 0; k < innerWidth; k++)
			{
				cout << " "; 
			}
			cout << "\u2502";

			cout << endl << initialSpace;
			cout << "\u2502";
			
			//Centering the rank text
			string text = to_string(lastRank);
			int thePlace = (10 - text.length())/2;
			for(int j = 0; j < 10; j++)
			{
				if(j == thePlace) { cout << text; j += text.length()-1; continue; };
				cout<<" ";
			}

			cout << "|";

			//Centering the name text
			thePlace = (20 - users[i].name.length())/2;
			for(int j = 0; j < 20; j++)
			{
				if(j == thePlace) { cout << users[i].name; j += users[i].name.length()-1; continue; };
				cout<<" ";
			}
			cout<<"|";

			//Centering the score text
			text = to_string(users[i].score);
			thePlace = (10 - text.length())/2;
			for(int j = 0; j < 10; j++)
			{
				if(j == thePlace) { cout << text; j += text.length()-1; continue; };
				cout<<" ";
			}


			cout << "\u2502";
			cout << endl<< initialSpace;
			cout << "\u2502";
			for(int k = 0; k < innerWidth; k++)
			{
				cout << " "; 
			}

			cout << "\u2502";

			cout << endl << initialSpace;

			cout << "\u2570";
			for(int k = 0; k < innerWidth; k++)
			{
				cout << "\u2500"; 
			}
			cout << "\u256f";
			
			cout << endl;
			SetConsoleTextAttribute(hConsole, menuButtonsColor);
		}

		delete[] users;
		
		char input = '0';
		while(input != 'b')
		{
			input = getch();
		}
	}

	void ShowIntro()
	{
		system("cls");
		Sleep(500);
		PrintDramatically("2048");
		Sleep(500);
		PrintDramatically("\nBy Mehrdad Shirvani");
		Sleep(500);
	}

	void AskGameDetails()
	{
		Sleep(300);
		system("cls");
		int size = -1;

		while(size <= 2)
		{	
			cout << endl << ">> Enter board size: ";
			string sizeString;
			cin >> sizeString;
			try
			{
				size = stoi(sizeString);
			}
			catch(...)//Catches all the exceptions
			{
				size = -1;
			}

			if(size <= 2)
			{
				SetConsoleTextAttribute(hConsole,gameoverColor);
				cout << ">>>> Invalid Input. The size should at least be 3 " << endl ;
				SetConsoleTextAttribute(hConsole,menuButtonsColor);
			}
		}

		string name;
		bool nameContainsComma = false;
		while(name.length() == 0 || name.length()>20 || nameContainsComma)
		{	
			nameContainsComma = false;
			cout << endl << ">> Enter your name: ";
			cin.ignore();
			getline(cin, name);
			if(name.length() == 0 || name.length()>=20)
			{
				SetConsoleTextAttribute(hConsole,gameoverColor);
				cout << ">>>> Invalid Input. The name's length should be more than 0 and less than 20"<< endl;
				SetConsoleTextAttribute(hConsole,menuButtonsColor);
			}
			int commmaIndex = name.find(",");
			if(commmaIndex != -1)
			{	
				SetConsoleTextAttribute(hConsole,gameoverColor);
				cout << ">>>> Invalid Input. The name can't contain comma"<< endl;
				SetConsoleTextAttribute(hConsole,menuButtonsColor);
				nameContainsComma = true;
			}
		}

		StartSandTimer(11, "Please wait...");
		start(size, name);
	}

	void ShowCredits()
	{
		system("cls");
		PrintString12Segment("mehrdad shirvani",1);
		Sleep(500);
		cout << endl <<initialSpace << "\u2190 press b to get back" << endl;
		char input = '\0';
		while(input != 'b')
		{
			input = getch();
		}
	}

	void AskSizeAndShowLeaderBoard()
	{
		Sleep(300);
		system("cls");
		int size = -1;

		while(size <= 2)
		{	
			cout << endl << ">> Enter board size: ";
			string sizeString;
			cin >> sizeString;
			try
			{
				size = stoi(sizeString);
			}
			catch(...) //Catches all the exceptions
			{
				size = -1;
			}

			if(size <= 2)
			{
				SetConsoleTextAttribute(hConsole,gameoverColor);
				cout << ">>>> Invalid Input. The size should at least be 3 )" << endl ;
				SetConsoleTextAttribute(hConsole,menuButtonsColor);
			}
		}

		ShowLeaderBoard(size);
	}

//Leaderbaord and User Manager
	void boubleSort(User *& users)
	{
		for(int i = 0; i < currentGameCount - 1; i++)
		{
			for(int j = i+1; j < currentGameCount; j++)
			{
				if(users[i].score < users[j].score)
				{
					swap(users[i],users[j]);
				}
			}
		}
	}

	void append(User user, User *& users)
	{
		if(currentGameCount >= capacity)
		{
			User* newUsers = new User[capacity*2];
		
			capacity *= 2;

			for(int i = 0; i < currentGameCount; i++)
			{
				newUsers[i] = users[i];
			}
			delete[] users;
			users = newUsers;
		}
		
		users[currentGameCount] = user;
		currentGameCount++;
	}

	int GetLeaderboard(int boardSize, User *& users)
	{
		ifstream dataFile("MeshScores.txt");
		currentGameCount = 0;
		capacity = 1;

		if(dataFile.is_open())
		{
			string text;
			while(getline(dataFile,text))
			{
				if(text.length() > 2)
				{
					User user;
					user.boardSize = stoi(text.substr(0, text.find(",")));
					if(user.boardSize != boardSize)
					{
						continue;
					}
					text = text.substr(text.find(",")+1);
					user.score = stoll(text.substr(0, text.find(",")));
					text = text.substr(text.find(",")+1);
					user.name = text.substr(0, text.find(","));
					text = text.substr(text.find(",")+1);
					user.hasWon = (text == "true")?true:false;
					append(user, users);
				}
			}

			boubleSort(users);
		}

		return currentGameCount;
	}

	long long GetBestScore(int boardSize)
	{
		User * users = new User[1];
		if(GetLeaderboard(boardSize, users) != 0)
		{
			return users[0].score;
		}
		return 0;
	}

	void SaveUser(User user)
	{
		ofstream dataFile("MeshScores.txt", ios::app);
		if(dataFile.is_open())
		{
			string line = "\n" +to_string(user.boardSize) + "," + to_string(user.score) + "," + user.name + "," + ((user.hasWon)?"true":"false") ; 
			dataFile << line;
			dataFile.close();
		}   
	}

//Board Movements
	//Moving the tiles up
	void Up(int** board)
	{	
		hasMoved = false;	
		for(int j = 0; j < boardSize; j++)
		{
			int lastNumberI = -1;
			int howManyToDelete = 0;		
			for(int i = 0; i < boardSize ; i++)
			{
				int theI = i;
				int theJ = j;
				if(board[theI][theJ] == 0)
				{
					howManyToDelete++;
				}
				else
				{				
					if(lastNumberI != -1)
					{
						if(board[lastNumberI][theJ] == board[theI][theJ])
						{
							howManyToDelete++;
							int newNumber = board[lastNumberI][theJ] * 2;
							score += newNumber;
							if(newNumber == maxNumber) {hasWon = true;}
							board[lastNumberI][theJ] = newNumber;
							board[theI][theJ] = 0;
							tileCounts--;
							lastNumberI = -1;	
							hasMoved = true;
						}
						else
						{
							if(howManyToDelete > 0)
							{
								board[theI - howManyToDelete][theJ ] = board[theI][theJ];
								board[theI][theJ] = 0;
								hasMoved = true;
							}
							lastNumberI = theI - howManyToDelete;
						}
					}
					else
					{
							if(howManyToDelete > 0)
							{ 												
								board[theI - howManyToDelete][theJ] = board[theI][theJ];
								board[theI][theJ] = 0;
								hasMoved = true;
							}
							lastNumberI = theI - howManyToDelete;
					}
				}
			}
		}
	}

	//Moving the tiles down
	void Down(int** board)
	{
		hasMoved = false;	

		for(int j = 0; j < boardSize; j++)
		{
			int lastNumberI = -1;
			int howManyToDelete = 0;		
			for(int i = boardSize - 1; i >= 0 ; i--)
			{
				int theI = i;
				int theJ = j;
				if(board[theI][theJ] == 0)
				{
					howManyToDelete++;
				}
				else
				{
					if(lastNumberI != -1)
					{
						if(board[lastNumberI][theJ] == board[theI][theJ])
						{
							howManyToDelete++;
							int newNumber = board[lastNumberI][theJ] * 2; 
							if(newNumber == maxNumber) {hasWon = true;}
							score += newNumber; 
							board[lastNumberI][theJ] = newNumber;
							board[theI][theJ] = 0;
							tileCounts--;
							lastNumberI = -1;	
							hasMoved = true;
						}
						else
						{
							if(howManyToDelete > 0)
							{
								board[theI + howManyToDelete][theJ ] = board[theI][theJ];
								board[theI][theJ] = 0;
							hasMoved = true;

							}
							lastNumberI = theI + howManyToDelete;
						}
					}
					else
					{
							if(howManyToDelete > 0)
							{ 												
								board[theI + howManyToDelete][theJ] = board[theI][theJ];
								board[theI][theJ] = 0;
								hasMoved = true;
							}
							lastNumberI = theI + howManyToDelete;
					}
				}
			}
		}
	}

	//Moving the tiles right
	void Right(int** board)
	{
		hasMoved = false;

		for(int i = 0; i < boardSize; i++)
		{
			int lastNumberJ = -1;
			int howManyToDelete = 0;		
			for(int j = boardSize - 1; j >= 0 ; j--)
			{
				int theI = i;
				int theJ = j;
				if(board[theI][theJ] == 0)
				{
					howManyToDelete++;
				}
				else
				{
					if(lastNumberJ != -1)
					{
						if(board[theI][lastNumberJ] == board[theI][theJ])
						{
							howManyToDelete++;
							int newNumber = board[theI][lastNumberJ] * 2; 
							if(newNumber == maxNumber) {hasWon = true;}
							score += newNumber;

							board[theI][lastNumberJ] = newNumber;
							board[theI][theJ] = 0;
							tileCounts--;
							lastNumberJ = -1;	
							hasMoved = true;

						}
						else
						{
							if(howManyToDelete > 0)
							{ 				
								board[theI][theJ + howManyToDelete] = board[theI][theJ];
								board[theI][theJ] = 0;
							hasMoved = true;

							}
							lastNumberJ = theJ + howManyToDelete;
						}
					}
					else
					{
							if(howManyToDelete > 0)
							{ 							
								board[theI][theJ + howManyToDelete] = board[theI][theJ];
								board[theI][theJ] = 0;
								hasMoved = true;
							}
							lastNumberJ = theJ + howManyToDelete;
					}
				}
			}
		}
	}

	// Moving the tiles left
	void Left(int** board)
	{
		hasMoved = false;

		for(int i = 0; i < boardSize; i++)
		{
			int lastNumberJ = -1;
			int howManyToDelete = 0;		
			for(int j = 0; j < boardSize; j++)
			{
				int theI = i;
				int theJ = j;
				if(board[theI][theJ] == 0)
				{
					howManyToDelete++;
				}
				else
				{
					if(lastNumberJ != -1)
					{
						if(board[theI][lastNumberJ] == board[theI][theJ])
						{
							howManyToDelete++;
							int newNumber = board[theI][lastNumberJ] * 2;
							if(newNumber == maxNumber) {hasWon = true;}
							score +=  newNumber;
							board[theI][lastNumberJ] = newNumber;
							board[theI][theJ] = 0;
							tileCounts--;
							lastNumberJ = -1;
							hasMoved = true;

						}
						else
						{
							if(howManyToDelete > 0)
							{ 						
								board[theI][theJ - howManyToDelete] = board[theI][theJ];
								board[theI][theJ] = 0;
							hasMoved = true;

							}
							lastNumberJ = theJ - howManyToDelete;

						}
					}
					
					else
					{
							if(howManyToDelete > 0)
							{ 	
								board[theI][theJ - howManyToDelete] = board[theI][theJ];
								board[theI][theJ] = 0;
							hasMoved = true;

							}
							
							lastNumberJ = theJ - howManyToDelete;
					}
				}
			}
			
			
		}
		
	}

	bool CheckIfMoveIsPossible(int** board)
	{
		for(int i = 0; i < boardSize; i++)
		{
			int lastOneHorizontally;
			int lastOneVertically;
			for(int j = 0; j < boardSize; j++)
			{
				if(j == 0) lastOneHorizontally = board[i][j];
				else if(lastOneHorizontally == board[i][j]) { return true;}
				else lastOneHorizontally = board[i][j];

				if(j == 0) lastOneVertically = board[j][i];
				else if(lastOneVertically == board[j][i]) { return true;}
				else lastOneVertically = board[j][i];
			}
		}
		return false;
	}

//TheGame 
	int GetRandomNumber(int from, int to)
	{
		return rand() % to + from;
	}

	int GetTwoOrFour()
	{
		int a = GetRandomNumber(1, 4);
		if(a <= 3)
		{
			return 2;
		}
		return 4;
	}

	int CountDigits(int number)
	{
		int t = 0;
		while(number > 0 )
		{
			number /= 10;
			t++;
		}
		return t;
	}
	
	int AddTile(int** board)
	{
		if(tileCounts >= boardSize * boardSize) {return 1;}
		while(true)
		{
			int i  = GetRandomNumber(1, boardSize) - 1;
			int j = GetRandomNumber(1, boardSize) - 1;
			if(board[i][j] == 0)
			{
				board[i][j] = GetTwoOrFour();
				break;
			}
		}
		tileCounts++;
		return 0;
	}

	void Finish()
	{
		User user;
		user.name = playerName;
		user.hasWon = hasWon;
		user.score = score;
		user.boardSize = boardSize;
		SaveUser(user);
	}

	void start(int theSize, string name)
	{
		//Initializing:
		tileCounts = 0;
		playerName = name;
		hasWon = false;
		hasBrokenRecord = false;
		boardSize = theSize;
		score = 0;
		bestScore = GetBestScore(boardSize);

		srand(static_cast<unsigned int>(time(nullptr)));

		SetConsoleTextAttribute(hConsole, defaultBorderColor);
		int** board = new int*[boardSize];
		for(int i = 0; i < boardSize; i++)
		{
			board[i] = new int[boardSize];
			for(int j = 0; j < boardSize; j++)
			{
				board[i][j] = 0;
			}
		}
		
		AddTile(board);
		AddTile(board);
		Print(board);

		while(true)
		{
			char input = getch();

			if(input == 'p') {Pause(); Print(board);}
			switch(input)
			{
				case 'W' : ;
				case 'w' : Up(board);break;
				case 'S' : ;
				case 's' : Down(board);break;	
				case 'D' : ;
				case 'd' : Right(board);break;
				case 'A' : ;
				case 'a' : Left(board);break;
				default: continue;
			}	
			if(score > bestScore) hasBrokenRecord = true;
			Print(board);

			if(hasWon)
			{
				cout << endl << endl;
				Finish();
				SetConsoleTextAttribute(hConsole, wonColor);
				PrintString12Segment("you won",3);
				
				cout << initialSpace << "Press b to get back to the main menu";
				SetConsoleTextAttribute(hConsole, defaultBorderColor);
				char input = '0';
				while(input != 'b')
				{
					input = getch();
				}

				break;
			}

			if(tileCounts >= boardSize * boardSize)
			{
				if(CheckIfMoveIsPossible(board) == false)
				{
					cout << endl << endl;

					Finish();
					SetConsoleTextAttribute(hConsole, gameoverColor);
					PrintString12Segment("game over",3);
					cout << endl;
					cout << initialSpace << "Press b to get back to the main menu";
					SetConsoleTextAttribute(hConsole, defaultBorderColor);
					char input = '0';
					while(input != 'b')
					{
						input = getch();
					}
					break;				
				}
				else
				{
					if(hasMoved == false)
					{
						SetConsoleTextAttribute(hConsole, gameoverColor);				
						cout << initialSpace << ">>You can't move this way...";
						SetConsoleTextAttribute(hConsole, defaultBorderColor);
					}
				}
			}
			else if(hasMoved == false)
			{
				SetConsoleTextAttribute(hConsole, gameoverColor);				
				cout << initialSpace << ">>You can't move this way...";
				SetConsoleTextAttribute(hConsole, defaultBorderColor);
			}
			else
			{
				AddTile(board);
				Print(board);
			}
		}
	}

	void Pause()
	{
		system("cls");
		cout << "Game is a Paused. Press p to continue" << endl;
		char ch = '1';
		while(ch != 'p')
		{
			ch = getch();
			
		}
	}


	void Print(int** board)
	{
		system("cls");
		cout << endl << endl;
		SetConsoleTextAttribute(hConsole,nameColor);
		cout << initialSpace << "> "<< playerName;
		cout << endl << endl;
		SetConsoleTextAttribute(hConsole,(hasBrokenRecord)?recordScoreColor:nowScoreColor );

		long long theActualBestScore = (hasBrokenRecord)?score:bestScore;

		string currentScoreTxt = "\u1bb0 score";
		if(hasBrokenRecord)
		{
			currentScoreTxt += "(new record)";
		}
		currentScoreTxt += ":";

		cout << initialSpace << currentScoreTxt << setw(boardSize*6 + boardSize+ CountDigits(score) - CountDigits(theActualBestScore) - currentScoreTxt.length())<< score << endl;
		SetConsoleTextAttribute(hConsole,bestScoreColor);
		string bestScoreTxt = "\u1bb0 Best score:";
		cout << initialSpace << bestScoreTxt << setw(boardSize * 6 + boardSize - bestScoreTxt.length()) << theActualBestScore;
		SetConsoleTextAttribute(hConsole,defaultBorderColor);
		cout << endl << endl;

		for(int i = 0; i < boardSize; i++)
		{
			cout << initialSpace;

				
			for(int k = 0; k < boardSize; k++)
			{
				int number = board[i][k];
				int color = baseNumberColor;
				switch(number)
				{
					case 0: color = 8; break;
					case 2: color = 11; break;
					case 4: color = 5; break;
					case 8: color = 13; break;
					case 16: color = 3; break;
					case 32: color = 6; break;
					case 64: color = 9; break;
					case 128: color = 15; break;
					case 256: color = 12; break;
					case 512: color = 14; break;
					case 1024: color = 2; break;
					case 2048: color = 10; break;
				}
				SetConsoleTextAttribute(hConsole, color);

				cout << "\u256d";
				cout << "\u2500\u2500\u2500\u2500"; 
				cout << "\u256e";
				if( k!= boardSize - 1) cout << " ";
			}
			cout << endl;
			cout << initialSpace;
			for(int k = 0; k < boardSize; k++)
			{
				int number = board[i][k];
				int color = baseNumberColor;
				switch(number)
				{
					case 0: color = 8; break;
					
					case 2: color = 11; break;
					case 4: color = 5; break;
					case 8: color = 13; break;
					case 16: color = 3; break;
					case 32: color = 6; break;
					case 64: color = 9; break;
					case 128: color = 15; break;
					case 256: color = 12; break;
					case 512: color = 14; break;
					case 1024: color = 2; break;
					case 2048: color = 10; break;
				}
				SetConsoleTextAttribute(hConsole, color);

				cout << "\u2502";
				cout << "    "; 
				cout << "\u2502";
				if(k!= boardSize - 1) cout << " ";
			}
			cout << endl;
			cout << initialSpace;
			for(int j = 0; j < boardSize; j++)
			{
				int number = board[i][j];

				int color = baseNumberColor;
				switch(number)
				{
					case 0: color = 8; break;
					
					case 2: color = 11; break;
					case 4: color = 5; break;
					case 8: color = 13; break;
					case 16: color = 3; break;
					case 32: color = 6; break;
					case 64: color = 9; break;
					case 128: color = 15; break;
					case 256: color = 12; break;
					case 512: color = 14; break;
					case 1024: color = 2; break;
					case 2048: color = 10; break;
				}
				SetConsoleTextAttribute(hConsole, color);

				cout << "\u2502";
				
				if(number / 10 == 0)
				{
					if(number != 0)
						cout << setw(3) << number<< " ";
					else 
						cout << "    ";
				}
				else if(number / 100 == 0)
				{
					cout << " "<< number << " ";
				}
				else
				{
					cout << setw(4) << number;
				}
				
				// SetConsoleTextAttribute(hConsole, defaultBorderColor);

				cout << "\u2502";
				if( j!= boardSize - 1) cout << " ";
			}
			
			cout << endl;
			cout << initialSpace;
			
			for(int k = 0; k < boardSize; k++)
			{
				int number = board[i][k];
				int color = baseNumberColor;
				switch(number)
				{
					case 0: color = 8; break;
					
					case 2: color = 11; break;
					case 4: color = 5; break;
					case 8: color = 13; break;
					case 16: color = 3; break;
					case 32: color = 6; break;
					case 64: color = 9; break;
					case 128: color = 15; break;
					case 256: color = 12; break;
					case 512: color = 14; break;
					case 1024: color = 2; break;
					case 2048: color = 10; break;
				}
				SetConsoleTextAttribute(hConsole, color);

				cout << "\u2502";
				cout << "    "; 
				cout << "\u2502";
				if(k!= boardSize - 1) cout << " ";
			}
			cout << endl;
			cout << initialSpace;
			for(int k = 0; k < boardSize; k++)
			{
				int number = board[i][k];
				int color = baseNumberColor;
				switch(number)
				{
					case 0: color = 8; break;
					
					case 2: color = 11; break;
					case 4: color = 5; break;
					case 8: color = 13; break;
					case 16: color = 3; break;
					case 32: color = 6; break;
					case 64: color = 9; break;
					case 128: color = 15; break;
					case 256: color = 12; break;
					case 512: color = 14; break;
					case 1024: color = 2; break;
					case 2048: color = 10; break;
				}
				SetConsoleTextAttribute(hConsole, color);

				cout << "\u2570";
				cout << "\u2500\u2500\u2500\u2500"; 
				cout << "\u256f";

				if(k != boardSize - 1) cout << " ";
			}
			
			cout << endl;
			cout << initialSpace;
			if(i != boardSize -1 )
				for(int k = 0; k < boardSize; k++)
				{
					cout << " ";
					cout << "    "; 
					cout << " ";
					if(k != boardSize - 1) cout << " ";
				}
			cout << endl;
			SetConsoleTextAttribute(hConsole, defaultBorderColor);

		}
	}



int main()
{
	//Initializing hConsole (For managing the colors)
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	HideCursor();
	SetConsoleTextAttribute(hConsole, menuButtonsColor);

	ShowIntro();

    int activeOne = 0;
	ShowMainMenu(activeOne);
    while(true)
    {
		char ch = getch();
		if(ch == 'w' || ch == 72) 
		{ 
			activeOne--;
			if(activeOne < 0) activeOne = 3;
			ShowMainMenu(activeOne);
		}
		if(ch == 's'|| ch == 80) 
		{	 		
			activeOne++;
			if(activeOne > 3) activeOne = 0;
			ShowMainMenu(activeOne);
		}
		if(ch == 'e') 
		{	 
			return 0;
		}
		if(ch == '\r') // Pressing Enter
		{
			if(activeOne == 0)
			{
				AskGameDetails();
				ShowMainMenu(activeOne);
		    	continue;
			}

			if(activeOne == 1)
        	{	
				AskSizeAndShowLeaderBoard();
				ShowMainMenu(activeOne);
			}

			if(activeOne == 2)
        	{
				ShowCredits();
				ShowMainMenu(activeOne);
			}

			if(activeOne == 3)
        	{
				system("cls");
				PrintDramatically("Goodbye");
				SetConsoleTextAttribute(hConsole, menuButtonsColor);
				Sleep(500);
           		return 0;
			}	
		}
	}	
}