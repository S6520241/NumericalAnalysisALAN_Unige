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
