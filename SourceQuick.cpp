/**
 @file
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <time.h> 
#include <map>
using namespace std;
/**
 *@brief �����, ����������� ������ �������� ���������� � �����������
*/
class FootballPlayer {
public:
    //! ���� - ������ ����������
    string country = "";
    //! ���� - ��� ����������
    string fullName = "";
    //! ���� - ���� ����������
    string clubName = "";
    //! ���� - ������� ����������
    string position = "";
    //! ���� - ������ ������� �����������
    int matchesPlayed = 0;
    //! ���� - ����� ������/����� ������� �����������
    int goalsScored = 0;
    /**
     *@brief ����������� �� ���������
    */
    FootballPlayer() {}
    /**
     *@brief �����������, ����������� ����-������ � �����������
     * @param c ������ ����������
     * @param n ��� ����������
     * @param cn ���� ����������
     * @param p ������� ����������
     * @param mp ������ ������� �����������
     * @param gs ����� ������/����� ������� �����������
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
        * @brief ����� ��� ������ ������ ���������� � ����
        * @param file ����� �����, � ������� ��������� ������
    */
    void writeToFile(ofstream& file) {
        file << country << "," << fullName << "," << clubName << "," << position << "," << matchesPlayed << "," << goalsScored << endl;
    }
    /**
       * @brief ���������� ��������� >=
       * @param other ������ �� ������, � ������� ���������� ������� ������
       * @return ��������� ���������
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
        * @brief ���������� ��������� >
        * @param other ������ �� ������, � ������� ���������� ������� ������
        * @return ��������� ���������
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
        * @brief ���������� ��������� <
        * @param other ������ �� ������, � ������� ���������� ������� ������
        * @return ��������� ���������
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
        * @brief ���������� ��������� <=
        * @param other ������ �� ������, � ������� ���������� ������� ������
        * @return ��������� ���������
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
   * @brief ���������� ��������� ������� ����������
   * @param mas ������ �� std::vector, ���������� � ���� ������ ���� ������ ������, �. �. ������ �������������� ����������
   * @param first ������ �������, ������������ ����� ������� �������� �����, ��� ��������� �������������
   * @param last ������ �������, ������������ ������ ������� �������� �����, ��� ��������� �������������
*/
void quicksort(vector<FootballPlayer>& mas, int first, int last)
{
    FootballPlayer mid, count;
    int f = first, l = last;
    mid = mas[(f + l) / 2]; //���������� �������� ��������
    do
    {
        while (mas[f].country < mid.country) f++;
        while (mas[l].country > mid.country) l--;
        if (f <= l) //������������ ���������
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
   * @brief ���������� ��������� ��������� ������
   * @param arr ������ �� std::vector, ���������� � ���� ������ ���� ������ ������, �. �. ������ �������������� ������
   * @param n ������ �������
   * @param key ������� ��������
   * @param res ������,� ������� ������ ���� �������� ���������� ������
   * @return int
*/
int linearSearch(vector<FootballPlayer>& arr, int n, string key, vector<FootballPlayer>& res) {
    for (int i = 0; i < n; i++) {
        if (arr[i].country == key) {
            res.push_back(arr[i]);
        }
    }
    return 1;
}
/**
   * @brief ���������� ��������� ��������� ������
   * @param arr ������ �� std::vector, ���������� � ���� ������ ���� ������ ������, �. �. ������ �������������� ������
   * @param l ����� ����� �������
   * @param r ������ ����� �������
   * @param key ������� ��������
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

const int SIZE = 100000; //  ���������� ��������

//multimap<string, FootballPlayer> mmap;

int main() {
    ifstream file("players100000.txt");
    if (!file) {
        cerr << "�� ������� ������� ����!\n";
        exit(1);
    }
    int fi;
    int i = 0; // ������� ��������
    vector<FootballPlayer> vec(SIZE);// ������ ��������

    //FootballPlayer arr[SIZE];

    string line;
    while (getline(file, line)) {
        // ���������� ������ �� ��������
        stringstream line_stream(line);
        string country, fullName, clubName, position, matchesPlayed, goalsScored;
        getline(line_stream, country, ',');
        getline(line_stream, fullName, ',');
        getline(line_stream, clubName, ',');
        getline(line_stream, position, ',');
        getline(line_stream, matchesPlayed, ',');
        getline(line_stream, goalsScored, ',');
        FootballPlayer obj(country, fullName, clubName, position, stoi(matchesPlayed), stoi(goalsScored));
        vec[i] = obj;
        //arr[i] = obj;
        //mmap.emplace(obj.country,obj);
        i++;

        // �������� �������� � ���������� �� � ������ objs

    }
    //int j = 0;
    int fi1,fi2;
    vector<FootballPlayer> vec1;
    clock_t start = clock();
    //auto fi = mmap.equal_range("France");
    //quicksort(vec, 0, SIZE - 1);
    //fi = binarySearch(vec, SIZE, "France", vec1);
    linearSearch(vec,SIZE,"France",vec1);
    /*fi1 = fi;
    fi2 = fi;
    while (vec[fi1].country == vec[fi1+1].country || fi1 == 999) {
        //vec1[j] = vec[fi1];
        //j++;
        fi1++;
        
    }
    
    while (vec[fi2].country == vec[fi2 - 1].country || fi1 == 0) {
        //vec1[j] = vec[fi2];
        //j++;
        fi2--;
    }
    */
    clock_t end = clock();
    //printf("%d\n", fi1);
    //printf("%d\n", fi2);
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    string namef = "FindL";
    namef.append(to_string(SIZE));
    namef.append(".txt");
    ofstream fileout(namef);
    for (int i = 0; i < vec1.size(); i++) {
        vec1[i].writeToFile(fileout);
    }
    /*while (fi.first != fi.second) {
        fi.first->second.writeToFile(fileout);
        fi.first++;
    }
    int tfi = fi;
    while (vec[fi].country == vec[fi+1].country || fi == 999) {
        vec[fi].writeToFile(fileout);
        fi++;
        
    }
    while (vec[tfi].country == vec[tfi-1].country || tfi == 0) {
        vec[tfi].writeToFile(fileout);
        tfi--;
    }*/
    fileout << seconds << endl;
    file.close();
    fileout.close();

    return 0;
}