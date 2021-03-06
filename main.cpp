#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
void init_field(char** field, int size);
void print_field(char** field, int size);
void player_turn(char** field, int size);
bool check_win(char** field, int size, char sign);
bool check_drow(char** field, int size);
//======================= MAIN ======================
int main() {
	setlocale(LC_ALL, "rus");
	int size = 3;
	char** field = new char* [size];
	for (int i = 0; i < size; i++) {
		field[i] = new char[size];
	}
	init_field(field, size);
	print_field(field, size);
	while (true) {
		//ход крестиков
		player_turn(field, size);
		print_field(field, size);
		// усли выигрыш крестиков,то прирвать цикл
		if (check_win(field, size, 'x')) {
			cout << "Выиграли крестики!" << endl;
			break;
		}
		//если ничья, то прирвать цикл
		if (check_drow(field, size)) {
			cout << "Ничья" << endl;
			break;
		}
		//ход ноликов
		player_turn(field, size);
		print_field(field, size);
		//если выигрыш ноликов, то пркрвать цикл
		if (check_win(field, size, 'o')) {
			cout << "Выиграли нолики!" << endl;
			break;
		}
		//если ничья, то прервать цикл
		if (check_drow(field, size)) {
			cout << "Ничья" << endl;
			break;
		}
	}
	return 0;
}
//====================== ФУНКЦИИ =====================
void init_field(char** field, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			field[i][j] = ' ';
		}
	}  
}
void print_field(char** field, int size){
	for (int i = 0; i < size; i++) {
		cout << "|---|---|---|" << endl;
		for (int j = 0; j < size; j++) {
			cout << "| " << field[i][j] << ' ';
		}
		cout << "|" << endl;
	}
	cout << "|---|---|---|" << endl;
}
void player_turn(char** field, int size) {
	int row, col;
	char sign;
	do {
		do {
			cout << "Введите номер строки ";
			cin >> row;
		} while (row < 0 || row > size - 1);
		do {
			cout << "Ввмдите номер столбца";
			cin >> col;
		} while (col < 0 || col > size - 1);
	} while (field[row][col] != ' ');
	do {
		cout << "Введите значок (английские х или о)";
		cin >> sign;
	} while (sign != sign && sign != 'o');
	field[row][col] = sign;
}
 bool check_win(char** field, int size, char sign) {
	 //провера 1-й строки
	 if (field[0][0] == sign && field[0][1] == sign && field[0][2] == sign) {return true;}
	 //Проверка 2-й строки
	 if (field[1][0] == sign && field[1][1] == sign && field[1][2] == sign) {return true;}
	 //Проверка 3-й строки
	 if (field[2][0] == sign && field[2][1] == sign && field[2][2] == sign) {return true;}
	 //Проверка 0-го столбца
	 if (field[0][0] == sign && field[1][0] == sign && field[2][0] == sign) {return true;}
	 //Проверка 1-го столбца
	 if (field[0][1] == sign && field[1][1] == sign && field[2][1] == sign) { return true; }
	//проверка 2-го столбца
	if (field[0][2] == sign && field[1][2] == sign && field[2][2] == sign) {return true;}
	 //Проверка диагонали основной
	 if (field[0][0] == sign && field[1][1] == sign && field[2][2] == sign) {return true;}
	 //Проверка диагонали побочной
	 return true;
}
 bool check_drow(char** field, int size) {
	 for (int i = 0; i < size; i++) {
		 for (int j = 0; j < size; j++) {
			 if (field[i][j] == ' ') return false;
		 }
	 }
	 return true;
 }