#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

using namespace sf;
using namespace std;

const int r = 10;
const int c = 10;
void smashrow(int a[r][c], int i, int j)
{

	for (int x = i; x >= 0; x--)
	{
		if (x > 0)
		{
			a[x][j] = a[x - 1][j];
		}
		else
			a[x][j] = rand() % 6 + 1;
	}
}
void smashcolumn(int a[r][c], int i, int j)
{
	for (int x = j; x >= 0; x--)
	{
		if (x > 0)
		{
			a[i][x] = a[i][x - 1];
		}
		else
			a[i][x] = rand() % 6 + 1;
	}
}

void strippedcandy()
{
	int a[r][c];
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] == a[i][j + 1] && a[i][j + 1] == a[i][j + 2] && a[i][j] == a[i][j + 3])
			{
				if (a[i][j] == 1)
				{
					smashrow(a, i, j);
					smashrow(a, i, j + 1);
					smashrow(a, i, j + 2);
					smashrow(a, i, j + 3);
					a[i][j + 3] = 7;
				}
				else if (a[i][j] == 2)
				{
					smashrow(a, i, j);
					smashrow(a, i, j + 1);
					smashrow(a, i, j + 2);
					smashrow(a, i, j + 3);
					a[i][j + 3] = 8;
				}
				else if (a[i][j] == 3)
				{
					smashrow(a, i, j);
					smashrow(a, i, j + 1);
					smashrow(a, i, j + 2);
					smashrow(a, i, j + 3);
					a[i][j + 3] = 9;
				}
				else if (a[i][j] == 4)
				{
					smashrow(a, i, j);
					smashrow(a, i, j + 1);
					smashrow(a, i, j + 2);
					smashrow(a, i, j + 3);
					a[i][j + 3] = 10;
				}
				else if (a[i][j] == 5)
				{
					smashrow(a, i, j);
					smashrow(a, i, j + 1);
					smashrow(a, i, j + 2);
					smashrow(a, i, j + 3);
					a[i][j + 3] = 11;
				}
				for (int x = j + 2, c = 3; x >= 0; x--)
				{
					if (x > c)
					{
						a[i][j] = a[i][j - c];
					}
					else
					{
						a[i][j] = rand() % 6 + 1;
					}

				}
			}
		}
		for (int i = 0; i < c; i++)
		{
			for (int j = 0; j < r - 3; j++)
			{
				if (a[i][j] == a[i + 1][j] && a[i][j] == a[i + 2][j] && a[i][j] == a[i + 3][j])
				{
					if (a[i + 3][j] == 1)
					{
						smashcolumn(a, i, j);
						smashcolumn(a, i + 1, j);
						smashcolumn(a, i + 2, j);
						smashcolumn(a, i + 3, j);
						a[i + 3][j] = 7;
					}
					else if (a[i + 3][j] == 2)
					{
						smashcolumn(a, i, j);
						smashcolumn(a, i + 1, j);
						smashcolumn(a, i + 2, j);
						smashcolumn(a, i + 3, j);
						a[i + 3][j] = 8;
					}
					else if (a[i + 3][j] == 3)
					{
						smashcolumn(a, i, j);
						smashcolumn(a, i + 1, j);
						smashcolumn(a, i + 2, j);
						smashcolumn(a, i + 3, j);
						a[i + 3][j] = 9;
					}
					else if (a[i + 3][j] == 4)
					{
						smashcolumn(a, i, j);
						smashcolumn(a, i + 1, j);
						smashcolumn(a, i + 2, j);
						smashcolumn(a, i + 3, j);
						a[i + 3][j] = 10;
					}
					else if (a[i + 3][j] == 5)
					{
						smashcolumn(a, i, j);
						smashcolumn(a, i + 1, j);
						smashcolumn(a, i + 2, j);
						smashcolumn(a, i + 3, j);
						a[i + 3][j] = 11;
					}
					for (int x = i + 2, c = 3; x >= 0; x--)
					{
						if (x > c)
						{
							a[i][j] = a[i - c][j];
						}
						else
						{
							a[i][j] = rand() % 6 + 1;
						}

					}
				}
			}
		}
	}


}
int wrappedbean_insert(int num)
{
	if (num == 1)
		return 12;
	if (num == 2)
		return 13;
	if (num == 3)
		return 14;
	if (num == 4)
		return 15;
	if (num == 5)
		return 16;
	return 0;

}
void wrappedcandy(int a[r][c], int i, int j)
{
	int num = 0;
	//for upside down and inverted L
	if (a[i][j] == a[i][j + 1] && a[i][j] == a[i][j + 2] && a[i][j] == a[i + 1][j + 2] && a[i][j] == a[i + 2][j + 2])
	{
		num = a[i][j];
		a[i][j] = wrappedbean_insert(num);
	}
	//for upside down L
	else if (a[i][j] == a[i][j + 1] && a[i][j] == a[i][j + 2] && a[i][j] == a[i + 1][j] && a[i][j] == a[i + 2][j])
	{
		num = a[i][j];
		a[i][j] = wrappedbean_insert(num);
	}
	//for a T
	else if (a[i][j] == a[i][j + 1] && a[i][j] == a[i][j + 2] && a[i][j] == a[i + 1][j + 1] && a[i][j] == a[i + 2][j + 1])
	{
		num = a[i][j];
		a[i][j] = wrappedbean_insert(num);
	}
	//for upside down T
	else if (a[i][j + 1] == a[i + 1][j + 1] && a[i][j + 1] == a[i + 2][j] && a[i][j + 1] == a[i + 2][j + 1] && a[i][j + 1] == a[i + 2][j + 2])
	{
		num = a[i][j];
		a[i][j] = wrappedbean_insert(num);
	}
	//for upright L
	else if ((a[i][j] == a[i][j + 1] == a[i][j + 2] == a[i + 1][j + 2] == a[i + 2][j + 2]))
	{
		num = a[i][j];
		a[i][j] = wrappedbean_insert(num);
	}
	//for upright inverted L
	else if (a[i + 2][j] == a[i + 2][j + 1] && a[i + 2][j] == a[i + 2][j + 2] && a[i + 2][j] == a[i + 1][j + 2] && a[i + 2][j] == a[i][j + 2])
	{
		num = a[i][j];
		a[i][j] = wrappedbean_insert(num);
	}
}

