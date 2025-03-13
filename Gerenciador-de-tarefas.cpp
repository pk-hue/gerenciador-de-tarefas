#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

struct Tarefa{
	string titulo;
	string descricao;
	int id;
	bool completa;
};

void adicionarTarefa(){
	Tarefa tarefa;
	
	cout << "Adicione o titulo da tarefa: ";
	cin.ignore();
	getline(cin, tarefa.titulo);
	
	cout << "Adicione a descricao da tarefa: ";
	getline(cin, tarefa.descricao);
	
	ofstream arquivo("tarefas.txt", ios::app);
	
	if(arquivo.is_open()){
		arquivo << "Titulo: " << tarefa.titulo << "\n";
		arquivo << "Descricao: " << tarefa.descricao << "\n\n";
		
		arquivo.close();
		
		cout << "Tarefa adicionada com sucesso! " << "\n";
		system("cls");
	}else{
		cout << "Erro ao adicinar tarefa." << "\n";
		system("pause");
	}
}


void visualizarTarefa(){
	ifstream arquivo("tarefas.txt");
	
	if(arquivo.is_open()){
		string linha{""};
		
		while(getline(arquivo, linha)){
			cout << linha << "\n";
		}
		arquivo.close();
		
		system("pause");
		system("cls");
	}else{
		cout << "Erro ao visualizar tarefa." << "\n";
		system("pause");
	}
}

void editarTarefa() {
    string tituloTarefaAntiga;
    cout << "Informe o titulo da tarefa que deseja editar: ";
    cin.ignore();
    getline(cin, tituloTarefaAntiga);

    ifstream arquivoAntigo("tarefas.txt");

    if (arquivoAntigo.is_open()) {
        string linha;
        string tituloNovo, descricaoNova;
        string arquivoTemporario = "temp.txt";

        ofstream arquivoNovo(arquivoTemporario, ios::out);

        if (arquivoNovo.is_open()) {
            while (getline(arquivoAntigo, linha)) {
                if (linha.find("Titulo: ") == 0) {
                    string tituloAtual = linha.substr(8); 

                    if (tituloAtual == tituloTarefaAntiga) {
                        cout << "Informe o novo titulo da tarefa: ";
                        getline(cin, tituloNovo);
                        cout << "Informe a nova descricao da tarefa: ";
                        getline(cin, descricaoNova);

                        arquivoNovo << "Titulo: " << tituloNovo << "\n";

                        getline(arquivoAntigo, linha);
                        arquivoNovo << "Descricao: " << descricaoNova << "\n";

                        continue; 
                    }
                }

                arquivoNovo << linha << "\n";
            }

            arquivoAntigo.close();
            arquivoNovo.close();

            remove("tarefas.txt");
            rename("temp.txt", "tarefas.txt");

            cout << "Tarefa editada com sucesso!" << "\n";
            system("cls");
        } else {
            cout << "Erro ao abrir o arquivo temporário. \n";
            system("pause");
        }
    } else {
        cout << "Erro ao abrir o arquivo antigo. \n";
        system("pause");
    }
}


int main(){
	vector<Tarefa> tarefas;
	int opcao;
	
	do{
		
		cout << "Selecione uma das opcoes abaixo: " << "\n";
		cout << "[ 1 ] - Adicionar tarefa" << "\n";
		cout << "[ 2 ] - Visualizar tarefa" << "\n";
		cout << "[ 3 ] - Editar tarefa" << "\n";
		cout << "[ 4 ] - Excluir tarefa" << "\n";
		cout << "[ 5 ] - Sair" << "\n";
		cout << "Opcao: ";
		cin >> opcao;
		
		system("cls");
		
		switch(opcao){
			case 1:
				adicionarTarefa();
				break;
			case 2:
				visualizarTarefa(); 
				break;
			case 3:
				editarTarefa(); 
				break;
			case 4: 
				cout << "Excluir tarefa" << "\n"; // <-- supondo chamado da função antes da criação
				break;
			case 5:
				cout << "Encerrando programa..." << "\n";
				break;
			default:
				cout << "Opcao invalida" << "\n";
				break;
		}
		
	}while( opcao != 5);
	return 0;
}