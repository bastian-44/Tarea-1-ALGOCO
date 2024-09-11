#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <functional>
#include <chrono>

using namespace std;

// Función para leer una matriz desde un archivo .txt
vector<vector<int>> read_matrix_from_file(const string& filename, int& rows, int& cols) {
    ifstream infile(filename);
    vector<vector<int>> matrix;
    string line;
    rows = 0;
    
    while (getline(infile, line)) {
        vector<int> row;
        stringstream ss(line);
        int num;
        while (ss >> num) {
            row.push_back(num);
        }
        if (!row.empty()) {
            cols = row.size();
            matrix.push_back(row);
            ++rows;
        }
    }
    infile.close();
    return matrix;
}

// Función para multiplicar dos matrices de manera cúbica
vector<vector<int>> multiply_matrices(const vector<vector<int>>& A, const vector<vector<int>>& B, int m, int n, int p) {
    vector<vector<int>> result(m, vector<int>(p, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

// Función para guardar el resultado en un archivo .txt
void save_matrix_to_file(const vector<vector<int>>& matrix, const string& filename) {
    ofstream outfile(filename);
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            outfile << elem << " ";
        }
        outfile << endl;
    }
    outfile.close();
}




int main() {
    int m, n, p;

    // Leer la primera matriz desde "matrix_A.txt"
    vector<vector<int>> A = read_matrix_from_file("data/matrix_A.txt", m, n); // m x n

    // Leer la segunda matriz desde "matrix_B.txt"
    int rows_B, cols_B;
    vector<vector<int>> B = read_matrix_from_file("data/matrix_B.txt", rows_B, cols_B); // n x p

    if (A.empty() || B.empty()) {
        cout << "Error: una o ambas matrices no se pudieron cargar correctamente." << endl;
        return 1;
    }

    // Verificar compatibilidad de las matrices para multiplicación
    if (n != rows_B) {
        cout << "Error: las dimensiones no son compatibles para la multiplicación." << endl;
        return 1;
    }

    // Actualizar p con el número de columnas de B
    p = cols_B;

    // Multiplicar las matrices
    auto start = chrono::high_resolution_clock::now();
    vector<vector<int>> result = multiply_matrices(A, B, m, n, p);
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1e9;

    // Guardar el resultado en "matrix_result.txt"
    save_matrix_to_file(result, "matrix_result.txt");

    cout << "Multiplicación realizada. Resultado guardado en 'matrix_result.txt'." << endl;

    cout << "Tiempo de ejecución: " << time_taken << " segundos." << endl;
    return 0;
}