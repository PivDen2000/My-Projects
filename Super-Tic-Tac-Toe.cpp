#include <iostream>
using namespace std;

char Player = 'X'; // XO
bool isDone = true;
int availableBig = -1;
int tempI = 0, tempJ = 0;

char Winner = ' ';
char Big[9] = { ' ',' ',' ',
				' ',' ',' ',
				' ',' ',' '
};
char Small[9][9] = {
{	' ',' ',' ',
	' ',' ',' ',
	' ',' ',' '
},
{	' ',' ',' ',
	' ',' ',' ',
	' ',' ',' '
},
{	' ',' ',' ',
	' ',' ',' ',
	' ',' ',' '
},
{	' ',' ',' ',
	' ',' ',' ',
	' ',' ',' '
},
{	' ',' ',' ',
	' ',' ',' ',
	' ',' ',' '
},
{	' ',' ',' ',
	' ',' ',' ',
	' ',' ',' '
},
{	' ',' ',' ',
	' ',' ',' ',
	' ',' ',' '
},
{	' ',' ',' ',
	' ',' ',' ',
	' ',' ',' '
},
{	' ',' ',' ',
	' ',' ',' ',
	' ',' ',' '
}
};

void Output() {
	system("cls");

	char Symbol = '#';

	cout << "Turn: " << Player << endl;;
	cout << "Available Big Cell: " << availableBig + 1 << endl;
	cout << "Last turn: (" << tempI << ',' << tempJ << ')' << endl;

	cout << " j  123 456 789" << endl;
	int counter = 1;
	for (size_t i = 0; i < 3; i++)
	{
		cout << (char*)(!i ? "i\n " : " ");
		cout << "  " << string(13, Symbol) << endl;
		for (size_t j = 0; j < 3; j++)
		{
			cout << counter << "  " << Symbol;
			++counter;
			for (size_t k = 0; k < 3; k++)
			{
				for (size_t l = 0; l < 3; l++)
				{
					cout << Small[k + 3 * i][l + 3 * j];
				}
				cout << Symbol;
			}
			cout << endl;
		}
	}
	cout << "   " << string(13, Symbol) << endl;
}
void Convertor(int& i, int& j) {
	int resI, resJ;
	if (1 <= i && i <= 3) {
		if (1 <= j && j <= 3) {
			resI = 0;
		}
		if (4 <= j && j <= 6) {
			resI = 1;
		}
		if (7 <= j && j <= 9) {
			resI = 2;
		}
	}
	if (4 <= i && i <= 6) {
		if (1 <= j && j <= 3) {
			resI = 3;
		}
		if (4 <= j && j <= 6) {
			resI = 4;
		}
		if (7 <= j && j <= 9) {
			resI = 5;
		}
	}
	if (7 <= i && i <= 9) {
		if (1 <= j && j <= 3) {
			resI = 6;
		}
		if (4 <= j && j <= 6) {
			resI = 7;
		}
		if (7 <= j && j <= 9) {
			resI = 8;
		}
	}

	if (i % 3 == 1) {
		if (j % 3 == 1) {
			resJ = 0;
		}
		if (j % 3 == 2) {
			resJ = 1;
		}
		if (j % 3 == 0) {
			resJ = 2;
		}
	}
	if (i % 3 == 2) {
		if (j % 3 == 1) {
			resJ = 3;
		}
		if (j % 3 == 2) {
			resJ = 4;
		}
		if (j % 3 == 0) {
			resJ = 5;
		}
	}
	if (i % 3 == 0) {
		if (j % 3 == 1) {
			resJ = 6;
		}
		if (j % 3 == 2) {
			resJ = 7;
		}
		if (j % 3 == 0) {
			resJ = 8;
		}
	}

	i = resI;
	j = resJ;
}
bool checkSmallWinner(char Player, int i) {
	if ((Player == Small[i][0] && Player == Small[i][4] && Player == Small[i][8]) ||
		(Player == Small[i][2] && Player == Small[i][4] && Player == Small[i][6]) ||
		(Player == Small[i][0] && Player == Small[i][1] && Player == Small[i][2]) ||
		(Player == Small[i][3] && Player == Small[i][4] && Player == Small[i][5]) ||
		(Player == Small[i][6] && Player == Small[i][7] && Player == Small[i][8]) ||
		(Player == Small[i][0] && Player == Small[i][3] && Player == Small[i][6]) ||
		(Player == Small[i][1] && Player == Small[i][4] && Player == Small[i][7]) ||
		(Player == Small[i][2] && Player == Small[i][5] && Player == Small[i][8])) {
		return true;
	}
	return false;
}
bool checkBigWinner(char Player) {
	if ((Player == Big[0] && Player == Big[4] && Player == Big[8]) ||
		(Player == Big[2] && Player == Big[4] && Player == Big[6]) ||
		(Player == Big[0] && Player == Big[1] && Player == Big[2]) ||
		(Player == Big[3] && Player == Big[4] && Player == Big[5]) ||
		(Player == Big[6] && Player == Big[7] && Player == Big[8]) ||
		(Player == Big[0] && Player == Big[3] && Player == Big[6]) ||
		(Player == Big[1] && Player == Big[4] && Player == Big[7]) ||
		(Player == Big[2] && Player == Big[5] && Player == Big[8])) {
		return true;
	}
	return false;
}

void GridInitialize() {
	int i = 0, j = 0;
	while (1 > i || i > 9 || 1 > j || j > 9) {
		Output();
		if (!isDone) {
			cout << "Incorrect turn, please i";
		}
		else {
			cout << 'I';
		}
		cout << "nput i and j coordinates of your turn..." << endl;
		cin >> i >> j;
	}
	tempI = i;
	tempJ = j;
	Convertor(i, j);

	isDone = false;
	if ((availableBig == -1 || availableBig == i) && Small[i][j] == ' ') {
			Small[i][j] = Player;
			if (checkSmallWinner(Player, i)) {
				Big[i] = Player;
				for (size_t j = 0; j < 9; j++)
				{
					Small[i][j] = Player;
				}
				if (checkBigWinner(Player)) {
					Winner = Player;
				}
			}
			(Big[j] == ' ') ? (availableBig = j) : (availableBig = -1);
			isDone = true;
	}
	else {
		isDone = false;
	}

	if (Winner == Player) {
		Output();
		cout << Player << " WIN!!!!!\n";
	}

	if (isDone) {
		(Player == 'X') ? (Player = 'O') : (Player = 'X');
	}
}

int main() {
	while (Winner == ' ')
	{
		GridInitialize();
	}

	system("pause");
	return 0;
}