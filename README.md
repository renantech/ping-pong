Documentação do Jogo

<Ping Pong!>

Autores: Gustavo Pereira e Renan Mendes

Belo Horizonte, julho de 2023.

Documentação do Sistema

Introdução

Esta documentação descreve o jogo "Ping Pong!" desenvolvido pelos autores Gustavo Pereira e Renan Mendes. O jogo é uma versão digital simplificada do clássico jogo de pingue-pongue, também conhecido como tênis de mesa. O documento apresenta uma visão geral do jogo, incluindo seus componentes principais, público-alvo, objetivos educacionais, arquitetura do sistema, funcionalidades e documentação do código.

Escopo do Jogo

O jogo "Ping Pong!" tem como objetivo proporcionar uma experiência de jogo simples e rápida para jogadores casuais. Ele conta com os seguintes componentes principais:

- Paddle (Raquete): Representa os dois jogadores no jogo, cada um com sua própria raquete que se move para cima e para baixo.
- Ball (Bola): A bola que quica entre as raquetes dos jogadores.
- Score (Pontuação): Mantém o controle da pontuação de cada jogador.
- Tela Inicial: Exibe uma tela de menu inicial antes do jogo começar.
- Tela de Vitória: Mostra quem ganhou o jogo quando um dos jogadores atinge a pontuação de vitória (WINNING_SCORE).
- Background (Fundo): Imagens de fundo utilizadas no jogo.
- Eventos: O jogo reage aos eventos do teclado (setas para cima e para baixo, 'W' e 'S', 'Enter' e 'Esc') e eventos de timer para atualização contínua.
- Colisões: Verifica colisões entre a bola e as raquetes dos jogadores para que a bola possa quicar e alterar sua direção adequadamente.
- Texto: Usa uma fonte para exibir informações como pontuações e mensagens de "Match Point!".

Análise do público-alvo

O jogo "Ping Pong!" é direcionado a dois principais grupos de público-alvo:

1. Jogadores casuais: O jogo é adequado para jogadores casuais que buscam uma experiência de jogo simples e rápida. Não requer conhecimentos complexos ou habilidades avançadas, tornando-o acessível para pessoas de diferentes idades e níveis de habilidade. É uma versão digital simplificada do clássico jogo de pingue-pongue.

2. Entusiastas de jogos retrô: Com seu estilo de jogo clássico de Pong, o jogo pode atrair entusiastas de jogos retrô que têm apreço por jogos mais simples e nostálgicos. A escolha de gráficos 2D e controles simples pode evocar sentimentos de nostalgia para os jogadores que cresceram jogando jogos antigos.

Pré-requisitos

Para jogar o jogo "Ping Pong!", é necessário ter um dispositivo computacional (PC, notebook) com o sistema operacional Windows.

Objetivos educacionais e específicos do jogo

O jogo "Ping Pong!" possui os seguintes objetivos educacionais gerais e específicos:

Objetivo educacional geral:
- Proporcionar entretenimento educativo enquanto pratica e aprimora habilidades cognitivas, como reflexos, coordenação motora e tomada de

decisões rápidas.

Objetivos educacionais específicos:
- Coordenação motora: O jogo requer que os jogadores controlem as raquetes (paddle) para rebater a bola, melhorando a coordenação entre a visão e os movimentos das mãos.
- Concentração e atenção: Os jogadores precisam acompanhar a bola em movimento, permanecer alertas e focados para responder rapidamente aos seus movimentos.
- Agilidade mental: Os jogadores devem tomar decisões rápidas sobre a direção em que devem mover suas raquetes para rebater a bola e evitar que ela passe por eles.

Itens de Avaliação

O jogo "Ping Pong!" inclui os seguintes itens de avaliação:

