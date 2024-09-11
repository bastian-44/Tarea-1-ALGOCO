#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <functional>
#include <chrono>
using namespace std;


int partition(vector<int>& arr, int low, int high) {
  
    // Choose the pivot
    int pivot = arr[high];
  
    // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[;ow..high] and move all smaller
    // elements on left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // Move pivot after smaller elements and
    // return its position
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

// The QuickSort function implementation
void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {
      
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
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
    int n = random_lst.size();
    vector<int> partially_sorted_lst = readVectorFromFile("data/partially_sorted_list.txt");
    int n2 = partially_sorted_lst.size();
    vector<int> nearly_sorted_lst = readVectorFromFile("data/nearly_sorted_list.txt");
    int n3 = nearly_sorted_lst.size();

    auto start = chrono::high_resolution_clock::now();
    quickSort(random_lst, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1e9 ;

    cout << time_taken << " seconds" << endl;

    auto start2 = chrono::high_resolution_clock::now();
    quickSort(partially_sorted_lst, 0, n2 - 1);
    auto end2 = chrono::high_resolution_clock::now();
    double time_taken2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count() / 1e9 ;

    cout << time_taken2 << " seconds" << endl;

    auto start3 = chrono::high_resolution_clock::now();
    quickSort(nearly_sorted_lst, 0, n3 - 1);   
    auto end3 = chrono::high_resolution_clock::now();
    double time_taken3 = chrono::duration_cast<chrono::nanoseconds>(end3 - start3).count() / 1e9 ;

    cout << time_taken3 << " seconds" << endl;
}

// https://www.geeksforgeeks.org/quick-sort-algorithm/