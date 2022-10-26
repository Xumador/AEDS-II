#include <iostream>
#include <fstream>
using namespace std;

typedef struct Tveiculo
{
    string modelo, marca, tipo, comb, camb, dir, cor, placa;
    int ano, km, port;
    float pot, valor;
};
Tveiculo *busca(Tveiculo *bd[], int tam, string placa)
{
    string a;
    cin >> a;
    for (int i = 0; i < tam; i++)
    {
        if (bd[i]->placa == a)
            return bd[i];
    }
    return NULL;
}
int main(int argc, char **argv)
{
    string a,remove;
    int tam = 0, opcao;
    ifstream myfile("BDVeiculos2.txt");
    Tveiculo *bd[50];
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            bd[tam] = new Tveiculo;
            myfile >> bd[tam]->modelo;
            myfile >> bd[tam]->marca;
            myfile >> bd[tam]->tipo;
            myfile >> bd[tam]->ano;
            myfile >> bd[tam]->km;
            myfile >> bd[tam]->pot;
            myfile >> bd[tam]->comb;
            myfile >> bd[tam]->camb;
            myfile >> bd[tam]->dir;
            myfile >> bd[tam]->cor;
            myfile >> bd[tam]->port;
            myfile >> bd[tam]->placa;
            myfile >> bd[tam]->valor;

            tam++;
        }
        myfile.close();
         cout << "Escolha uma opção: "<< endl;
         cout << "Incluir veículo (1)" << endl;
         cout << "Fazer busca pela placa (2)" << endl;
         cout << "Fazer busca dos 10 veículos mais próximos (3)" << endl;
         cin >> opcao;
        /*for (int i = 0; i < tam; i++){
            cout << bd[i]->modelo << " ";
            cout << bd[i]->marca << " ";
            cout << bd[i]->tipo << " ";
            cout << bd[i]->ano << " ";
            cout << bd[i]->km << " ";
            cout << bd[i]->pot << " ";
            cout << bd[i]->comb << " ";
            cout << bd[i]->camb << " ";
            cout << bd[i]->dir << " ";
            cout << bd[i]->cor << " ";
            cout << bd[i]->port << " ";
            cout << bd[i]->placa << " ";
            cout << bd[i]->valor <<".00" << endl;
        }
*/
        if (opcao == 2)
        {
            cout << "Informe a placa do veículo: " <<endl;
            Tveiculo *p = busca(bd, tam, a);
            if (p)
            {
                cout << "Veiculo encontrado" << endl;
                cout << p->marca << " " << p->modelo << " " << p->tipo << " " << p->ano << " " << p->km << " " << p->pot << " " << p->comb << " " << p->camb << " " << p->dir << " " << p->cor << " "
                     << p->port << " " << p->placa << " " << p->valor<< endl;
                cout << "Deseja remover?" << endl;
            }
            else
                cout << "Veiculo não encontrado" << endl;
        }
        // Apontando os espaços vazios
        for (int i = tam; i < 50; i++)
            bd[i] = NULL;

        // Removendo structs da memória
        for (int i = 0; i < tam; i++)
            delete (bd[i]);
    }
    else
        cout << "Unable to open file";
}