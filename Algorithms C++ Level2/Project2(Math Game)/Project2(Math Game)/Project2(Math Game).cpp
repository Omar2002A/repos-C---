#include <iostream>
#include <cstdlib>
using namespace std;

enum enQuestionsLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };

enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5 };

string GetOpTypeSympol(enOperationType OpType)
{
	switch (OpType)
	{
	case Add:
		return "+";
	case Sub:
		return "-";
	case Mul:
		return "*";
	case Div:
		return "/";
	default:
		return "Mix";
	}
}

string GetQuestionLevel(enQuestionsLevel QuestionLevel)
{
	string arrQuestionLevel[4] = { "Easy","Med","Hard","Mix" };
	return arrQuestionLevel[QuestionLevel - 1];
}

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

short ReadHowManyQuestions()
{
	short Number = 1;
	do
	{
		cout << "How Many Questions do you want to answer! 1 to 10 ? ";
		cin >> Number;

	} while (Number < 1 || Number>10);
	return Number;
}

enQuestionsLevel ReadQuestionsLevel()
{
	short QuestionLevel = 1;
	do
	{
		cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
		cin >> QuestionLevel;

	} while (QuestionLevel<1||QuestionLevel>4);
	return (enQuestionsLevel)QuestionLevel;
}

enOperationType ReadOpType()
{
	short OpType = 1;
	do
	{
		cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
		cin >> OpType;

	} while (OpType < 1 || OpType>5);
	return (enOperationType)OpType;
}

void SetScreenColor(bool Right)
{
	if (Right)
		system("color 2F");
	else
	{
		system("color 4F");
		cout << "\a";
	}
}

void Reset()
{
	system("cls");
	system("color 0F");
}

struct stQuestion
{
	int Number1 = 0, Number2 = 0;
	enOperationType OperationType;
	enQuestionsLevel QuestionLevel;
	int CorrectAnswer = 0, PlayerAnswer = 0;
	bool AnswerResult = false;
};

struct stQuizz
{
	stQuestion QuestionsList[100];
	short NumberOfQuestion;
	enOperationType OperationType;
	enQuestionsLevel QuestionLevel;
	short NumberOfWrongAnswers = 0, NumberOfRightAnswers = 0;
	bool isPass = false;
};

int SimpleCalculator(int Number1, int Number2, enOperationType OpType)
{
	switch (OpType)
	{
	case Add:
		return Number1 + Number2;
	case Sub:
		return Number1 - Number2;
	case Mul:
		return Number1 * Number2;
	case Div:
		return Number1 / Number2;
	default:
		return Number1 + Number2;
	}
}

enOperationType GetRandomOpType()
{
	return (enOperationType)RandomNumber(1, 4);
}

enQuestionsLevel GetRandomQLevel()
{
	return (enQuestionsLevel)RandomNumber(1, 3);
}

stQuestion GenerateQuestion(enQuestionsLevel QuestionLevel, enOperationType OpType)
{
	stQuestion Question;
	if (QuestionLevel == enQuestionsLevel::Mix)
		QuestionLevel = GetRandomQLevel();
	if (OpType == enOperationType::MixOp)
		OpType = GetRandomOpType();
	Question.OperationType = OpType;

	switch (QuestionLevel)
	{
	case Easy:
		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);

		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;

		return Question;
	
	case Med:
		Question.Number1 = RandomNumber(10, 50);
		Question.Number2 = RandomNumber(10, 50);

		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;

		return Question;
	
	case Hard:
		Question.Number1 = RandomNumber(50, 100);
		Question.Number2 = RandomNumber(50, 100);

		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;

		return Question;
	}
	return Question;
}

void GenerateQuizzQuestion(stQuizz& Quizz)
{
	for (short Question = 0; Question < Quizz.NumberOfQuestion; Question++)
	{
		Quizz.QuestionsList[Question] = GenerateQuestion(Quizz.QuestionLevel, Quizz.OperationType);
	}
}

int ReadQuestionAnswer()
{
	int Answer = 0;
	cin >> Answer;
	return Answer;
}

void PrintTheQuestion(stQuizz& Quizz, short QuestionNumber)
{
	cout << "\nQuestion [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestion << "] \n\n";
	cout << Quizz.QuestionsList[QuestionNumber].Number1
		<< " " << GetOpTypeSympol(Quizz.QuestionsList[QuestionNumber].OperationType) << endl;
	cout << Quizz.QuestionsList[QuestionNumber].Number2 << "\n________" << endl;
}

void CorrectTheQuestionAnswer(stQuizz& Quizz, short QuestionNumber)
{
	if (Quizz.QuestionsList[QuestionNumber].PlayerAnswer != Quizz.QuestionsList[QuestionNumber].CorrectAnswer)
	{
		Quizz.QuestionsList[QuestionNumber].AnswerResult = false;
		Quizz.NumberOfWrongAnswers++;

		cout << "Wrong Answer :( \n";
		cout << "The Right Answer is : " << Quizz.QuestionsList[QuestionNumber].CorrectAnswer << "\n";
	}
	else
	{
		Quizz.QuestionsList[QuestionNumber].AnswerResult = true;
		Quizz.NumberOfRightAnswers++;

		cout << "Right Answer :) \n";
	}
	cout << endl;
	SetScreenColor(Quizz.QuestionsList[QuestionNumber].AnswerResult);
}

void AskAndCorrectQuestionListAnswers(stQuizz& Quizz)
{
	for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestion; QuestionNumber++)
	{
		PrintTheQuestion(Quizz, QuestionNumber);

		Quizz.QuestionsList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();
		CorrectTheQuestionAnswer(Quizz, QuestionNumber);
	}
	Quizz.isPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers);
}

string GetFinalResultsText(bool Pass)
{
	if (Pass)
		return "PASS :) ";
	else
		return "Fail :( ";
}

void PrintQuizzResults(stQuizz Quizz)
{
	cout << "\n";      
	cout << "______________________________\n\n"; 
	cout << " Final Resutls is " << GetFinalResultsText(Quizz.isPass);      
	cout << "\n______________________________\n\n";;
	cout << "Number of Questions: " << Quizz.NumberOfQuestion << endl;
	cout << "Questions Level    : " << GetQuestionLevel(Quizz.QuestionLevel) << endl;
	cout << "OpType             : " << GetOpTypeSympol(Quizz.OperationType) << endl;      
	cout << "Number of Right Answers: " << Quizz.NumberOfRightAnswers << endl;    
	cout << "Number of Wrong Answers: " << Quizz.NumberOfWrongAnswers << endl;      
	cout << "______________________________\n"; 
}

void PlayMathGame()
{
	stQuizz Quizz;

	Quizz.NumberOfQuestion = ReadHowManyQuestions();
	Quizz.QuestionLevel = ReadQuestionsLevel();
	Quizz.OperationType = ReadOpType();

	GenerateQuizzQuestion(Quizz);
	AskAndCorrectQuestionListAnswers(Quizz);
	PrintQuizzResults(Quizz);
}

void StartGame()
{
	char PlayAgain = 'y';
	do
	{
		Reset();
		PlayMathGame();

		cout << endl << "Do you want to play again ? Y / N ?";
		cin >> PlayAgain;

	} while (PlayAgain == 'y' || PlayAgain == 'Y');
}

int main()
{
	srand((unsigned)time(NULL));
	StartGame();
	return 0;
}