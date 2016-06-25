#include <string>
#include <cstring>
#include <iostream>
#include <ctype.h>
#include <cstdlib>
#include <vector>
#include <iostream>
#include "Alfabeto.cpp"

using namespace std;

class Expressao{
    public:
    	int recebe, tamanho, verifica, aceito, cont, result, a;
	    string alfabeto, auxiliar, unirAlfa;
	    vector<char> alfa;
	    vector<string> alfabetos;
        vector<char> alfaUnir;

    	int quantidade, quant;
    	string estado[10], estadoInicial, estadoFinal[10], estd, simb, simbolo[10];
    	int pertence;
    public:

        Expressao(){
        	this->quantidade = quantidade;
        	this->quant = quant;
            alfaUnir = this->alfaUnir;
        	this->recebe = recebe;
        	this->tamanho = 0;
        	this->aceito = 0;
        	this->cont = 0;
        	this->result = 0;
        };

        ~Expressao();

        

        void tratandoAlfabeto(){
        	Alfabeto *alfabet = new Alfabeto();
        	cin.ignore();
        	cout << " INFORME O ALFABETO: ";
        	getline(cin, alfabeto);
            tamanho = alfabeto.length();

            for(int x = 0; x < tamanho; x++){
            	if(alfabeto[x] != ' '){
                	auxiliar += alfabeto[x];
                }else{
            	    cont++;
			    }
            }
            result = tamanho-cont;
            alfabeto = auxiliar;
            cont = 0;
		    auxiliar = "";
			if(result > 3 ){
            	for(int x = 1; x < result-2; x++){
                	if(alfabeto[0] != '{' || alfabeto[result-1] != '}' || alfabeto[x] == ',' || alfabeto[x+1] != ',' || alfabeto[result-2] == ','){
                    	aceito++;
                    }
                    x++;
                }
		    }
		    else{
            	if(result == 3){
                	if (!isalnum (alfabeto[1])){
                    	aceito++;
                    }
                }else{
                	aceito++;
                }
            }

            if(aceito == 0){
            	alfabet->verifAlfabetoAlfanumerico(alfabeto, result);
                alfabet->verifAlfabetoRepetido(alfabeto, result);
            }
            else{
            	cout << endl << "\t ALFABETO INFORMADO NÃO ACEITO." << endl;
			}
            aceito = 0;
            cont = 0;
            guardaAlfabetos(alfabeto, result);
        };

        //FUNÇÃO PARA PEGAR O ALFABETO UNIDO PARA JOGAR NA TABELA
        char guardaAlfabetos(string alfabeto, int result){
            int contando = 0;
            alfabetos.push_back(alfabeto);
            contando++;
            for(int x = 0; x < result; x++){
                if(alfabeto[x] != '{' && alfabeto[x] != '}' && alfabeto[x] != ',' && alfabeto[x] != ' '){
                    unirAlfa += alfabeto[x];
                }
            }
            cout << "Alfabeto Unido:" << unirAlfa << endl;
        };

        void definindoAutomato(){
        	cout << "---------------------------------------------" << endl;
        	tratandoAlfabeto();
        	cout << "---------------------------------------------" << endl;
        	cout << " INFORME A QUANTIDADE DE ESTADOS: ";
            cin >> quantidade;
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

	            cout << "---------------------------------------------" << endl;
	            cout << " INFORME O ESTADO INICIAL: ";
	            cin >> estadoInicial; 
	            cout << endl;
	            cout << "---------------------------------------------" << endl;
	            cout << "\t FORNECA OS ESTADOS FINAIS" << endl;
	            cout << "---------------------------------------------" << endl;
                for (int x = 0; x < quant; x++){
                    cout << " " <<  x+1 << "º  ESTADO FINAL: ";
                    cin >> estadoFinal[x];
                }
                /*if(estadoFinal != estado){
                    cout << " NÃO EXISTE ESTE ESTADO NO AUTOMATO" << endl;
                    cout << " \tINFORME UM VÁLIDO" << endl;
                }*/
            }
           
            
            cout << "---------------------------------------------" << endl << endl;
            cout << " --> ALFABETO: " << alfabeto << endl;
            cout << " --> QUANTIDADE: " << quantidade << endl;
            cout << " --> ESTADOS: " ;
            for(int x = 0; x < quantidade; x++){
                cout << " " << estado[x];
            }
            cout << endl << " --> ESTADOS INICIAL: " << estadoInicial << endl;
            cout << " --> ESTADOS FINAIS: ";
            for(int x = 0; x < quant; x++){
                cout << " " << estadoFinal[x];
            }
        };


        void mostrarAutomato(){
            int tam =  unirAlfa.length();
            cout << endl;
            for (int x = 0; x < tam; x++){
                cout << "       |      " << unirAlfa[x]; 
                
            }
            cout << endl;
            cout << "----------------------------------------" <<endl;
            for(int x = 0; x < quantidade; x++){
                cout << "  " << estado[x] << "   |  " << endl;  
                cout << "----------------------------------------" <<endl;
            }
            
        };

        /*int retornaLinha(string estd){
        	for(int x = 0; x < quantidade; x++){
        		if(strcmp(estd == estado[x]) == 0)
        			return x;
        	}
        	return -1;
        }*/

        /*
        int retornaColuna(string simbolo){
        	for(int x = 0; x < quantidade; x++){
        		if(strcmp(simb == simbolo[x]) == 0)
        			return x;
        	}
        	return -1;
        }

        string funcaoTransicao(string estd, string simb){
        	int linha = retornaLinha(estd);
        	int coluna = retornaColuna(simb);
        	if(linha == -1 || coluna == -1)
        		return "Erro";
        	return retornaEstado(tabela[linha][coluna]);
        }

        string retornaEstado(int x){
        	if(x > 0)
        		return estado;
        	return "Erro";
        }

        void mostrarAutomato(){
        	cout << " TESTE" << endl;
        }*/       
};