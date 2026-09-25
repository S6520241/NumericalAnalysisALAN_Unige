#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Funzione per calcolare il polinomio di Taylor per exp(x) in modo iterativo.
double taylorExponential(double x, int N) {
    double sum = 1.0;   // Inizialmente f_N(x) = 1 (n=0)
    double term = 1.0;  // Il termine corrente (x^n/n!)
    for (int n = 1; n <= N; n++) {
        term *= x / n;  // Aggiorna il termine in modo efficiente
        sum += term;
    }
    return sum;
}

// Funzione per il calcolo e la visualizzazione degli errori assoluto e relativo.
void computeErrors(double approx, double actual) {
    double absError = fabs(actual - approx);
    double relError = fabs(absError / actual);
    cout << "    Errore assoluto: " << absError << "\n";
    cout << "    Errore relativo:  " << relError << "\n";
}

// Funzione template per calcolare la precisione di macchina (epsilon)
template <typename T>
T computeMachineEpsilon() {
    T eps = 1.0;
    while (1.0 + eps > 1.0) {
        eps /= 2.0;
    }
    return eps * 2.0;
}

int main() {
    // Impostazione della precisione per l'output
    cout << fixed << setprecision(10);

    // Dati del primo componente (modificare d0 e d1 in base alla matricola effettiva)
    int d0 = 1, d1 = 4;

    // -------------------------
    // Parte 1: Calcoli Numerici
    // -------------------------
    cout << "Parte 1: Calcoli numerici - Dimostrazione della non-associativita'\n";
    
    // b e c sono costanti
    double b = (d1 + 1) * pow(10.0, 20);
    double c = -b;
    
    // Ciclo per i = 0,1,...,6 per calcolare a e poi (a+b)+c e a+(b+c)
    for (int i = 0; i <= 6; i++) {
        double a = (d0 + 1) * pow(10.0, i);
        double result1 = (a + b) + c;
        double result2 = a + (b + c);
        cout << "\nPer i = " << i << " (a = " << a << "):\n";
        cout << "  (a + b) + c = " << result1 << "\n";
        cout << "  a + (b + c) = " << result2 << "\n";
    }

    cout << "\n---------------------------------------------------\n";

    // ----------------------------------------
    // Parte 2: Approssimazione con Taylor
    // ----------------------------------------
    cout << "\nParte 2: Polinomio di Taylor per exp(x)\n";

    // Algoritmo 1: Calcolo diretto di exp(x)
    double xValues[] = {0.5, 30.0, -0.5, -30.0};
    int NValues[] = {3, 10, 50, 100, 150};

    cout << "\nAlgoritmo 1: Calcolo di exp(x) tramite polinomio di Taylor\n";
    for (double x : xValues) {
        cout << "\nValore di x = " << x << "\n";
        for (int N : NValues) {
            double approx = taylorExponential(x, N);
            double actual = exp(x);
            cout << "  N = " << N << ":\n";
            cout << "    Taylor approssimato: " << approx << "\n";
            cout << "    exp(x) reale:        " << actual << "\n";
            computeErrors(approx, actual);
        }
    }

    // Algoritmo 2: Calcolo di exp(-x) tramite il reciproco di f_N(x) per x positivo
    cout << "\nAlgoritmo 2: Approssimazione di exp(-x) tramite il reciproco del polinomio di Taylor\n";
    double posValues[] = {0.5, 30.0}; // Per x = 0.5 e x = 30
    for (double x : posValues) {
        cout << "\nCalcolo di exp(-" << x << ") utilizzando 1/f_N(" << x << "):\n";
        for (int N : NValues) {
            double approxReciprocal = 1.0 / taylorExponential(x, N);
            double actual = exp(-x);
            cout << "  N = " << N << ":\n";
            cout << "    Reciproco (1/Taylor): " << approxReciprocal << "\n";
            cout << "    exp(-x) reale:        " << actual << "\n";
            computeErrors(approxReciprocal, actual);
        }
    }

    cout << "\n---------------------------------------------------\n";

    // -----------------------------
    // Parte 3: Precisione di Macchina
    // -----------------------------
    cout << "\nParte 3: Calcolo della precisione di macchina\n";
    float epsSingle = computeMachineEpsilon<float>();
    double epsDouble = computeMachineEpsilon<double>();
    cout << "Precisione in singola precisione (float):  " << epsSingle << "\n";
    cout << "Precisione in doppia precisione (double): " << epsDouble << "\n";

    return 0;
}
