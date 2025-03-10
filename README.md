# Simulador de Autômato Finito Determinístico (AFD)

Este é um simulador de autômatos finitos determinísticos (AFD) implementado em C++. O programa permite que o usuário defina um autômato, configure seus estados, transições e alfabeto, e teste palavras para verificar se são aceitas pelo autômato.

## Funcionalidades

- **Definição de Estados**: O usuário pode definir a quantidade de estados do autômato.
- **Definição do Alfabeto**: O usuário pode especificar os símbolos que compõem o alfabeto do autômato.
- **Estados Finais**: O usuário pode marcar quais estados são finais (de aceitação).
- **Transições**: O usuário pode definir as transições entre estados com base em símbolos do alfabeto.
- **Teste de Palavras**: O usuário pode testar palavras para verificar se são aceitas pelo autômato.

## Como Usar

### Passo a Passo

1. **Quantidade de Estados**:
   - O programa solicita o número de estados do autômato.
   - Exemplo: Se o autômato tiver 3 estados, digite `3`.

2. **Alfabeto**:
   - O programa solicita os símbolos do alfabeto.
   - Exemplo: Para um alfabeto com os símbolos `0` e `1`, digite `01`.

3. **Estados Finais**:
   - O programa solicita os estados finais (um por vez).
   - Digite o número de cada estado final e, ao terminar, digite `-1`.
   - Exemplo: Para definir o estado `1` como final, digite `1` e depois `-1`.

4. **Transições**:
   - O programa solicita as transições no formato `estado_origem simbolo estado_destino`.
   - Exemplo: Para uma transição do estado `0` para o estado `1` com o símbolo `1`, digite `0 1 1`.
   - Para encerrar a definição de transições, digite `-1` como estado de origem.

5. **Teste de Palavras**:
   - O programa permite testar palavras para verificar se são aceitas pelo autômato.
   - Digite uma palavra e o programa informará se ela é aceita ou rejeitada.
   - Para encerrar, digite `sair`.

### Exemplo de Uso

#### Configuração do Autômato

```
=== Configuração do Autômato ===
1. Quantidade de Estados:
Digite o número de estados do autômato (exemplo: 3 para estados 0, 1 e 2): 2

2. Alfabeto:
Digite os símbolos do alfabeto (exemplo: 01 para símbolos '0' e '1'): 01

3. Estados Finais:
Digite os números dos estados finais (um por vez).
Quando terminar, digite -1:
Estado final: 1
Estado 1 definido como final.
Estado final: -1

4. Transições:
Agora, defina as transições do autômato.
Formato: estado_origem simbolo estado_destino (exemplo: 0 1 1)
Para encerrar, digite -1 como estado de origem.
Transição (origem símbolo destino): 0 1 1
Transição adicionada: 0 --(1)--> 1
Transição (origem símbolo destino): 1 0 1
Transição adicionada: 1 --(0)--> 1
Transição (origem símbolo destino): -1

=== Autômato Configurado com Sucesso! ===
```

#### Teste de Palavras

```
=== Teste de Palavras ===
Digite palavras para testar no autômato.
Dica: Use apenas símbolos do alfabeto definido anteriormente.
Para encerrar, digite 'sair'.
Palavra: 01
Resultado: A palavra '01' é ACEITA pelo autômato!
Palavra: 00
Resultado: A palavra '00' foi REJEITADA pelo autômato.
Palavra: sair

=== Encerrando Testes ===
Obrigado por usar o simulador de autômatos!
```

## Estrutura do Código

### Estruturas
- **`Transicoes`**: Armazena as transições de um estado.
- **`Estado`**: Representa um estado do autômato, incluindo se é final e suas transições.

### Funções
- **`verifica_palavra`**: Verifica se uma palavra é aceita pelo autômato.
- **`ler_quantidade_estados`**: Lê a quantidade de estados.
- **`ler_alfabeto`**: Lê os símbolos do alfabeto.
- **`ler_estados_finais`**: Lê os estados finais.
- **`ler_transicoes`**: Lê as transições do autômato.
- **`testar_palavras`**: Testa palavras no autômato.

### Função Principal
- **`main`**: Orquestra a execução do programa, chamando as funções na ordem correta.

## Requisitos

- Compilador C++ (ex: g++, Clang, ou MSVC).
- Terminal ou prompt de comando para executar o programa.

## Como Compilar e Executar

1. Salve o código em um arquivo com extensão `.cpp` (ex: `afd.cpp`).
2. Abra o terminal ou prompt de comando.
3. Navegue até o diretório onde o arquivo está salvo.
4. Compile o código com o comando:
   ```sh
   g++ afd.cpp -o afd
   ```
5. Execute o programa:
   ```sh
   ./afd
   ```

## Licença

Este projeto está disponível sob a licença MIT.

## Contribuições

Sugestões são bem-vindas! Abra uma issue ou envie um pull request.

