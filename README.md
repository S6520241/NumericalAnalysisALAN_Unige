# ProgettoALAN_Unige

# Calcolo Numerico e Algebra Lineare in C++

Questo progetto implementa e analizza algoritmi numerici in C++, focalizzandosi sugli effetti dell'aritmetica a precisione finita e sulla risoluzione di sistemi lineari complessi. 

Il codice esplora la stabilità numerica, il condizionamento delle matrici e l'impatto degli errori di arrotondamento, dimostrando un'applicazione pratica dello standard IEEE 754 per i numeri in virgola mobile[cite: 6].

## Struttura del Progetto

Il progetto è diviso in due moduli principali:

### 1. Analisi degli Errori e Precisione di Macchina (`errori.cpp`)
Questo modulo valuta il comportamento dell'hardware e degli algoritmi in condizioni estreme:
* **Cancellazione Numerica:** Dimostrazione pratica della non-associatività delle operazioni matematiche (es. `(a + b) + c` vs `a + (b + c)`) in presenza di numeri con ordini di grandezza molto diversi.
* **Polinomio di Taylor:** Approssimazione iterativa di $e^x$[cite: 8]. Implementa logiche condizionali per ridurre gli errori: ad esempio, per valori di $x$ negativi viene utilizzata l'identità $e^{-x} = 1/e^x$ per evitare la cancellazione numerica causata dai segni alternati[cite: 6, 8].
* **Precisione di Macchina:** Calcolo iterativo dell'epsilon di macchina per i tipi `float` (circa 7 cifre significative, $1.19 \times 10^{-7}$) e `double` (circa 15 cifre significative, $2.22 \times 10^{-16}$)

### 2. Risoluzione di Sistemi Lineari (`sistemiLineari.cpp`)
Questo modulo implementa la risoluzione di sistemi lineari $Ax = b$ tramite l'algoritmo di **Eliminazione Gaussiana con pivoting parziale**, garantendo stabilità numerica ed evitando divisioni per valori prossimi allo zero.
L'algoritmo è stato collaudato calcolando la norma infinito e analizzando il condizionamento su diverse tipologie di matrici, tra cui:
* Matrici di test standard (4x4).
* **Matrice di Pascal (10x10):** Utilizzata per testare la stabilità dell'algoritmo in presenza di valori in rapida crescita (fattoriali).
* **Matrice Tridiagonale (51x51):** Matrice a dominanza diagonale utilizzata per dimostrare l'efficienza e l'accuratezza del metodo su matrici ben condizionate di dimensioni maggiori.
* **Perturbazione del termine noto:** Analisi della variazione della soluzione in risposta a una perturbazione del vettore $b$, confermando l'efficacia del pivoting parziale.

## Tecnologie e Competenze
* **Linguaggio:** C++
* **Concetti Teorici:** Standard IEEE 754, Eliminazione di Gauss, Pivoting Parziale, Condizionamento delle Matrici, Complessità Computazionale

## Compilazione ed Esecuzione
I sorgenti sono stati sviluppati utilizzando le librerie standard del C++ (`<iostream>`, `<cmath>`, `<iomanip>`)

Per compilare ed eseguire i file separatamente da terminale:
```bash
# Compilazione ed esecuzione del modulo sugli errori
g++ -o errori src/errori.cpp
./errori

# Compilazione ed esecuzione del modulo sui sistemi lineari
g++ -o sistemi src/sistemiLineari.cpp
./sistemi
```
____________________________________________________________________

# ProgettoALAN_Unige

# Numerical Analysis and Linear Algebra in C++

This project implements and analyzes numerical algorithms in C++, focusing on the effects of finite precision arithmetic and the resolution of complex linear systems. 

The code explores numerical stability, matrix conditioning, and the impact of rounding errors, demonstrating a practical application of the IEEE 754 standard for floating-point numbers.

## Project Structure

The project is divided into two main modules:

### 1. Error Analysis and Machine Precision (`errori.cpp`)
This module evaluates hardware and algorithm behavior under extreme conditions:
* **Numerical Cancellation:** Practical demonstration of the non-associativity of mathematical operations (e.g., `(a + b) + c` vs `a + (b + c)`) when dealing with numbers of vastly different magnitudes.
* **Taylor Polynomial:** Iterative approximation of $e^x$. It implements conditional logic to reduce errors: for example, for negative values of $x$, the identity $e^{-x} = 1/e^x$ is used to prevent numerical cancellation caused by alternating signs.
* **Machine Precision:** Iterative calculation of machine epsilon for `float` (approx. 7 significant digits, $1.19 \times 10^{-7}$) and `double` (approx. 15 significant digits, $2.22 \times 10^{-16}$) types.

### 2. Linear Systems Resolution (`sistemiLineari.cpp`)
This module implements the resolution of linear systems $Ax = b$ using the **Gaussian Elimination with partial pivoting** algorithm, ensuring numerical stability and avoiding divisions by values close to zero.
The algorithm was tested by calculating the infinity norm and analyzing the conditioning on various types of matrices, including:
* Standard test matrices (4x4).
* **Pascal Matrix (10x10):** Used to test the algorithm's stability in the presence of rapidly growing values (factorials).
* **Tridiagonal Matrix (51x51):** A diagonally dominant matrix used to demonstrate the method's efficiency and accuracy on well-conditioned, larger matrices.
* **Constant Term Perturbation:** Analysis of the solution's variation in response to a perturbation of vector $b$, confirming the effectiveness of partial pivoting.

## Technologies and Skills
* **Language:** C++
* **Theoretical Concepts:** IEEE 754 Standard, Gaussian Elimination, Partial Pivoting, Matrix Conditioning, Computational Complexity.

## Compilation and Execution
The source code was developed using C++ standard libraries (`<iostream>`, `<cmath>`, `<iomanip>`).

To compile and execute the files separately from the terminal:
```bash
# Compilation and execution of the error module
g++ -o errori src/errori.cpp
./errori

# Compilation and execution of the linear systems module
g++ -o sistemi src/sistemiLineari.cpp
./sistemi
