#include <iostream>
#include <istream>
#include "Expressao.cpp"

using namespace std;

int main(){
    int opcao;
    string estado, palavra, alfabeto;

    Expressao *exp = new Expressao();

    do{
        cout << endl << "---------------------------------------------" << endl;
        cout << "\t MENU PRINCIPAL" << endl;
        cout << "---------------------------------------------" << endl;
        cout << " 1 -- DEFININDO AUTÔMATO" << endl;
        cout << " 2 -- DEFININDO TRANSICAO" << endl;
        cout << " 3 -- FUNCAO DE TRANSICAO ESTENDIDA" << endl;
        cout << " 4 -- VISUALIZAR AUTÔMATO" << endl;
        cout << " 0 -- SAIR " << endl;
        cout << "---------------------------------------------" << endl;
        cout << "OPCAO: ";
        cin >> opcao;
        cout << "---------------------------------------------" << endl << endl;

        switch(opcao){
            case 1:
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t DEFININDO AUTÔMATO " << endl;
                cout << "---------------------------------------------" << endl;
                exp->definindoAutomato();
                break;
            case 2:
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t DEFININDO TRANSICAO" << endl;
                cout << "---------------------------------------------" << endl;
                exp->definindoTransicao(palavra, alfabeto);
                break;
            case 3:
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t FUNÇÃO DE TRANSICAO ESTENDIDA" << endl;
                cout << "---------------------------------------------" << endl;
                cout << " INFORME UMA PALAVRA: ";
                cin >> palavra;
                exp->funcaoTransicaoEstendida(palavra);
                break;
            case 4:
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t VISUALIZAÇÃO DE AUTÔMATOS" << endl;
                cout << "---------------------------------------------" << endl;
                exp->mostrarAutomato(alfabeto, palavra);
                break;
            case 0:
                cout << "PROGRAMA ENCERRADO COM SUCESSO!" << endl;
                break;
            default:
                cout << "\tOPÇÃO INVÁLIDA. POR FAVOR, INFORME UMA VÁLIDA" << endl;
        };

    }while(opcao != 0);
    return 0;
};
