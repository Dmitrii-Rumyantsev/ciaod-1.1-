//natural_sort
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;
// Структура для представления фильма
struct film {
    string title;
    string studio;
    string genre;
    int year;
    string director;
    vector<string> actors;

    // Конструктор с параметрами
    film(string t, string s, string g, int y, string d, vector<string> a) {
        title = t;
        studio = s;
        genre = g;
        year = y;
        director = d;
        actors = a;
    }
};

// Функция для слияния двух отсортированных массивов
void merge_natural(vector<film>& films, int start, int mid, int end, string field) {
    // Создание векторов для левой и правой половин
    vector<film> films_l(films.begin() + start, films.begin() + mid + 1);
    vector<film> films_r(films.begin() + mid + 1, films.begin() + end + 1);
    vector<film> films_merged;
    int i = 0, j = 0;
    // Объединение двух половин, сравнивая значения в соответствии с полем сортировки
    while (i < films_l.size() && j < films_r.size()) {
        if (field == "director" && films_l[i].director.compare(films_r[j].director) >= 0) {
            films_merged.push_back(films_r[j++]);
        }
        else {
            films_merged.push_back(films_l[i++]);
        }
    }
    // Добавление оставшихся элементов в вектор объединенных элементов
    while (i < films_l.size()) {
        films_merged.push_back(films_l[i++]);
    }

    while (j < films_r.size()) {
        films_merged.push_back(films_r[j++]);
    }

    // Копирование объединенных элементов в оригинальный массив
    for (int i = 0; i < films_merged.size(); i++) {
        films[start + i] = films_merged[i];
    }
}


// Функция для сортировки массива
vector<film> merge_sort_natural(vector<film>& films, string field) {
    if (films.size() <= 1) {
        return;
    }

    int start = 0, mid = 0, end = 0;
    while (end < films.size() - 1) {
        // Ищем возрастающие подпоследовательности (runs) элементов
        for (mid = start + 1; mid < films.size() &&
                              (field == "director" && films[mid].director >= films[mid - 1].director); mid++);

        for (end = mid; end < films.size() &&
                        (field == "director" && films[end].director >= films[end - 1].director); end++);

        // Объединяем найденные подпоследовательности элементов
        merge_natural(films, start, mid - 1, end - 1, field);
        start = end;
    }
    return films;
}

// Функция записи содержимого файла a в два файла b и c
void zapis(string a, string b, string c) {
    ifstream file_a(a);
    ofstream file_b(b), file_c(c);
    string line;
    while (getline(file_a, line)) {
        file_b << line << endl;
        getline(file_a, line);
        file_c << line << endl;
    }
    file_a.close(), file_b.close(), file_c.close();
}

int main() {
    string a = "a.txt", b = "b.txt", c = "c.txt";
    zapis(a, b, c);  // задаются названия файлов и вызывается функция zapis, которая создает файлы и заполняет их случайными данными

    vector<film> films;  // объявление вектора структур film
    ifstream file_b(b), file_c(c);  // создание потоков для чтения файлов b и c
    string line;
    while (getline(file_b, line)) {  // чтение строк из файла b
        istringstream iss(line);  // создание потока для чтения из строки
        string t, s, g, d, a;
        int y;

        if (iss >> t >> s >> g >> y >> d) {  // чтение данных из строки
            // Чтение списка актеров
            vector<string> actors;
            while (iss >> a) {  // чтение списка актеров из строки
                actors.push_back(a);  // добавление актера в вектор
            }

            // Создание экземпляра структуры film и добавление его в вектор
            film f(t, s, g, y, d, actors);
            films.push_back(f);  // добавление фильма в вектор
        }
    }
    while (getline(file_c, line)) {  // чтение строк из файла c
        istringstream iss(line);  // создание потока для чтения из строки
        string t, s, g, d, a;
        int y;

        if (iss >> t >> s >> g >> y >> d) {  // чтение данных из строки
            // Чтение списка актеров
            vector<string> actors;
            while (iss >> a) {  // чтение списка актеров из строки
                actors.push_back(a);  // добавление актера в вектор
            }

            // Создание экземпляра структуры film и добавление его в вектор
            film f(t, s, g, y, d, actors);
            films.push_back(f);  // добавление фильма в вектор
        }
    }
    file_b.close(), file_c.close();  // закрытие файловых потоков

    string filed;  // создание переменной filed типа string
    vector<film> sorted_films = merge_sort_natural(films,filed);  // сортировка вектора films и сохранение результата в sorted_films

    ofstream file_a(a);  // создание потока для записи в файл a
    for (int i = 0; i < sorted_films.size(); i++) {  // цикл по элементам отсортированного вектора
        // запись данных фильма в файл a
        file_a << sorted_films[i].title << " " << sorted_films[i].studio << " " << sorted_films[i].genre << " "
               << sorted_films[i].year << " " << sorted_films[i].director << " ";
        for (int j = 0; j < sorted_films[i].actors.size(); j++) {  // цикл по актерам фильма
            file_a << sorted_films[i].actors[j] << " ";  // запись актера в файл
        }
        file_a << endl;

    }
    file_a.close();

}
