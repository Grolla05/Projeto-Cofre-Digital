# Relatório – Projeto Cofre Digital
**PONTIFÍCIA UNIVERSIDADE CATÓLICA DE CAMPINAS**  
**ESCOLA POLITÉCNICA**  
**CURSO DE ENGENHARIA DE COMPUTAÇÃO**

## AUTORES:
- Felipe Grolla Freitas 
- Gabriel Henrique Pozeti de Faria 
- João Victor Vasconcelos Junqueira Criscuolo 
- Lucas Espica Rezende 

## 1. Introdução
O presente relatório tem como objetivo apresentar o desenvolvimento completo do Projeto Cofre Digital, idealizado e implementado como parte da disciplina Programação de Computadores (PC). O projeto consistiu na criação de um sistema de autenticação baseado em senha, desenvolvido em linguagem C, com foco em segurança, lógica de programação e manipulação de vetores.

A proposta foi implementar um programa que simulasse um cofre digital protegido por senha. Essa senha seria derivada do deslizamento de um vetor contendo 25 dígitos, compostos exclusivamente pelos números 0, 2, 4, 6, 8 e 9, dispostos de forma aleatória e passíveis de atualização a qualquer momento.

O usuário dispõe de três tentativas para desbloquear o cofre com base em uma senha previamente definida, a qual também pode ser alterada nas configurações do sistema. O projeto, portanto, envolve a validação da senha inserida, controle de tentativas e resposta visual conforme o sucesso ou falha na autenticação, reunindo elementos fundamentais da engenharia de computação com princípios práticos de segurança digital.

## 2. Descrição do Problema
O desafio proposto consistia na criação de um sistema funcional de controle de acesso com autenticação por senha, sendo necessário lidar com variáveis como limite de tentativas, manipulação de vetores e validação precisa de entradas. Os principais aspectos técnicos estão detalhados a seguir:

### 2.1 Tamanho da Senha
O sistema foi projetado para operar sobre um vetor com 25 posições. Isso exigiu uma estrutura capaz de processar e analisar uma ampla faixa de dados, garantindo eficiência na manipulação e integridade das informações.

### 2.2 Validação da Senha
A senha válida é composta por seis dígitos específicos: 0, 2, 4, 6, 8 e 9. O sistema deveria contabilizar as ocorrências desses números durante o processo de deslizamento e comparar a combinação formada com uma senha pré-configurada, composta pelas rotações 11, 12, 13, 14 e 15 em sequência. Entradas contendo quaisquer dígitos fora dos permitidos devem ser imediatamente rejeitadas.

### 2.3 Interface de Usuário
O projeto demandava uma interface suficientemente clara para que o usuário pudesse compreender a dinâmica do sistema e inserir a senha de maneira intuitiva, mesmo sem instruções externas. A usabilidade foi um dos critérios essenciais considerados no design lógico do sistema.

### 2.4 Autorização de Acesso
Ao identificar a senha como correta, o sistema deve conceder acesso ao cofre digital. Para isso, mecanismos de autorização e bloqueio foram implementados de forma a controlar o fluxo de execução com base na validação da senha digitada.

## 3. Dificuldades, Soluções e Desenvolvimento do Projeto
Durante o desenvolvimento do projeto, foi utilizada uma lógica estruturada que integrava laços de repetição (while, do while e for) para controlar o número de tentativas disponíveis, bem como o deslizamento no vetor. A estrutura condicional if/else foi essencial na definição de respostas lógicas às entradas do usuário.

Além disso, as bibliotecas stdio.h, locale.h (para compatibilidade com acentuação da língua portuguesa) e stdlib.h (para controle de tela e saída de fluxo) foram utilizadas como suporte ao sistema.

Uma das principais dificuldades enfrentadas foi a implementação da barra deslizante, a qual define um intervalo de leitura entre dois índices do vetor, começando na posição 10 e se estendendo até o limite superior informado pelo usuário. Inicialmente, foram utilizados dois vetores — um para armazenar os valores numéricos e outro para mapear suas posições reais.

Durante os testes, surgiram erros decorrentes de entradas inválidas (índices fora do intervalo permitido), o que causava a leitura de áreas de memória indevidas e resultava em comportamento incorreto do programa. A solução adotada foi a reestruturação do código, reduzindo o uso de dois vetores para apenas um, com uma nova lógica que solucionou os erros de forma definitiva.

Outro componente fundamental foi o sistema de verificação de senha, cuja lógica compara a senha digitada pelo usuário com a senha armazenada internamente. Essa comparação é feita dígito por dígito, utilizando estruturas condicionais e operadores lógicos (&&, ||) para garantir a correspondência exata entre as senhas.

A lógica inclui variáveis auxiliares (como zero, dois, quatro, etc.) para contar a ocorrência dos números permitidos, além de um contador de tentativas que informa ao usuário quantas chances ainda restam. A cada tentativa incorreta, o contador é decrementado. Quando chega a zero, o loop é encerrado com o comando break, bloqueando novas tentativas.

Na fase final do projeto, a equipe aprimorou o sistema ao adotar a estrutura switch-case no lugar de diversas estruturas if, buscando uma lógica mais otimizada e legível para realizar a contagem de números válidos inseridos pelo usuário.

Por fim, o grupo dedicou-se ao aprimoramento visual da aplicação, buscando uma apresentação mais atrativa para o usuário. Foram implementadas ilustrações básicas em ASCII com o objetivo de simular:

- Um cofre fechado, exibido no início do programa;
- Um cofre aberto com cédulas de dinheiro, apresentado quando a senha é corretamente digitada.

Esses elementos visuais, mesmo simples, contribuíram para uma experiência de uso mais interativa e amigável.

## 4. Referências
GUIMARÃES, Lúcia Filomena de Almeida. Atividade_Avaliativa_1_T0102, 2024.  
Disponível em:  
<a href="https://puc-campinas.instructure.com/courses/51258/assignments/159945?module_item_id=361221">https://puc-campinas.instructure.com/courses/51258/assignments/159945?module_item_id=361221</a>  
Acesso em: 01 de abril de 2024.
