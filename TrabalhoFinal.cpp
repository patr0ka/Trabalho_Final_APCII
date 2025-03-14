#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MaxClientes 99

typedef struct{ //Struct para lanches
    string pao;
    string carne;
    string queijo;
    string hortaliça;
} Lanche;

typedef struct{ // Struct para pedidos
    Lanche comida;
    string bebida;
    string acompanhamento;
    string observação;
}Pedidos;

typedef struct{ // Struct para clientes;
    string nome;
    string telefone;
    string endereco;
    Pedidos pedido;
} Cliente;

bool VerificaNome(const string& nome){ // Verificação de entrada
    if (nome.empty()) {
        return false;
    }
    for (char c : nome) {
        if (!isdigit(c)) {
            return true;
        }
    }
    return false;
}

bool VerificaTelefone(const string& telefone){ // Verificação de entrada
    if (telefone.empty()) {
        return false;
    }
    for (char c : telefone) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool VerificaEndereco(const string& endereco){ // Verificação de entrada
    return !endereco.empty();
}

bool VerificaConfNum(char confirmacao, int limite){ // Verificação de entrada
    if(confirmacao >= 1 && confirmacao <= limite){
        return true;
    }
    return false;
}

bool VerificaConfLetra(char confirmacao){ // Verificação de entrada
    if(confirmacao == 'N' || confirmacao == 'S' || confirmacao == 'n' || confirmacao == 's'){
        return true;
    }
    return false;
}

void Cadastrar(Cliente *NovoCliente, int C){
    cin.ignore();
    cout << "<== Insira o nome do cliente: ==>" << endl;
    getline(cin, NovoCliente[C].nome); 
    while(!VerificaNome(NovoCliente[C].nome)){
        cout << "<== Nome invalido. Tente novamente: ==>" << endl;
        getline(cin, NovoCliente[C].nome);
    }

    cout << "<== Insira o telefone do cliente: ==>" << endl;
    getline(cin, NovoCliente[C].telefone); 
    while(!VerificaTelefone(NovoCliente[C].telefone)){
        cout << "<== Telefone invalido. Tente novamente: ==>" << endl;
        getline(cin, NovoCliente[C].telefone);
    }

    cout << "<== Insira o endereco do cliente: ==>" << endl;
    getline(cin, NovoCliente[C].endereco); 
    while(!VerificaEndereco(NovoCliente[C].endereco)){
        cout << "<== Endereco invalido. Tente novamente: ==>" << endl;
        getline(cin, NovoCliente[C].endereco);
    }
    cout << "<== Cliente cadastrado com sucesso! ==>" << endl;
}

int BinarySearch(Cliente *NovoCliente, const string& NomeCliente, int NumCliente){ // Busca binaria
    int ini = 0;
    int fim = NumCliente - 1;
    while(ini<=fim){
        int meio = ((ini+fim)/2);
        if(NovoCliente[meio].nome == NomeCliente){
            return meio;
        }
        if(NovoCliente[meio].nome < NomeCliente){
            ini = meio+1;
        }
        else{
            fim = meio-1;
        }
    }
    cout << "<== Cliente nao encontrada, verifique se as entradas estao corretas ==>" << endl;
    return -1;
}

string Pedido(string item, string item1, string item2, string item3){
    char confirmacao;
    cout << "Escolha o " << item <<endl;
    cout << "1 - " << item1 << endl << "2 - " << item2 << endl << "3 - " << item3 << endl;
    cin >> confirmacao;
    while(VerificaConfNum(confirmacao, 3)){
        cout << "<== Opcao invalida. Tente novamente: ==>" << endl;
        cin >> confirmacao;
    }
    if(confirmacao == '1'){
        return item1;
    }
    if(confirmacao == '2'){
        return item2;
    }
    if(confirmacao == '3'){
        return item3;
    }
    return 0;
}

void Anotar(Cliente *NovoCliente, string NomeCliente, int NumClientes){
    char confirmacao, i;
    string observação;
    i = BinarySearch(NovoCliente, NomeCliente, NumClientes);
    NovoCliente[i].pedido.comida.pao = Pedido("pao", "Pao brioche", "Pao australiano", "Pao de hamburguer");
    NovoCliente[i].pedido.comida.carne = Pedido("carne", "Gado", "Porco", "Frango");
    NovoCliente[i].pedido.comida.queijo = Pedido("queijo", "Mussarela", "Cheddar", "Provolone");
    NovoCliente[i].pedido.comida.hortaliça = Pedido("hortalica", "Cebola", "Alface", "Tomate");
    NovoCliente[i].pedido.bebida = Pedido("bebida", "Refrigerante", "Suco de Laranja", "Agua");
    NovoCliente[i].pedido.acompanhamento = Pedido("acompanhamento", "Batata Frita", "Onion Ring", "Batata Rustica");

    cout << "Deseja fazer alguma observacao? (N/S)" << endl;
    cin >> confirmacao;
    while(!VerificaConfLetra(confirmacao)){
        cout << "<== Opcao invalida. Tente novamente: ==>" << endl;
        cin >> confirmacao;
    }
    if(confirmacao == 'S' || confirmacao == 's'){
        cout << "<== Insira a informacao: (Ex: 'Sem cebola') ==>" << endl;
        cin.ignore();
        getline(cin, NovoCliente[i].pedido.observação);
        while(!VerificaEndereco(NovoCliente[i].pedido.observação)){
            cout << "<== Informacao invalida. Tente novamente: ==>" << endl;
            getline(cin, NovoCliente[i].pedido.observação);
        }
    }
    if(confirmacao == 'N' || confirmacao == 'n'){
    }
}

void Alterar(Cliente *NovoCliente, const string& ClienteAlterar, int NumClientes){
    for(int i=0; i<NumClientes; i++){
        if(NovoCliente[i].nome == ClienteAlterar){
            cout << "<== Cliente encontrado, insira os novos dados ==>" << endl;
            cout << "Insira o novo nome: ";
            getline(cin, NovoCliente[i].nome);
            while(!VerificaNome(NovoCliente[i].nome)){
                cout << "<== Nome invalido, por favor insira um nome valido ==>" << endl;
                getline(cin, NovoCliente[i].nome);
            }

            cout << "Insira o novo telefone: ";
            getline(cin, NovoCliente[i].telefone);
            while(!VerificaTelefone(NovoCliente[i].telefone)){
                cout << "<== Nome invalido, por favor insira um nome valido ==>" << endl;
                getline(cin, NovoCliente[i].telefone);
            }

            cout << "Insira o novo endereco: ";
            getline(cin, NovoCliente[i].endereco);
            while(!VerificaEndereco(NovoCliente[i].endereco)){
                cout << "<== Nome invalido, por favor insira um nome valido ==>" << endl;
                getline(cin, NovoCliente[i].endereco);
            }
            cout << "<== Dados alterados com sucesso ==>" << endl;
            return;
        }
    }
    cout << "<== Cliente nao encontrado, verifique se o nome foi digitado corretamente ou se o cliente foi cadastrado (Opcao 4) ==>" << endl;
}

void Visu_Clientes(Cliente *NovoCliente, int NumClientes){
    for(int i=0; i<NumClientes; i++){
        cout << "<=== " << (i+1) << "* Cliente" << " ====>" << endl;
        cout << "Nome: " << NovoCliente[i].nome << endl;
        cout << "Telefone: " << NovoCliente[i].telefone << endl;
        cout << "Endereco: " << NovoCliente[i].endereco << endl;
        cout << endl;
    }
}

void Visu_Pedido(Cliente *NovoCliente, string NomeCliente, int NumClientes){
    int i = BinarySearch(NovoCliente, NomeCliente, NumClientes);
    cout << endl;
    cout << "<== Pedido do cliente: " << NovoCliente[i].nome << " ==>" << endl;
    cout << "Prato principal:" << endl;
    cout << "- " << NovoCliente[i].pedido.comida.pao << endl;
    cout << "- Carne de " << NovoCliente[i].pedido.comida.carne << endl;
    cout << "- Queijo " << NovoCliente[i].pedido.comida.queijo << endl;
    cout << "- " << NovoCliente[i].pedido.comida.hortaliça << endl << endl;
    cout << "Bebida: " << endl << "- " << NovoCliente[i].pedido.bebida << endl << endl;
    cout << "Acompanhamento: " << endl << "- " << NovoCliente[i].pedido.acompanhamento << endl << endl;
    cout << "Observacoes: " << (NovoCliente[i].pedido.observação.empty() ? "Nenhuma observacao" : NovoCliente[i].pedido.observação) << endl << endl;
}

void OrdenarClientes(Cliente *NovoCliente, int NumClientes){ // Bubble sort recursivo
    if(NumClientes==1){
        return;
    }
    for(int i=0; i<NumClientes-1; i++){
        if(NovoCliente[i].nome > NovoCliente[i+1].nome){
            swap(NovoCliente[i], NovoCliente[i+1]);
        }
    }
    OrdenarClientes(NovoCliente, NumClientes-1);
}

void Escolha(Cliente *NovoCliente){
    int C=0;
    char opcao, confirmacao;
    string ClienteAlterar, ClientePedido, NomeCliente;
    int NumClientes=0;
    do {
        cout << "O que voce deseja fazer?" << endl;
        cout << "1 - Cadastrar cliente" << endl;
        cout << "2 - Anotar pedido" << endl;
        cout << "3 - Alterar cadastro" << endl;
        cout << "4 - Visualizar clientes" << endl;
        cout << "5 - Visualizar pedidos" << endl;
        cout << "6 - Sair" << endl;
        cin >> opcao;
        while(opcao < '1' || opcao > '6'){
            cout << "Opcao invalida. Tente novamente." << endl;
            cin >> opcao;
        }
        while((opcao == '2' || opcao == '3' || opcao == '4' || opcao == '5') && NumClientes == 0){
            cout << "<== Nao ha clientes cadastrados ==>" << endl;
            cin >> opcao;
        }
        if (opcao == '1') {
            do {
                Cadastrar(NovoCliente, C);
                C++;
                cout << "<== Deseja continuar cadastrando? (N/S) ==>" << endl;
                cin >> confirmacao;
                while(!VerificaConfLetra(confirmacao)){
                    cout << "<== Opcao invalida. Tente novamente. ==>" << endl;
                    cin >> confirmacao;
                }
                NumClientes++;
            } while (confirmacao != 'N' && confirmacao != 'n' && C <= MaxClientes);
            OrdenarClientes(NovoCliente, NumClientes);
        }
        if (opcao == '2'){
            do {
                cout << "<== Para qual cliente voce deseja anotar o pedido? (Insira o nome do cliente) ==>" << endl;
                Visu_Clientes(NovoCliente, NumClientes);
                cin.ignore();
                getline(cin, NomeCliente);
                while(!VerificaNome(NomeCliente)){
                    cout << "<== Nome invalido, insira o nome do cliente novamente ==>" << endl;
                    getline(cin, NomeCliente);
                }
                Anotar(NovoCliente, NomeCliente, NumClientes);
                cout << "<== Deseja anotar outro pedido? (N/S) ==>" << endl;
                cin >> confirmacao;
                while(!VerificaConfLetra(confirmacao)){
                    cout << "Opcao invalida. Tente novamente." << endl;
                    cin >> confirmacao;
                }
            } while (confirmacao != 'N' && confirmacao != 'n');
        }
        if (opcao == '3') {
            do{
                Visu_Clientes(NovoCliente, NumClientes);
                cout << "<== Qual cliente deseja alterar? (Insira o nome cadastrado) ==>" << endl;
                cin.ignore();
                getline(cin, ClienteAlterar);
                while(!VerificaNome(ClienteAlterar)){
                    cout << "<== Nome invalido, insira o nome do cliente novamente ==>" << endl;
                    getline(cin, ClienteAlterar);
                }
                Alterar(NovoCliente, ClienteAlterar, NumClientes);
                cout << "<== Continuar alterando? (N/S) ==>" << endl;
                cin >> confirmacao;
                while(!VerificaConfLetra(confirmacao)){
                    cout << "<== Opcao invalida. Tente novamente. ==>" << endl;
                    cin >> confirmacao;
                }
            }while(confirmacao != 'N' && confirmacao != 'n');
        }
        if(opcao == '4'){
            Visu_Clientes(NovoCliente, NumClientes);
        }
        if(opcao == '5'){
            cout << "<== Deseja visualizar o pedido de qual cliente? (Insira o nome do cliente) ==>" << endl;
            Visu_Clientes(NovoCliente, NumClientes);
            cin.ignore();
            getline(cin, NomeCliente);
            while(!VerificaNome(NomeCliente)){
                cout << "<== Nome invalido. Tente novamente ==>" << endl;
            }
            Visu_Pedido(NovoCliente, NomeCliente, NumClientes);
        }
    } while (opcao != '6');
}

int main(){
    Cliente *NovoCliente = new(nothrow) Cliente[MaxClientes]; // Alocação dinamica do vetor
    if(!NovoCliente){ // Verifica se a alocação foi bem sucedida
        cout << "<== Erro ao alocar memoria. ==>" << endl;
        return 1;
    }
    Escolha(NovoCliente);
    delete[] NovoCliente; // Deleta o vetor alocado dinamicamente
    return 0;
};