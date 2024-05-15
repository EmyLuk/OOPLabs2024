#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <queue>

using namespace std;
struct Comparare {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
        return !(a.second > b.second || (a.second == b.second && a.first < b.first));
    }
};

int main() {
    ifstream intrare("TextFile1.txt");
    if (!intrare) {
        cerr << "Nu s-a putut deschide fișierul de intrare.\n";
        return 1;
    }
    priority_queue<string, vector<pair<string, int>>, Comparare> coadaPrioritate;
    const char delimitator[] = " .,!?";
    string linie;
    map<string, int> frecventaCuvinte;
    while (getline(intrare, linie)) {
        size_t i = linie.find_first_not_of(delimitator);
        while (i != string::npos) {
            string cuvant;
            size_t j;
            for (j = i; j < linie.size() && strchr(delimitator, linie[j]) == nullptr; j++)
                cuvant += linie[j];
            for (char& c : cuvant)
                c = (char)tolower(c);
            frecventaCuvinte[cuvant]++;
            i = linie.find_first_not_of(delimitator, j);
        }
    }
    for (const auto& pereche : frecventaCuvinte)
        coadaPrioritate.push(make_pair(pereche.first, pereche.second));

  
    while (!coadaPrioritate.empty()) {
        cout << coadaPrioritate.top().first << ' ' << coadaPrioritate.top().second << '\n';
        coadaPrioritate.pop();
    }

    return 0;
}
