5da#include <iostream>
#include <vector>
#include <fstream>
#include <random>

using namespace std;

// Función para generar una matriz con dimensiones mxn y valores aleatorios
vector<vector<int>> generate_matrix(int rows, int cols) {
    vector<vector<int>> matrix(rows, vector<int>(cols));
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100); // Valores entre 1 y 100

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = dis(gen);
        }
    }
    return matrix;
}

// Función para guardar una matriz en un archivo .txt
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

// Función principal para generar y guardar dos matrices
int main() {
    int m, n;
    
    // Entrada de las dimensiones m y n
    cout << "Introduce el número de filas de la primera matriz (m): ";
    cin >> m;
    cout << "Introduce el número de columnas de la primera matriz (n): ";
    cin >> n;
    
    // Generar la primera matriz (m x n)dat
    vector<vector<int>> A = generate_matrix(m, n);
    save_matrix_to_file(A, "data/matrix_A.txt");
    
    // Generar la segunda matriz (n x m)
    vector<vector<int>> B = generate_matrix(n, m);
    save_matrix_to_file(B, "data/matrix_B.txt");

    cout << "Matrices generadas y guardadas en 'matrix_A.txt' y 'matrix_B.txt'." << endl;

    return 0;
}