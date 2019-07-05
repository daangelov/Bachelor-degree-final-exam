#include <iostream>

using namespace std;

bool isOrdered(char row[30][100], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (row[i][j] < row[i + 1][j]) {
                break;
            } else if (row[i][j] > row[i + 1][j]) {
                return false;
            }
            // else continue;
        }
    }
    return true;
}

int* revealPassword(char a[20][30][100], int m, int n) {

    int* password = new int[20 * 50 + 1];

    int nextPasswordIndex = 0;;

    for (int i = 0; i < m; ++i) {

        if (isOrdered(a[i], n)) {

            char* middleBook = a[i][(n-1) / 2];
            int wordLength = 0;

            for (int j = 0; j < 100; ++j) {
                if (middleBook[j] == ' ') {
                    password[nextPasswordIndex] = wordLength; // / 2;
                    nextPasswordIndex++;
                    wordLength = 0;
                } else if (middleBook[j] == '\0') {
                    password[nextPasswordIndex] = wordLength; // / 2;
                    nextPasswordIndex++;
                    break;
                } else {
                    wordLength++;
                }
            }
        }
    }
    password[nextPasswordIndex] = -1;

    return password;
}

int main()
{
    int m = 3;
    int n = 3;

    char a[20][30][100] = {
        {"Алгебра", "Аналитична геометрия", "Математически анализ"},
        {"Увод в програмирането", "Обектно-ориентирано програмиране", "Структури от данни и програмиране"},
        {"Бази от данни", "Изкуствен интелект", "Функционално програмиране"}
	};

	int* password = revealPassword(a, m, n);

	for (int i = 0; i < 1000; ++i) {
        if (password[i] != -1) {
            cout << password[i] << " ";
        } else {
            break;
        }
	}


}
