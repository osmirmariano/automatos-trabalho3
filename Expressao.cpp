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
	    string alfabetoTratado, alfabeto, palavra;


    	int quantidade, quant;
    	string estado[10], estadoInicial, estadoFinal[10], estd, simb, simbolo[10];
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
                        for(int y = x; y < quantidade; y++){
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
            definindoTransicao(alfabeto, palavra);
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
        };

        //FUNÇÃO PARA MOSTRAR O AUTOMATO --> STATUS EM ANDAMENTO
        void mostrarAutomato(string alfabeto){
            unirAlfabeto(alfabeto);
            int tam =  alfabetoTratado.length();
            cout << endl;
            for (int x = 0; x < tam; x++){
                cout << "       |      " << alfabetoTratado[x];

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

        //FUNÇÃO PARA PEGAR O ÚLTIMO SÍMBOLO --> STATUS OK
        void ultimoSimbolo(string palavra){
            string diviPalava;
            int tam = palavra.length();
            for(int x = tam-1; x >= 0; x--){
                cont++;
                for(int y = 0; y < tam-cont; y++){
                    diviPalava += palavra[y];
                }
                cout << " PALAVRA: " << diviPalava << " | ÚLTIMO SÍMBOLO: " << palavra[x] << endl;
                cout << "---------------------------------------------" << endl;
                diviPalava = "";
            }
            cout << endl;
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
                    cout << "   A PALAVRA '" << palavra << "' PERTENCE AO ALFABETO " << endl;
                }
                else{
                    cout << "   A PALAVRA '" << palavra << "' NÃO PERTENCE AO ALFABETO " << endl;
                }
            }
        }

        //FUNÇÃO PARA DEFINIR A TRANSIÇÃO DO AUTOMATO
        void definindoTransicao(string palavra, string alfabeto){
            int conta = 0;
            string str1, str2;
            while(conta == 0){
                cout << "---------------------------------------------" << endl;
                cout << "\tDEFININDO AS TRANSIÇÕES DO AUTOMATO" << endl;
                cout << "---------------------------------------------" << endl;
                for(int x = 0; x < quantidade; x++){
                    str1 = simbolo[x]; str2 = palavra[x];
                    cout << "QUAIS SIMBOLOS ENTRA NO ESTADO " << estado[x] << ": ";
                    cin >> simbolo[x];
                    if(str1 == str2){ //(strcmp(str1,str2)==0) //(str1.compare(str2) == 0)
                        conta++;
                    }
                }
                if(conta == 0){
                    cout << " EXISTEM SIMBOLOS QUE NÃO PERTECE A PALAVRA" << endl;
                   /* for(int x = 0; x < quantidade; x++){
                        simbolo[x].clear();
                    }*/
                }
            }

            for(int x = 0; x < quantidade; x++){
                cout << "  " << simbolo[x] << endl;
            }

        }

        //FUNÇÃO PARA CALCULAR A FUNÇÃO DE TRANSIÇÃO ESTENDIDA --> STATUS EM ANDAMENTO
        void funcaoTransicaoEstendida(string palavra){
            verificaPertenceAlfa(alfabeto, palavra);
            cout << "---------------------------------------------" << endl;
            definindoTransicao(palavra, alfabeto);
            int tam = 0, recebe1 = 0, recebe2 = 0;
            string q0, q1, q2, q3, q4, q5, q6, q7, estado="q0";

            tam = palavra.length();
            ultimoSimbolo(palavra);
            for(int x = 0; x < tam; x++){
                if(estado[x] == palavra[x])
                /*for(int y = x+1; y < tam; y++){
                    if(alfabetoTratado[x] == palavra[y]){
                        recebe1++;
                        cout << "RECEBE 1: " << recebe1 << endl;
                    }
                    else{
                        recebe2++;
                        cout << "RECEBE 2: " << recebe2 << endl;
                    }
                }*/

                if(palavra[x] != 'a' && palavra[x] != 'b'){
                    pertence = 1;
                }
                else{
                    if(estado == "q0"){
                        if(palavra[x] == 'a'){
                            estado = "q1";
                        }
                        else{
                            if(palavra[x] == 'b')
                                estado == "q0";
                        }
                    }
                    else{
                        if(estado == "q1"){
                            if(palavra[x] == 'a'){
                                estado = "q2";
                            }
                            else if(palavra[x] == 'b'){
                                estado = "q3";
                            }
                        }
                        else{
                            if(estado == "q2"){
                                if(palavra[x] == 'a'){
                                    estado = "q4";
                                }
                                else if(palavra[x] == 'b'){
                                    estado = "q5";
                                }
                            }
                            else{
                                if (estado == "q3"){
                                    if(palavra[x] == 'a'){
                                        estado = "q6";
                                    }
                                    else if(palavra[x] == 'b'){
                                        estado = "q7";
                                    }
                                }
                                else{
                                    if (estado == "q4"){
                                        if(palavra[x] == 'a'){
                                            estado = "q4";
                                        }
                                        else if(palavra[x] == 'b'){
                                            estado = "q5";
                                        }
                                    }
                                    else{
                                        if (estado == "q5"){
                                            if(palavra[x] == 'a'){
                                                estado = "q6";
                                            }
                                            else if(palavra[x] == 'b'){
                                                estado = "q7";
                                            }
                                        }
                                        else{
                                            if (estado == "q6"){
                                                if(palavra[x] == 'a'){
                                                    estado = "q2";
                                                }
                                                else if(palavra[x] == 'b'){
                                                    estado = "q3";
                                                }
                                            }
                                            else{
                                                if (estado == "q7"){
                                                    if(palavra[x] == 'a'){
                                                        estado = "q1";
                                                    }
                                                    else if(palavra[x] == 'b'){
                                                        estado = "q0";
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if(recebe1 > recebe2){
                cout << " PALAVRA PERTENCE AO ALFABETO" << endl;
                cout << endl << " ESTADO RETORNADO: " << estado << endl;
                if (estado == "q4" || estado == "q5" || estado == "q6" || estado == "q7"){
                    cout << "---------------------------------------------" << endl;
                    cout << " PALAVRA ACEITA PELA O AUTÔMATO!" << endl;
                    cout << " \tESTADO " << estado << " É FINAL" << endl;
                    cout << "---------------------------------------------" << endl;
                }
                else{
                    cout << "---------------------------------------------" << endl;
                    cout << " PALAVRA NÃO É ACEITA PELO O AUTÔMATO!" << endl;
                    cout << "\tESTADO " << estado << " NÃO É FINAL" << endl;
                    cout << "---------------------------------------------" << endl;
                }
            }
        };

};
