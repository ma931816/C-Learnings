#include <iostream>
using namespace std;

char Arr[3][3] = { { '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' } };
char turn = 'O';
int row, column;
bool draw = false;

void board()
{
	system("cls");

	cout << "\n\n\t This is  T I C   T A C    T O E    Game!" << endl;
	cout << "\n\tGame is developed by SYED M ALI HUSSAIN\n";
	cout << "\n\tplayer1[X]";
	cout << "\n\tPlayer2[O]\n";
	cout << "\t\t      |     |     \n";
	cout << "\t\t  " << Arr[0][0] << "   |  " << Arr[0][1] << "  |  " << Arr[0][2] << "  \n";
	cout << "\t\t      |     |     \n";
	cout << "\t\t _____|_____|_____\n";
	cout << "\t\t      |     |     \n";
	cout << "\t\t  " << Arr[1][0] << "   |  " << Arr[1][1] << "  |  " << Arr[1][2] << "  \n";
	cout << "\t\t      |     |     \n";
	cout << "\t\t _____|_____|_____\n";
	cout << "\t\t      |     |     \n";
	cout << "\t\t  " << Arr[2][0] << "   |  " << Arr[2][1] << "  |  " << Arr[2][2] << "  \n";
	cout << "\t\t      |     |     \n";
	cout << "\t\t      |     |     \n";
}

void player_turn() 
{
	int choice;

	if (turn == 'X')
	{
		cout << "\t\nEnter your location to mark[1-9] Player1 turn[X]:";
	}
	if (turn == 'O')
	{
		cout << "\t\nEnter your location to mark[1-9] Player2 turn[O]:";
	}
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
			  row = 0;
			  column = 0;
			  break;
	}
	case 2:
	{
			  row = 0;
			  column = 1;
			  break;
	}
	case 3:
	{
			  row = 0;
			  column = 2;
			  break;
	}
	case 4:
	{
			  row = 1;
			  column = 0;
			  break;
	}
	case 5:
	{
			  row = 1;
			  column = 1;
			  break;
	}
	case 6:
	{
			  row = 1;
			  column = 2;
			  break;
	}
	case 7:
	{
			  row = 2;
			  column = 0;
			  break;
	}
	case 8:
	{
			  row = 2;
			  column = 1;
			  break;
	}
	case 9:
	{
			  row = 2;
			  column = 2;
			  break;
	}
	default:
	{
			   cout << "invalid Choice:";
			   break;
	}
	}
	if (turn == 'X' && Arr[row][column] != 'X' && Arr[row][column] != 'O')
	{
		Arr[row][column] = 'X';
		turn = 'O';
	}
	else if (turn == 'O' && Arr[row][column] != 'X' && Arr[row][column] != 'O')
	{
		Arr[row][column] = 'O';
		turn = 'X';
	}
	else 
	{
		cout << "Box already filed! Try again!!\n\n";
		player_turn();
	}
	board();
}

bool gameover() 
{
	for (int i = 0; i < 3; i++)
	{
		if (Arr[i][0] == Arr[i][1] && Arr[i][0] == Arr[i][2] || Arr[0][i] == Arr[1][i] && Arr[0][i] == Arr[2][i]) 
		{
			return false;
		}
	}
	if (Arr[0][0] == Arr[1][1] && Arr[0][0] == Arr[2][2] || Arr[0][2] == Arr[1][1] && Arr[0][0] == Arr[2][0])
	{
		return false;
	}
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			if (Arr[i][j] != 'X' && Arr[i][j] != 'O')
			{
				return true;
			}
		}
	}
	draw = true;
	return false;
}

int main() 
{
	while (gameover())
	{
		board();
		player_turn();
		gameover();
	}
	if (turn == 'X' && draw == false) 
	{
		cout << "Player2 [O] Wins!! Congratulations\n";
	}
	else if (turn == 'O' && draw == false)
	{
		cout << "Player1 [X] Wins!! Congratulations\n";
	}
	else 
	{
		cout << "Game is Draw!!\n";
	}

	system("pause");
	return 0;
}
