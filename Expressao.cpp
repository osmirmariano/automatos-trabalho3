#include <string>
#include <cstring>
#include <iostream>
#include <ctype.h>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

class Expressao{
    public:
        int recebe, tamanho, verifica, aceito, cont, result, a;
        string alfabetoTratado, alfabeto, palavra, alf;


        int quantidade, quant;
        string estado[20], estadoFinal[10], simbolo, estadoDefinido[50][50];
        int pertence;
    public:

        Expressao(){
            this->quantidade = quantidade;
            this->quant = quant;
            this->alfabetoTratado = alfabetoTratado;
            this->alfabeto = alfabeto;
            this->palavra = palavra;
            this->recebe = recebe;
            this->tamanho = 0;
            this->aceito = 0;
            this->cont = 0;
            this->result = 0;
            this->a = 0;
        };

        ~Expressao();

        //FUNÇÃO PARA PEGAR O ALFABETO UNIDO PARA JOGAR NA TABELA
        string unirAlfabeto(string alfabeto){
            int valor = alfabeto.length();
            for(int x = 0; x < valor; x++){
                if(alfabeto[x] != '{' && alfabeto[x] != '}' && alfabeto[x] != ',' && alfabeto[x] != ' '){
                    alf += alfabeto[x];
                }
            }
            alfabetoTratado = alf;
            destrutor(alfabeto);
            return alfabetoTratado;

        };


        //FUNÇÃO PARA AS DEFINIÇÕES DO AUTOMATO --> STATUS OK
        void definindoAutomato(){
            //INFORMAÇÕES DE INSERÇÃO DOS DADOS
            cout << "Por favor, insira alfabeto neste modelo {0,1}" << endl;
            cout << "---------------------------------------------" << endl;
            cout << " INFORME O ALFABETO: ";
            cin >> alfabeto;
            cout << "---------------------------------------------" << endl;
            cout << " INFORME A QUANTIDADE DE ESTADOS: ";
            cin >> quantidade;
            cout << "---------------------------------------------" << endl;
            cout << " QUANTIDADE DE ESTADOS FINAIS: ";
            cin >> quant;
            cout << "---------------------------------------------" << endl;
            if(quant > quantidade){
                cout << " NÃO EXISTE ESTA QUANTIDADE DE ESTADOS NO AUTOMATOS" << endl;
            }
            else{
                cout << "\t FORNECA OS ESTADOS" << endl;
                cout << "---------------------------------------------" << endl;
                for(int x = 0; x < quantidade; x++){
                    cout << " INFORME O " << x+1 << "º ESTADO: ";
                    cin >> estado[x];
                }

                //INSERÇÃO E TRATAMENTO DOS ESTADOS FINAIS
                int verificar = 0;
                while(verificar < quant){
                    cout << "---------------------------------------------" << endl;
                    cout << "\t FORNECA OS ESTADOS FINAIS" << endl;
                    cout << "---------------------------------------------" << endl;
                    for (int x = 0; x < quant; x++){
                        cout << " " <<  x+1 << "º  ESTADO FINAL: ";
                        cin >> estadoFinal[x];
                        for(int y = 0; y < quantidade; y++){
                            if(estadoFinal[x] == estado[y]){
                                verificar++;
                            }
                        }
                    }
                    if(verificar < quant){
                        cout << endl << "\t ALGUNS DOS ESTADOS NÃO EXISTEM NO AUTOMATO" << endl;
                        verificar = 0;
                    }
                }
                cout << "---------------------------------------------" << endl;
            }

            //MOSTRANDO OS DADOS INSERIDOS PARA VERIFICAR SE ESTÁ CERTO
            cout << "---------------------------------------------" << endl << endl;
            cout << " --> ALFABETO: " << alfabeto << endl;
            cout << " --> CONJUNTOS DE ESTADOS: " ;
            for(int x = 0; x < quantidade; x++){
                cout << " " << estado[x];
            }
            cout << endl << " --> ESTADOS INICIAL: q0" << endl;
            cout << " --> ESTADOS FINAIS: ";
            for(int x = 0; x < quant; x++){
                cout << " " << estadoFinal[x];
            }
            cout << endl << " --> ALFABETO TRATADO: " << unirAlfabeto(alfabeto) << endl;
            //
            //definindoTransicao(alfabeto, palavra);
        };




        void destrutor(string alfabeto){
            alf.clear();
        }


        //VERIFICANDO SE A PALAVRA PERTENCE AO ALFABETO INFORMADO
        void verificaPertenceAlfa(string alfabeto, string palavra){
            int pertence = 0;
            int tam = alfabetoTratado.length();
            int tam2 = palavra.length();
            if(tam == 0)
                cout << "\tNÃO EXISTE NENHUM ALFABETO REGISTRADO" << endl;
            else{
                for(int x = 0; x < tam; x++){
                    for(int y = 0; y < tam2; y++){
                        if(alfabetoTratado[x] == palavra[y]){
                            pertence++;
                        }
                    }
                }
                if(pertence == tam2){
                    cout << endl << "   A PALAVRA '" << palavra << "' PERTENCE AO ALFABETO " << endl;
                }
                else{
                    cout << endl << "   A PALAVRA '" << palavra << "' NÃO PERTENCE AO ALFABETO " << endl;
                }
            }
        }


