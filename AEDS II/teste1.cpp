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
    string a;
    cin >> a;
    for (int i = 0; i < tam; i++)
    {
        if (bd[i]->placa == a)
            *index = i;
            return bd[i];
    }
    return NULL;
}



void remove(Tveiculo *bd[], int tam, string placa) {
    int index;

    busca(bd, tam, placa, &index);

    for(int i = index; i < tam - 1; i++){
        bd[i] = bd[i+1];
    }
}

int insere(Tveiculo *bd[], int tam){
    string placa,dados;
    int dados_num;
    float dados_numF;
    cout << "Digite a placa: ";
    cin >> placa;
    for(int i = 0; i < tam; i++){
        if(placa == bd[i]->placa){
            return -1;
        }
    }
      tam = tam +1;
      bd[tam]->placa              = dados;
      cout << "Digite o modelo do automovel: ";
      cin >> dados;
      bd[tam]->modelo             = dados;
      cout << "Digite a marca do automovel: ";
      cin >> dados;
      bd[tam]->marca              = dados;
      cout << "Digite o tipo do automovel: ";
      cin >> dados;
      bd[tam]->tipo               = dados;
      cout << "Digite o ano do automovel: ";
      cin >> dados_num;
      bd[tam]->ano                = dados_num;
      cout << "Digite o km do automovel: ";
      cin >> dados_num;
      bd[tam]->km                 = dados_num;
      bd[tam]->pot                = dados_numF;
      cout << "Digite a potencia do motor do automovel: ";
      cin >> dados_num;
      bd[tam]->comb       = dados;
      cout << "Digite qual o cambio do automovel: ";
      cin >> dados;
      bd[tam]->camb            = dados;
      cout << "Digite o tipo de direcao do automovel: ";
      cin >> dados;
      bd[tam]->dir            = dados;
      cout << "Digite qual a cor do automovel: ";
      cin >> dados;
      bd[tam]->cor                = dados;
      cout << "Digite qual numero de portas do automovel: ";
      cin >> dados_num;
      bd[tam]->port            = dados_num;
      cout << "Digite qual numero de portas do automovel: ";
      cin >> dados_num;
      bd[tam]->valor              = dados_numF;
      return 1;
}


Tveiculo *ordena(Tveiculo *bd[], int tam){
    Tveiculo *aux;
    Tveiculo *ord[50];
    for(int i = 0; i < tam; i++){
        ord[i] = bd[i];
    }
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam - i; j++){
            if(stoi(ord[j]->placa) > stoi(ord[j+1]->placa)) {
                aux = ord[j];
                ord[j] = ord[j+1];
                ord[j+1] = aux;
            }
        }
    }
    return *ord;
}

Tveiculo *busca_valor(Tveiculo *ord[], int tam, int valor) {
    Tveiculo *busca[10];
    int fit[tam];
    int menor = INT_MAX;
    int menor_index = -1;
    int l = 1;
    int m1, m2;

    for(int i = 0; i < tam; i++){
        fit[i] = abs(ord[i]->valor - valor);
    }


    for(int i = 0; i < tam; i++){
        if(fit[i] < menor){
            menor = fit[i];
            menor_index = i;
        }
    }
    busca[0] = ord[menor_index];
    m1 = menor_index - 1;
    m2 = menor_index + 1;
    while (l <= 10)
    {
        if(fit[m1] >= fit[m2]) {
            busca[l] = ord[m1];
            
        }
    }
    
}


int main(int argc, char **argv)
{
    string a,remove;
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
        switch (opcao)
        {
        case 1:
            insere(bd,tam);
            tam++;
            break;
        
        default:
            break;
        }
        /*if (opcao == 2)
        {
            cout << "Informe a placa do veículo: " <<endl;
            Tveiculo *p = busca(bd, tam, a, &index);
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
        */
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