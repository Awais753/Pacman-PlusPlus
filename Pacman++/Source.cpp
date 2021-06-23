#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
int ChooseLevel();//This functions asks to choosefrome oneoftwo levels each built on different concepts.
int StupidDIRcheck();//In classic level this funtion asssingns random direction to stupidghost "S".
int ChaserDIRcheck(char map[32][28], int& My, int& Mx, int xpos, int ypos);/*In classic level this function asssingns direction
using Pythagoras thorum to chaser ghost "M"*/
int EDIRcheck(char Amap[18][32], int& Ey, int& Ex, int Px, int Py);/*In advanced level,This funtion gives dirction to Eater "E".*/
void Stupidmove(int Sdir, char dotmap[32][28], char map[32][28], int& Sx, int& Sy);/*This function moves the Stupid ghost in assigned direction.*/
void ChaserMove(int Mdir, char dotmap[32][28], char map[32][28], int& Mx, int& My);/*This funtion moves Chaser "M" in an assigned direction.*/
void EMove(int Edir, char Amap[18][32], int& Ex, int& Ey);/*This funtion moves Eater "E" in an assigned direction.*/
void PACmove(char map[32][28], char dotmap[32][28], int& ypos, int& xpos, int& score);/*This funtion moves Pacman "<" according to keypress.*/
void Pmove(char Amap[18][32], int& Px, int& Py, int& score);/*This funtion moves Pacman "P" according to keypress.*/
bool GameOver(char map[32][28], int Mx, int My, int Sx, int Sy, int xpos, int ypos);/*Checks if coords of ghosts and pacman collide and endsthe game.*/
bool AdvGameOver(char Amap[18][32], int score, int Ex, int Ey, int Px, int Py);/*Checks if coords of ghosts and pacman collide and endsthe game
in advanced level*/
void MapDraw(char map[32][28], int& score);//These finction draw maps/boards.
void AdvMapDraw(char Amap[18][32], int& score);
int main()
{
	int level;
	level = ChooseLevel();
	if (level == 1)
	{
		system("cls");
		int xpos, ypos, Mx, My, Sx, Sy, CD, SD, score = 0;
		char dir, dotmap[32][28], map[32][28] = {
			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
			{ '#','o','o','o','o','o','o','o','o','o','o','o','o','#','#','o','o','o','o','o','o','o','o','o','o','o','o','#' },
			{ '#','o','#','#','#','#','o','#','#','#','#','#','o','#','#','o','#','#','#','#','#','o','#','#','#','#','o','#' },
			{ '#','o','#','#','#','#','o','#','#','#','#','#','o','#','#','o','#','#','#','#','#','o','#','#','#','#','o','#' },
			{ '#','o','#','#','#','#','o','#','#','#','#','#','o','#','#','o','#','#','#','#','#','o','#','#','#','#','o','#' },
			{ '#','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','#' },
			{ '#','o','#','#','#','#','o','#','#','o','#','#','#','#','#','#','#','#','o','#','#','o','#','#','#','#','o','#' },
			{ '#','o','#','#','#','#','o','#','#','o','#','#','#','#','#','#','#','#','o','#','#','o','#','#','#','#','o','#' },
			{ '#','o','o','o','o','o','o','#','#','o','o','o','o','#','#','o','o','o','o','#','#','o','o','o','o','o','o','#' },
			{ '#','#','#','#','#','#','o','#','#','#','#','#',' ','#','#',' ','#','#','#','#','#','o','#','#','#','#','#','#' },
			{ '#','#','#','#','#','#','o','#','#','#','#','#',' ','#','#',' ','#','#','#','#','#','o','#','#','#','#','#','#' },
			{ '#','#','#','#','#','#','o','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','o','#','#','#','#','#','#' },
			{ '#','#','#','#','#','#','o','#','#',' ','#','#','#',' ',' ','#','#','#',' ','#','#','o','#','#','#','#','#','#' },
			{ '#','#','#','#','#','#','o','#','#',' ','#',' ',' ',' ',' ',' ','M','#',' ','#','#','o','#','#','#','#','#','#' },
			{ '#','#','#','#','#','#','o','#','#',' ','#',' ',' ',' ',' ',' ',' ','#',' ','#','#','o','#','#','#','#','#','#' },
			{ '<',' ',' ',' ',' ',' ','o',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','o',' ',' ',' ',' ',' ',' ' },
			{ '#','#','#','#','#','#','o','#','#',' ','#',' ',' ',' ',' ',' ',' ','#',' ','#','#','o','#','#','#','#','#','#' },
			{ '#','#','#','#','#','#','o','#','#',' ','#',' ',' ',' ',' ',' ',' ','#',' ','#','#','o','#','#','#','#','#','#' },
			{ '#','#','#','#','#','#','o','#','#',' ','#','#','#',' ',' ','#','#','#',' ','#','#','o','#','#','#','#','#','#' },
			{ '#','#','#','#','#','#','o','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','o','#','#','#','#','#','#' },
			{ '#','#','#','#','#','#','o','#','#',' ','#','#','#','#','#','#','#','#',' ','#','#','o','#','#','#','#','#','#' },
			{ '#','o','o','o','o','o','o','o','o','o','o','o','o','#','#','o','o','o','o','o','o','o','o','o','o','o','o','#' },
			{ '#','o','#','#','#','#','o','#','#','#','#','#','o','#','#','o','#','#','#','#','#','o','#','#','#','#','o','#' },
			{ '#','o','#','#','#','#','o','#','#','#','#','#','o','#','#','o','#','#','#','#','#','o','#','#','#','#','o','#' },
			{ '#','o','o','o','#','#','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','#','#','o','o','o','#' },
			{ '#','#','#','o','#','#','o','#','#','o','#','#','#','#','#','#','#','#','o','#','#','o','#','#','o','#','#','#' },
			{ '#','#','#','o','#','#','o','#','#','o','#','#','#','#','#','#','#','#','o','#','#','o','#','#','o','#','#','#' },
			{ '#','o','o','o','o','o','o','#','#','o','o','o','o','#','#','o','o','o','o','#','#','o','o','o','o','o','o','#' },
			{ '#','o','#','#','#','#','#','#','#','#','#','#','o','#','#','o','#','#','#','#','#','#','#','#','#','#','o','#' },
			{ '#','o','#','#','#','#','#','#','#','#','#','#','o','#','#','o','#','#','#','#','#','#','#','#','#','#','o','#' },
			{ '#','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','S','#' },
			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' } };
		for (int i = 0; i < 32; i++)//for getting coords of S,M and <.
		{

			for (int j = 0; j < 28; j++)
			{
				if (map[i][j] == '<')
				{//cords of <.
					ypos = i;
					xpos = j;
				}
				if (map[i][j] == 'M')
				{//cords of M.
					Mx = j;
					My = i;
				}
				if (map[i][j] == 'S')
				{//cords of S.
					Sx = j;
					Sy = i;
				}
				cout << map[i][j];
			}
			cout << endl;
		}
		for (int i = 0; i < 32; i++)//fot making dotmap.
		{

			for (int j = 0; j < 28; j++)
			{
				if (map[i][j] == '#')
				{
					dotmap[i][j] = '\0';
				}
				if (map[i][j] == ' ')
				{
					dotmap[i][j] = ' ';
				}
				if (map[i][j] == 'o')
				{
					dotmap[i][j] = 'o';
				}
				if (map[i][j] == '<' || map[i][j] == 'C' || map[i][j] == 'S')
				{
					dotmap[i][j] = ' ';
				}
				cout << map[i][j];
			}
			cout << endl;
		}
		do {
			system("cls");
			MapDraw(map, score);
			CD = ChaserDIRcheck(map, My, Mx, xpos, ypos);
			SD = StupidDIRcheck();
			PACmove(map, dotmap, ypos, xpos, score);
			Stupidmove(SD, dotmap, map, Sx, Sy);
			ChaserMove(CD, dotmap, map, Mx, My);
			MapDraw(map, score);
		} while (!GameOver(map, Mx, My, Sx, Sy, xpos, ypos));
	}
	if (level == 2)
	{
		system("cls");
		int Ex, Ey, Px, Py, score = 0, ED;
		char Amap[18][32] = {
			"+#############################+",
			"|E                            |",
			"|                             |",
			"|## ########### ##   #########|",
			"|   |                         |",
			"| | |### |  |           |     |",
			"| |      |  | |###  |   |  |  |",
			"| | #####|  | |      ## |     |",
			"| |           |###  |      |  |",
			"| |##### ###         ##       |",
			"|          ######  ####### ###|",
			"|                             |",
			"|# ### ####      ###   #######|",
			"|                             |",
			"|                             |",
			"|                             |",
			"|                 P           |",
			"+#############################+"
		};
		for (int i = 0; i < 32; i++)//for getting coords of P and E.
		{

			for (int j = 0; j < 28; j++)
			{
				if (Amap[i][j] == 'E')
				{//cords of E
					Ey = i;
					Ex = j;
				}
				if (Amap[i][j] == 'P')
				{//cords of P
					Px = j;
					Py = i;
				}
				cout << Amap[i][j];
			}
			cout << endl;
		}
		do {
			system("cls");
			AdvMapDraw(Amap, score);
			Pmove(Amap, Px, Py, score);
			ED = EDIRcheck(Amap, Ey, Ex, Px, Py);
			EMove(ED, Amap, Ex, Ey);
		} while (!AdvGameOver(Amap, score, Ex, Ey, Px, Py));
	}
}
int ChaserDIRcheck(char map[32][28], int& My, int& Mx, int xpos, int ypos)
{//It checks if there is any tile next to "M" i.e # and then applies Pythagoras theorum to find shortest path to pacman from next tile.
	int up, down, left, right, UR, UL, DR, DL, paths[8];
	if (map[My - 1][Mx + 1] == ' ' || map[My - 1][Mx + 1] == 'o' || map[My - 1][Mx + 1] == '<' || map[My - 1][Mx + 1] == '^' || map[My - 1][Mx + 1] == 'v' || map[My - 1][Mx + 1] == '>')
	{
		UR = sqrt(pow((Mx + 1) - xpos, 2) + pow((My - 1) - ypos, 2));//pythagoras theorum on Up-Right tile.
		paths[0] = UR;
	}
	else
	{
		paths[0] = 9999;
	}
	if (map[My - 1][Mx - 1] == ' ' || map[My - 1][Mx - 1] == 'o' || map[My - 1][Mx - 1] == '<' || map[My - 1][Mx - 1] == '^' || map[My - 1][Mx - 1] == 'v' || map[My - 1][Mx - 1] == '>')
	{
		UL = sqrt(pow((Mx - 1) - xpos, 2) + pow((My - 1) - ypos, 2));//pythagoras theorum on Up-Left tile.
		paths[1] = UL;
	}
	else
	{
		paths[1] = 9999;
	}
	if (map[My + 1][Mx + 1] == ' ' || map[My + 1][Mx + 1] == 'o' || map[My + 1][Mx + 1] == '<' || map[My + 1][Mx + 1] == '^' || map[My + 1][Mx + 1] == 'v' || map[My + 1][Mx + 1] == '>')
	{
		DR = sqrt(pow((Mx + 1) - xpos, 2) + pow((My + 1) - ypos, 2));//pythagoras theorum on Down-right tile.
		paths[2] = DR;
	}
	else
	{
		paths[2] = 9999;
	}
	if (map[My + 1][Mx - 1] == ' ' || map[My + 1][Mx - 1] == 'o' || map[My + 1][Mx - 1] == '<' || map[My + 1][Mx - 1] == '^' || map[My + 1][Mx - 1] == 'v' || map[My + 1][Mx - 1] == '>')
	{
		DL = sqrt(pow((Mx - 1) - xpos, 2) + pow((My + 1) - ypos, 2));//pythagoras theorum on Down-Left tile.
		paths[3] = DL;
	}
	else
	{
		paths[3] = 9999;
	}
	if (map[My - 1][Mx] == ' ' || map[My - 1][Mx] == 'o' || map[My - 1][Mx] == '<' || map[My - 1][Mx] == '^' || map[My - 1][Mx] == 'v' || map[My - 1][Mx] == '>')
	{
		up = sqrt(pow(Mx - xpos, 2) + pow((My - 1) - ypos, 2));//pythagoras theorum on Upper tile.
		paths[4] = up;
	}
	else
	{
		paths[4] = 9999;
	}
	if (map[My + 1][Mx] == ' ' || map[My + 1][Mx] == 'o' || map[My + 1][Mx] == '<' || map[My + 1][Mx] == '^' || map[My + 1][Mx] == 'v' || map[My + 1][Mx] == '>')
	{
		down = sqrt(pow(Mx - xpos, 2) + pow((My + 1) - ypos, 2));//pythagoras theorum on Down tile.
		paths[5] = down;
	}
	else
	{
		paths[5] = 9999;
	}
	if (map[My][Mx - 1] == ' ' || map[My][Mx - 1] == 'o' || map[My][Mx] == '<' || map[My][Mx] == '^' || map[My][Mx] == 'v' || map[My][Mx] == '>')
	{
		left = sqrt(pow((Mx - 1) - xpos, 2) + pow(My - ypos, 2));//pythagoras theorum on Left tile.
		paths[6] = left;
	}
	else
	{
		paths[6] = 9999;
	}
	if (map[My][Mx + 1] != '#')
	{
		right = sqrt(pow((Mx + 1) - xpos, 2) + pow(My - ypos, 2));//pythagoras theorum on Right tile.
		paths[7] = right;
	}
	else
	{
		paths[7] = 9999;
	}
	int temp = 0;
	for (int i = 6; i >= 0; i--)//find the least of all pythagoras theorm by storing them in an int array. 
	{
		for (int j = 0; j <= i; j++)
		{
			if (paths[j] > paths[j + 1])
			{
				temp = paths[j + 1];
				paths[j + 1] = paths[j];
				paths[j] = temp;
			}
		}
	}
	if (paths[0] == UR)
	{
		return 1;
	}
	if (paths[0] == up)
	{
		return 2;
	}
	if (paths[0] == UL)
	{
		return 3;
	}
	if (paths[0] == right)
	{
		return 4;
	}
	if (paths[0] == left)
	{
		return 5;
	}
	if (paths[0] == DR)
	{
		return 6;
	}
	if (paths[0] == down)
	{
		return 7;
	}
	if (paths[0] == DL)
	{
		return 8;
	}
}
int StupidDIRcheck()
{
	return rand() % 9;//gives random Direction to S.
}
void Stupidmove(int Sdir, char dotmap[32][28], char map[32][28], int& Sx, int& Sy)
{//moves in given Random Direction.by checking if there in no thile # in its path
	char tmpS;
	if (map[Sy - 1][Sx + 1] != '#')
	{
		if (Sdir == 1)
		{
			tmpS = dotmap[Sy][Sx];
			map[Sy][Sx] = tmpS;
			Sy--; Sx++;
			map[Sy][Sx] = 'S';
		}
	}
	if (map[Sy - 1][Sx] != '#')
	{
		if (Sdir == 2)
		{
			tmpS = dotmap[Sy][Sx];
			map[Sy][Sx] = tmpS;
			Sy--;
			map[Sy][Sx] = 'S';
		}
	}
	if (map[Sy - 1][Sx - 1] != '#')
	{
		if (Sdir == 3)
		{
			tmpS = dotmap[Sy][Sx];
			map[Sy][Sx] = tmpS;
			Sy--; Sx--;
			map[Sy][Sx] = 'S';
		}
	}
	if (map[Sy][Sx + 1] != '#')
	{
		if (Sdir == 4)
		{
			tmpS = dotmap[Sy][Sx];
			map[Sy][Sx] = tmpS;
			Sx++;
			map[Sy][Sx] = 'S';
		}
	}
	if (map[Sy][Sx - 1] != '#')
	{
		if (Sdir == 5)
		{
			tmpS = dotmap[Sy][Sx];
			map[Sy][Sx] = tmpS;
			Sx--;
			map[Sy][Sx] = 'S';
		}
	}
	if (map[Sy + 1][Sx + 1] != '#')
	{
		if (Sdir == 6)
		{
			tmpS = dotmap[Sy][Sx];
			map[Sy][Sx] = tmpS;
			Sy++; Sx++;
			map[Sy][Sx] = 'S';
		}
	}
	if (map[Sy + 1][Sx] != '#')
	{
		if (Sdir == 7)
		{
			tmpS = dotmap[Sy][Sx];
			map[Sy][Sx] = tmpS;
			Sy++;
			map[Sy][Sx] = 'S';
		}
	}
	if (map[Sy + 1][Sx - 1] != '#')
	{
		if (Sdir == 8)
		{
			tmpS = dotmap[Sy][Sx];
			map[Sy][Sx] = tmpS;
			Sy++; Sx--;
			map[Sy][Sx] = 'S';
		}
	}
}
void ChaserMove(int Mdir, char dotmap[32][28], char map[32][28], int& Mx, int& My)
{//Moves Chaser Min shortest distance to pacman.
	char tmp1;
	if (Mdir == 1)
	{
		tmp1 = dotmap[My][Mx];
		map[My][Mx] = tmp1;
		My--; Mx++;
		if (map[My][Mx] == '<' || map[My][Mx] == '^' || map[My][Mx] == 'v' || map[My][Mx] == '>')
		{
			map[My][Mx] = 'X';
		}
		else
		{
			map[My][Mx] = 'M';
		}
	}
	if (Mdir == 2)
	{
		tmp1 = dotmap[My][Mx];
		map[My][Mx] = tmp1;
		My--;
		if (map[My][Mx] == '<' || map[My][Mx] == '^' || map[My][Mx] == 'v' || map[My][Mx] == '>')
		{
			map[My][Mx] = 'X';
		}
		else
		{
			map[My][Mx] = 'M';
		}
	}
	if (Mdir == 3)
	{
		tmp1 = dotmap[My][Mx];
		map[My][Mx] = tmp1;
		My--; Mx--;
		if (map[My][Mx] == '<' || map[My][Mx] == '^' || map[My][Mx] == 'v' || map[My][Mx] == '>')
		{
			map[My][Mx] = 'X';
		}
		else
		{
			map[My][Mx] = 'M';
		}
	}
	if (Mdir == 4)
	{
		tmp1 = dotmap[My][Mx];
		map[My][Mx] = tmp1;
		Mx++;
		if (map[My][Mx] == '<' || map[My][Mx] == '^' || map[My][Mx] == 'v' || map[My][Mx] == '>')
		{
			map[My][Mx] = 'X';
		}
		else
		{
			map[My][Mx] = 'M';
		}
	}
	if (Mdir == 5)
	{
		tmp1 = dotmap[My][Mx];
		map[My][Mx] = tmp1;
		Mx--;
		if (map[My][Mx] == '<' || map[My][Mx] == '^' || map[My][Mx] == 'v' || map[My][Mx] == '>')
		{
			map[My][Mx] = 'X';
		}
		else
		{
			map[My][Mx] = 'M';
		}
	}
	if (Mdir == 6)
	{
		tmp1 = dotmap[My][Mx];
		map[My][Mx] = tmp1;
		My++; Mx++;
		if (map[My][Mx] == '<' || map[My][Mx] == '^' || map[My][Mx] == 'v' || map[My][Mx] == '>')
		{
			map[My][Mx] = 'X';
		}
		else
		{
			map[My][Mx] = 'M';
		}
	}
	if (Mdir == 7)
	{
		tmp1 = dotmap[My][Mx];
		map[My][Mx] = tmp1;
		My++;
		if (map[My][Mx] == '<' || map[My][Mx] == '^' || map[My][Mx] == 'v' || map[My][Mx] == '>')
		{
			map[My][Mx] = 'X';
		}
		else
		{
			map[My][Mx] = 'M';
		}
	}
	if (Mdir == 8)
	{
		tmp1 = dotmap[My][Mx];
		map[My][Mx] = tmp1;
		My++; Mx--;
		if (map[My][Mx] == '<' || map[My][Mx] == '^' || map[My][Mx] == 'v' || map[My][Mx] == '>')
		{
			map[My][Mx] = 'X';
		}
		else
		{
			map[My][Mx] = 'M';
		}
	}
}
void PACmove(char map[32][28], char dotmap[32][28], int& ypos, int& xpos, int& score)
{//gets input to move pacman <.
	char dir;
	dir = _getch();
	switch (dir)
	{
	case'a':
		if (map[ypos][xpos - 1] == 'o')
		{
			map[ypos][xpos] = ' '; dotmap[ypos][xpos] = ' ';
			xpos--;
			map[ypos][xpos] = '>';
			score++;
		}
		if (map[ypos][xpos - 1] == ' ')
		{
			map[ypos][xpos] = ' '; dotmap[ypos][xpos] = ' ';
			xpos--;
			map[ypos][xpos] = '>';
		}
		if (map[ypos][xpos - 1] == 'M' || map[ypos][xpos - 1] == 'S')
		{
			map[ypos][xpos] = ' '; dotmap[ypos][xpos] = ' ';
			xpos--;
			map[ypos][xpos] = 'X';
		}
		break;
	case's':
		if (map[ypos + 1][xpos] == 'o')
		{
			map[ypos][xpos] = ' '; dotmap[ypos][xpos] = ' ';
			ypos++;
			map[ypos][xpos] = '^';
			score++;
		}
		if (map[ypos + 1][xpos] == ' ')
		{
			map[ypos][xpos] = ' '; dotmap[ypos][xpos] = ' ';
			ypos++;
			map[ypos][xpos] = '^';
		}
		if (map[ypos + 1][xpos] == 'M' || map[ypos + 1][xpos] == 'S')
		{
			map[ypos][xpos] = ' '; dotmap[ypos][xpos] = ' ';
			ypos++;
			map[ypos][xpos] = 'X';
		}
		break;
	case'd':
		if (map[ypos][xpos + 1] == 'o')
		{
			map[ypos][xpos] = ' '; dotmap[ypos][xpos] = ' ';
			xpos++;
			map[ypos][xpos] = '<';
			score++;
		}
		if (map[ypos][xpos + 1] == ' ')
		{
			map[ypos][xpos] = ' '; dotmap[ypos][xpos] = ' ';
			xpos++;
			map[ypos][xpos] = '<';
		}
		else if (map[ypos][xpos + 1] == 'M' || map[ypos][xpos + 1] == 'S')
		{
			map[ypos][xpos] = ' '; dotmap[ypos][xpos] = ' ';
			xpos++;
			map[ypos][xpos] = 'X';
		}
		break;
	case'w':
		if (map[ypos - 1][xpos] == 'o')
		{
			map[ypos][xpos] = ' '; dotmap[ypos][xpos] = ' ';
			ypos--;
			map[ypos][xpos] = 'v';
			score++;
		}
		if (map[ypos - 1][xpos] == ' ')
		{
			map[ypos][xpos] = ' '; dotmap[ypos][xpos] = ' ';
			ypos--;
			map[ypos][xpos] = 'v';
		}
		if (map[ypos - 1][xpos] == 'M' || map[ypos - 1][xpos] == 'S')
		{
			map[ypos][xpos] = ' '; dotmap[ypos][xpos] = ' ';
			ypos--;
			map[ypos][xpos] = 'X';
		}
		break;
	default:
		break;
	}
}
bool GameOver(char map[32][28], int Mx, int My, int Sx, int Sy, int xpos, int ypos)
{//Checks if ghosts and pacman have same coorrds and if so returns True.
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 28; j++)
		{
			if (map[i][j] == 'o')
			{
				count++;
			}
		}
	}
	if (count == 0)
	{
		return true;
	}
	else if (Mx == xpos && My == ypos)
	{
		map[My][Mx] = 'X';
		return true;
		system("pause");
	}
	else if (Sx == xpos && Sy == ypos)
	{
		map[Sy][Sx] = 'X';
		return true;
		system("pause");
	}
	else
	{
		return false;
	}
}
void MapDraw(char map[32][28], int& score)
{
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 28; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;
	cout << "SCORE :" << score << endl;
}
int ChooseLevel()
{//Asks the user to choose betweentwo levels.
	int n, c = 0;
	cout << "Given Choices: \n" << "1. Classic \n" << "2. Advanced \n";
	while (c < 1)
	{
		cin >> n;
		if (n == 1 || n == 2)
		{
			c++;
		}
		else
		{
			cout << "Wrong input,Enter only 1 or 2 !" << endl;
		}
	}
	return n;
}
int EDIRcheck(char Amap[18][32], int& Ey, int& Ex, int Px, int Py)
{//applies pythagoras theorum tofind minimum path.
	int up, down, left, right, UR, UL, DR, DL, paths[8];
	if (Amap[Ey - 1][Ex + 1] == ' ' || Amap[Ey - 1][Ex + 1] == 'o' || Amap[Ey - 1][Ex + 1] == 'P')
	{
		UR = sqrt(pow((Ex + 1) - Px, 2) + pow((Ey - 1) - Py, 2));//Up right
		paths[0] = UR;
	}
	else
	{
		paths[0] = 9999;
	}
	if (Amap[Ey - 1][Ex - 1] == ' ' || Amap[Ey - 1][Ex - 1] == 'o' || Amap[Ey - 1][Ex - 1] == 'P')
	{
		UL = sqrt(pow((Ex - 1) - Px, 2) + pow((Ey - 1) - Py, 2));//up left
		paths[1] = UL;
	}
	else
	{
		paths[1] = 9999;
	}
	if (Amap[Ey + 1][Ex + 1] == ' ' || Amap[Ey + 1][Ex + 1] == 'o' || Amap[Ey + 1][Ex + 1] == 'P')
	{
		DR = sqrt(pow((Ex + 1) - Px, 2) + pow((Ey + 1) - Py, 2));//down right
		paths[2] = DR;
	}
	else
	{
		paths[2] = 9999;
	}
	if (Amap[Ey + 1][Ex - 1] == ' ' || Amap[Ey + 1][Ex - 1] == 'o' || Amap[Ey + 1][Ex - 1] == 'P')
	{
		DL = sqrt(pow((Ex - 1) - Px, 2) + pow((Ey + 1) - Py, 2));//down left
		paths[3] = DL;
	}
	else
	{
		paths[3] = 9999;
	}
	if (Amap[Ey - 1][Ex] == ' ' || Amap[Ey - 1][Ex] == 'o' || Amap[Ey - 1][Ex] == 'P')
	{
		up = sqrt(pow(Ex - Px, 2) + pow((Ey - 1) - Py, 2));//up
		paths[4] = up;
	}
	else
	{
		paths[4] = 9999;
	}
	if (Amap[Ey + 1][Ex] == ' ' || Amap[Ey + 1][Ex] == 'o' || Amap[Ey + 1][Ex] == 'P')
	{
		down = sqrt(pow(Ex - Px, 2) + pow((Ey + 1) - Py, 2));//down
		paths[5] = down;
	}
	else
	{
		paths[5] = 9999;
	}
	if (Amap[Ey][Ex - 1] == ' ' || Amap[Ey][Ex - 1] == 'o' || Amap[Ey][Ex - 1] == 'P')
	{
		left = sqrt(pow((Ex - 1) - Px, 2) + pow(Ey - Py, 2));//left
		paths[6] = left;
	}
	else
	{
		paths[6] = 9999;
	}
	if (Amap[Ey][Ex + 1] != ' ' || Amap[Ey][Ex + 1] != 'o' || Amap[Ey][Ex + 1] != 'P')
	{
		right = sqrt(pow((Ex + 1) - Px, 2) + pow(Ey - Py, 2));//right
		paths[7] = right;
	}
	else
	{
		paths[7] = 9999;
	}
	int temp = 0;
	for (int i = 6; i >= 0; i--)//to find sortest of all paths by storing each in an array and arranging its values.
	{
		for (int j = 0; j <= i; j++)
		{
			if (paths[j] > paths[j + 1])
			{
				temp = paths[j + 1];
				paths[j + 1] = paths[j];
				paths[j] = temp;
			}
		}
	}
	if (paths[0] == UR)
	{
		return 1;
	}
	if (paths[0] == up)
	{
		return 2;
	}
	if (paths[0] == UL)
	{
		return 3;
	}
	if (paths[0] == right)
	{
		return 4;
	}
	if (paths[0] == left)
	{
		return 5;
	}
	if (paths[0] == DR)
	{
		return 6;
	}
	if (paths[0] == down)
	{
		return 7;
	}
	if (paths[0] == DL)
	{
		return 8;
	}
}
void EMove(int Edir, char Amap[18][32], int& Ex, int& Ey)
{//Moves E in shortest path found by pythagoras theorum.
	if (Edir == 1)
	{
		Amap[Ey][Ex] = 'o';
		Ey--; Ex++;
		if (Amap[Ey][Ex] == 'P')
		{
			Amap[Ey][Ex] = 'X';
		}
		else
		{
			Amap[Ey][Ex] = 'E';
		}
	}
	if (Edir == 2)
	{
		Amap[Ey][Ex] = 'o';
		Ey--;
		if (Amap[Ey][Ex] == 'P')
		{
			Amap[Ey][Ex] = 'X';
		}
		else
		{
			Amap[Ey][Ex] = 'E';
		}
	}
	if (Edir == 3)
	{
		Amap[Ey][Ex] = 'o';
		Ey--; Ex--;
		if (Amap[Ey][Ex] == 'P')
		{
			Amap[Ey][Ex] = 'X';
		}
		else
		{
			Amap[Ey][Ex] = 'E';
		}
	}
	if (Edir == 4)
	{
		Amap[Ey][Ex] = 'o';
		Ex++;
		if (Amap[Ey][Ex] == 'P')
		{
			Amap[Ey][Ex] = 'X';
		}
		else
		{
			Amap[Ey][Ex] = 'E';
		}
	}
	if (Edir == 5)
	{
		Amap[Ey][Ex] = 'o';
		Ex--;
		if (Amap[Ey][Ex] == 'P')
		{
			Amap[Ey][Ex] = 'X';
		}
		else
		{
			Amap[Ey][Ex] = 'E';
		}
	}
	if (Edir == 6)
	{
		Amap[Ey][Ex] = 'o';
		Ey++; Ex++;
		if (Amap[Ey][Ex] == 'P')
		{
			Amap[Ey][Ex] = 'X';
		}
		else
		{
			Amap[Ey][Ex] = 'E';
		}
	}
	if (Edir == 7)
	{
		Amap[Ey][Ex] = 'o';
		Ey++;
		if (Amap[Ey][Ex] == 'P')
		{
			Amap[Ey][Ex] = 'X';
		}
		else
		{
			Amap[Ey][Ex] = 'E';
		}
	}
	if (Edir == 8)
	{
		Amap[Ey][Ex] = 'o';
		Ey++; Ex--;
		if (Amap[Ey][Ex] == 'P')
		{
			Amap[Ey][Ex] = 'X';
		}
		else
		{
			Amap[Ey][Ex] = 'E';
		}
	}
}
void Pmove(char Amap[18][32], int& Px, int& Py, int& score)
{//moves P by getting keypress from user.
	char dir;
	dir = _getch();
	switch (dir)
	{
	case'a':
		if (Amap[Py][Px - 1] == 'o')
		{
			Amap[Py][Px] = ' ';
			Px--;
			Amap[Py][Px] = 'P';
			score++;
		}
		if (Amap[Py][Px - 1] == ' ')
		{
			Amap[Py][Px] = ' ';
			Px--;
			Amap[Py][Px] = 'P';
		}
		if (Amap[Py][Px - 1] == 'E')
		{
			Amap[Py][Px] = ' ';
			Px--;
			Amap[Py][Px] = 'X';
		}
		break;
	case's':
		if (Amap[Py + 1][Px] == 'o')
		{
			Amap[Py][Px] = ' ';
			Py++;
			Amap[Py][Px] = 'P';
			score++;
		}
		if (Amap[Py + 1][Px] == ' ')
		{
			Amap[Py][Px] = ' ';
			Py++;
			Amap[Py][Px] = 'P';
		}
		if (Amap[Py + 1][Px] == 'E')
		{
			Amap[Py][Px] = ' ';
			Py++;
			Amap[Py][Px] = 'X';
		}
		break;
	case'd':
		if (Amap[Py][Px + 1] == 'o')
		{
			Amap[Py][Px] = ' ';
			Px++;
			Amap[Py][Px] = 'P';
			score++;
		}
		if (Amap[Py][Px + 1] == ' ')
		{
			Amap[Py][Px] = ' ';
			Px++;
			Amap[Py][Px] = 'P';
		}
		else if (Amap[Py][Px + 1] == 'E')
		{
			Amap[Py][Px] = ' ';
			Px++;
			Amap[Py][Px] = 'X';
		}
		break;
	case'w':
		if (Amap[Py - 1][Px] == 'o')
		{
			Amap[Py][Px] = ' ';
			Py--;
			Amap[Py][Px] = 'P';
			score++;
		}
		if (Amap[Py - 1][Px] == ' ')
		{
			Amap[Py][Px] = ' ';
			Py--;
			Amap[Py][Px] = 'P';
		}
		if (Amap[Py - 1][Px] == 'E')
		{
			Amap[Py][Px] = ' ';
			Py--;
			Amap[Py][Px] = 'X';
		}
		break;
	default:
		break;
	}
}
bool AdvGameOver(char Amap[18][32], int score, int Ex, int Ey, int Px, int Py)
{//CHecks if coords of pacman P and eater E are same ornot and returns True oor False.
	if (Amap[Ey][Ex] == 'X')
	{
		return true;
	}
	if (Ex == Px && Ey == Py)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void AdvMapDraw(char Amap[18][32], int& score)
{//Simply Prints Advanced Map.
	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			cout << Amap[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;
	cout << "SCORE:" << score << endl;
}
void INTRO()
{
	cout << "Coded by : Awais Ahmad" << endl;
	cout << "ROLL.NO:16L-4172" << endl;
	cout << endl << endl << endl;

}