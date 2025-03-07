#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Tarefa{
	
	string titulo;
	string descricao;
	int id;
	bool completa;
};

void adicionarTarefa(){
	Tarefa tarefa;
	
	cout << "Adicione o titulo da tarefa: "	<< endl;
	cin.ignore();
	getline(cin, tarefa.titulo);
	
	cout << "Adicione a descricao da tarefa: " << endl;
	cin.ignore();
	getline(cin, tarefa.descricao);
	
	ofstream arquivo("tarefas.txt", ios::app);
}

int main(){
	int opcao;
	
	do{
		
		cout << "Selecione uma das opcoes abaixo:" << endl;
		cout << "[ 1 ] - Adicionar tarefa" << endl;
		cout << "[ 2 ] - Visualizar tarefa" << endl;
		cout << "[ 3 ] - Editar tarefa" << endl;
		cout << "[ 4 ] - Excluir tarefa" << endl;
		cout << "[ 5 ] - Sair" << endl;
		cin >> opcao;
		
		switch(opcao){
			case 1:
				adicionarTarefa();
				break;
			case 2:
				cout << "Visualizar tarefa" << endl; // <-- supondo chamado da função antes da criação
				break;
			case 3:
				cout << "Editar tarefa" << endl;
				break;
			case 4: 
				cout << "Excluir tarefa" << endl;
				break;
			case 5:
				cout << "Encerrando programa..." << endl;
				break;
			default:
				cout << "Opcao invalida" << endl;
				break;
		}
		
	}while( opcao != 5);
	return 0;
}