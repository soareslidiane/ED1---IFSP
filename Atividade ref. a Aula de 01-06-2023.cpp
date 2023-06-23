#include <iostream>
#include <vector>

void exibirVetor(const std::vector<int>& vetor) {
    for (int elemento : vetor) {
        std::cout << elemento << " ";
    }
    std::cout << std::endl;
}

void insertionSort(std::vector<int>& vetor) {
    int n = vetor.size();
    for (int i = 1; i < n; ++i) {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}


int particionar(std::vector<int>& vetor, int esquerda, int direita) {
    int pivo = vetor[direita];
    int i = esquerda - 1;

    for (int j = esquerda; j < direita; ++j) {
        if (vetor[j] <= pivo) {
            i++;
            std::swap(vetor[i], vetor[j]);
        }
    }

    std::swap(vetor[i + 1], vetor[direita]);
    return i + 1;
}

void quickSort(std::vector<int>& vetor, int esquerda, int direita) {
    if (esquerda < direita) {
        int indicePivo = particionar(vetor, esquerda, direita);
        quickSort(vetor, esquerda, indicePivo - 1);
        quickSort(vetor, indicePivo + 1, direita);
    }
}


void selectionSort(std::vector<int>& vetor) {
    int n = vetor.size();
    for (int i = 0; i < n - 1; ++i) {
        int indiceMenor = i;
        for (int j = i + 1; j < n; ++j) {
            if (vetor[j] < vetor[indiceMenor]) {
                indiceMenor = j;
            }
        }
        std::swap(vetor[i], vetor[indiceMenor]);
    }
}


void merge(std::vector<int>& vetor, int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    std::vector<int> vetorEsquerda(n1);
    std::vector<int> vetorDireita(n2);

    for (int i = 0; i < n1; ++i) {
        vetorEsquerda[i] = vetor[esquerda + i];
    }
    for (int j = 0; j < n2; ++j) {
        vetorDireita[j] = vetor[meio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = esquerda;

    while (i < n1 && j < n2) {
        if (vetorEsquerda[i] <= vetorDireita[j]) {
            vetor[k] = vetorEsquerda[i];
            i++;
        } else {
            vetor[k] = vetorDireita[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = vetorEsquerda[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = vetorDireita[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& vetor, int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        mergeSort(vetor, esquerda, meio);
        mergeSort(vetor, meio + 1, direita);
        merge(vetor, esquerda, meio, direita);
    }
}


void shellSort(std::vector<int>& vetor) {
    int n = vetor.size();
    for (int intervalo = n / 2; intervalo > 0; intervalo /= 2) {
        for (int i = intervalo; i < n; ++i) {
            int chave = vetor[i];
            int j = i;
            while (j >= intervalo && vetor[j - intervalo] > chave) {
                vetor[j] = vetor[j - intervalo];
                j -= intervalo;
            }
            vetor[j] = chave;
        }
    }
}

int main() {
    std::vector<int> vetor = {9, 2, 7, 5, 1, 6, 8, 3, 4};

    std::cout << "Vetor original: ";
    exibirVetor(vetor);

    std::cout << "Insertion Sort: ";
    insertionSort(vetor);
    exibirVetor(vetor);

    vetor = {9, 2, 7, 5, 1, 6, 8, 3, 4}; // Resetando o vetor

    std::cout << "Quick Sort: ";
    quickSort(vetor, 0, vetor.size() - 1);
    exibirVetor(vetor);

    vetor = {9, 2, 7, 5, 1, 6, 8, 3, 4}; // Resetando o vetor

    std::cout << "Selection Sort: ";
    selectionSort(vetor);
    exibirVetor(vetor);

    vetor = {9, 2, 7, 5, 1, 6, 8, 3, 4}; // Resetando o vetor

    std::cout << "Merge Sort: ";
    mergeSort(vetor, 0, vetor.size() - 1);
    exibirVetor(vetor);

    vetor = {9, 2, 7, 5, 1, 6, 8, 3, 4}; // Resetando o vetor

    std::cout << "Shell Sort: ";
    shellSort(vetor);
    exibirVetor(vetor);

    return 0;
}
