#include <array>
#include <iostream>

void printBoard(const std::array<char, 9>& board)
{
	std::cout << '\n';
	for (int row = 0; row < 3; ++row)
	{
		std::cout << " " << board[row * 3] << " | " << board[row * 3 + 1]
				  << " | " << board[row * 3 + 2] << '\n';
		if (row < 2)
		{
			std::cout << "---+---+---\n";
		}
	}
	std::cout << '\n';
}

bool hasWon(const std::array<char, 9>& board, char player)
{
	constexpr int winningLines[8][3] = {
		{0, 1, 2}, {3, 4, 5}, {6, 7, 8},
		{0, 3, 6}, {1, 4, 7}, {2, 5, 8},
		{0, 4, 8}, {2, 4, 6}
	};

	for (const auto& line : winningLines)
	{
		if (board[line[0]] == player && board[line[1]] == player && board[line[2]] == player)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	std::array<char, 9> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	char player = 'X';
	int moves = 0;

	std::cout << "Tic-Tac-Toe\nChoose a square from 1 to 9.\n";

	while (moves < 9)
	{
		printBoard(board);
		std::cout << "Player " << player << ", choose a square: ";

		int choice;
		if (!(std::cin >> choice))
		{
			std::cout << "Please enter a number from 1 to 9.\n";
			return 0;
		}

		if (choice < 1 || choice > 9 || board[choice - 1] == 'X' || board[choice - 1] == 'O')
		{
			std::cout << "That square is not available. Try again.\n";
			continue;
		}

		board[choice - 1] = player;
		++moves;

		if (hasWon(board, player))
		{
			printBoard(board);
			std::cout << "Player " << player << " wins!\n";
			return 0;
		}

		player = (player == 'X') ? 'O' : 'X';
	}

	printBoard(board);
	std::cout << "It's a draw!\n";
	return 0;
}
