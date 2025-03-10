//Esdras F.C
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Estrutura para armazenar as transições de um estado
struct Transicoes {
    vector<pair<string, int>> transicao; // Cada transição é um par (símbolo, próximo estado)
};

// Estrutura para representar um estado do autômato
struct Estado {
    bool estado_final = false;  // Indica se o estado é final
    Transicoes transicoes;      // As transições desse estado
};

// Função para verificar se uma palavra é aceita pelo autômato
bool verifica_palavra(const vector<Estado>& estados, const string& palavra, int estado_inicial) {
    int estado_atual = estado_inicial;
    
    for (char c : palavra) {
        string simbolo(1, c);
        bool transicao_encontrada = false;

        // Buscar uma transição válida para o símbolo atual
        for (const auto& trans : estados[estado_atual].transicoes.transicao) {
            if (trans.first == simbolo) {
                estado_atual = trans.second;
                transicao_encontrada = true;
                break;
            }
        }
        // Se não houver transição válida, rejeita a palavra
        if (!transicao_encontrada) return false;
    }

    // Verifica se terminou em um estado final
    return estados[estado_atual].estado_final;
}

// Função para ler a quantidade de estados
int ler_quantidade_estados() {
    int quantidade;
    cout << "=== Configuração do Autômato ===" << endl;
    cout << "1. Quantidade de Estados:" << endl;
    cout << "Digite o número de estados do autômato (exemplo: 3 para estados 0, 1 e 2): ";
    cin >> quantidade;
    return quantidade;
}

// Função para ler o alfabeto
string ler_alfabeto() {
    string alfabeto;
    cout << "\n2. Alfabeto:" << endl;
    cout << "Digite os símbolos do alfabeto (exemplo: 01 para símbolos '0' e '1'): ";
    cin >> alfabeto;
    return alfabeto;
}

// Função para ler os estados finais
void ler_estados_finais(vector<Estado>& estados, int quantidade) {
    int estado_final;
    cout << "\n3. Estados Finais:" << endl;
    cout << "Digite os números dos estados finais (um por vez)." << endl;
    cout << "Quando terminar, digite -1: " << endl;
    while (true) {
        cout << "Estado final: ";
        cin >> estado_final;
        if (estado_final == -1) break;
        if (estado_final >= 0 && estado_final < quantidade) {
            estados[estado_final].estado_final = true;
            cout << "Estado " << estado_final << " definido como final." << endl;
        } else {
            cout << "Erro: Estado " << estado_final << " não existe. Tente novamente." << endl;
        }
    }
}

// Função para ler as transições
void ler_transicoes(vector<Estado>& estados, const string& alfabeto, int quantidade) {
    int origem, destino;
    string simbolo;
    cout << "\n4. Transições:" << endl;
    cout << "Agora, defina as transições do autômato." << endl;
    cout << "Formato: estado_origem simbolo estado_destino (exemplo: 0 1 1)" << endl;
    cout << "Para encerrar, digite -1 como estado de origem." << endl;
    
    while (true) {
        cout << "Transição (origem símbolo destino): ";
        cin >> origem;
        if (origem == -1) break;
        cin >> simbolo >> destino;
        
        // Verificar se os estados são válidos
        if (origem < 0 || origem >= quantidade || destino < 0 || destino >= quantidade) {
            cout << "Erro: Um dos estados informados não existe. Tente novamente." << endl;
            continue;
        }
        
        // Verificar se o símbolo pertence ao alfabeto
        if (alfabeto.find(simbolo) == string::npos) {
            cout << "Erro: O símbolo '" << simbolo << "' não pertence ao alfabeto. Use apenas: " << alfabeto << "." << endl;
            continue;
        }
        
        // Verificar se já existe uma transição para o mesmo símbolo a partir do mesmo estado
        bool transicao_duplicada = false;
        for (const auto& trans : estados[origem].transicoes.transicao) {
            if (trans.first == simbolo) {
                cout << "Erro: Já existe uma transição para o símbolo '" << simbolo << "' a partir do estado " << origem << "." << endl;
                transicao_duplicada = true;
                break; // Sai do loop de verificação
            }
        }
        
        if (transicao_duplicada) {
            continue; // Pula para a próxima iteração do loop principal
        }
        
        // Adicionar a transição
        estados[origem].transicoes.transicao.push_back({simbolo, destino});
        cout << "Transição adicionada: " << origem << " --(" << simbolo << ")--> " << destino << endl;
    }
}

// Função para testar palavras no autômato
void testar_palavras(const vector<Estado>& estados) {
    string palavra;
    cout << "\n=== Teste de Palavras ===" << endl;
    cout << "Digite palavras para testar no autômato." << endl;
    cout << "Dica: Use apenas símbolos do alfabeto definido anteriormente." << endl;
    cout << "Para encerrar, digite 'sair'." << endl;
    while (true) {
        cout << "Palavra: ";
        cin >> palavra;
        
        if (palavra == "sair") break;
        
        if (verifica_palavra(estados, palavra, 0))
            cout << "Resultado: A palavra '" << palavra << "' é ACEITA pelo autômato!" << endl;
        else
            cout << "Resultado: A palavra '" << palavra << "' foi REJEITADA pelo autômato." << endl;
    }
}

int main() {
    vector<Estado> estados;

    // Leitura da quantidade de estados
    int quantidade = ler_quantidade_estados();
    estados.resize(quantidade);

    // Leitura do alfabeto
    string alfabeto = ler_alfabeto();

    // Leitura dos estados finais
    ler_estados_finais(estados, quantidade);

    // Leitura das transições
    ler_transicoes(estados, alfabeto, quantidade);

    cout << "\n=== Autômato Configurado com Sucesso! ===" << endl;

    // Teste de palavras
    testar_palavras(estados);

    cout << "\n=== Encerrando Testes ===" << endl;
    cout << "Obrigado por usar o simulador de autômatos!" << endl;
    return 0;
}
