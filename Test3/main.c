#include <iostream>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

clock_t start, finish;
int Universe, value, maxCost;
int* size;
int** data;

struct results
{
	int result;
	double timeofAlg;
};

bool duplicate(int number, int count, int row) {
	if (count < 1) {
		return false;
	}
	int i = 0;
	do {
		if (data[row][i] == number) {
			return true;
		}
		i++;
	} while (i < count);
	return false;
}

int Generator(){
	int number;
	for (int j = 0; j < value; j++){
		number = (rand() % Universe) + 1;
		size[j] = number;
		data[j] = new int [size[j]];
		number = (rand() % maxCost) + 1;
		data[j][0] = number;
		cout << data[j][0] << " ";
		int i = 1;
		while (i <= size[j]) {
			number = (rand() % Universe) + 1;
			if (duplicate(number, i, j) == false){
				data[j][i] = number;
				cout << data[j][i] << " ";
				i++;
			}
		} 
		cout << "\n";
	}
	return 0;
}

//Algorytm dokładny
results Exact() {
	results output;

	start = clock();
	//TODO


	finish = clock();

	output.result = 0;
	output.timeofAlg = (finish - start) / (double)CLOCKS_PER_SEC;
	return output;
}

//Algorytm przybliżony
results Aprox() {
	results output;

	start = clock();
	//TODO


	finish = clock();

	output.result = 0;
	output.timeofAlg = (finish - start) / (double)CLOCKS_PER_SEC;
	return output;
}

int main() {
	srand(time(NULL));
	cout << "Start\n";
	cout << "Podaj wielkosc zbioru: ";
	cin >> Universe;
	cout << "Podaj ilosc przedzialow ";
	cin >> value;
	cout << "Podaj maksymalny koszt ";
	cin >> maxCost;
	data = new int *[value];
	size = new int [value];
	//generowanie danych
	Generator();
	//zapis do pliku
	results Ex,Ap;
	Ex = Exact();
	Ap = Aprox();
	ofstream results;
	results.open("output.txt", ofstream::app);
	results << Ex.result << "," << Ex.timeofAlg * 1000 << "; "
		<< Ap.result << "," << Ap.timeofAlg * 1000 << "\n";
	results.close();

	system("PAUSE");

	//zwalnianie pamieci
	for (int j = 0; j < value; j++){
	delete[] data[j];
	}
	delete[] data;
	delete[] size;
	return 0;
}
