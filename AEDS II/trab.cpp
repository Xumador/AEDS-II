#include <iostream>
#include <fstream>
#include <limits.h>

using namespace std;

typedef struct Tveiculo
{
    string modelo, marca, tipo, comb, camb, dir, cor, placa;
    int ano, km, port;
    float pot, valor;
};
Tveiculo *busca(Tveiculo *bd[], int tam, string placa, int *index)
{
    for (int i = 0; i <= tam; i++)
    {
        if (bd[i]->placa == placa)
        {
            *index = i;
            return bd[i];
        }
    }
    return NULL;
}

void remove(Tveiculo *bd[], int tam, string placa)
{
    int index;

    busca(bd, tam, placa, &index);
    for (int i = index; i < tam; i++)
    {
        bd[i] = bd[i + 1];
    }
}

int insere(Tveiculo *bd[], int tam)
{
    string placa, dados;
    int dados_num;
    float dados_numF;
    cout << "Digite a placa: ";
    cin >> placa;
    if (tam == 50)
    {
        cout << "cheio";
        return -1;
    }
    for (int i = 0; i <= tam; i++)
    {
        if (placa == bd[i]->placa)
        {
            cout << "Veiculo já existe!" << endl;
            return -1;
        }
    }
    tam = tam + 1;
    bd[tam] = new Tveiculo;
    cout << "Digite o modelo do automovel: ";
    cin >> bd[tam]->modelo;
    cout << "Digite a marca do automovel: ";
    cin >> bd[tam]->marca;
    cout << "Digite o tipo do automovel: ";
    cin >> bd[tam]->tipo;
    cout << "Digite o ano do automovel: ";
    cin >> bd[tam]->ano;
    cout << "Digite o km do automovel: ";
    cin >> bd[tam]->km;
    cout << "Digite a potencia do motor do automovel: ";
    cin >> bd[tam]->pot;
    cout << "Digite qual o combustivel do automovel: ";
    cin >> bd[tam]->comb;
    cout << "Digite qual o cambio do automovel: ";
    cin >> bd[tam]->camb;
    cout << "Digite o tipo de direcao do automovel: ";
    cin >> bd[tam]->dir;
    cout << "Digite qual a cor do automovel: ";
    cin >> bd[tam]->cor;
    cout << "Digite qual numero de portas do automovel: ";
    cin >> bd[tam]->port;
    bd[tam]->placa = placa;
    cout << "Digite qual o valor do automovel: ";
    cin >> bd[tam]->valor;
    return 1;
}

Tveiculo *ordena(Tveiculo *bd[], int tam)
{
    Tveiculo *aux;
    Tveiculo *ord[50];
    for (int i = 0; i <= tam; i++)
    {
        ord[i] = bd[i];
    }
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam - i; j++)
        {
            if ((ord[j]->placa) > (ord[j + 1]->placa))
            {
                aux = ord[j];
                ord[j] = ord[j + 1];
                ord[j + 1] = aux;
            }
        }
    }
    for (int i = 0; i <= tam; i++)
    {
        cout << ord[i]->modelo << " ";
        cout << ord[i]->marca << " ";
        cout << ord[i]->tipo << " ";
        cout << ord[i]->ano << " ";
        cout << ord[i]->km << " ";
        cout << ord[i]->pot << " ";
        cout << ord[i]->comb << " ";
        cout << ord[i]->camb << " ";
        cout << ord[i]->dir << " ";
        cout << ord[i]->cor << " ";
        cout << ord[i]->port << " ";
        cout << ord[i]->placa << " ";
        cout << ord[i]->valor << ".00" << endl;
    }
    return *ord;
}

void *busca_valor(Tveiculo *bd[], int tam, int valor)
{
    int fit[tam];
    int i, j;
    int aux;
    int menor = INT_MAX;
    int menor_index = -1;

    for (int i = 0; i <= tam; i++)
    {
        fit[i] = abs(bd[i]->valor - valor);
    }

    for (i = 0; i < 10; i++)
    {

        for (j = 0; j <= tam; j++)
        {
            if (fit[j] < menor)
            {
                menor = fit[j];
                menor_index = j;
            }
        }
        fit[menor_index] = INT_MAX;
        cout << bd[menor_index]->modelo << " ";
        cout << bd[menor_index]->marca << " ";
        cout << bd[menor_index]->tipo << " ";
        cout << bd[menor_index]->ano << " ";
        cout << bd[menor_index]->km << " ";
        cout << bd[menor_index]->pot << " ";
        cout << bd[menor_index]->comb << " ";
        cout << bd[menor_index]->camb << " ";
        cout << bd[menor_index]->dir << " ";
        cout << bd[menor_index]->cor << " ";
        cout << bd[menor_index]->port << " ";
        cout << bd[menor_index]->placa << " ";
        cout << bd[menor_index]->valor << ".00" << endl;
        menor = INT_MAX;
    }
}
int main(int argc, char **argv)
{
    char removev;
    string a;
    int tam = 0, opcao, index;
    ifstream myfile("BD_veiculos_2.txt");
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
        tam--;
        myfile.close();
        cout << "Escolha uma opção: " << endl;
        cout << "Incluir veículo (1)" << endl;
        cout << "Fazer busca pela placa (2)" << endl;
        cout << "Ordenar pela placa (3)" << endl;
        cout << "Fazer busca por valor (4)" << endl;
        cout << "Parar (5)" << endl;
        do
        {
            cin >> opcao;
            switch (opcao)
            {
            case 1:

                if (insere(bd, tam) == -1)
                {
                    break;
                }
                tam++;
                for (int i = 0; i <= tam; i++)
                {
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
                    cout << bd[i]->valor << ".00" << endl;
                }
                break;
            case 2:
            {
                cout << "Informe a placa do veículo: " << endl;
                cin >> a;
                Tveiculo *p = busca(bd, tam, a, &index);
                if (p)
                {
                    cout << "Veiculo encontrado" << endl;
                    cout << p->marca << " " << p->modelo << " " << p->tipo << " " << p->ano << " " << p->km << " " << p->pot << " " << p->comb << " " << p->camb << " " << p->dir << " " << p->cor << " "
                         << p->port << " " << p->placa << " " << p->valor << endl;
                    cout << "Deseja remover?" << endl;
                    cin >> removev;
                    if (removev == 's')
                    {
                        if (busca(bd, tam, a, &index))
                        {
                            remove(bd, tam, a);
                            tam--;
                            for (int i = 0; i <= tam; i++)
                            {
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
                                cout << bd[i]->valor << ".00" << endl;
                            }
                        }
                    }
                }
                else
                    cout << "Veiculo não encontrado" << endl;
                    break;
            }
            case 3:
            {
                Tveiculo *ordenado = ordena(bd, tam);
                break;
            }
            case 4:
            {
                int valor;
                cout << "Digite um valor:" << endl;
                cin >> valor;
                busca_valor(bd, tam, valor);
            }
            }
            if (opcao != 5)
            {
                cout << endl;
                cout << "Escolha uma opção: " << endl;
                cout << "Incluir veículo (1)" << endl;
                cout << "Fazer busca pela placa (2)" << endl;
                cout << "Ordenar pela placa (3)" << endl;
                cout << "Fazer busca por valor (4)" << endl;
                cout << "Parar (5)" << endl;
            }

        } while (opcao != 5);
        for(int i=0;i<tam;i++){
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
