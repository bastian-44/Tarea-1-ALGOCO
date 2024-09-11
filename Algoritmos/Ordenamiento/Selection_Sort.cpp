// C++ program for implementation of
// selection sort
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <functional>
#include <chrono>
#include <algorithm>



using namespace std;

// Function for Selection sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}


vector<int> readNumbersFromFile(const string& filename) {
    
    vector<int> numbers;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: No se pudo abrir el archivo." << endl;
        return numbers;
    }

    string line;
    if (getline(file, line)) {
        istringstream iss(line);
        int number;
        while (iss >> number) {
            numbers.push_back(number);
        }
    }

    file.close();
    return numbers;
}

double count_time_in_function(function<void()> func) {
    auto start = chrono::high_resolution_clock::now();
    func();
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1e9 ;

}

// Vector to array

int arrayConverter(vector<int> v) {
    int n = v.size();
     
    // Printing original vector
    cout<<"Vector: ";
    for (int i: v) {
        cout << i << ' ';
    }
    cout<<endl;
  
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = v[i];
    }
     
    // Printing the array
    cout<<"Array: ";
    for (int i: arr) {
        cout << i << ' ';
    }
    cout<<endl;
  
    return arr;
}

// Driver code
int main()
{
    vector<int> random_lst = readNumbersFromFile("data/random_list.txt");
    vector<int> partially_sorted_lst = readNumbersFromFile("data/partially_sorted_list.txt");
    vector<int> nearly_sorted_lst = readNumbersFromFile("data/nearly_sorted_list.txt");
    
    arrayConverter(random_lst);

    double selection_time_1 = count_time_in_function([&]() {
        bubbleSort(random_lst);
    });
    cout << "Selection Sort Time for Random List: " << selection_time_1 << " segundos " << endl;

    double selection_time_2 = count_time_in_function([&]() {
        bubbleSort(partially_sorted_lst);
    });
    double selection_time_3 = count_time_in_function([&]() {
        bubbleSort(nearly_sorted_lst);
    });
    

    cout << "Selection Sort Time for Random List: " << selection_time_1 << " segundos " << endl;
    cout << "Selection Sort Time for Partially Sorted List: " << selection_time_2 << " segundos " << endl;
    cout << "Selection Sort Time for Nearly Sorted List: " << selection_time_3 << " segundos " << endl;
    return 0;
}


// Obtenido en: https://www.geeksforgeeks.org/selection-sort-algorithm-2/