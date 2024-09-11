#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <functional>
#include <chrono>

using namespace std;

void sort(vector<int>& arr) {
    sort(arr.begin(), arr.end());
}

vector<int> readVectorFromFile(const string& filename) {
    ifstream infile(filename);
    vector<int> arr;
    int number;

    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            istringstream iss(line);
            while (iss >> number) {
                arr.push_back(number);
            }
        }
        infile.close();
    } else {
        cerr << "Unable to open file: " << filename << endl;
    }
    
    return arr;
}

double count_time_in_function(function<void()> func) {
    auto start = chrono::high_resolution_clock::now();
    func();
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1e9 ;

}

// Driver code
int main()
{
    vector<int> random_lst = readVectorFromFile("data/random_list.txt");
    vector<int> partially_sorted_lst = readVectorFromFile("data/partially_sorted_list.txt");
    vector<int> nearly_sorted_lst = readVectorFromFile("data/nearly_sorted_list.txt");

    

    double sort_time_1 = count_time_in_function([&]() {
        sort(random_lst);
    });
    double sort_time_2 = count_time_in_function([&]() {
        sort(partially_sorted_lst);
    });
    double sort_time_3 = count_time_in_function([&]() {
        sort(nearly_sorted_lst);
    });
    cout << "Sort Time for Random List: " << sort_time_1 << " segundos " << endl;
    cout << "Sort Time for Partially Sorted List: " << sort_time_2 << " segundos " << endl;
    cout << "Sort Time for Nearly Sorted List: " << sort_time_3 << " segundos " << endl;
    return 0;
}
