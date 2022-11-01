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
    cout << index;
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
    cin >> bd[tam]->modelo;
    cin >> bd[tam]->marca;
    cin >> bd[tam]->tipo;
    cin >> bd[tam]->ano;
    cin >> bd[tam]->km;
    cin >> bd[tam]->pot;
    cin >> bd[tam]->comb;
    cin >> bd[tam]->camb;
    cin >> bd[tam]->dir;
    cin >> bd[tam]->cor;
    cin >> bd[tam]->port;
    bd[tam]->placa = placa;
    cin >> bd[tam]->valor;
    tam++;
    /*cout << "Digite o modelo do automovel: ";
    cin >> dados;
    bd[tam]->modelo = dados;
    cout << "Digite a marca do automovel: ";
    cin >> dados;
    bd[tam]->marca = dados;
    cout << "Digite o tipo do automovel: ";
    cin >> dados;
    bd[tam]->tipo = dados;
    cout << "Digite o ano do automovel: ";
    cin >> dados_num;
    bd[tam]->ano = dados_num;
    cout << "Digite o km do automovel: ";
    cin >> dados_num;
    bd[tam]->km = dados_num;
    cout << "Digite a potencia do motor do automovel: ";
    cin >> dados_num;
    bd[tam]->pot = dados_numF;
    cout << "Digite qual o cambio do automovel: ";
    cin >> dados;
    bd[tam]->camb = dados;
    cout << "Digite o tipo de direcao do automovel: ";
    cin >> dados;
    bd[tam]->dir = dados;
    cout << "Digite qual a cor do automovel: ";
    cin >> dados;
    bd[tam]->cor = dados;
    cout << "Digite qual numero de portas do automovel: ";
    cin >> dados_num;
    bd[tam]->port = dados_num;
    cout << "Digite qual numero de portas do automovel: ";
    cin >> dados_num;
    bd[tam]->valor = dados_numF;
    */
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

    for (int i = 0; i < tam; i++)
    {
        fit[i] = abs(bd[i]->valor - valor);
    }

    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam - i; j++){
            if(fit[j] > fit[j+1]) {
                aux = fit[j];
                fit[j] = fit[j+1];
                fit[j+1] = aux;
            }
        }
    }

    for (i = 0; i < 10; i++)
    {
        
        for (j = 0; j < tam; j++)
        {
            if(fit[j] < menor){
                menor = fit[j];
                menor_index = j;
            }
        }
        fit[menor_index] = INT_MAX;
        cout << bd[menor]->modelo << " ";
        cout << bd[menor]->marca << " ";
        cout << bd[menor]->tipo << " ";
        cout << bd[menor]->ano << " ";
        cout << bd[menor]->km << " ";
        cout << bd[menor]->pot << " ";
        cout << bd[menor]->comb << " ";
        cout << bd[menor]->camb << " ";
        cout << bd[menor]->dir << " ";
        cout << bd[menor]->cor << " ";
        cout << bd[menor]->port << " ";
        cout << bd[menor]->placa << " ";
        cout << bd[menor]->valor << ".00" << endl;
        menor= INT_MAX;
    }

}
int main(int argc, char **argv)
{
    char removev;
    string a;
    int tam = 0, opcao, index;
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
        tam--;
        myfile.close();
        cout << "Escolha uma opção: " << endl;
        cout << "Incluir veículo (1)" << endl;
        cout << "Fazer busca pela placa (2)" << endl;
        cout << "Ordenar pela placa (3)" << endl;
        cout << "Fazer busca dos 10 veículos mais próximos (4)" << endl;
        cin >> opcao;
        /* for (int i = 0; i < tam; i++){
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
        switch (opcao)
        {
        case 1:
            insere(bd, tam);
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
            cout << index;
            if (p)
            {
                cout << "Veiculo encontrado" << endl;
                cout << p->marca << " " << p->modelo << " " << p->tipo << " " << p->ano << " " << p->km << " " << p->pot << " " << p->comb << " " << p->camb << " " << p->dir << " " << p->cor << " "
                     << p->port << " " << p->placa << " " << p->valor << endl;
                cout << "Deseja remover?" << endl;
                cin >> removev;
                if (removev == 's')
                {
                    remove(bd, tam, a);
                }
                for (int i = 0; i < tam; i++)
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
                tam--;
            }
            else
                cout << "Veiculo não encontrado" << endl;
        }
        case 3:
        {
            Tveiculo *ordenado = ordena(bd, tam);
        }
        case 4:
        {
            int valor;
            cin >> valor;
            busca_valor(bd, tam, valor);
        }
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