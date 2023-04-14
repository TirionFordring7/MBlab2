#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <time.h> 
#include <map>
using namespace std;
/**
 *@brief Класс, реализующий способ хранения информации о футболистах
*/
class FootballPlayer {
public:
    //! Поле - страна футболиста
    string country = "";
    //! Поле - имя футболиста
    string fullName = "";
    //! Поле - клуб футболиста
    string clubName = "";
    //! Поле - позиция футболиста
    string position = "";
    //! Поле - матчей сыграно футболистом
    int matchesPlayed = 0;
    //! Поле - голов забито/мячей поймано футболистом
    int goalsScored = 0;
    /**
     *@brief Конструктор по умолчанию
    */
    FootballPlayer() {}
    /**
     *@brief Конструктор, заполняющий поля-данные о футболистах
     * @param c страна футболиста
     * @param n имя футболиста
     * @param cn клуб футболиста
     * @param p позиция футболиста
     * @param mp матчей сыграно футболистом
     * @param gs голов забито/мячей поймано футболистом
    */
    FootballPlayer(string c, string n, string cn, string p, int mp, int gs) {
        this->country = c;
        this->fullName = n;
        this->clubName = cn;
        this->position = p;
        this->matchesPlayed = mp;
        this->goalsScored = gs;
    }
    /**
        * @brief Метод для вывода данных футболиста в файл
        * @param file поток файла, в который выводятся данные
        * @return void
    */
    void writeToFile(ofstream& file) {
        file << country << "," << fullName << "," << clubName << "," << position << "," << matchesPlayed << "," << goalsScored << endl;
    }
    /**
       * @brief Перегрузка оператора >=
       * @param other ссылка на объект, с которым сравниваем текущий объект
       * @return результат сравнения
   */
    bool operator>=(const FootballPlayer& other) const {
        if (matchesPlayed > other.matchesPlayed) {
            return true;
        }
        if (matchesPlayed == other.matchesPlayed) {
            if (fullName > other.fullName) {
                return true;
            }
        }
        if ((fullName == other.fullName) && (matchesPlayed == other.matchesPlayed)) {
            if (abs(goalsScored) <= abs(other.goalsScored)) {
                return true;
            }
        }
        return false;
    }
    /**
        * @brief Перегрузка оператора >
        * @param other ссылка на объект, с которым сравниваем текущий объект
        * @return результат сравнения
    */
    bool operator>(const FootballPlayer& other) const {
        if (matchesPlayed > other.matchesPlayed) {
            return true;
        }
        if (matchesPlayed == other.matchesPlayed) {
            if (fullName > other.fullName) {
                return true;
            }
        }
        if ((fullName == other.fullName) && (matchesPlayed == other.matchesPlayed)) {
            if (abs(goalsScored) < abs(other.goalsScored)) {
                return true;
            }
        }
        return false;
    }
    /**
        * @brief Перегрузка оператора <
        * @param other ссылка на объект, с которым сравниваем текущий объект
        * @return результат сравнения
    */
    bool operator<(const FootballPlayer& other) const {
        if (matchesPlayed < other.matchesPlayed) {
            return true;
        }
        if (matchesPlayed == other.matchesPlayed) {
            if (fullName < other.fullName) {
                return true;
            }
        }
        if ((fullName == other.fullName) && (matchesPlayed == other.matchesPlayed)) {
            if (abs(goalsScored) > abs(other.goalsScored)) {
                return true;
            }
        }
        return false;
    }
    /**
        * @brief Перегрузка оператора <=
        * @param other ссылка на объект, с которым сравниваем текущий объект
        * @return результат сравнения
    */
    bool operator<=(const FootballPlayer& other) const {
        if (matchesPlayed < other.matchesPlayed) {
            return true;
        }
        if (matchesPlayed == other.matchesPlayed) {
            if (fullName < other.fullName) {
                return true;
            }
        }
        if ((fullName == other.fullName) && (matchesPlayed == other.matchesPlayed)) {
            if (abs(goalsScored) >= abs(other.goalsScored)) {
                return true;
            }
        }
        return false;
    }
};

using namespace std;



/**
   * @brief Реализация алгоритма быстрой сортировки
   * @param mas ссылка на std::vector, содержащий в себе данный типа нашего класса, т. е. массив подвергающийся сортировке
   * @param first индекс массива, определяющий левую границу текуюшей части, что требуется отсортировать
   * @param last индекс массива, определяющий правую границу текуюшей части, что требуется отсортировать
   * @return void
*/
void quicksort(vector<FootballPlayer>& mas, int first, int last)
{
    FootballPlayer mid, count;
    int f = first, l = last;
    mid = mas[(f + l) / 2]; //вычисление опорного элемента
    do
    {
        while (mas[f].country < mid.country) f++;
        while (mas[l].country > mid.country) l--;
        if (f <= l) //перестановка элементов
        {
            swap(mas[f],mas[l]);
            f++;
            l--;
        }
    } while (f < l);
    if (first < l) quicksort(mas, first, l);
    if (f < last) quicksort(mas, f, last);
}
/**
   * @brief Реализация алгоритма линейного поиска
   * @param arr ссылка на std::vector, содержащий в себе данный типа нашего класса, т. е. массив подвергающийся поиску
   * @param n размер массива
   * @param key искомое значение
   * @return int
*/
int linearSearch(vector<FootballPlayer>& arr, int n, string key) {
    for (int i = 0; i < n; i++)
        if (arr[i].country == key)
            return i;
    return -1;
}
/**
   * @brief Реализация алгоритма бинарного поиска
   * @param arr ссылка на std::vector, содержащий в себе данный типа нашего класса, т. е. массив подвергающийся поиску
   * @param l левая грань массива
   * @param r правая грань массива
   * @param key искомое значение
   * @return int
*/
int binarySearch(vector<FootballPlayer>& arr, int l, int r, string key) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid].country == key)
            return mid;
        else if (arr[mid].country < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

const int SIZE = 100000; //  количество объектов

multimap<string, FootballPlayer> mmap;

int main() {
    ifstream file("players100000.txt");
    if (!file) {
        cerr << "Не удается открыть файл!\n";
        exit(1);
    }
    //int fi;
    int i = 0; // Счетчик объектов
    vector<FootballPlayer> vec(SIZE);// Массив объектов

    //FootballPlayer arr[SIZE];

    string line;
    while (getline(file, line)) {
        // Разделение строки на значения
        stringstream line_stream(line);
        string country, fullName, clubName, position, matchesPlayed, goalsScored;
        getline(line_stream, country, ',');
        getline(line_stream, fullName, ',');
        getline(line_stream, clubName, ',');
        getline(line_stream, position, ',');
        getline(line_stream, matchesPlayed, ',');
        getline(line_stream, goalsScored, ',');
        FootballPlayer obj(country, fullName, clubName, position, stoi(matchesPlayed), stoi(goalsScored));
        //vec[i] = obj;
        //arr[i] = obj;
        mmap.emplace(obj.country,obj);
        i++;

        // создание объектов и добавление их в массив objs

    }
    
    clock_t start = clock();
    auto fi = mmap.find("France");
    //quicksort(vec, 0, SIZE - 1);
    //fi = binarySearch(vec,0,SIZE,"France");
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    string namef = "FindMM";
    namef.append(to_string(SIZE));
    namef.append(".txt");
    ofstream fileout(namef);
    /*for (int i = 0; i < SIZE; i++) {
        vec[i].writeToFile(fileout);
    }*/
    fileout << seconds << endl;
    fi->second.writeToFile(fileout);
    file.close();
    fileout.close();

    return 0;
}