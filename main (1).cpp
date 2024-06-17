#include <iostream>
#include <vector>

using namespace std;

double determinant(vector<vector<double>> matrix) {
    int n = matrix.size();
    if (n == 1) return matrix[0][0];
    if (n == 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    
    double det = 0;
    for (int i = 0; i < n; ++i) {
        vector<vector<double>> submatrix(n - 1, vector<double>(n - 1));
        for (int j = 1; j < n; ++j) {
            int k = 0;
            for (int l = 0; l < n; ++l) {
                if (l == i) continue;
                submatrix[j - 1][k] = matrix[j][l];
                ++k;
            }
        }
        det += matrix[0][i] * determinant(submatrix) * ((i % 2 == 0) ? 1 : -1);
    }
    return det;
}

vector<double> cramer(vector<vector<double>> A, vector<double> b) {
    int n = A.size();
    double detA = determinant(A);
    vector<double> x(n);
    
    for (int i = 0; i < n; ++i) {
        vector<vector<double>> Ai = A;
        for (int j = 0; j < n; ++j) {
            Ai[j][i] = b[j];
        }
        x[i] = determinant(Ai) / detA;
    }
    return x;
}

int main() {
    vector<vector<double>> A = {{5, 3, -2},
                                {2, 1, -1},
                                {3, -2, -3}};
    vector<double> b = {-1, 0, 2};
    
    vector<double> result = cramer(A, b);
    
    cout << "Решение системы методом Крамера: ";
    for (double xi : result) {
        cout << xi << " ";
    }
    cout << endl;
    return 0;
}
