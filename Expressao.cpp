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
        string alfabetoTratado, alfabeto, palavra;


        int quantidade, quant;
        string estado[10], estadoInicial, estadoFinal[10], estadoDefinido[10], simbolo;
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
        };

        ~Expressao();

        //FUNÇÃO PARA PEGAR O ALFABETO UNIDO PARA JOGAR NA TABELA
        string unirAlfabeto(string alfabeto){
            int valor = alfabeto.length();
            for(int x = 0; x < valor; x++){
                if(alfabeto[x] != '{' && alfabeto[x] != '}' && alfabeto[x] != ',' && alfabeto[x] != ' '){
                    alfabetoTratado += alfabeto[x];
                }
            }
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

                //INSERÇÃO E TRATAMENTO DO ESTADO INCIAL
                int ver = 0;
                while(ver == 0){
                    cout << "---------------------------------------------" << endl;
                    cout << " INFORME O ESTADO INICIAL: ";
                    cin >> estadoInicial;
                    for(int x = 0; x < quantidade; x++){
                        if(estadoInicial == estado[x]){
                            ver = 1;
                            break;
                        }
                        else
                            ver = 0;
                    }
                    if(ver != 1){
                        cout << endl << "\tNÃO EXISTE ESTE ESTADO NO AUTOMATO" << endl;
                    }
                }
                cout << endl;
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
            cout << endl << " --> ESTADOS INICIAL: " << estadoInicial << endl;
            cout << " --> ESTADOS FINAIS: ";
            for(int x = 0; x < quant; x++){
                cout << " " << estadoFinal[x];
            }
            cout << endl << " --> ALFABETO TRATADO: " << unirAlfabeto(alfabeto) << endl;
            //definindoTransicao(alfabeto, palavra);
        };

        

             

        

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
            unirAlfabeto(alfabeto);
            int tam =  alfabetoTratado.length();
            int tam1 = palavra.length();

            cout << endl;
            for (int x = 0; x < tam; x++){
                cout << "       |      " << alfabetoTratado[x]; 
                
            }
            cout << endl;
            cout << "----------------------------------------" <<endl;
            for(int x = 0; x < quantidade; x++){
                cout << "  " << estado[x] << "   |  " << endl;  
                cout << "----------------------------------------" <<endl;
                
                cout << "    "  << estadoDefinido[x];
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
                        cin >> estadoDefinido[contador];
                        simbolo = alfabetoTratado[y];
                        contador++;
                    }  
                }
                //Tratamento de Informar número que não pertence
                for(int x = 0; x < contador; x++){
                    for(int y = 0; y < quantidade; y++){
                        if(estadoDefinido[x] == estado[y]){
                            conta++;
                            break;
                        }
                    }  
                }
                if(conta < contador){
                    cout << endl << " EXISTEM ESTADOS INFORMADOS QUE NÃO PERTECE AO AUTOMATO" << endl;
                    cout << "---------------------------------------------" << endl;
                    conta = 0;
                    contador = 0;
                }
                
            }
        };

        

          

        //FUNÇÃO PARA PEGAR O ÚLTIMO SÍMBOLO --> STATUS OK não vai precisar
        /*void ultimoSimbolo(string palavra){
            string diviPalavra;
            int tam = palavra.length();
            for(int x = tam-1; x >= 0; x--){
                cont++;
                for(int y = 0; y < tam-cont; y++){
                    diviPalavra += palavra[y];
                }
                cout << " PALAVRA: " << diviPalavra << " | ÚLTIMO SÍMBOLO: " << palavra[x] << endl;
                cout << "---------------------------------------------" << endl;
                diviPalavra = "";
                
            }
            cout << endl;
        };*/

        

        //FUNÇÃO PARA CALCULAR A FUNÇÃO DE TRANSIÇÃO ESTENDIDA --> STATUS EM ANDAMENTO
        void funcaoTransicaoEstendida(string palavra){
            string novoEstado = "q0";
            int tam = 0, tam1;
            verificaPertenceAlfa(alfabeto, palavra); 
            cout << endl << "---------------------------------------------" << endl;
                        
            tam1 = alfabetoTratado.length();
            tam = palavra.length();

            for(int x = 0; x < tam; x++){
                for(int y = 0; y < quantidade; y++){
                    for(int i = 0; i < tam1; i++){
                        if(estado[y] == novoEstado){
                            if(palavra[x] == alfabetoTratado[i]){
                                novoEstado = estadoDefinido[x];
                                cout << "ESTADO: " << novoEstado << endl;
                                cout << "ESTADO DEF: " << estadoDefinido[x] << endl;
                            }
                        }

                    }

                }
            }
            
            cout << "ESTADO RETORNADO: " << novoEstado << endl;
            int tratar = 0;
            for(int x = 0; x < quant; x++){
                if(novoEstado == estadoFinal[x]){
                    tratar = 1;
                }
            }
            if(tratar == 1){
                cout << "---------------------------------------------" << endl;
                cout << " PALAVRA ACEITA PELA O AUTÔMATO!" << endl;
                cout << " \tESTADO " << novoEstado << " É FINAL" << endl;
                cout << "---------------------------------------------" << endl;
            }
            else{
                cout << "---------------------------------------------" << endl;
                cout << " PALAVRA NÃO É ACEITA PELO O AUTÔMATO!" << endl;
                cout << "\tESTADO " << novoEstado << " NÃO É FINAL" << endl;
                cout << "---------------------------------------------" << endl;
            }
        };

        /*int retornaLinha(string novoEstado){
            for(int x = 0; x < quantidade; x++){
                if(novoEstado == estado[x])
                    return x;
            }
            return -1;
        };


        int retornaColuna(string palavra){
            for(int x = 0; x < quantidade; x++){
                if(palavra[x] == alfabetoTratado[x])
                    return x;
            }
            return -1;
        };

        string funcaoTransicao(string novoEstado, string palavra){
            int tam1 = alfabetoTratado.length();
            string tabela[quantidade][tam1];
            int linha = retornaLinha(novoEstado);
            int coluna = retornaColuna(palavra);
            if(linha == -1 || coluna == -1)
                return "Erro";
            return retornaEstado(tabela[linha][coluna]);
        };

        string retornaEstado(int x){
            if(x > 0)
                return estado;
            return "Erro";
        };*/
        
};