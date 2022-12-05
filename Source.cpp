/*Tyler LeBlanc
CIS 1202.201
CharacterOffsets
12/5/2022
*/

#include <iostream>

using namespace std;

class InvalidCharacterException_C {
public:
	string InvalidCharacterException() {
		return "Error: Character must be a letter.";
	}
};

class InvalidRangeException_C {
public:
	string InvalidRangeException() {
		return "Error: Offset is out of range.";
	}
};

char Character(char start, int offset) {
	if (!((start >= 'A' && start <= 'Z') || (start >= 'a' && start <= 'z'))) {
		throw InvalidCharacterException_C();
	}
	if (!(((start + offset) >= 'A' && (start + offset) <= 'Z') || ((start + offset) >= 'a' && (start + offset) <= 'z'))) {
		throw InvalidRangeException_C();
	}
	if ((((start >= 'A' && start <= 'Z') && ((start + offset) >= 'a' && (start + offset) <= 'z')) || (((start + offset) >= 'A' && (start + offset) <= 'Z') && (start >= 'a' && start <= 'z')))) {
		throw InvalidRangeException_C();
	}
	return (start + offset);
}

int main() {

	char start;
	int offset;

	bool again = true;
	while (again) {
		try {
			cout << endl << "Enter the starting letter." << endl;
			cin >> start;

			cout << endl << "Enter the offset." << endl;
			cin >> offset;

			cout << endl << start << " offset by " << offset << " is " << Character(start, offset) << endl;

			cout << endl << "Enter 1 to continue offsetting letters, or enter 0 to quit." << endl;
			cin >> again;
		}
		catch (InvalidCharacterException_C invalidCharacterException) {
			cout << endl << invalidCharacterException.InvalidCharacterException() << endl;
		}
		catch (InvalidRangeException_C invalidRangeException) {
			cout << endl << invalidRangeException.InvalidRangeException() << endl;
		}
	}

	cout << endl << endl;
	system("pause");
	return 0;
}