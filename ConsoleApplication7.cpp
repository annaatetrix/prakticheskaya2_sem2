#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <list>
#include <string>
#include <chrono>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int menu;
	list<int> list;
	int size, n;
	int* arr = new int[0];

	chrono::time_point<chrono::high_resolution_clock> time;

	while (true) {

		cout << "1. Создать массив автоматически\n"
			<< "2. Ввести массив с клавиатуры\n"
			<< "3. Создать массив из файла\n"
			<< "4. Добавить элемент в массив\n"
			<< "5. Удалить элемент из массива\n"
			<< "6. Получить элемент массива\n"
			<< "7. Создать двусвязный список автоматически\n"
			<< "8. Ввести двусвязный список с клавиатуры\n"
			<< "9. Создать двусвязный список из файла\n"
			<< "10. Добавить элемент в список\n"
			<< "11. Удалить элемент из списка\n"
			<< "12. Получить элемент списка\n"
			<< "13. Выход\n"
			<< "Выберите один из вариантов ";

		cin >> menu;
		cout << "\n";

		switch (menu) {

		case 1: {
			cout << "Введите размер массива: ";
			cin >> n;
			arr = new int[n];

			time = chrono::high_resolution_clock::now();

			for (int i = 0; i < n; i++) {
				arr[i] = rand() % 100;
			}

			break;
		} case 2: {
			cout << "Введите значения элементов массива (введите 0 чтобы закончить)\n";
			int* a;
			int* newArr = new int[0];
			int k;
			n = 0;

			time = chrono::high_resolution_clock::now();

			while (cin >> k) {

				a = new int[n + 1];
				for (int i = 0; i != n; i++) {
					a[i] = newArr[i];
				}

				if (k != 0) {
					a[n] = k;
					newArr = a;
					n++;
				}

				if (k == 0) {
					break;
				}

			}

			arr = new int[n];
			for (int i = 0; i < n; i++) {
				arr[i] = newArr[i];
			}

			break;
		} case 3: {

			ifstream file;
			string arr2[7];

			n = 7;

			file.open("Text.txt");

			time = chrono::high_resolution_clock::now();

			for (int i = 0; i < 7; ++i)
			{
				file >> arr2[i];
			}

			arr = new int[7];

			for (int i = 0; i < 7; i++) {
				arr[i] = stoi(arr2[i]);
			}

			break;
		} case 4: {
			int num;
			cout << "Введите элемент, который вы хотите добавить: ";
			cin >> num;
			int* arr2 = new int[n];
			n = n + 1;

			time = chrono::high_resolution_clock::now();

			for (int i = 0; i < n - 1; i++) {
				arr2[i] = arr[i];
			}

			arr2[n - 1] = num;

			for (int i = 0; i < n; i++) {
				arr[i] = arr2[i];
			}

			break;
		} case 5: {
			int k;
			int* arr2 = new int[n - 1];

			cout << "Введите индекс элемента чтобы удалить: ";
			cin >> k;

			time = chrono::high_resolution_clock::now();

			for (int i = 0; i < k; i++) {
				arr2[i] = arr[i];
			}
			for (int i = k; i < n - 1; i++) {
				arr2[i] = arr[i + 1];
			}

			n = n - 1;

			arr = new int[n];

			for (int i = 0; i < n; i++) {
				arr[i] = arr2[i];
			}

			break;
		} case 6: {
			int k;
			cout << "Введите индекс элемента: ";
			cin >> k;

			time = chrono::high_resolution_clock::now();
			cout << "Элемент: " << arr[k] << "\n";
			break;
		} case 7: {
			list.clear();
			cout << "Введите размер списка: ";
			cin >> size;

			time = chrono::high_resolution_clock::now();

			for (int i = 0; i < size; i++) {
				list.push_back(rand() % 100);
			}

			break;
		} case 8: {

			int k;

			list.clear();
			cout << "Введите значения элементов списка (введите 0 чтобы закончить): \n";

			time = chrono::high_resolution_clock::now();

			while (cin >> k) {

				if (k == 0) {
					break;
				}
				else {
					list.push_back(k);
				}

			}

			size = list.size();

			break;
		}
		case 9: {
			list.clear();

			ifstream file;
			string arr2[7];

			size = 7;

			file.open("Text.txt");

			time = chrono::high_resolution_clock::now();

			for (int i = 0; i < 7; i++)
			{
				file >> arr2[i];
			}

			for (int i = 0; i < 7; i++) {
				list.push_back(stoi(arr2[i]));
			}

			break;

		} case 10: {
			int k;

			time = chrono::high_resolution_clock::now();
			cout << "Введите элемент, который вы хотите добавить: ";
			cin >> k;

			list.push_back(k);

			size = list.size();

			break;
		} case 11: {
			int k, i = 0;
			int* arr2 = new int[size];

			time = chrono::high_resolution_clock::now();

			for (int j : list) {
				arr2[i] = j;
				i++;
			}

			cout << "Введите индекс элемента чтобы удалить: ";
			cin >> k;

			list.clear();

			time = chrono::high_resolution_clock::now();

			for (int i = 0; i < k; i++) {
				list.push_back(arr2[i]);
			}

			for (int i = k + 1; i < size; i++) {
				list.push_back(arr2[i]);
			}

			break;
		} case 12: {
			int k, l = 0;
			cout << "Введите индекс элемента: ";
			cin >> k;

			time = chrono::high_resolution_clock::now();

			for (int j : list) {
				if (l == k) {
					cout << "Этот элемент - " << j;
				}
				l++;
			}

			cout << "\n";

			break;
		} case 13: {
			return 0;
			break;
		}


		}

		if (menu < 6) {

			cout << "Массив: ";

			for (int i = 0; i < n; i++) {
				cout << arr[i] << " ";
			}
			cout << "\n";

		}
		else if (menu > 6 && menu < 12) {
			cout << "Список: ";

			for (int j : list) {
				cout << j << " ";
			}

			cout << "\n";
		}

		cout << "Время выполнения задания: " << chrono::duration_cast <chrono::microseconds> (chrono::high_resolution_clock::now() - time).count() << " микросекунд" << "\n";

	}

}





