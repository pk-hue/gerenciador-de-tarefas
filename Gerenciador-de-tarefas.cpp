#include <iostream>
#include <fstream>
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
	
	cout << "Adicione o titulo da tarefa: "	<< "\n";
	cin.ignore();
	getline(cin, tarefa.titulo);
	
	cout << "Adicione a descricao da tarefa: " << "\n";
	cin.ignore();
	getline(cin, tarefa.descricao);
	
	ofstream arquivo("tarefas.txt", ios::app);
	
	if(arquivo.is_open()){
		arquivo << tarefa.titulo << "\n";
		arquivo << tarefa.descricao << "\n";
		
		arquivo.close();
		
		cout << "Tarefa adicionada com sucesso!" << "\n";
	}else{
		cout << "Erro ao adicinar tarefa!" << "\n";
		system("pause");
	}
	
}

void visualizarTarefa(){
	ifstream arquivo("tarefa.txt");
	
	if(arquivo.is_open()){
		string linha{""};
		
		while(getline(arquivo, linha)){
			cout << linha << "\n";
		}
		arquivo.close();
	}else{
		cout << "Erro ao visualizar tarefa!" << "\n";
		system("pause");
	}
}

int main(){
	int opcao;
	
	do{
		
		cout << "Selecione uma das opcoes abaixo:" << "\n";
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
				cout << "Editar tarefa" << "\n"; // <-- supondo chamado da função antes da criação
				break;
			case 4: 
				cout << "Excluir tarefa" << "\n";
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