        //FUNÇÃO PARA MOSTRAR O AUTOMATO --> STATUS EM ANDAMENTO
        void mostrarAutomato(string alfabeto, string palavra){
            int c = 0;
            int tam =  alfabetoTratado.length();
            for(int x = 0; x < tam; x++){
                cout << "        |   ";
                cout << alfabetoTratado[x];
            }
            cout << endl << "---------------------------------------------" << endl;
            for(int x = 0; x < quantidade; x++){
                //cout << endl;
                //cout << "    " << estado[x]  << "  | ";
                if(estado[x] == "q0"){
                    cout << "  ->" << estado[x]  << "  | ";
                }
                else{
                    if(estado[x] != estadoFinal[c])
                        cout << "    " << estado[x]  << "  | ";
                    else
                        cout << "    *" << estado[x]  << "  | ";
                    c++;
                }

                for(int y = 0; y < tam; y++){
                    cout << "  " << estadoDefinido[x][y];
                    cout << "    |  ";
                }
                cout << endl << "---------------------------------------------" << endl;
            }

        };


        //FUNÇÃO PARA DEFINIR A TRANSIÇÃO DO AUTOMATO --> STATUS OK
        void definindoTransicao(string palavra, string alfabeto){
            int contador = 0, conta = 0, a = 0;
            int tamanho = alfabetoTratado.length();

            while(conta == 0){
                cout << " Antes de seguir defina as transições do automato" << endl;
                cout << "---------------------------------------------" << endl;
                cout << "\tDEFININDO AS TRANSIÇÕES DO AUTOMATO" << endl;
                cout << "---------------------------------------------" << endl;
                for(int x = 0; x < quantidade; x++){
                    for(int y = 0; y < tamanho; y++){
                        cout << " NO ESTADO <" << estado[x] << "> ENTRA <" << alfabetoTratado[y] << "> VAI PARA: ";
                        cin >> estadoDefinido[x][y];
                        //simbolo = alfabetoTratado[y];
                        contador++;
                    }
                }

                //Tratamento de Informar número que não pertence
                /*for(int x = 0; x < tamanho; x++){
                    cout << " ENTROU AQUI" << endl;
                    for(int y = 0; y < quantidade; y++){
                        cout << " ENTROU AQUI 2" << endl;
                        if(estado[y] == estadoDefinido[x][y]){
                            cout << " ENTROU AQUI 3" << endl;
                            conta++;
                            break;
                        }
                    }
                }
                cout << " CONTADOR: " << contador << endl;
                cout << " CONTA: " << conta << endl;
                if(conta != 0){
                    cout << endl << " EXISTEM ESTADOS INFORMADOS QUE NÃO PERTECE AO AUTOMATO" << endl;
                    cout << "---------------------------------------------" << endl;
                    conta = 0;
                    contador = 0;
                }*/
                conta = 1;
            }
            //a = contador;
        };


        //FUNÇÃO PARA CALCULAR A FUNÇÃO DE TRANSIÇÃO ESTENDIDA --> STATUS EM ANDAMENTO
        void funcaoTransicaoEstendida(string palavra){
            //string estadoAtual = "q0";
            string estadoAtual = estado[0];
            int tam = 0, tam1 = 0, k = 0, x = 0, flag = 0;
            verificaPertenceAlfa(alfabeto, palavra);
            cout << endl << "---------------------------------------------" << endl;

            tam1 = alfabetoTratado.length();
            tam = palavra.length();            

            int y=0;
            while(y < quantidade){
               // y++;
                x=-1;
                for(int z = 0; z < tam1; z++){
                    if(k < tam){
                        if(palavra[k] == alfabetoTratado[z]){
                            estadoAtual  = estadoDefinido[y][z];
                            //cout << "Estado atual: " << estado[y] << " entra: " << palavra[k] << " vai para: " << estadoDefinido[y][z] << endl;
                            //cout << " Palavra: " << palavra[k] << " Alfabeto: " << alfabetoTratado[z] << " novoEstado: " << novoEstado << endl << endl;
                           do{
                                x++;
                                y=x;
                                flag=1;
                           }while(estado[y] != estadoAtual);
                           //cout << " Y: " << y << endl;
                           //cout << " ESTADO: " << estado[y] << endl;
                        }
                    }
                    else{
                        y = quantidade;
                    }
                }
                k++;
                //y++;
                if(flag != 1){
                    y++;
                    flag=0;
                }
            }

            cout << "ESTADO RETORNADO: " << estadoAtual << endl;
            int tratar = 0;
            for(int x = 0; x < quant; x++){
                if(estadoAtual == estadoFinal[x]){
                    tratar = 1;
                }
            }
            if(tratar == 1){
                cout << "---------------------------------------------" << endl;
                cout << " PALAVRA ACEITA PELA O AUTÔMATO!" << endl;
                cout << " \tESTADO " << estadoAtual << " É FINAL" << endl;
                cout << "---------------------------------------------" << endl;
            }
            else{
                cout << "---------------------------------------------" << endl;
                cout << " PALAVRA NÃO É ACEITA PELO O AUTÔMATO!" << endl;
                cout << " \tESTADO " << estadoAtual << " NÃO É FINAL" << endl;
                cout << "---------------------------------------------" << endl;
            }
        };
};
