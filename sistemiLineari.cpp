#include <iostream>
#include <cmath> 
using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

struct Matrix {
    double data[MAX_ROWS][MAX_COLS];
    int rows;
    int cols;

    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// Funzione per calcolare la norma infinito
double normInf(const Matrix& M) {
    double maxEl = 0;
    for (int i = 0; i < M.rows; i++) {
        double sum = 0;
        for (int j = 0; j < M.cols; j++) {
            sum += abs(M.data[i][j]);
        }
        if (sum > maxEl) maxEl = sum;
    }
    return maxEl;   
}

// Matrice di Pascal
double fact(int n) {
    double result = 1;
    for (int i = 2; i <= n; i++) result *= i;
    return result;
}

double pascal(int i, int j) {
    return fact(i + j - 2) / (fact(i - 1) * fact(j - 1));
}

Matrix matrixPascal(int n) {
    Matrix P;
    P.rows = P.cols = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            P.data[i][j] = pascal(i + 1, j + 1);
        }
    }
    return P;
}

// Matrice tridiagonale
Matrix matrixTridiagonal(int n) {
    Matrix T;
    T.rows = T.cols = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) T.data[i][j] = 2;
            else if (abs(i - j) == 1) T.data[i][j] = -1;
            else T.data[i][j] = 0;
        }
    }
    return T;
}

// Calcolo del termine noto
Matrix CalcolodelTermineNoto(const Matrix& A, const Matrix& x) {
    Matrix b;
    b.rows = A.rows;
    b.cols = 1;
    for (int i = 0; i < A.rows; i++) {
        b.data[i][0] = 0;
        for (int j = 0; j < A.cols; j++) {
            b.data[i][0] += A.data[i][j] * x.data[j][0];
        }
    }
    return b;
}

// Eliminazione di Gauss con pivoting parziale
Matrix gaussElimination(Matrix A, Matrix b) {
    int n = A.rows;
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            if (abs(A.data[i][k]) > abs(A.data[k][k])) {
                for (int j = 0; j < n; j++) swap(A.data[k][j], A.data[i][j]);
                swap(b.data[k][0], b.data[i][0]);
            }
        }
        for (int i = k + 1; i < n; i++) {
            double factor = A.data[i][k] / A.data[k][k];
            for (int j = k; j < n; j++) {
                A.data[i][j] -= factor * A.data[k][j];
            }
            b.data[i][0] -= factor * b.data[k][0];
        }
    }
    Matrix x;
    x.rows = n;
    x.cols = 1;
    for (int i = n - 1; i >= 0; i--) {
        x.data[i][0] = b.data[i][0];
        for (int j = i + 1; j < n; j++) {
            x.data[i][0] -= A.data[i][j] * x.data[j][0];
        }
        x.data[i][0] /= A.data[i][i];
    }
    return x;
}

int main() {
    // A1
    Matrix A1 = {{{3, 1, -1, 0},
                   {0, 7, -3, 0},
                   {0, -3, 9, -2},
                   {0, 0, 4, -10}}, 4, 4};

    // A2
    Matrix A2 = {{{2, 4, -2, 0},
                   {1, 3, 0, 1},
                   {3, -1, 1, 2},
                   {0, -1, 2, 1}}, 4, 4};

    // Matrice Pascal
    Matrix P = matrixPascal(10);

    // Matrice Tridiagonale
    const int d0 = 1, d1 = 4; // Sostituire con le cifre del numero di matricola
    int nTr = 10 * (d1 + 1) + d0;
    Matrix T = matrixTridiagonal(nTr);

    // Vettore soluzione noto x
    Matrix x;
    x.rows = 4;
    x.cols = 1;
    for (int i = 0; i < x.rows; i++) x.data[i][0] = 1.0;

    // Calcolo del termine noto e risoluzione
    cout << "Norma infinito di A1: " << normInf(A1) << endl;
    cout << "Norma infinito di A2: " << normInf(A2) << endl;
    cout << "Norma infinito di P: " << normInf(P) << endl;
    cout << "Norma infinito di T: " << normInf(T) << endl;

    Matrix b = CalcolodelTermineNoto(A1, x);
    cout << "Termine noto b (per A1): \n";
    b.print();

    Matrix solution = gaussElimination(A1, b);
    cout << "Soluzione del sistema Ax = b: \n";
    solution.print();

    // Calcolo del termine perturbato
    Matrix perturbation;
    perturbation.rows = b.rows;
    perturbation.cols = 1;
    for (int i = 0; i < b.rows; i++) {
        perturbation.data[i][0] = ((i % 2 == 0) ? -1 : 1) * 0.01 * normInf(b);
    }

    Matrix b_perturbato = b;
    for (int i = 0; i < b.rows; i++) {
        b_perturbato.data[i][0] += perturbation.data[i][0];
    }

    cout << "Termine noto perturbato b': \n";
    b_perturbato.print();

    Matrix solution_perturbata = gaussElimination(A1, b_perturbato);
    cout << "Soluzione del sistema Ax = b' (con perturbazione): \n";
    solution_perturbata.print();

    return 0;
}
