#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
void exibirVetor(T vet[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        cout << vet[i] << "\t";
    }
    cout << endl;
}

template <typename T>
int ordenar(T vet[], int inicio, int fim)
{
    T pivo = vet[fim];

    int i = inicio - 1;

    for (int j = inicio; j < fim; j++)
    {
        if (vet[j] <= pivo)
        {
            i++;

            T aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
        }
    }

    T aux = vet[i + 1];
    vet[i + 1] = vet[fim];
    vet[fim] = aux;

    return i + 1;
}

template <typename T>
void quickSort(T vet[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int pivo = ordenar(vet, inicio, fim);

        quickSort(vet, inicio, pivo - 1); // para o lado esquerdo
        quickSort(vet, pivo + 1, fim);    // para o lado direito
    }
}

int main()
{
    srand(time(NULL));

    int vet[10];

    for (int i = 0; i < 10; i++)
    {
        vet[i] = rand() % 100 + 1;
    }

    cout << "Vetor original:\n";
    exibirVetor(vet, 10);

    quickSort(vet, 0, 9);

    cout << "\nVetor ordenado:\n";
    exibirVetor(vet, 10);

    return 0;
}