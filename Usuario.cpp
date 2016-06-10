#include <string>
#include <cstring>
#include <iostream>
#include <ctype.h>
#include <cstdlib>
#include <vector>

using namespace std;

class Usuario{
    public:
    	int quantidade, quant;
    	string estado, estados, estadoInicial, estadoFinal, estadoFinais;

    public:
        Usuario(){
        	this->quantidade = quantidade;
        	this->quant = quant;
        	this->estado = estado;
        	this->estadoInicial = estadoInicial;
        	this->estadoFinal = estadoFinal;
        };

        ~Usuario();

        void definindoAutomato(){
        	cout << " INFORME A QUANTIDADE DE ESTADOS: ";
            cin >> quantidade;
            cout << endl;
            cout << "---------------------------------------------" << endl << endl;
            cout << "---------------------------------------------" << endl;
            cout << "\t FORNECE AGORA OS ESTADOS" << endl;
            for(int x = 0; x < quantidade; x++){
             	cout << " INFORME O " << x+1 << "º ESTADO: ";
                cin >> estado;
                estados += estado;
                cout << endl;
            }
            cout << "---------------------------------------------" << endl << endl;
            cout << "---------------------------------------------" << endl;
            cout << " INFORME O ESTADO INICIAL: ";
            cin >> estadoInicial; 
            cout << endl;

            cout << "---------------------------------------------" << endl << endl;
            cout << "---------------------------------------------" << endl;
            cout << "QUANTIDADE DE ESTADOS FINAIS: ";
            cin >> quant;
            cout << endl;
            if(quant > quantidade){
            	cout << " NÃO EXISTE ESTA QUANTIDADE DE ESTADOS NO AUTÔMATOS" << endl;
            }
            else{
            	for (int x = 0; x < quant; x++){
	               	cout << " " <<  x+1 << "º  ESTADO FINAL: ";
	               	cin >> estadoFinal;
	            }
	            /*if(estadoFinais != estados){
	               	cout << " NÃO EXISTE ESTE ESTADO NO AUTÔMATO" << endl;
	               	cout << " \tINFORME UM VÁLIDO" << endl;
	            }
	            else{
	            	estadoFinais += estadoFinal;
	               	cout << endl;
	            }*/
            }
            
            cout << "---------------------------------------------" << endl << endl;
            cout << " --> QUANTIDADE: " << quantidade << endl;
            cout << " --> ESTADOS: " << estados << endl;
            cout << " --> ESTADOS FINAL: " << estadoFinais << endl;
            cout << " --> ESTADOS INICIAL: " << estadoInicial << endl;
        };
};