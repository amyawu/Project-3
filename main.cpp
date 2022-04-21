#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace chrono;

class Graph {
    unordered_map<string, unsigned int> mappy;

public:
    void putIn(string category);
    vector<pair<unsigned int, string>> organize();
};

void Graph::putIn(string category) {
    if (mappy.count(category) > 0) {
        mappy[category]++;
    }
    else {
        mappy[category] = 1;
    }
}

vector<pair<unsigned int, string>> Graph::organize() {
    vector<pair<unsigned int, string>> ordering;
    for(auto iter = mappy.begin(); iter != mappy.end(); iter++) {
        ordering.push_back(make_pair(iter->second,iter->first));
    }
    sort(ordering.rbegin(), ordering.rend());
    return ordering;
}

//opening and reading file
void ReadFile(Graph unorderedMappy) {
    ifstream info("rows.csv");
    if (info.is_open()) {
        string liner;
        getline(info, liner);

        while (getline(info, liner)) {
            istringstream stream(liner);

            string date;
            getline(stream, date, ',');

            string category;
            getline(stream, category, ',');

            unorderedMappy.putIn(category);
        }
    }
    else {
        cout << "Go cry" << endl;
    }
}

int main() {
    /*
     * runtime duration code from https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
     */
    auto start = high_resolution_clock::now();

    Graph unorderedMappy;
    ReadFile(unorderedMappy);
    vector<pair<unsigned int, string>> ordered = unorderedMappy.organize();

    cout << "The most common complaint is:" << ordered[0].second << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Runtime:" << duration.count() << endl;
    return 0;
}