//x=row, y=column
//After the statement y1==y2 becomes true. Call this function
void verticalswap(int a[r][c], int y, int x1, int x2)
{
	int temp;
	temp = a[x1][y];
	a[x1][y] = a[x2][y];
	a[x2][y] = temp;
}
//x=row, y=column
//After the statement x1==x2 becomes true. Call this function
void horizontalswap(int a[r][c], int x, int y1, int y2)
{
	int temp;
	temp = a[x][y1];
	a[x][y1] = a[x][y2];
	a[x][y2] = temp;
}
void colourbomb()
{
	int a[r][c];
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] == a[i][j + 1] && a[i][j + 1] == a[i][j + 2] && a[i][j + 2] == a[i][j + 3] && a[i][j + 3] == a[i][j + 4])
			{
				if (a[i][j] == 1)
				{
					smashrow(a, i, j);
					smashrow(a, i, j + 1);
					smashrow(a, i, j + 2);
					smashrow(a, i, j + 3);
					smashrow(a, i, j + 4);
					a[i][j + 4] = 6;
				}
				else if (a[i][j] == 2)
				{
					smashrow(a, i, j);
					smashrow(a, i, j + 1);
					smashrow(a, i, j + 2);
					smashrow(a, i, j + 3);
					smashrow(a, i, j + 4);
					a[i][j + 4] = 6;
				}
				else if (a[i][j] == 3)
				{
					smashrow(a, i, j);
					smashrow(a, i, j + 1);
					smashrow(a, i, j + 2);
					smashrow(a, i, j + 3);
					smashrow(a, i, j + 4);
					a[i][j + 4] = 6;
				}
				else if (a[i][j] == 4)
				{
					smashrow(a, i, j);
					smashrow(a, i, j + 1);
					smashrow(a, i, j + 2);
					smashrow(a, i, j + 3);
					smashrow(a, i, j + 4);
					a[i][j + 4] = 6;
				}
				else if (a[i][j] == 5)
				{
					smashrow(a, i, j);
					smashrow(a, i, j + 1);
					smashrow(a, i, j + 2);
					smashrow(a, i, j + 3);
					smashrow(a, i, j + 4);
					a[i][j + 4] = 6;
				}
				for (int x = j + 2, c = 3; x >= 0; x--)
				{
					if (x > c)
					{
						a[i][j] = a[i][j - c];
					}
					else
					{
						a[i][j] = rand() % 6 + 1;
					}

				}
			}
		}
		for (int i = 0; i < c; i++)
		{
			for (int j = 0; j < r - 3; j++)
			{
				if (a[i][j] == a[i + 1][j] && a[i][j] == a[i + 2][j] && a[i][j] == a[i + 3][j] && a[i][j] == a[i][j + 3])
				{
					if (a[i + 4][j] == 1)
					{
						smashcolumn(a, i, j);
						smashcolumn(a, i + 1, j);
						smashcolumn(a, i + 2, j);
						smashcolumn(a, i + 3, j);
						smashcolumn(a, i + 4, j);
						a[i + 4][j] = 6;
					}
					else if (a[i + 4][j] == 2)
					{
						smashcolumn(a, i, j);
						smashcolumn(a, i + 1, j);
						smashcolumn(a, i + 2, j);
						smashcolumn(a, i + 3, j);
						smashcolumn(a, i + 4, j);
						a[i + 4][j] = 6;
					}
					else if (a[i + 4][j] == 3)
					{
						smashcolumn(a, i, j);
						smashcolumn(a, i + 1, j);
						smashcolumn(a, i + 2, j);
						smashcolumn(a, i + 3, j);
						smashcolumn(a, i + 4, j);
						a[i + 4][j] = 6;
					}
					else if (a[i + 4][j] == 4)
					{
						smashcolumn(a, i, j);
						smashcolumn(a, i + 1, j);
						smashcolumn(a, i + 2, j);
						smashcolumn(a, i + 3, j);
						smashcolumn(a, i + 4, j);
						a[i + 4][j] = 6;
					}
					else if (a[i + 4][j] == 5)
					{
						smashcolumn(a, i, j);
						smashcolumn(a, i + 1, j);
						smashcolumn(a, i + 2, j);
						smashcolumn(a, i + 3, j);
						smashcolumn(a, i + 4, j);
						a[i + 4][j] = 6;
					}
					for (int x = i + 2, c = 3; x >= 0; x--)
					{
						if (x > c)
						{
							a[i][j] = a[i - c][j];
						}
						else
						{
							a[i][j] = rand() % 6 + 1;
						}

					}
				}
			}
		}
	}


}


