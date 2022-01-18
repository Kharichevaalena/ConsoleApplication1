#include <iostream>
#include <iomanip>

using namespace std;

int find_max1(int X[], int n) // для поиска индекса макс элемента
{
	int maxX = 0; //максимум в векторе Х
	int K; // индек максимального элемента
	int count = 0; // для проверки кол-ва встреченных максимумов

	for (int i = 0; i < n; i++)
	{
		if (X[i] >= maxX) // ищем максимум
		{
			maxX = X[i];
			K = i;
			count++;
		}
		if (count > 1) { // если встретилось 2 максимальных одинаковых числа , выводим индекс -1 ,значит вектор не корректен
			K = -1;
			break;
		}
	}
	return K;
}

int find_max2(int Y[], int n) { // для поиска индекса макс элемента
	int maxY = 0; // максимум в векторе У
	int p; // индекс макс элемента
	int count1 = 0; // кол-во максимальных элементов в векторе

	for (int i = 0; i < n; i++)
	{
		if (Y[i] >= maxY) // ищем максимум
		{
			maxY = Y[i];
			p = i;
			count1++;
		}
		if (count1 > 1) { p = -1; break; } // если встретилось 2 и более максимума , то вектор не корректен
	}
	return p;
}

int summ(int X[], int Y[], int n) //функция для суммы произведений векторов Х и У 
{
	int pr = 1;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		pr *= (X[i] * Y[i]); // перемножаем 2 элемента с индексом i 
		sum += pr; //складываем все перемноженные элементы
		pr = 1; // обновляем произведение для следующих итераций
	}
	return sum;
}
int summx(int X[], int n) { // функция для суммы элементов вектора Х
	int sumX = 0;
	for (int i = 0; i < n; i++) {
		sumX += X[i];
	}
	return sumX;
}

int summx_kv(int X[], int n) { // функция для суммы квадратов вектора Х
	int sumXX = 0;
	for (int i = 0; i < n; i++) {
		sumXX += X[i] * X[i];
	}
	return sumXX;
}

int summy(int Y[], int n) { // функция для суммы вектора У
	int sumY = 0;
	for (int i = 0; i < n; i++) {
		sumY += Y[i];
	}
	return sumY;
}

int summy_kv(int Y[], int n) { // функция для суммы квадратов вектора У
	int sumYY = 0;
	for (int i = 0; i < n; i++) {
		sumYY += Y[i] * Y[i];
	}
	return sumYY;
}

int main()
{
	int n = 30;
	int X[100]; //вектор Х
	int Y[100]; //вектор У

	for (int i = 0; i < n; i++) //заполняем X
	{
		cin >> X[i];
	}

	for (int i = 0; i < n; i++) //заполняем Y
	{
		cin >> Y[i];
	}

	// считаем функцию 
	if ((find_max1(X, n) == -1) || (find_max2(Y, n) == -1)) { // если встретили несколько максимумов в одном или двух векторах, выводи отрицательный резульат
		cout << "NONONO";
	}
	int otvet;
	if ((find_max1(X, n) != -1) && (find_max2(Y, n) != -1)) { // если макс элементы в норме, считаем значение функции
		otvet = (n * summ(X, Y, n) - summ(X, Y, n)) / pow(((find_max1(X, n) * summx_kv(X, n) - pow(summx(X, n), 2)) * ((find_max2(Y, n) * summy_kv(Y, n) - pow(summy(Y, n), 2)))), 0.5);
		cout << otvet << '\n'; //вывожу искомое значение функции
	}
	return 0;
}
