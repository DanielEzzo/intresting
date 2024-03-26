#include <iostream>
using namespace std;

int main()
{
	const int SIZE = 7;
	int array[SIZE]{ 7, 900,672,55, 38672, 693, 345}, arrBuf[10][SIZE]{};
	int countR = 1;
	int max = array[0];
	//нахождения макс числа
	for (int i = 1; i < SIZE; i++) {
		if (array[i] > max) max = array[i];
	}
	int min = array[0];
	for (int i = 1; i < SIZE; i++) {
		if (array[i] < min) min = array[i];
	}
	if ((-1 * min) > max) max = min * -1;
	int Raz = 1;
	//колво разрядов
	for (int raz = 1; (max / raz) != 0; raz *= 10) {
		Raz*=10;
	}

	int arrayBuf[10][SIZE]{};

	for (int raz = 1; raz <= Raz; raz *= 10) {
		for (int i = 0, jBuf = 0; i < SIZE; i++) {
			//высовываем
			for (int j = 0; j < 10; j++) {
				if (((array[i] / raz)) % 10 == j) arrayBuf[j][jBuf++] = array[i];
			}
		}
		//засоваваем
		for (int i = 0, arrI = 0; i < 10; i++) {
			for (int j = 0; j < SIZE; j++) {
				if (arrayBuf[i][j]) array[arrI++] = arrayBuf[i][j];
			}
		}
		//чистим
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < SIZE; j++) {
				arrayBuf[i][j] = 0;
			}
		}
	}


	for (int i = 0; i < SIZE; i++) {
			cout << array[i]<<"  ";
	}
}