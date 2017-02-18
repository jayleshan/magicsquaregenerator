#include <iostream>

using namespace std;

void generateSquare(int size, int version) {

	int MagicSquare[size][size];

	// Initializes MagicSquare to contain all zeros.
	for (int i = 0; i != size; ++i) {
		for (int j = 0; j != size; ++j) {
			MagicSquare[i][j] = 0;
		}
	}

	// Calculate the magic square
	if (version == 1) {

		int i = size/2;
		int j = size-1;

		for (int number = 1; number <= size*size; ) {
			// Third Condition
			if (i == -1 && j == size) {
				j = size-2;
				i = 0;
			}
			else {
				if (j == size) {
					j = 0;
				}
				if (i < 0) {
					i = size -1;
				}
			}
			// Second Condition
			if (MagicSquare[i][j]) {
				j -= 2;
				++i;
				continue;
			}
			else {
				// Sets Number
				MagicSquare[i][j] = ++number - 1;
			}
			// First Condition
			++j;
			--i;
		}
	}
	if (version == 2) {

		int i = size/2;
		int j = size-1;

		for (int number = 1; number <= size*size; ) {
			// Third Condition
			if (i == -1 && j == size) {
				j = size-2;
				i = 0;
			}
			else {
				if (j == size) {
					j = 0;
				}
				if (i < 0) {
					i = size -1;
				}
			}
			// Second Condition
			if (MagicSquare[i][j]) {
				j -= 2;
				++i;
				continue;
			}
			else {
				// Sets Number
				MagicSquare[i][j] = ((size*size) + 2) - ++number;
			}
			// First Condition
			++j;
			--i;
		}
	}
	if (version == 3) {
		int i = 0;
		int j = size/2;

		for (int number = 1; number <= (size*size); ++number) {
			MagicSquare[i][j] = number - 1;
			i--;
			j++;

			if (number%size == 0) {
				i += 2;
				--j;
			}
			else {
				if (j == size) {
					j -= size;
				}
				else if (i < 0) {
					i += size;
				}
			}
		}
		for (int i = 0; i != size; ++i) {
			for (int j = 0; j != size; ++j) {
				MagicSquare[i][j] += 1;
			}
		}

	}
	if (version == 4) {
		int i = 0;
		int j = size/2;

		for (int number = 1; number <= (size*size); ++number) {
			MagicSquare[i][j] = number;
			i--;
			j++;

			if (number%size == 0) {
				i += 2;
				--j;
			}
			else {
				if (j == size) {
					j -= size;
				}
				else if (i < 0) {
					i += size;
				}
			}
		}
		for (int i = 0; i != size; ++i) {
			for (int j = 0; j != size; ++j) {
				MagicSquare[i][j] = ((size*size) + 1) - MagicSquare[i][j];
			}
		}
	}
	

	// Prints magic square
	cout << "\nMagic Square #" << version << " is:\n\n";
	for (int x = 0; x != size; ++x) {
		for (int y = 0; y != size; ++y) {
			cout << MagicSquare[x][y] << "  ";
			if (MagicSquare[x][y] < 100) {
				cout << " ";
			}
			if (MagicSquare[x][y] < 10) {
				cout << " ";
			}
		}
		cout << endl;
	}
	

	// Check sums of rows
	cout << "\nChecking the sums of every row: ";
	for (int i = 0; i != size; ++i) {
		int sum = 0;
		for (int j = 0; j != size; ++j) {
			sum += MagicSquare[i][j];
		}
		cout << sum << " ";
	}
	cout << endl;

	// Check sum of cols
	cout << "Checking the sums of every column: ";
		for (int i = 0; i != size; ++i) {
		int sum = 0;
		for (int j = 0; j != size; ++j) {
			sum += MagicSquare[j][i];
		}
		cout << sum << " ";
	}
	cout << endl;

	// Check sum of diagonals
	cout << "Checking the sums of every diagonal: ";
	int diagonalSum = 0;
	for (int i = 0; i != size; ++i) {
		diagonalSum += MagicSquare[i][i];
	}
	cout << diagonalSum << " ";
	int diagonalSum2 = 0;
	for (int i = 0; i != size; ++i) {
		diagonalSum2 += MagicSquare[size-1-i][i];
	}
	cout << diagonalSum2 << " ";
	cout << endl;
}

int main(void) {

	int size = 0;

	// Gets size of square
	while (true) {
		cout << "\nEnter the size of a magic square: ";
		if (cin >> size && size >= 3 && size <= 15 && (size%2 != 0)) {
			break;
		}
		if ((size%2 == 0)) {
			cout << "\nMust be odd. ";
		}
		if (size < 3 || size > 15) {
			cout <<"\nMust be between 3 and 15, inclusive. ";
		}
		cout << endl;
	}

	// Generates squares
	generateSquare(size,1);
	generateSquare(size,2);
	generateSquare(size,3);
	generateSquare(size,4);

	return 0;
}