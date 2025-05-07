🎩 Jogo da Velha em C

Este é um jogo da velha (tic-tac-toe) feito em C para dois jogadores locais via terminal. O jogo permite:

Escolher posições de 1 a 9 para marcar com "X" ou "O"

Exibir um tabuleiro formatado a cada jogada

Detectar vitórias e empates automaticamente

Registrar o histórico de partidas com data e hora em um arquivo historico.txt

📦 Requisitos

Compilador C (como gcc)

Terminal ou console

🚀 Como jogar

Compilar o código:

gcc jogo_da_velha.c -o jogo

Executar:

./jogo

Menu:

1 → Jogar

2 → Ver Histórico

3 → Sair

📄 Histórico

Ao final de cada jogo, o resultado é automaticamente salvo no arquivo historico.txt, com data e hora da finalização:

Exemplo de entrada no histórico:

Jogador 1 ganhou do jogador 2 no dia 07/05/2025 às 15:42
O jogo terminou em empate no dia 07/05/2025 às 15:47

🛠️ Para Desenvolvedores

Se quiser modificar ou expandir o jogo, veja as dicas abaixo:

🧱 Estrutura do Código

main() → Contém o menu principal

jogar() → Executa a partida entre dois jogadores

mostrarTabuleiro() → Desenha o tabuleiro no console

verificarVencedor() → Verifica se houve um vencedor

tabuleiroCheio() → Verifica se o jogo empatou

salvarHistorico() → Escreve o resultado com data e hora em historico.txt

verHistorico() → Lê e exibe o histórico de jogos

💡 Sugestões de Melhorias

Permitir entrada de nomes personalizados dos jogadores

Adicionar opção para resetar o histórico

Implementar modo contra CPU (inteligência artificial simples)

Melhorar a interface visual no terminal com cores (via ANSI)

Salvar o histórico em formato JSON para uso em outros sistemas

Feito com 💻 em C puro.Sinta-se livre para contribuir!

