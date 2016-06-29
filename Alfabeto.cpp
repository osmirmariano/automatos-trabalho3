#include <string>
#include <iostream>
#include <ctype.h>
#include <cstdlib>
#include <vector>

using namespace std;

class Alfabeto{}
	public:
		int cont, flag, recebe, contando;
		vector<string> alfabetos;
        vector<char> alfa;
        string unirAlfa, alfabetor;
        vector<char> alfaUnir;
        vector<char> inseriAlfa;
        vector<string> subpalavras;


    public:
		Alfabeto(){
			cont = 0;
			flag = 1;
            contando = 0;
            alfabetos = this->alfabetos;
            alfa = this->alfa;
            unirAlfa = this->unirAlfa;
            alfaUnir = this->alfaUnir;
            inseriAlfa = this->inseriAlfa;
            subpalavras = this->subpalavras;;
		};

		~Alfabeto();

		/*---------------------------FUNÇÃO VERIFICA ALFABETO------------------------------*/
		void verifAlfabetoAlfanumerico(string alfabeto, int result){ //pega cada elemento da string alfabeto e coloca em um vetor
			for(int x = 0; x < result; x++){
			    if(alfabeto[x] != '{' && alfabeto[x] != '}' && alfabeto[x] != ',' && alfabeto[x] != ' '){
                    if (isalnum (alfabeto[x])){
			            alfa.push_back(alfabeto[x]);
			            cont++;
			        }
			        else{
			            recebe = 1;
			        }
			    }
			}
		};
		/*----------------------FUNÇÃO VERIFICA ALFABETO REPETIDOS-------------------------*/
		void verifAlfabetoRepetido (string alfabeto, int result){ // verifica repetições de elementos no alfabeto
			for(int x = 0; x < cont; x++){
			    for(int y = x+1; y < cont; y++){
				   	if(alfa[x] == alfa[y]){
				   		recebe = 1;
				   		break;
				   	}
				}
			}
			if(recebe == 1){
				cout << endl << "\tALFABETO INFORMADO NÃO ACEITO!" << endl;
			}
			else{
				cout << endl << "\tALFABETO INFORMADO ACEITO - ";
		        function(alfabeto, result);
		        cout << endl;
		    }
			recebe = 0;
			destrutor();
            cont = 0;
		};

		/*---------------------------FUNÇÃO DESTRUTOR DE ALFABETO-----------------------------*/
		void destrutor(){
            alfa.clear();
		}
       
        /*----------------------------FUNÇÃO PARA PRINTAR SEM ESPAÇOS------------------------------*/
        void function(string alfabeto, int result){
        	int cont = 0;/**/
            for(int x = 0; x < result-1; x++){
                if(alfabeto[x] == ' '){
                	cont++;
                    int y = x;
                    while(y < result-1){
                    	alfabeto[y] = alfabeto[y+1];
                        y++;
                    }
                }
            }

            for(int x = 0; x < result; x++){
            	cout << alfabeto[x];
            }
   		};

   		
};