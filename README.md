# Projeto Lista Itinerario

## Descrição
Código em C++ para gerenciar uma lista de itinerários.

## Requisitos
- GCC/G++ versão 9.0 ou superior
- VS Code com extensões de C++

## Compilação e Execução
Para compilar:
g++ main.cpp -o programa

Para executar:
./programa

Para os testes:
g++ tests/*.cpp -I include -o exec_teste

# Sistema de Gerenciamento de Rota de Ônibus

## Respostas da Análise

**1. Qual variação de lista foi escolhida?**
A estrutura escolhida para o desenvolvimento do sistema foi a Lista Duplamente Encadeada.

**2. Por que essa estrutura é mais adequada para esse problema do que as demais?**
A Lista Duplamente Encadeada é a opção ideal porque uma das operações exigidas é a "Listagem da rota em ordem inversa". Em uma lista simplesmente encadeada, exibir os elementos de trás para frente seria muito ineficiente, exigindo percorrer a lista várias vezes ou usar memória extra. Como a lista duplamente encadeada possui ponteiros tanto para o próximo nó quanto para o anterior, é possível começar do último nó e percorrer a lista de forma reversa de maneira direta e rápida. Além disso, operações de remoção no final da lista são otimizadas, pois temos acesso direto ao penúltimo elemento.

**3. Haveria algum cenário real em que outra variação de lista seria mais vantajosa? Explique.**
Sim. Se a frota de ônibus operasse em uma rota estritamente circular, onde não há um ponto final definitivo e o ônibus volta imediatamente para a primeira parada após a última, uma Lista Circular seria muito mais vantajosa. Nesse cenário, o ponteiro final da lista apontaria de volta para o primeiro nó, simulando perfeitamente o ciclo contínuo do trajeto na vida real.
