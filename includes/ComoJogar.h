! $Id: howtoplay.h,v 1.3 2017/10/24 13:36:34 michael Exp $
! ----------------------------------------------------------------------------
!   howtoplay.h for Inform 6, by Michael J. Coyne
!	How to Play text Copyright 2003 Fredrik Ramsberg
!
! ----------------------------------------------------------------------------
!   Installation: add the lines:
!
!       Include "Menus";    ! optional
!       Include "Howtoplay";
!
!   anywhere in your game AFTER the Include "VerbLib"; directive
!
! ----------------------------------------------------------------------------
!   Based on the structure of Roger Firth's ccpl.h
!
!   Implements a HELP verb which uses Menus.h (or any compatible menu
!   package) to display a menu of Fredrik Ramsberg's "How to Play"
!   instructions from "A Beginner's Guide to Playing Interactive Fiction".
!   Fredrik's full text can be found at:
!   http://IFGuide.ramsberg.net
!
!   Define NO_HOWTO_GRAMMAR to prevent the Help verb from being included.  You
!   will then have to provide an alternate means of running HowToMenu.select()
!
!   If you are not using Menus, then HowToMenu.select will just dump the
!   text to the screen.
!
!   If you wish to include this in an existing menu in your game instead of
!   just having it available through the help verb, you can do this:
!
!   Menu MyMenu "My Menu Object"
!      with   description "Please select one of the following items.^",
!            number 2;
!
!   Option   ->   "How to Play"
!      with   description [;
!               howtoplay.description();
!         ];
!
!	$Log: howtoplay.h,v $
!	Revision 1.3  2017/10/24 13:36:34  michael
!	Make it work properly with DMenus as found on IF Archive.
!
!	Revision 1.2  2003/05/24 13:36:34  michael
!	Removed DOS carriage-returns introduced by opening on DOS machine.
!	
!	Revision 1.1  2003/05/24 13:32:44  michael
!	Initial revision.
!	
! ---------------------------------------------------------------------------- !

system_file;

#ifndef MENU;
Class   Menu with select [;
         howtoplay.description();
      ];
#endif;
#ifndef OPTION;
Class   Option;
#endif;

[ bf text; style bold; print (string) text; style roman; ];

Menu    HowToMenu
   with   short_name [;
              print "Como Jogar ", (string) Story;
            rtrue;
         ];

