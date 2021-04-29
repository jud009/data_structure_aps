#include <iostream>
#include "ArrayList.h"

/*UNIT_TEST*/

const string OK_MESSAGE = "OK";
const string ERROR_MESSAGE = "ERROR";

/*------------------------------------------------------------------*/
//Funções auxiliares
void printHelper(string methodName, string message){
	cout << methodName << ": "<< message<<endl;
}

void assert(bool rule, string message){
	if (rule){
		printHelper(message, OK_MESSAGE);
	}
	else{
		printHelper(message, ERROR_MESSAGE);
	}
}
/*------------------------------------------------------------------*/
//Funções teste

void add_verificarTamanho_tamanhoCorreto() {
	ArrayList<int> list;
    list.add(10);
    list.add(15);
    list.add(20);
    
    assert(list.getSize() == 3, 
	"add_verificarTamanho_tamanhoCorreto");
}

void add_adicionarMaximaCapacidade_capacidadeoAumentada() {
    ArrayList<int> list;
    int capacidade = 10;

    for (int x = 0; x <= capacidade; x++) {
        list.add(x);
    }

    assert(list.getSize() > capacidade, 
	"add_adicionarMaximaCapacidade_capacidadeoAumentada");
}

 void add_adiconarNaPosicao_elementoAdicionado() {
    ArrayList<int> list;
    list.add(10);
    list.add(15);
    list.add(20);

    list.add(25, 2);

    assert(list.get(2) == 25, 
	"add_adiconarNaPosicao_elementoAdicionado");
}

void add_indexCorretoPassado_trueRetornado() {
        ArrayList<int> list;
        list.add(10);
        list.add(15);
        list.add(20);

        assert(list.add(25, 2), 
		"add_indexCorretoPassado_trueRetornado");
}

void add_indexIncorretoPassado_falseRetornado() {
        ArrayList<int> list;
        list.add(10);
        list.add(15);
        list.add(20);

        assert(list.add(25, 10) == false, 
		"add_indexIncorretoPassado_falseRetornado");
}

void remove_elementoRemovido_tamanhoListDecrementado_trueRetornado() {
    ArrayList<string> list;
    list.add("a");
    list.add("b");
    list.add("c");
	
    assert(list.remove("a"), 
	"remove_elementoRemovido_tamanhoListDecrementado_trueRetornado");
	
    assert(list.getSize() == 2, 
	"remove_elementoRemovido_tamanhoListDecrementado_trueRetornado");
}


void remove_posicoesAlteradas_trueRetornado() {
    ArrayList<string> list;
    list.add("a");
    list.add("b");
    list.add("c");
	
    assert(list.remove("a"), 
	"remove_posicoesAlteradas_trueRetornado");
    
    assert(list.get(0) == "b", 
	"remove_posicoesAlteradas_trueRetornado");
}

void remove_elementoNaoEncontrado_falseRetornado(){
	ArrayList<string> list;
    list.add("a");
    list.add("b");
    list.add("c");

    assert(list.remove("d") == false, 
	"remove_elementoNaoEncontrado_falseRetornado");
}

void removeAt_elementoRemovido_trueRetornado_tamanhoDecrementado() {
    ArrayList<string> list;
    list.add("a");
    list.add("b");
    list.add("c");

    assert(list.removeAt(1), 
	"removeAt_elementoRemovido_trueRetornado_tamanhoDecrementado");
    
    assert(list.getSize() == 2, 
	"removeAt_elementoRemovido_trueRetornado_tamanhoDecrementado");
}

void removeAt_indexNaoEncontrado_falseRetornado_tamanhoNaoAlterado() {
    ArrayList<string> list;
    list.add("a");
    list.add("b");
    list.add("c");
    
	
    assert(list.removeAt(10) == false, 
	"removeAt_indexNaoEncontrado_falseRetornado_tamanhoNaoAlterado");
	
    assert(list.getSize() == 3, 
	"removeAt_indexNaoEncontrado_falseRetornado_tamanhoNaoAlterado");
}

void clear_limparTudo_tamanhoReiniciado_listEmpty(){
    ArrayList<string> list;
    list.add("a");
    list.add("b");
    list.add("c");

    list.clear();
    
    assert(list.isEmpty(), 
	"clear_limparTudo_tamanhoReiniciado_listEmpty");
}

void clear_valoresZerados_novosValoresAdicionados_ok(){
    ArrayList<string> list;
    list.add("a");
    list.add("b");
    list.add("c");

    list.clear();
    list.add("b");
	
    assert(list.getSize() == 1, 
	"clear_valoresZerados_novosValoresAdicionados_ok");
    assert(list.get(0) == "b", 
	"clear_valoresZerados_novosValoresAdicionados_ok");
}

void get_indexCorreto_valorRetornado(){
    ArrayList<string> list;
    list.add("a");
    list.add("b");
    list.add("c");

    assert(list.get(0) == "a", 
	"get_indexCorreto_valorRetornado");
}

void get_indexIncorreto_excecaoLancada(){
    ArrayList<string> list;
    list.add("a");
    list.add("b");
    list.add("c");
	try{
		string result = list.get(10);
		assert(false, "get_indexIncorreto_excecaoLancada");
	}
	catch(const char* e){
		assert(true, "get_indexIncorreto_excecaoLancada");
	}
    
}

void indexOf_valorPassado_indexRetornado(){
    ArrayList<string> list;
    list.add("a");
    list.add("b");
    list.add("c");
	
    assert(list.indexOf("a")== 0, 
	"indexOf_valorPassado_indexRetornado");
}

void indexOf_valorInexistentePassado_NegativoRetornado(){
    ArrayList<string> list;
    list.add("a");
    list.add("b");
    list.add("c");
	
    assert(list.indexOf("d") ==-1, 
	"indexOf_valorInexistentePassado_NegativoRetornado");
}

/*------------------------------------------------------------------*/
int main(int argc, char** argv)
{
	add_verificarTamanho_tamanhoCorreto();
	add_adicionarMaximaCapacidade_capacidadeoAumentada();
	add_adiconarNaPosicao_elementoAdicionado();
	add_indexCorretoPassado_trueRetornado();
	add_indexIncorretoPassado_falseRetornado();
	
	remove_elementoRemovido_tamanhoListDecrementado_trueRetornado();
	remove_elementoNaoEncontrado_falseRetornado();
	remove_posicoesAlteradas_trueRetornado();
	
	removeAt_elementoRemovido_trueRetornado_tamanhoDecrementado();
	removeAt_indexNaoEncontrado_falseRetornado_tamanhoNaoAlterado();
	
	clear_limparTudo_tamanhoReiniciado_listEmpty();
	clear_valoresZerados_novosValoresAdicionados_ok();
	
	get_indexCorreto_valorRetornado();
	get_indexIncorreto_excecaoLancada();
	
	indexOf_valorPassado_indexRetornado();
	indexOf_valorInexistentePassado_NegativoRetornado();
	
	/*Alunos
    *Judiclei Almeida - 365191049
    *Moisés Costa - 365191055
    *Willinson Bastos - 365192008
    */
	return 0;
}
