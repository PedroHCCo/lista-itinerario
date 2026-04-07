# Sistema de Gerenciamento de Rota de Ônibus

## Descrição
Sistema interno desenvolvido em C++ para auxiliar motoristas e supervisores de rota de uma empresa de transporte coletivo municipal. O programa permite gerenciar o itinerário de ônibus, garantindo a ordem correta das paradas através de um menu interativo. A estrutura de dados principal utilizada nos bastidores é a lista duplamente encadeada.

## Requisitos
* **Compilador:** GCC (G++) com suporte a C++11 ou superior.
* **IDE Recomendada:** Visual Studio Code (VSCode) com a extensão C/C++ da Microsoft instalada.

## Compilação e Execução

### Fluxo Principal
Para compilar e executar o fluxo principal do sistema, abra o terminal na raiz do projeto e execute os seguintes comandos:

**Compilação:**
```bash
g++ main.cpp -o sistema_rotas

1. Qual variação de lista foi escolhida?
A estrutura escolhida para o desenvolvimento do sistema foi a Lista Duplamente Encadeada.

2. Por que essa estrutura é mais adequada para esse problema do que as demais?
A Lista Duplamente Encadeada é a opção ideal porque uma das operações exigidas é a "Listagem da rota em ordem inversa". Em uma lista simplesmente encadeada, exibir os elementos de trás para frente seria muito ineficiente, exigindo percorrer a lista várias vezes ou usar memória extra. Como a lista duplamente encadeada possui ponteiros tanto para o próximo nó quanto para o anterior, é possível começar do último nó e percorrer a lista de forma reversa de maneira direta e rápida. Além disso, operações de remoção no final da lista são otimizadas, pois temos acesso direto ao penúltimo elemento.

3. Haveria algum cenário real em que outra variação de lista seria mais vantajosa? Explique.
Sim. Se a frota de ônibus operasse em uma rota estritamente circular, onde não há um ponto final definitivo e o ônibus volta imediatamente para a primeira parada após a última, uma Lista Circular seria muito mais vantajosa. Nesse cenário, o ponteiro final da lista apontaria de volta para o primeiro nó, simulando perfeitamente o ciclo contínuo do trajeto na vida real.
