#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <iostream>
#include <fstream>

using namespace std;

void save_list_to_file(const vector<int>& lst, const string& filename) {
    ofstream outfile(filename, ios::app); // abre el archivo en modo append
    for (int num : lst) {
        outfile << num << " ";
    }
    outfile << endl;
    outfile.close();
}

vector<int> generate_random_list(int size) {
        vector<int> lst(size);
        iota(lst.begin(), lst.end(), 0); // Rellena con 0, 1, 2, ..., size-1
        shuffle(lst.begin(), lst.end(), mt19937{random_device{}()});
        save_list_to_file(lst, "data/random_list.txt");
        return lst;
    };

vector<int> generate_partially_sorted_list(int size, double sorted_fraction) {
    int sorted_size = static_cast<int>(size * sorted_fraction);
    vector<int> sorted_part(sorted_size);
    iota(sorted_part.begin(), sorted_part.end(), 0);
0
    vector<int> random_part(size - sorted_size);
    iota(random_part.begin(), random_part.end(), sorted_size);
    shuffle(random_part.begin(), random_part.end(), mt19937{random_device{}()});

    sorted_part.insert(sorted_part.end(), random_part.begin(), random_part.end());
    save_list_to_file(sorted_part, "data/partially_sorted_list.txt");  
    return sorted_part;
}

vector<int> generate_nearly_sorted_list(int size, int num_disruptions) {
    vector<int> lst(size);
    iota(lst.begin(), lst.end(), 0);

    for (int i = 0; i < num_disruptions; ++i) {
        int a = rand() % size;
        int b = rand() % size;
        swap(lst[a], lst[b]);
    }
    save_list_to_file(lst, "data/nearly_sorted_list.txt");
    return lst;
}

int main() {
    int count; float sorted_fraction;
    cin >> count;
    cin >> sorted_fraction;
    generate_random_list(count);
    generate_partially_sorted_list(count, sorted_fraction);
    generate_nearly_sorted_list(count, count / 10);
    return 0;
}