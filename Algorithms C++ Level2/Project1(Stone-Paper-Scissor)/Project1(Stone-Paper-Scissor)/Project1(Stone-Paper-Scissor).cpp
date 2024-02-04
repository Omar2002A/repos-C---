#include <iostream>
#include <cstdlib>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Seissors = 3 };

enum enWinner { Player = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
	short RoundNumber = 0;
	enGameChoice PlayerChoice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName;
};

struct stGameResults
{
	short GameRound = 0;
	short PlayerWinTimes = 0;
	short CompterWinTimes = 0;
	short DrawTimes = 0;
	enWinner GameWinner;
	string WinnerName = "";
};

short ReadHowManyRounds()
{
	short GameRounds = 1; 
	do 
	{ cout << "How Many Rounds 1 to 10 ? \n";
	cin >> GameRounds; 

	}while (GameRounds < 1 || GameRounds >10); 
	return GameRounds;
}

short RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void SetWinnerScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case Player:
		system("color 2F");
		break;
	case Computer:
		system("color 4F");
		cout << "\a";
		break;
	case Draw:
		system("color 6F");
		break;
	}
}

enGameChoice ReadPlayerChoice()
{
	short Choice = 1;
	{
		cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ?";
		cin >> Choice;

	} while (Choice < 1 || Choice>3);
	return enGameChoice(Choice);
}

enGameChoice GetComputerChoice()
{
	return (enGameChoice)RandomNumber(1, 3);
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

string ChoiceName(enGameChoice Choice)
{
	string arrGameChoices[3] = { "Stone","Paper","Seissors" };
	return arrGameChoices[Choice - 1];
}

string WinnerName(enWinner Winner)
{
	string arrWinner[3] = { "Player","Computer","No Winner" };
	return arrWinner[Winner - 1];
}

enWinner HowWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.ComputerChoice == RoundInfo.PlayerChoice)
		return enWinner::Draw;
	switch (RoundInfo.PlayerChoice)
	{
	case enGameChoice::Stone:
		if (RoundInfo.ComputerChoice == enGameChoice::Paper)
			return enWinner::Computer;
	case enGameChoice::Paper:
		if (RoundInfo.ComputerChoice == enGameChoice::Seissors)
			return enWinner::Computer;
	case enGameChoice::Seissors:
		if (RoundInfo.ComputerChoice == enGameChoice::Stone)
			return enWinner::Computer;
	}
	return enWinner::Player;
}

void PrintRoundResults(stRoundInfo RoundInfo)
{
	cout << "\n__________Round [" << RoundInfo.RoundNumber << "] __________\n\n";
	cout << "Player Choice : " << ChoiceName(RoundInfo.PlayerChoice) << endl;
	cout << "Computer Choice : " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner : [" << RoundInfo.WinnerName << "] \n";
	cout << "_____________________________\n";
	SetWinnerScreenColor(RoundInfo.Winner);
}

enWinner HowWonTheGame(short PlayerWinTimes, short ComputerWinTimes)
{
	if (PlayerWinTimes > ComputerWinTimes)
		return enWinner::Player;
	else if (ComputerWinTimes > PlayerWinTimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;
}

string Tabs(short NumberOfTabs)
{
	string t = "";
	for (int i = 1; i < NumberOfTabs; i++)
	{
		t += "\t";
		cout << t;
	}
	return t;
}

void ShowGameOver()
{
	cout << Tabs(2) << "     ____________________________\n\n";
	cout << Tabs(2) << "           +++ Game Over +++      \n";
	cout << Tabs(2) << "     ____________________________\n\n";
}

void ShowFinalGameResults(stGameResults GameResults)
{
	cout << Tabs(2) << "______________ [Game Results]_______________\n\n";
	cout << Tabs(2) << "Game Rounds        : " << GameResults.GameRound << endl;
	cout << Tabs(2) << "Player won times   : " << GameResults.PlayerWinTimes << endl;
	cout << Tabs(2) << "Computer won times : " << GameResults.CompterWinTimes << endl;
	cout << Tabs(2) << "Draw times         : " << GameResults.DrawTimes << endl;
	cout << Tabs(2) << "Final Winner       :  " << GameResults.WinnerName << endl;
	cout << Tabs(2) << "____________________________________________\n";
	SetWinnerScreenColor(GameResults.GameWinner);
}

stGameResults FillGameResults(short GameRounds, short PlayerWinTimes, short ComputerWinTimes, short DrawTimes)
{
	stGameResults GameResults;
	GameResults.GameRound = GameRounds;
	GameResults.PlayerWinTimes = PlayerWinTimes;
	GameResults.CompterWinTimes = ComputerWinTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.GameWinner = HowWonTheGame(PlayerWinTimes, ComputerWinTimes);
	GameResults.WinnerName = WinnerName(GameResults.GameWinner);

	return GameResults;
}

stGameResults PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;
	short PlayerWinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;
	for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		cout << "\nRound [" << GameRound << "] begins : \n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.PlayerChoice = ReadPlayerChoice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = HowWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		if (RoundInfo.Winner == enWinner::Player)
			PlayerWinTimes++;
		else if (RoundInfo.Winner == enWinner::Computer)
			ComputerWinTimes++;
		else
			DrawTimes++;

		PrintRoundResults(RoundInfo);
	}
	return FillGameResults(HowManyRounds, PlayerWinTimes, ComputerWinTimes, DrawTimes);
}

void StartGame()
{
	char PlayAgain = 'y';
	while (PlayAgain == 'Y' || PlayAgain == 'y')
	{
		ResetScreen();
		stGameResults GameResults = PlayGame(ReadHowManyRounds());
		ShowGameOver();
		ShowFinalGameResults(GameResults);
		cout << endl << Tabs(4) << "Do you want to play again? Y/N ? ";
		cin >> PlayAgain;
	}
}

//void ShowGameOver()

int main()
{
	srand((unsigned)time(NULL));
	StartGame();
	return 0;
}