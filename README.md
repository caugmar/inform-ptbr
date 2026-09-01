# Inform 6 em português

Este projeto reúne arquivos de linguagem, gramática e bibliotecas auxiliares
para criar ficção interativa em português com o Inform 6. Ele também inclui
`Ruínas`, uma versão traduzida e ampliada do jogo de demonstração `Ruins`,
construído ao longo do *Inform Designer's Manual*.

## Para jogar

### Ruínas

Você é um arqueólogo em uma expedição pela selva de Quintana Roo, em março de
1938. Depois de dias de busca, encontrou um sítio maia escondido sob a floresta.
Agora precisa explorar as ruínas, compreender seus sinais e retornar em
segurança com os achados registrados.

O objetivo é encontrar cinco artefatos: a estatueta, a máscara de jade, a pedra
funerária, o osso entalhado e o favo de mel. Fotografe cada peça no local,
remova-a somente depois do registro e coloque-a no caixote da Grande Plaza.
Reunir os cinco artefatos vale 30 pontos e encerra a expedição.

O jogo é uma aventura de exploração e quebra-cabeças. Observe cuidadosamente os
ambientes, examine objetos, consulte o dicionário maia e faça um mapa. A história
usa a luz, os glifos, a máscara e as passagens estreitas para conduzir a
exploração. Algumas descobertas também alteram a forma como o protagonista pode
se mover pelo templo.

Comandos úteis:

- `olhe` ou `observe`: descreve o local novamente.
- `examine objeto`: mostra detalhes de um objeto.
- `i` ou `inventario`: mostra o que você está carregando.
- `pegue objeto`, `solte objeto` e `coloque objeto no caixote`: manipulam itens.
- `dicas`: abre as dicas graduais do jogo.
- `instruções`: explica como jogar ficção interativa.
- `salvar`, `restaurar` e `desfazer`: ajudam a experimentar sem perder o
  progresso.

Para começar pelo terminal, compile o jogo e abra o arquivo resultante com um
interpretador Z-machine:

```sh
make run
```

O comando usa Gargoyle quando há uma sessão gráfica disponível e, caso contrário,
tenta o Fizmo. Também é possível abrir `ruinas.z5` diretamente em qualquer
interpretador compatível com Z-machine.

### Versão no navegador (Parchment)

Jogadores que preferirem jogar no navegador podem iniciar a versão web a partir
da raiz do projeto:

```sh
make parchment
```

Esse comando inicia um servidor local e abre automaticamente o jogo no navegador
em `http://0.0.0.0:8000`. Se a abertura automática não acontecer, acesse esse
endereço manualmente. Para encerrar o servidor, volte ao terminal e pressione
`Ctrl+C`.

Durante a partida, `dicas` oferece ajuda sem exigir que a solução inteira seja
revelada de uma vez. As categorias ligadas à exploração profunda são liberadas
conforme a história avança.

## Para desenvolver

### Requisitos

É necessário ter o compilador Inform 6 instalado e disponível como `inform`.
Para jogar ou testar os arquivos compilados, use um interpretador como Fizmo,
Gargoyle ou `dfrotz`. Python 3 é necessário apenas para servir a versão web
local do Parchment.

O repositório contém uma cópia da Inform 6 Standard Library em `lib/` e os
arquivos específicos deste projeto em `includes/`. O caminho `+lib,includes`
usado pelo Makefile permite que o compilador encontre ambos.

### Compilação

O comando básico usado pelo projeto é:

```sh
inform -Cu +language_name=Portugues +lib,includes src/ruinas.inf
```

Isso gera `ruinas.z5`. Os alvos mais úteis do Makefile são:

- `make`: compila o jogo e atualiza a cópia usada pelo Parchment.
- `make run`: compila e inicia um interpretador local.
- `make replay`: executa o replay de vitória.
- `make test`: executa o replay de vitória e o teste de regressão da pontuação.
- `make clean`: remove o arquivo Z-machine gerado.

Variáveis como `INFORM`, `DFROTZ`, `FIZMO`, `GARGOYLE` e `PYTHON` podem ser
substituídas na linha de comando quando os executáveis tiverem outros nomes ou
estiverem em locais diferentes. Por exemplo:

```sh
make test INFORM=/caminho/para/inform DFROTZ=/caminho/para/dfrotz
```

### Esqueleto de um jogo

Um jogo simples pode usar a gramática portuguesa desta forma:

```inform6
Constant Story "MINHA HISTÓRIA";
Constant Headline "^Uma ficção interativa em português^";

Include "Parser";
Include "VerbLib";
Include "PortuguesG";

Object Sala "Sala inicial"
    with description "Um lugar silencioso.",
         has light;

[ Initialise;
    location = Sala;
];
```

Compile o arquivo com `-Cu`, `+language_name=Portugues` e os caminhos de
inclusão deste projeto. `Portugues.h` fornece as mensagens e o vocabulário de
linguagem; `PortuguesG.h` fornece os verbos e as construções reconhecidos pelo
parser, como `pegue`, `examine`, `coloque`, `pergunte`, `desça` e as direções em
português. A gramática deve ser incluída depois de `VerbLib`.

### Bibliotecas auxiliares

- `Portugues.h`: definições de linguagem, mensagens padrão, caracteres
  acentuados e vocabulário básico em português.
- `PortuguesG.h`: gramática portuguesa para os verbos padrão e suas variações.
- `ComoJogar.h`: menu com instruções gerais sobre ficção interativa.
- `DoMenu.h` e `AltMenu.h`: infraestrutura para menus navegáveis.
- `Hints.h`: sistema de dicas em tópicos, exibidas gradualmente.
- `Utility.h`: rotinas auxiliares usadas pelas bibliotecas, incluindo `Pmove`.

Para usar menus e dicas, siga a ordem adotada por `Ruínas`:

```inform6
Include "Parser";
Include "Utility";
Include "DoMenu";
Include "AltMenu";
Include "Hints";
Include "VerbLib";
Include "ComoJogar";
Include "PortuguesG";
```

Depois, defina um menu principal e atribua-o à variável global `hint_menu`:

```inform6
Menu menu_de_ajuda "Ajuda";

[ Initialise;
    hint_menu = menu_de_ajuda;
];
```

Um tópico de dicas é formado por um `HintTopic` com objetos `Hint` como filhos:

```inform6
Menu -> exploracao "Exploração";
HintTopic -> -> "Como sair da sala?";
Hint -> -> -> "Observe as saídas.";
Hint -> -> -> "Tente ir para o norte.";
```

Para revelar tópicos adaptativamente, mantenha-os fora do menu principal no
início e mova-os para ele quando a história avançar. `Pmove` preserva a ordem
dos tópicos e dicas:

```inform6
Pmove(exploracao, menu_de_ajuda);
```

### Exemplos e referências

`src/ruinas.inf` é o exemplo mais completo e mostra salas, portas, objetos,
artefatos pontuáveis, iluminação, conversas, transformação do jogador, menus e
dicas adaptativas. Os diretórios `demos/house` e `demos/balances` contêm outros
exemplos da Inform 6, embora nem todo o texto deles esteja traduzido.

Os arquivos da Standard Library em `lib/` são da versão 6.12.2. A documentação
e as notas completas do Inform 6 estão disponíveis em:

- https://www.inform-fiction.org
- https://www.ifarchive.org/indexes/if-archive/infocom/compilers/inform6/library/contributions/
