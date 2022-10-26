#include <iostream>
#include <fstream>
using namespace std;

typedef struct Tveiculo // struct do tipo Tveiculo
{
    string modelo, marca, tipo, gas, cambio, direcao, cor, placa;
    int ano, km, portas;
    float potencia, valor;
};
Tveiculo *busca(Tveiculo *bd[], int tam, string placa)
{
    int loc = 0;
    for (int i = 0; i < tam; i++)
    {
        if (bd[i]->placa == placa)
        {
            cout << "Veiculo Encontrado!" << endl;
            cout << bd[i]->modelo << " ";
            cout << bd[i]->marca << " ";
            cout << bd[i]->tipo << " ";
            cout << bd[i]->ano << " ";
            cout << bd[i]->km << " ";
            cout << bd[i]->potencia << " ";
            cout << bd[i]->gas << " ";
            cout << bd[i]->cambio << " ";
            cout << bd[i]->direcao << " ";
            cout << bd[i]->cor << " ";
            cout << bd[i]->portas << " ";
            cout << bd[i]->placa << " ";
            cout << bd[i]->valor << endl;
            loc = 1;
        }
    }
    if (loc == 0)
    {
        cout << "Veiculo nao encontrado." << endl;
    }
}

int main()
{
    ifstream carrin("BDVeiculos2.txt");
    Tveiculo *bd[50]; // ponteiro de Tveiculo
    int tam = 0;
    if (carrin.is_open())
    {
        cout << "ABRIU" << endl;
        while (!carrin.eof())
        {
            bd[tam] = new Tveiculo; // cria a struct que sera apontada pelo vetor de ponteiro bd
            carrin >> bd[tam]->modelo;
            carrin >> bd[tam]->marca;
            carrin >> bd[tam]->tipo;
            carrin >> bd[tam]->ano;
            carrin >> bd[tam]->km;
            carrin >> bd[tam]->potencia;
            carrin >> bd[tam]->gas;
            carrin >> bd[tam]->cambio;
            carrin >> bd[tam]->direcao;
            carrin >> bd[tam]->cor;
            carrin >> bd[tam]->portas;
            carrin >> bd[tam]->placa;
            carrin >> bd[tam]->valor;
            tam++;
        }
        carrin.close();
        for (int i = 0; i < tam; i++)
        {
            cout << bd[i]->modelo << " ";
            cout << bd[i]->marca << " ";
            cout << bd[i]->tipo << " ";
            cout << bd[i]->ano << " ";
            cout << bd[i]->km << " ";
            cout << bd[i]->potencia << " ";
            cout << bd[i]->gas << " ";
            cout << bd[i]->cambio << " ";
            cout << bd[i]->direcao << " ";
            cout << bd[i]->cor << " ";
            cout << bd[i]->portas << " ";
            cout << bd[i]->placa << " ";
            cout << bd[i]->valor << endl;
        }

        // atribuindo NULL aos espaços livres
        for (int i = tam; i < 50; i++)
        {
            bd[i] = NULL;
        }

        // Removendo as structs da memória
        for (int i = 0; i < tam; i++)
        {
            delete (bd[i]);
        }
        char a;
        cout << "Deseja realizar uma busca? [S/n]" << endl;
        cin >> a;
        while (a != 'A' + 50 && a != 'A' + 18 && a != 'A' + 45 && a != 'A' + 13) // A = 65 na tabela ASCII
        {
            cout << "Entrada inválida, tente novamente." << endl
                 << "[S/n]" << endl;
            cin >> a;
        }
        if (a == 's' || a == 'S')
        {
            string plate;
            cout << "Informe a placa do veiculo: ";
            cin >> plate;
            busca(bd, tam, plate);
        }
    }
    else
        cout << "N ABRIU" << endl;
}