- Pontuação: O jogo acompanha a pontuação dos jogadores, premiando-os por cada ponto marcado. Isso pode ajudar a medir o progresso e o sucesso dos jogadores no jogo.
- Tempo de reação: O tempo de reação dos jogadores para responder aos movimentos da bola é medido. Quanto mais rápido eles conseguirem rebater a bola, melhor será sua pontuação nesse item.
- Precisão: A precisão dos jogadores ao acertar a bola com a raquete é avaliada. Isso pode ser medido pela porcentagem de vezes que eles conseguem rebater a bola com sucesso em relação ao número total de tentativas.

Estratégia de apresentação

A estratégia de apresentação do jogo "Ping Pong!" é a seguinte:

- Introdução: Apresentação do jogo Ping Pong!
- Público-alvo: Introdução do público-alvo.
- Objetivos educacionais.
- Recursos e funcionalidades: Descrição da jogabilidade e dos controles.
- Avaliação: Explicação sobre a pontuação do jogo e como o jogo é competitivo.
- Pré-requisitos: Listagem dos pré-requisitos necessários para jogar o jogo.
- Demonstração.
- Conclusão: Resumo do projeto.

Arquitetura do Sistema

A arquitetura do sistema não é especificada no documento fornecido. Seria necessário um diagrama do sistema para fornecer uma visão geral das partes do sistema e sua interação. O documento menciona que não se deve confundir o diagrama de arquitetura com um fluxograma, pois o diagrama de arquitetura oferece uma visão geral da estrutura do sistema.

Funcionalidades do produto

O jogo "Ping Pong!" possui as seguintes funcionalidades:

1. Menu Inicial: Os jogadores podem iniciar o jogo ou sair do jogo a partir do menu inicial.
2. Modo de Jogo: Dois jogadores podem competir entre si no clássico jogo de pingue-pongue.
3. Controles: Os jogadores controlam as raquetes usando as teclas de seta (cima e baixo) e as teclas W e S no teclado, tornando o jogo acessível e fácil de jogar.
4. Pontuação: O jogo acompanha a pontuação de cada jogador à medida que eles marcam pontos durante o jogo.
5. Determinação do Vencedor: O jogo tem um sistema para determinar o vencedor, onde o primeiro jogador a alcançar a pontuação definida como WINNING_SCORE ganha a partida.

Usuários e sistemas externos

O jogo "Ping Pong!" é destinado aos seguintes usuários

Usuários:
1. Bruno: Busca um jogo simples para jogar no tédio.
2. Rafael: Procura um jogo "retro" para relembrar sua infância.
3. Luana: Precisa de um jogo simples para jogar com sua filha.

Esses são exemplos de usuários que podem se beneficiar e desfrutar do jogo "Ping Pong!" devido à sua jogabilidade simples e acessível.

Documentação do código

A documentação do código não é fornecida no documento. No entanto, é mencionado que o jogo foi implementado em C++. Algumas informações sobre a estrutura de dados e uma função específica são mencionadas:

- Estrutura de dados:
  - Matrizes e Vetores: Embora não sejam usados diretamente no código fornecido, a linguagem C++ permite o uso de matrizes e vetores para armazenar dados tabulares ou unidimensionais, respectivamente. Eles podem ser utilizados para armazenar informações adicionais no jogo.
  - Registros e Estruturas: O código faz uso das estruturas "Paddle" e "Ball" para armazenar informações relacionadas às raquetes e à bola.
  - Classes: Embora não sejam mencionadas no código fornecido, o conceito de classes é fundamental para a programação orientada a objetos em C++. O uso de classes pode organizar e estender o código, representando entidades do jogo, como jogadores, placar ou ambiente de jogo.

- Função "checkCollision":
  - A função "checkCollision" verifica se ocorre colisão entre dois retângulos.
  - Parâmetros:
    - x1, y1, width1, height1: Coordenadas e dimensões do primeiro retângulo.
    - x2, y2, width2, height2: Coordenadas e dimensões do segundo retângulo.
  - Retorno: Um valor booleano indicando se ocorre colisão (true) ou não (false).
