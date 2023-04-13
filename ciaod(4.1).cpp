//merge_sort
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

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

vector<film> merge(vector<film>& films_l, vector<film>& films_r) {
    vector<film> films_merged;
    int i = 0, j = 0;
    while (i < films_l.size() && j < films_r.size()) {
        if (films_l[i].director < films_r[j].director) {
            films_merged.push_back(films_l[i++]);
        }
        else {
            films_merged.push_back(films_r[j++]);
        }
    }
    while (i < films_l.size()) {
        films_merged.push_back(films_l[i++]);
    }
    while (j < films_r.size()) {
        films_merged.push_back(films_r[j++]);
    }
    return films_merged;
}

vector<film> merge_sort_by_director(vector<film>& films) {
    if (films.size() <= 1) {
        return films;
    }
    int mid = films.size() / 2;
    vector<film> films_l(films.begin(), films.begin() + mid);
    vector<film> films_r(films.begin() + mid, films.end());
    films_l = merge_sort_by_director(films_l);
    films_r = merge_sort_by_director(films_r);
    return merge(films_l, films_r);
}

// Запись
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
    unsigned int start = clock();
    string a = "a.txt", b = "b.txt", c = "c.txt";
    zapis(a, b, c);

    vector<film> films;
    ifstream file_b(b), file_c(c);
    string line;
    while (getline(file_b, line)) {
        istringstream iss(line);
        string t, s, g, d, a;
        int y;

        if (iss >> t >> s >> g >> y >> d) {
            // Чтение списка актеров
            vector<string> actors;
            while (iss >> a) {
                actors.push_back(a);
            }

            // Создание экземпляра структуры film и добавление его в вектор
            film f(t, s, g, y, d, actors);
            films.push_back(f);
        }
    }

    while (getline(file_c, line)) {
        istringstream iss(line);
        string t, s, g, d, a;
        int y;

        if (iss >> t >> s >> g >> y >> d) {
            // Чтение списка актеров
            vector<string> actors;
            while (iss >> a) {
                actors.push_back(a);
            }

            // Создание экземпляра структуры film и добавление его в вектор
            film f(t, s, g, y, d, actors);
            films.push_back(f);
        }
    }
    file_b.close(), file_c.close();

    vector<film> sorted_films = merge_sort_by_director(films);
    ofstream file_a(a);
    for (int i = 0; i < sorted_films.size(); i++) {
        file_a << sorted_films[i].title << " " << sorted_films[i].studio << " " << sorted_films[i].genre << " "
            << sorted_films[i].year << " " << sorted_films[i].director << " ";
        for (int j = 0; j < sorted_films[i].actors.size(); j++) {
            file_a << sorted_films[i].actors[j] << " ";
        }
        file_a << endl;
    }
    file_a.close();
    unsigned int end = clock();
    cout << "Time = " << (end - start) << " ms ";
    return 0;
}