void smashcandy(int a[r][c])
{
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < r; j++)
		{
			if (a[i][j] == a[i + 1][j] && a[i + 1][j] == a[i + 2][j] && a[i][j] == a[i + 2][j])
			{
				smashrow(a, i, j);
				smashrow(a, i + 1, j);
				smashrow(a, i + 2, j);

			}
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] == a[i][j + 1] && a[i][j + 1] == a[i][j + 2] && a[i][j] == a[i][j + 2])
			{
				smashcolumn(a, i, j);
				smashcolumn(a, i, j + 1);
				smashcolumn(a, i, j + 2);

			}
		}

	}
}
void smashwrap(int array[r][c], int a, int b)
{
	if (a < r - 1)
	{
		if (b != 0)
		{
			for (int i = a + 1, k = 3; i >= 0; i--)//moving top to bottom for three deleted(left) candies
			{
				if (i >= k)
					array[i][b - 1] = array[i - k][b - 1];
				else
					array[i][b - 1] = rand() % 6;
			}
		}
		if (b < c - 1)
		{
			for (int i = a + 1, k = 3; i >= 0; i--)//moving top to bottom for three deleted(right) candies
			{

				if (i >= k)
					array[i][b + 1] = array[i - k][b + 1];
				else
					array[i][b + 1] = rand() % 6;
			}
		}
		for (int i = a + 1, k = 3; i >= 0; i--)//moving top to bottom for three deleted candies
		{

			if (i >= k)
				array[i][b] = array[i - k][b];
			else
				array[i][b] = rand() % 6 + 1;
		}
	}
	else
	{
		if (b != 0)
		{
			for (int i = a; i >= 0; i--)//moving top to bottom for three deleted(left) candies
			{
				if (i >= 2)
					array[i][b - 1] = array[i - 2][b - 1];
				else
					array[i][b - 1] = rand() % 6 + 1;
			}
		}
		if (b < c - 1)
		{
			for (int i = a; i >= 0; i--)//moving top to bottom for three deleted(right) candies
			{

				if (i >= 2)
					array[i][b + 1] = array[i - 2][b + 1];
				else
					array[i][b + 1] = rand() % 6;
			}
		}
		for (int i = a; i >= 0; i--)//moving top to bottom for three deleted candies
		{

			if (i >= 2)
				array[i][b] = array[i - 2][b];
			else
				array[i][b] = rand() % 6;
		}
	}
}
void plainandwarppedcandy(int a[r][c], int x, int y)
{

	smashcandy(a);

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)

		{

			if (a[i][j] == 1 && a[i][j + 1] == 1 && a[i][j + 2] == 12) //for red  
			{
				smashwrap(a, i, j + 2);
			}
			else if (a[i][j] == 1 && a[i][j + 1] == 12 && a[i][j + 2] == 1)
			{
				smashwrap(a, i, j + 1);
			}
			else if (a[i][j] == 12 && a[i][j + 1] == 1 && a[i][j + 2] == 1)
			{
				smashwrap(a, i, j);
			}

		}
	}
	if (a[x][y] == 2 && a[x][y + 1] == 2 && a[x][y + 2] == 13)//for yellow
	{
		smashwrap(a, x, y + 2);
	}
	else if (a[x][y] == 2 && a[x][y + 1] == 13 && a[x][y + 2] == 2)
	{
		smashwrap(a, x, y + 1);
	}
	else if (a[x][y] == 13 && a[x][y + 1] == 2 && a[x][y + 2] == 2)
	{
		smashwrap(a, x, y);
	}
	if (a[x][y] == 3 && a[x][y + 1] == 3 && a[x][y + 2] == 14)//for green
	{
		smashwrap(a, x, y + 2);
	}
	else if (a[x][y] == 3 && a[x][y + 1] == 14 && a[x][y + 2] == 3)
	{
		smashwrap(a, x, y + 1);
	}
	else if (a[x][y] == 14 && a[x][y + 1] == 3 && a[x][y + 2] == 3)
	{
		smashwrap(a, x, y);
	}
	if (a[x][y] == 4 && a[x][y + 1] == 4 && a[x][y + 2] == 15)//for blue
	{
		smashwrap(a, x, y + 2);
	}
	else if (a[x][y] == 4 && a[x][y + 1] == 15 && a[x][y + 2] == 4)
	{
		smashwrap(a, x, y + 1);
	}
	else if (a[x][y] == 15 && a[x][y + 1] == 4 && a[x][y + 2] == 4)
	{
		smashwrap(a, x, y);
	}
	if (a[x][y] == 5 && a[x][y + 1] == 5 && a[x][y + 2] == 16)//for orange
	{
		smashwrap(a, x, y + 2);
	}
	else if (a[x][y] == 5 && a[x][y + 1] == 16 && a[x][y + 2] == 5)
	{
		smashwrap(a, x, y + 1);
	}
	else if (a[x][y] == 16 && a[x][y + 1] == 5 && a[x][y + 2] == 5)
	{
		smashwrap(a, x, y);
	}




	for (int y = 0; y < c; y++)
	{
		for (int x = 0; x < r; x++)
		{

			if (a[x][y] == 1 && a[x + 1][y] == 1 && a[x + 2][y] == 12) //for red  
			{
				smashwrap(a, x + 2, y);
			}
			else if (a[x][y] == 1 && a[x + 1][y] == 12 && a[x + 2][y] == 1)
			{
				smashwrap(a, x + 1, y);
			}
			else if (a[x][y] == 12 && a[x + 1][y] == 1 && a[x + 2][y] == 1)
			{
				smashwrap(a, x, y);
			}

		}
	}

	if (a[x][y] == 2 && a[x + 1][y] == 2 && a[x + 2][y] == 13) //for yellow  
	{
		smashwrap(a, x + 2, y);
	}
	else if (a[x][y] == 2 && a[x + 1][y] == 13 && a[x + 2][y] == 2)
	{
		smashwrap(a, x + 1, y);
	}
	else if (a[x][y] == 13 && a[x + 1][y] == 2 && a[x + 2][y] == 2)
	{
		smashwrap(a, x, y);
	}
	if (a[x][y] == 3 && a[x + 1][y] == 3 && a[x + 2][y] == 14) //for green  
	{
		smashwrap(a, x + 2, y);
	}
	else if (a[x][y] == 3 && a[x + 1][y] == 14 && a[x + 2][y] == 3)
	{
		smashwrap(a, x + 1, y);
	}
	else if (a[x][y] == 14 && a[x + 1][y] == 3 && a[x + 2][y] == 3)
	{
		smashwrap(a, x, y);
	}
	if (a[x][y] == 4 && a[x + 1][y] == 4 && a[x + 2][y] == 15) //for blue  
	{
		smashwrap(a, x + 2, y);
	}
	else if (a[x][y] == 4 && a[x + 1][y] == 15 && a[x + 2][y] == 4)
	{
		smashwrap(a, x + 1, y);
	}
	else if (a[x][y] == 15 && a[x + 1][y] == 4 && a[x + 2][y] == 4)
	{
		smashwrap(a, x, y);
	}
	if (a[x][y] == 5 && a[x + 1][y] == 5 && a[x + 2][y] == 16)
	{
		smashwrap(a, x + 2, y);
	}
	else if (a[x][y] == 5 && a[x + 1][y] == 16 && a[x + 2][y] == 5)
	{
		smashwrap(a, x + 1, y);
	}
	else if (a[x][y] == 16 && a[x + 1][y] == 5 && a[x + 2][y] == 5)
	{
		smashwrap(a, x, y);
	}
}
void colourbombandcolourbomb()
{
	int a[9][9];
	for (int i = 0; i < (c - 1); i++)
	{
		for (int j = 0; j < (r - 1); j++)
		{
			if (((a[i][j] == a[i - 1][j]) && (a[i][j] == a[i + 1][j])))
			{
				if (a[i][j] == 6)
				{
					for (int i = 0; i < 9; i++)
					{
						for (int j = 0; j < 9; j++)
							a[i][j] = '\0';
					}
					for (i = 0; i < 9; ++i)
					{
						for (j = 0; j < 9; ++j)
						{
							a[i][j] = (rand() % 16) + 1;
						}
					}
				}
			}
		}
	}

}
void crush(int a[][c], int stripped)
{
	int candy;
	if (stripped == 11)
		candy = 1;
	else if (stripped == 12)
		candy = 2;
	else if (stripped == 13)
		candy = 3;
	else if (stripped == 14)
		candy = 4;
	else if (stripped == 15)
		candy = 5;
	for (int x = 0; x < r; x++)
	{
		for (int y = 0; y < c; y++)
		{
			if (a[x][y] == candy)
				a[x][y] = stripped;
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] == stripped)
			{
				for (int rows = 0; rows < r; rows++)
				{
					a[rows][j] = rand() % 5;
				}

				for (int rows = i; rows >= 1; rows--)
				{
					int columns = 0;
					while (columns < c)
					{
						a[rows][columns] = a[rows - 1][columns];
						columns++;
					}
				}
				for (int k = 0;k < c;k++)
				{
					a[0][k] = rand() % 5;

				}
			}
		}
	}
	return;
}