Option   ->   howtoplay
   with   short_name [;
              print "Como Jogar ", (string) Story;
            rtrue;
         ],
         description [;
         print "Estas instruções gerais são um trecho de:
         ~A Beginner's Guide to Playing Interactive Fiction~. 
         O texto completo pode ser encontrado em http://IFGuide.ramsberg.net",

         (bf) "^^O jogo começa";
         print "
         ^Quando você inicia um jogo, você verá primeiro uma introdução,
         geralmente consistindo de uma ou poucas telas de texto, dando a você
         algum contexto sobre quem você é, onde você está e, talvez, até mesmo
         quais são seus objetivos no jogo. Sempre que o jogo tiver impresso uma
         tela cheia de texto, ele esperará até que você pressione ENTER ou
         alguma outra tecla, para que você tenha a chance de ler tudo antes
         que ele role para fora do topo da tela.^",

         (bf) "^Como interagir";
         print "
         ^Quando a introdução terminar, você receberá um prompt, geralmente ~>~,
         mas pode ser um pouco diferente de jogo para jogo. O prompt significa
         que o jogo agora está esperando por você para dizer o que você quer fazer.
         Você faz isso digitando comandos imperativos, como se estivesse
         comandando alguém. Digamos que a introdução lhe disse que você está em
         uma cozinha e que você pode ver um pote de vidro fechado sobre o
         balcão da cozinha. Comandos que você poderia tentar neste ponto incluem
         PEGAR O POTE, ou ABRIR O POTE, ou talvez EXAMINAR O POTE
         (Ao longo deste documento, coisas que estão escritas em letras
         maiúsculas são comandos completos que podem ser digitados em um jogo
         de IF. Eles não precisam ser digitados em letras maiúsculas ao serem
         inseridos em um jogo). Se você quiser, pode pular os artigos: PEGAR POTE
         funcionará tão bem quanto PEGAR O POTE. Se houver vários potes diferentes
         que você poderia querer dizer, o jogo pode perguntar qual deles você
         quer dizer. Basta digitar uma ou mais palavras que identifiquem
         unicamente um dos itens. Por exemplo, se o jogo disser ~Qual pote você
         quer dizer, o pote de vidro azul ou o pote de vidro verde?~, você
         poderia responder AZUL para pegar o azul. Você também pode optar por
         ignorar a pergunta completamente, apenas digitando um novo comando.^",

         (bf) "^Movimento";
         print "
         ^Para ir para outro local, a maioria dos jogos espera que você digite
         em que direção você quer ir. Você pode digitar IR PARA O SUL, mas
         apenas SUL também funcionará, assim como S (que é a abreviação
         comumente aceita para SUL). Outras direções e suas abreviações são
         NORTE (N), LESTE (L), OESTE (O), NORDESTE (NE), SUDESTE (SE),
         NOROESTE (NO), SUDOESTE (SO), CIMA (C), BAIXO (B), PARA DENTRO e PARA FORA.
         Se você estiver a bordo de um navio de algum tipo, também poderá usar
         PROA, POPA, ESTIBORDO e BOMBORDO.^
         ^Outras maneiras de se mover podem incluir comandos como ENTRAR NO CARRO,
         IR PARA O CARRO, SENTAR NA MOTO, SUBIR NA BICICLETA, SUBIR A BORDO DO
         NAVIO, PULAR NA PLATAFORMA, MERGULHAR NO LAGO, EMBARCAR NO NAVIO, SAIR DO
         CARRO, SAIR, PARTIR, TIRAR. Exatamente quais comandos são ";
#ifdef DIALECT_US;
         print "reconhecidos";
#ifnot;
         print "reconhecidos";
#endif;
         print " variam de jogo para jogo, bem como de situação para
         situação nesses jogos. Ao interagir com jogos de IF, sempre
         tente se expressar da forma mais simples possível.
         Se você tentou várias maneiras de se expressar e o jogo
         se recusa a entender o que você quer fazer, você provavelmente
         está no caminho errado; é hora de tentar algo completamente
         diferente.^",

         (bf) "^Verbos comuns";
         print "
         ^Como você já sabe, você pode usar o verbo PEGAR para pegar itens no
         jogo. É claro, você também pode usar SOLTAR para soltar itens. A maioria
         dos jogos modernos realmente ";
#ifdef DIALECT_US;
         print "reconhece";
#ifnot;
         print "reconhece";
#endif;
         print " cem verbos diferentes ou mais. Com alguns dos verbos mais
         usados, você também pode usar múltiplos itens, como este: PEGAR BOLA
         VERDE E CHAVE DE FENDA ou SOLTAR TUDO ou COLOCAR TUDO MENOS MARTELO
         NA SACOLA. Você descobrirá que TUDO é frequentemente uma palavra muito
         útil, embora funcione apenas com certos verbos, principalmente PEGAR
         e SOLTAR. Aqui estão alguns dos verbos mais importantes, com exemplos:^";

         font off;
         print "^
         OLHAR ou O      O ou OLHAR PARA BOB ou OLHAR EM POTE ou OLHAR DEBAIXO DA CAMA^
         PEGAR           PEGAR FACA^
         SOLTAR          SOLTAR FACA^
         EXAMINAR ou E   EXAMINAR FACA ou E FACA^
         PROCURAR        PROCURAR MESA^
         INVENTÁRIO ou I I^
         ABRIR           ABRIR GAVETA^
         FECHAR          FECHAR GAVETA^
         TRANCAR         TRANCAR PORTA COM CHAVE ENFERRUJADA^
         DESTRANCAR      DESTRANCAR PORTA COM CHAVE ENFERRUJADA^
         PERGUNTAR       PERGUNTAR A JOHN SOBRE POLICIAL^
         CONTAR          CONTAR A JOHN SOBRE ASSASSINATO^
         DIZER           DIZER OLÁ A JOHN^
         DAR             DAR COELHO PARA BOB^
         MOSTRAR         MOSTRAR FACA PARA POLICIAL^
         ESPERAR ou Z    Z^
         NOVAMENTE ou G  G^";
         font on;

         print "^Outros verbos que você precisará de tempos em tempos incluem ATACAR,
         COMPRAR, COBRIR, BEBER, COMER, ENCHER, PULAR, BEIJAR, BATER, OUVIR, MOVER,
         PUXAR, EMPURRAR, REMOVER, LER, SENTAR, DORMIR, FICAR DE PÉ, JOGAR, AMARRAR,
         TOCAR, VIRAR, DIGITAR, DESAMARRAR, VESTIR. Existem muitos mais.
         Espera-se que eles pareçam naturais para você quando você precisar deles.^",

         (bf) "^Como o tempo funciona";
         print "
         ^Quase todos os jogos de IF contam o tempo em turnos, em vez de horas e
         minutos. Toda vez que você digita algo e pressiona ENTER, um turno
         passa. Isso também significa que até você pressionar ENTER, nenhum
         tempo passa. Você poderia pensar em um turno como algo como um minuto,
         mas o quão longo ele realmente é depende do que você faz durante esse
         turno. Se você quiser que o tempo passe, mas não quiser realizar
         nenhuma ação, apenas digite ESPERAR ou Z. Isso será útil enquanto
         espera por alguém para chegar ou algo para ficar pronto no forno etc
         (no mundo do jogo, não no mundo real!).^

         ^Existem jogos que usam tempo real em vez de jogo baseado em turnos,
         mas são poucos e distantes entre si, e eles lhe dirão sobre seu sistema
         de tempo real no início do jogo.^",

         (bf) "^Falando com pessoas";
         print "
         ^As maneiras mais úteis de falar com pessoas geralmente envolvem os
         verbos PERGUNTAR e CONTAR. Ao usá-los, tente identificar a melhor
         palavra-chave para o que você está interessado, em vez de
         construções mais longas. Por exemplo, CONTAR A BOB SOBRE COMO EU VI
         SHEILA DAR UM ESTRANHO AMULETO PARA OUTRA MULHER não é provável que
         produza resultados úteis, mas CONTAR A BOB SOBRE AMULETO ou talvez
         CONTAR A BOB SOBRE SHEILA podem de fato ser úteis. Em outras palavras,
         você diz ao jogo o assunto sobre o qual você quer falar ou perguntar,
         não exatamente o que dizer. O jogo tentará fazer suposições razoáveis
         sobre o que você quer dizer em relação ao assunto.^";

         print "^Também observe que muitos jogos são bastante primitivos
         quando se trata de modelar pessoas. O autor tem que se esforçar
         enormemente para fazer com que as pessoas no jogo se comportem de
         forma realista e respondam bem à conversa. Em geral, não espere muito
         das pessoas no jogo, mas existem, é claro, jogos que se destacam
         nessa área também. Você também verá que alguns autores preferem
         conversas baseadas em menu, para facilitar a interação.^

         ^Para dizer a outra pessoa para fazer algo, digite o nome da pessoa,
         uma vírgula e, em seguida, um comando. Exemplo: BOB, QUEBRE O POTE.
         Assim como na vida real, a maioria das pessoas não fará
         automaticamente algo só porque você disse a elas. Se você acha que Bob
         sabe o que fazer com o pote, você também pode tentar DAR POTE A BOB
         ou MOSTRAR POTE A BOB.^",

         (bf) "^Verbos especiais";
         print "^Todos os jogos ";
#ifdef DIALECT_US;
         print "reconhecem";
#ifnot;
         print "reconhecem";
#endif;
         print " alguns verbos que não fazem nada no mundo do jogo, mas
         dizem ao jogo algo sobre como você quer que ele se comporte,
         ou alguma tarefa especial que você quer que ele execute. Esses verbos
         incluem:^";

         font off;
         print "^
         DESFAZER        Desfaz a última jogada que você fez.^
         SAIR ou S       Termina o jogo atual.^
         REINICIAR       Começa o jogo do início.^
         SALVAR          Salva sua posição atual em um arquivo no disco.^
         RESTAURAR       Carrega uma posição de jogo salva anteriormente.^
         AJUDA ou SOBRE  Mostra algumas informações sobre o jogo e seu
                        autor, em alguns casos até mesmo dicas para alguns dos
                     quebra-cabeças.^
         DETALHADO       Diz ao jogo que você quer uma descrição longa de cada
                         sala que você entra, mesmo que você já tenha estado lá antes.^
         BREVE           Diz ao jogo que você quer uma descrição longa na primeira
                         vez que você entra em uma sala, e uma descrição curta quando
                     você volta. Este é o modo padrão.^
         SUPERBREVE      Diz ao jogo que você sempre quer descrições curtas de
                     todas as salas.^";
         font on;

         print (bf) "^Ficar preso e se soltar";
         print "
         ^Ao jogar IF, você ficará preso. Isso faz parte do acordo --
         onde há quebra-cabeças, também haverá momentos em que você ficará preso.
         Se você se cansar de ficar preso no mesmo lugar por muito tempo, você
         pode digitar AJUDA no jogo para ver se há alguma dica disponível, ou
         você pode pedir dicas a outros jogadores. Um bom lugar para pedir
         dicas é o newsgroup rec.games.int-fiction (pode ser acessado em
         http://groups.google.com/groups?group=rec.games.int-fiction ).
         Esse também é um dos melhores lugares para encontrar outros jogadores
         de IF, discutir jogos que você jogou, obter dicas sobre jogos que
         você deve jogar e muito mais.^

         ^Ah, uma última coisa sobre jogar ficção interativa. Faça um mapa
         enquanto joga. É muito provável que você precise dele.";

];

[ HowToSub;      HowToMenu.select(); ];

#IFNDEF NO_HOWTO_GRAMMAR;
Verb meta 'instruções'
    * -> HowTo;
#ENDIF;

! ---------------------------------------------------------------------------- !
