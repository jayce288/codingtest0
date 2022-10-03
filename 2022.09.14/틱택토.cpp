#include <iostream>
#include <string>
using namespace std;

char map[3][3];
string input;

bool CheckXwin()
{
	bool ret = false;
	for (int i = 0; i < 3; ++i)
		if (map[i][0] == 'X' && map[i][0] == map[i][1] && map[i][1] == map[i][2])
			ret = true;
	for (int j = 0; j < 3; ++j)
		if (map[0][j] == 'X' && map[0][j] == map[1][j] && map[1][j] == map[2][j])
			ret = true;

	if (map[0][0] == 'X' && map[0][0] == map[1][1] && map[1][1] == map[2][2])
		ret = true;

	if (map[0][2] == 'X' && map[0][2] == map[1][1] && map[1][1] == map[2][0])
		ret = true;

	return ret;
}

bool CheckOwin()
{
	bool ret = false;
	for (int i = 0; i < 3; ++i)
		if (map[i][0] == 'O' && map[i][0] == map[i][1] && map[i][1] == map[i][2])
			ret = true;
	for (int j = 0; j < 3; ++j)
		if (map[0][j] == 'O' && map[0][j] == map[1][j] && map[1][j] == map[2][j])
			ret = true;

	if (map[0][0] == 'O' && map[0][0] == map[1][1] && map[1][1] == map[2][2])
		ret = true;

	if (map[0][2] == 'O' && map[0][2] == map[1][1] && map[1][1] == map[2][0])
		ret = true;

	return ret;
}


int main()
{
	cin >> input;

	while (input != "end")
	{
		int onum = 0, xnum = 0;
		bool owin = false, xwin = false;

		for (int i = 0; i < 9; ++i) {
			map[i / 3][i % 3] = input[i];
			if (input[i] == 'O')
				++onum;
			else if (input[i] == 'X')
				++xnum;
		}

		owin = CheckOwin();
		xwin = CheckXwin();

		if (xwin && !owin && xnum - onum == 1) {
			cout << "valid\n";
		}
		else if (!xwin && owin && onum == xnum) {
			cout << "valid\n";
		}
		else if (!xwin && !owin && xnum == 5 && onum == 4) {
			cout << "valid\n";
		}
		else {
			cout << "invalid\n";
		}

		cin >> input;
	}
	return 0;
}