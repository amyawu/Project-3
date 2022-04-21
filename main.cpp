#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
#include <algorithm>
#include <string>
using namespace std;
using namespace chrono;

class Graph {
    unordered_map<string, int> mappy;

public:
    Graph();
    void putIn(string category);
    vector<pair<int, string>> organize();
};

Graph::Graph() {
}

void Graph::putIn(string category) {
    if (mappy.count(category) > 0) {
        mappy[category]++;
    }
    else {
        mappy[category] = 1;
    }
}

vector<pair<int, string>> Graph::organize() {
    vector<pair<int, string>> ordering;
    for(auto iter = mappy.begin(); iter != mappy.end(); iter++) {
        if (iter->first.at(0) == '"') {
            if (iter->first.at(1) == 'M') {
                int num = iter->second;
                string first = "Money transfer, virtual currency, or money service";
                ordering.push_back(make_pair(num,first));
                continue;
            }
            else if (iter->first.at(1) == 'C') {
                int num = iter->second;
                string first = "Credit reporting, credit repair services, or other personal consumer reports";
                ordering.push_back(make_pair(num,first));
                continue;
            }
            else if (iter->first.at(1) == 'P') {
                int num = iter->second;
                string first = "Payday loan, title loan, or personal loan";
                ordering.push_back(make_pair(num,first));
                continue;
            }
        }
        ordering.push_back(make_pair(iter->second,iter->first));
    }
    sort(ordering.rbegin(), ordering.rend());
    return ordering;
}

//opening and reading file
void ReadFile(Graph& unorderedMappy) {
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
    vector<pair<int, string>> ordered = unorderedMappy.organize();

    int size = ordered.size();

    cout << "The most common complaint is: " << ordered[0].second << endl;
    cout << "With " << ordered[0].first << " calls" << endl;
    cout << "The least common complaint is: " << ordered[size-1].second << endl;
    cout << "With " << ordered[size-1].first << " calls" << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Runtime for Unordered Map: " << duration.count() << endl;
    return 0;
}