void strippedandcolourbomb(int a[][c])
{
	int stripped = 0;
	if (stripped == 7 || stripped == 8 || stripped == 9 || stripped == 10 || stripped == 11)
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if ((a[i][j + 1] == 6 && a[i][j] == stripped) || (a[i][j + 1] == stripped && a[i][j] == 6))
				{
					crush(a, stripped);
				}

				else if ((a[i][j] == 6 && a[i + 1][j] == stripped) || (a[i][j] == stripped && a[i + 1][j] == 6))
				{
					crush(a, stripped);
				}

			}
		}
}
void crush(int a[][c], int r1, int c1, int wrap)
{

	for (int i = r1 - 1; i >= 1; i--)
	{
		a[i][c1] = a[i - 1][c1];
		a[i][c1 + 1] = a[i - 1][c1 + 1];
		a[i][c1 + 2] = a[i - 1][c1 + 2];
	}
	a[0][c1] = rand() % 5;
	a[0][c1 + 1] = rand() % 5;
	a[0][c1 + 2] = rand() % 5;

	for (int i = r1; i >= 1; i--)
	{
		a[i][c1] = a[i - 1][c1];
		a[i][c1 + 1] = a[i - 1][c1 + 1];
		a[i][c1 + 2] = a[i - 1][c1 + 2];
	}
	a[0][c1] = rand() % 5;
	a[0][c1 + 1] = rand() % 5;
	a[0][c1 + 2] = rand() % 5;

	for (int i = r1 + 1; i >= 1; i--)
	{
		a[i][c1] = a[i - 1][c1];
		a[i][c1 + 1] = a[i - 1][c1 + 1];
		a[i][c1 + 2] = a[i - 1][c1 + 2];
	}
	a[0][c1] = rand() % 5;
	a[0][c1 + 1] = rand() % 5;
	a[0][c1 + 2] = rand() % 5;


	int candy;
	if (wrap == 12)
		candy = 1;
	else if (wrap == 13)
		candy = 2;
	else if (wrap == 14)
		candy = 3;
	else if (wrap == 15)
		candy = 4;
	else if (wrap == 16)
		candy = 5;


	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] == candy)
			{
				a[i][j] = wrap;
			}
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << a[i][j] << "  ";
		}
		cout << endl;
	}
	return;
}
void wrappedandcolourbomb(int a[][c])
{
	int wrap = 0;
	if (wrap == 12 || wrap == 13 || wrap == 14 || wrap == 15)
	{

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if ((a[i][j] == 6 && a[i][j + 1] == wrap) || (a[i][j] == wrap && a[i][j + 1] == 6))
				{
					crush(a, i + 1, j, wrap);
				}
				else if ((a[i][j] == 6 && a[i][j + 1] == wrap) || (a[i][j] == wrap && a[i][j + 1] == 6))
				{
					crush(a, i + 1, j, wrap);
				}
			}
		}
	}
	return;
}