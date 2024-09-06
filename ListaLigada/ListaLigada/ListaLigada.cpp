
#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;

		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista já possuir elementos
	// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));

	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
	}
	else
	{
		// se nao encontrar dois valores iguais
		NO* aux = primeiro;
		while (aux != NULL) {
			if (aux->valor == novo->valor) {
				cout << "Valor ja exista na lista. \n";
				return;
			}
			aux = aux->prox;
		}

		// procura o final da lista
		aux = primeiro;
		while (aux->prox != NULL) {
			aux = aux->prox;
		}

		aux->prox = novo;
	}
}

void excluirElemento()
{
	/*Pede para o usuario digitar um numero
	Busca o numero na lista
	Se encontrado exclue o elemento e atualiza a quantidade de elementos na lista
	Se não econtrado exibe "ELEMENTO NAO ENCONTRADO"*/

	int elementoDeletado;
	bool verificacao = false;
	NO* atual = primeiro;
	NO* anterior = NULL;
	NO* proximoAtual;

	cout << "Digite o elemento a ser deletado: ";
	cin >> elementoDeletado;

	while (atual != NULL) {
		if (atual->valor == elementoDeletado) {

			cout << "O elemento escolhido foi apagado. \n";

			if (anterior == NULL) {
				// primeiro da lista
				proximoAtual = atual->prox;
				primeiro = proximoAtual;
			}
			else {
				// nao é o primeiro da lista
				proximoAtual = atual->prox;
				anterior->prox = proximoAtual;
			}

			free(atual);
			verificacao = true;
			return;
		}
		anterior = atual; // anterior pro atual
		atual = atual->prox; //atual pro proximo depois dele
	}

	if (verificacao == false) {
		cout << "Elemento nao encontrado! \n";
		return;
	}

}

void buscarElemento()
{
	int elementoBuscado;
	bool verificacao = false;
	NO* atual = primeiro;

	cout << "Digite o elemento que você quer buscar: ";
	cin >> elementoBuscado;

	while (atual != NULL) {
		if (atual->valor == elementoBuscado) {
			cout << "Elemento encontrado. \n";
			verificacao = true;
			break;
		}

		atual = atual->prox;
	}

	if (verificacao == false) {
		cout << "Elemento nao encontrado! \n";
	}
}

// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento não estiver na lista
NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}