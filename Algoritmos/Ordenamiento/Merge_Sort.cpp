#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <functional>
#include <chrono>


using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(vector<int>& arr, int left, 
                     int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Function to print a vector
void printVector(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
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
    return chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1e9;

}

// Driver code
int main()
{
    vector<int> random_lst = readVectorFromFile("data/random_list.txt");
    vector<int> partially_sorted_lst = readVectorFromFile("data/partially_sorted_list.txt");
    vector<int> nearly_sorted_lst = readVectorFromFile("data/nearly_sorted_list.txt");

    

    double merge_time_1 = count_time_in_function([&]() {
        mergeSort(random_lst, 0, random_lst.size() - 1);
    });
    double merge_time_2 = count_time_in_function([&]() {
        mergeSort(partially_sorted_lst, 0, partially_sorted_lst.size() - 1);
    });
    double merge_time_3 = count_time_in_function([&]() {
        mergeSort(nearly_sorted_lst, 0, nearly_sorted_lst.size() - 1);
    });

    cout << "Merge Sort Time for Random List: " << merge_time_1 << " segundos " << endl;
    cout << "Merge Sort Time for Partially Sorted List: " << merge_time_2 << " segundos" << endl;
    cout << "Merge Sort Time for Nearly Sorted List: " << merge_time_3 << " segundos" << endl;
    return 0;
}
