#include <iostream>
#include <cstdlib> //for rand and srand
#include <ctime> //for time
#include <conio.h> //for getch

void task1();
void task2();
void task3();
void task4();
void clearcin();

int main() {

	bool Repeat{};
	char Choice{};
	char RepeatChoice{};

	srand(time(nullptr));
	do {
		Repeat = false;
		system("cls");
		std::cout << "What task would you like to do?\n" << "A. Tic-tac-toe table, using either 1D or 2D array.\n"
			<< "B. Initialize a 2D array (2,4) using a for loop, asking for values.\n"
			<< "C. Get a random number between two user-inputted numbers\n"
			<< "D. Moving around in a \"game\"\n";
		std::cin >> Choice;
		clearcin();
		Choice = toupper(Choice);
		switch (Choice) {
		case 'A': case '1':
			task1();
			break;
		case 'B': case '2':
			task2();
			break;
		case 'C': case '3':
			task3();
			break;
		case 'D': case '4':
			task4();
			break;
		default:
			std::cout << "You did not enter a valid input!\n";
			break;
		}
		std::cout << "\nWould you like to try another task? Y/N\n";
		std::cin >> RepeatChoice;
		clearcin();
		RepeatChoice = toupper(RepeatChoice);
		if (RepeatChoice == 'Y') {
			Repeat = true;
		}
		else {
			Repeat = false;
			std::cout << "Thank you for trying my program, goodbye!\n";
			exit(0);
		}
	} while (Repeat == true);

	return 0;
}

void task1() {

	std::string board = " | | \n-----\n | | \n-----\n | | ";
	char Choice{};

	std::cout << "Would you like to use a 1D or a 2D array?\n" << "1. 1D-array\n" << "2. 2D-array\n";
	std::cin >> Choice;
	clearcin();
	switch (Choice) {
	case '1': case 'A':
		break;
	default:
		std::cout << "That's not a valid input!\n";
	}
}

void task2() {
	
	int Values[2][4]{};

	for (int i{}; i < 2; i++) {
		for (int j{}; j < 4; j++) {
			std::cout << "Please enter a value for coordinate " << i << "," << j << "\n";
			std::cin >> Values[i][j];
		}
	}

	for (int i{}; i < 2; i++) {
		for (int j{}; j < 4; j++) {
			std::cout << Values[i][j] << "\t";
		}
		std::cout << "\n";
	}

}

void task3() {
	int min{};
	int max{};
	int RandomNumber{};
	bool Repeat{};

	do {
		Repeat = false;
		std::cout << "Please choose the lower number: " << std::endl;
		std::cin >> min;
		clearcin();
		std::cout << "Please choose the higher number: " << std::endl;
		std::cin >> max;
		clearcin();
		if (min > max) {
			std::cout << "The lower number is higher than the higher number! Please choose different numbers!\n";
			Repeat = true;
		}
	} while (Repeat == true);
	
	RandomNumber = rand() % (max - min) + min;
	std::cout << "Here's a random number between " << min << " and " << max << ": " << RandomNumber << "\n";

}

void task4() {

	const int Rows = 20;
	const int Cols = 20;
	char Board[Rows][Cols]{};
	char input{};
	int CurPos[2]{};

	//Initialize the board, making everything space, then the middle square the player icon
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			Board[i][j] = ' ';
		}
	}
	Board[Rows / 2][Cols / 2] = '*';

	//Draw the board
	system("cls");
	std::cout << "Press WASD to move around, Q to quit\n";
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			std::cout << Board[i][j];
		}
		std::cout << '\n';
	}

	//Get initial position of player, in hindsight I realize since we know the starting position we can just directly set it (to Rows/2 and Cols/2) but I will leave it here for posterity
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			if (Board[i][j] == '*') {
				CurPos[0] = i;
				CurPos[1] = j;
			}
		}
	}

	do {
		input = _getch(); //Capture keypresses, to quit if Q is pressed and move if WASD is pressed, without having to press enter inbetween.

		
		switch (input) {
		case 'w': case 'W':
			//Update players position; up one row IF player is not already on row 0
			if (CurPos[0] != 0) {
				Board[CurPos[0]][CurPos[1]] = ' ';
				Board[CurPos[0] - 1][CurPos[1]] = '*';
				CurPos[0] = CurPos[0] - 1;
			}
			//Now draw the board again with the updated position
			system("cls");
			std::cout << "Press WASD to move around, Q to quit\n";
			for (int i = 0; i < Rows; i++) {
				for (int j = 0; j < Cols; j++) {
					std::cout << Board[i][j];
				}
				std::cout << '\n';
			}
			break;
		case 'a': case 'A':
			//Update players position; left one column IF player is not already on column 0
			if (CurPos[1] != 0) {
				Board[CurPos[0]][CurPos[1]] = ' ';
				Board[CurPos[0]][CurPos[1] - 1] = '*';
				CurPos[1] = CurPos[1] - 1;
			}
			//Now draw the board again with the updated position
			system("cls");
			std::cout << "Press WASD to move around, Q to quit\n";
			for (int i = 0; i < Rows; i++) {
				for (int j = 0; j < Cols; j++) {
					std::cout << Board[i][j];
				}
				std::cout << '\n';
			}
			break;
		case 's': case 'S':
			//Update players position; down one row IF player is not already on bottom row
			if (CurPos[0] != Rows - 1) {
				Board[CurPos[0]][CurPos[1]] = ' ';
				Board[CurPos[0] + 1][CurPos[1]] = '*';
				CurPos[0] = CurPos[0] + 1;
			}
			//Now draw the board again with the updated position
			system("cls");
			std::cout << "Press WASD to move around, Q to quit\n";
			for (int i = 0; i < Rows; i++) {
				for (int j = 0; j < Cols; j++) {
					std::cout << Board[i][j];
				}
				std::cout << '\n';
			}
			break;
		case 'd': case 'D':
			//Update players position; right one column IF player is not already on rightmost column
			if (CurPos[1] != Cols - 1) {
				Board[CurPos[0]][CurPos[1]] = ' ';
				Board[CurPos[0]][CurPos[1] + 1] = '*';
				CurPos[1] = CurPos[1] + 1;
			}
			//Now draw the board again with the updated position
			system("cls");
			std::cout << "Press WASD to move around, Q to quit\n";
			for (int i = 0; i < Rows; i++) {
				for (int j = 0; j < Cols; j++) {
					std::cout << Board[i][j];
				}
				std::cout << '\n';
			}
			break;
		}
	} while (input != 'Q' && input != 'q');
}

void clearcin() {
	std::cin.clear();
	std::cin.ignore(32767, '\n');
}

