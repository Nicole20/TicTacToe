#include "stdafx.h"
#include "game.h"

game::game()
{
	srand(time(NULL));

	player = rand() % 2;

	for (int i = 0; i < 9; i++)
	{
		board[0][i] = 0;
		board[1][i] = 2;
	}
}

int game::pick()
{
	for (int i = 0; i < 3; i++)
	{
		if (board[0][3 * i] == 1 || board[0][3 * i + 1] == 1 || board[0][3 * i + 2] == 1)
		{
			if (board[1][3 * i] == board[1][3 * i + 1] && board[1][3 * i] != 2)
			{
				if (board[0][3 * i + 2] == 0)
				{
					return (3 * i + 2);
				}
			}
			if (board[1][3 * i] == board[1][3 * i + 2] && board[1][3 * i] != 2)
			{
				if (board[0][3 * i + 1] == 0)
				{
					return (3 * i + 1);
				}
			}
			if (board[1][3 * i + 1] == board[1][3 * i + 2] && board[1][3 * i + 1] != 2)
			{
				if (board[0][3 * i] == 0)
				{
					return (3 * i);
				}
			}
		}
		
		if (board[0][i] == 1 || board[0][i + 3] == 1 || board[0][i + 6] == 1)
		{
			if (board[1][i] == board[1][i + 3] && board[1][i] != 2)
			{
				if (board[0][i + 6] == 0)
				{
					return (i + 6);
				}
			}
			if (board[1][i] == board[1][i + 6] && board[1][i] != 2)
			{
				if (board[0][i + 3] == 0)
				{
					return (i + 3);
				}
			}
			if (board[1][i + 3] == board[1][i + 6] && board[1][i + 3] != 2)
			{
				if (board[0][i] == 0)
				{
					return (i);
				}
			}
		}
	}

	if (board[0][0] == 1 || board[0][4] == 1 || board[0][8] == 1)
	{
		if (board[1][0] == board[1][4] && board[1][0] != 2)
		{
			if (board[0][8] == 0)
			{
				return 8;
			}
		}
		if (board[1][0] == board[1][8] && board[1][0] != 2)
		{
			if (board[0][4] == 0)
			{
				return 4;
			}
		}
		if (board[1][4] == board[1][8] && board[1][4] != 2)
		{
			if (board[0][0] == 0)
			{
				return 0;
			}
		}
	}
	
	if (board[0][2] == 1 || board[0][4] == 1 || board[0][6] == 1)
	{
		if (board[1][2] == board[1][4] && board[1][2] != 2)
		{
			if (board[0][6] == 0)
			{
				return 6;
			}
		}
		if (board[1][2] == board[1][6] && board[1][2] != 2)
		{
			if (board[0][4] == 0)
			{
				return 4;
			}
		}
		if (board[1][4] == board[1][6] && board[1][4] != 2)
		{
			if (board[0][2] == 0)
			{
				return 2;
			}
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (board[0][i] == 1 && board[1][i] == 1)
		{
			if (i + 1 != 3 && i + 1 != 6)
			{
				if (board[0][i + 1] == 0)
				{
					return i + 1;
				}
			}
			
			if (i - 1 > -1 && i - 1 != 2 && i - 1 != 5)
			{
				if (board[0][i - 1] == 0)
				{
					return i - 1;
				}
			}
			
			if (i + 3 < 9)
			{
				if (board[0][i + 3] == 0)
				{
					return i + 3;
				}
			}
			
			if (i - 3 > -1)
			{
				if (board[0][i - 3] == 0)
				{
					return i - 3;
				}
			}

			if (i == 0)
			{
				if (board[0][4] == 0)
				{
					return 4;
				}

				if (board[0][8] == 0)
				{
					return 8;
				}
			}

			if (i == 2)
			{
				if (board[0][4] == 0)
				{
					return 4;
				}

				if (board[0][6] == 0)
				{
					return 6;
				}
			}

			if (i == 4)
			{
				if (board[0][0] == 0)
				{
					return 0;
				}

				if (board[0][2] == 0)
				{
					return 2;
				}

				if (board[0][6] == 0)
				{
					return 6;
				}

				if (board[0][8] == 0)
				{
					return 8;
				}
			}

			if (i == 6)
			{
				if (board[0][4] == 0)
				{
					return 4;
				}

				if (board[0][2] == 0)
				{
					return 2;
				}
			}

			if (i == 8)
			{
				if (board[0][4] == 0)
				{
					return 4;
				}

				if (board[0][0] == 0)
				{
					return 0;
				}
			}
		}
	}
	
	return rand() % 9;
}

int game::check()
{
	for (int i = 0; i < 3; i++)
	{
		if (board[0][3 * i] == 1 && board[0][3 * i + 1] == 1 && board[0][3 * i + 2] == 1)
		{
			if (board[1][3 * i] == board[1][3 * i + 1] && board[1][3 * i] == board[1][3 * i + 2])
			{
				return board[1][3 * i];
			}
		}
		else if (board[0][i] == 1 && board[0][i + 3] == 1 && board[0][i + 6] == 1)
		{
			if (board[1][i] == board[1][i + 3] && board[1][i] == board[1][i + 6])
			{
				return board[1][i];
			}
		}
	}

	if (board[0][0] == 1 && board[0][4] == 1 && board[0][8] == 1)
	{
		if (board[1][0] == board[1][4] && board[1][0] == board[1][8])
		{
			return board[1][0];
		}
	}
	else if (board[0][2] == 1 && board[0][4] == 1 && board[0][6] == 1)
	{
		if (board[1][2] == board[1][4] && board[1][2] == board[1][6])
		{
			return board[1][2];
		}
	}

	count = 0;
	
	for (int i = 0; i < 9; i++)
	{
		if (board[0][i] == 1)
		{
			count++;
		}
	}
	if (count == 9)
	{
		return 10;
	}

	return -1;
}

game::~game()
{
}
