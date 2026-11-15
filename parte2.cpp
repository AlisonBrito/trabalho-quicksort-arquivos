#include <iostream>
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

    FILE *arquivo = fopen("numeros.txt", "r");

    if (arquivo == NULL)
    {
        cout << "Erro ao abrir arquivo";
        return 1;
    }

    int vet[10];
    int qtd = 0;

    while (qtd < 10 && fscanf(arquivo, "%d", &vet[qtd]) == 1)
    {
        qtd++;
    }

    fclose(arquivo);

    if (qtd != 10)
    {
        cout << "O arquivo precisa conter 10 numeros";
        return 1;
    }

    cout << "Vetor original:\n";
    exibirVetor(vet, qtd);

    quickSort(vet, 0, qtd - 1);

    cout << "\nVetor ordenado:\n";
    exibirVetor(vet, qtd);

    return 0;
}