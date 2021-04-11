! vim:ft=inform:
! ==============================================================================
!   Portugu�s: Arquivo de defini��o de linguagem
!
!   Para uso com Inform 6 -- Release 6/11 -- Serial number 040227
!
!   Copyright Guto Marcicano 2012. Pode ser usado gratuitamente.
! ==============================================================================

System_file;

! ------------------------------------------------------------------------------
!   Part I.   Preliminaries
! ------------------------------------------------------------------------------

Constant LanguageVersion = "Tradu��o portuguesa por Guto Marcicano";

#ifdef TARGET_ZCODE;
  Zcharacter '�';
  Zcharacter '�';
  Zcharacter '�';
  Zcharacter '�';
  Zcharacter '�';
  Zcharacter '�';
  Zcharacter '�';
  Zcharacter '�';
  Zcharacter '�';
  Zcharacter '�';
#endif;

Class   CompassDirection
  with  number 0, article "o",
        description [;
            if (location provides compass_look && location.compass_look(self)) rtrue;
            if (self.compass_look()) rtrue;
            L__M(##Look, 7, self);
        ],
        compass_look false,
  has   scenery;

Object Compass "compass" has concealed;

#Ifndef WITHOUT_DIRECTIONS;
CompassDirection -> n_obj "norte"
                    with door_dir n_to, name 'n//' 'norte';
CompassDirection -> s_obj "sul"
                    with door_dir s_to, name 's//' 'sul';
CompassDirection -> e_obj "leste"
                    with door_dir e_to, name 'e//' 'leste';
CompassDirection -> w_obj "oeste"
                    with door_dir w_to, name 'w//' 'oeste';
CompassDirection -> ne_obj "nordeste"
                    with door_dir ne_to, name 'ne' 'nordeste';
CompassDirection -> nw_obj "noroeste"
                    with door_dir nw_to, name 'nw' 'noroeste';
CompassDirection -> se_obj "sudeste"
                    with door_dir se_to, name 'se' 'sudeste';
CompassDirection -> sw_obj "sudoeste"
                    with door_dir sw_to, name 'sw' 'sudoeste';
CompassDirection -> u_obj "para cima"
                    with door_dir u_to, name 'para' 'cima' 'acima' 'suba';
CompassDirection -> d_obj "ground"
                    with door_dir d_to, name 'para' 'baixo' 'abaixo' 'des@cca' 'desca';
#endif; ! WITHOUT_DIRECTIONS

CompassDirection -> in_obj "para dentro"
                    with door_dir in_to, name 'para' 'dentro' 'entre';
CompassDirection -> out_obj "outside"
                    with door_dir out_to, name 'para' 'fora' 'saia';

! ------------------------------------------------------------------------------
!   Part II.   Vocabulary
! ------------------------------------------------------------------------------

Constant AGAIN1__WD     = 'repita';
Constant AGAIN2__WD     = 'de novo';
Constant AGAIN3__WD     = 'novamente';
Constant OOPS1__WD      = 'opa';
Constant OOPS2__WD      = 'oops';
Constant OOPS3__WD      = 'epa';
Constant UNDO1__WD      = 'desfaca';
Constant UNDO2__WD      = 'desfa@cc';
Constant UNDO3__WD      = 'volte';

Constant ALL1__WD       = 'todos';
Constant ALL2__WD       = 'todas';
Constant ALL3__WD       = 'cada';
Constant ALL4__WD       = 'ambos';
Constant ALL5__WD       = 'ambas';
Constant AND1__WD       = 'e//';
Constant AND2__WD       = 'e//';
Constant AND3__WD       = 'e//';
Constant BUT1__WD       = 'menos';
Constant BUT2__WD       = 'exceto';
Constant BUT3__WD       = 'fora';
Constant ME1__WD        = 'mim';
Constant ME2__WD        = 'mim';
Constant ME3__WD        = 'mim';
Constant OF1__WD        = 'de';
Constant OF2__WD        = 'de';
Constant OF3__WD        = 'de';
Constant OF4__WD        = 'de';
Constant OTHER1__WD     = 'outro';
Constant OTHER2__WD     = 'outra';
Constant OTHER3__WD     = 'outro';
Constant THEN1__WD      = 'entao';
Constant THEN2__WD      = 'ent@~ao';
Constant THEN3__WD      = 'entao';

Constant NO1__WD        = 'n//';
Constant NO2__WD        = 'nao';
Constant NO3__WD        = 'n@~ao';
Constant YES1__WD       = 's//';
Constant YES2__WD       = 'sim';
Constant YES3__WD       = 'sim';

Constant AMUSING__WD    = 'interessantes';
Constant FULLSCORE1__WD = 'pontos';
Constant FULLSCORE2__WD = 'pontua@cc@~ao';
Constant QUIT1__WD      = 'encerrar';
Constant QUIT2__WD      = 'fechar';
Constant RESTART__WD    = 'reiniciar';
Constant RESTORE__WD    = 'restaurar';

Constant COLON__TX      = ": ";
Constant MYFORMER__TX   = "meu eu anterior";
Constant MYSELF__TX     = "eu mesmo";
Constant WAS__TX        = " era";
Constant WERE__TX       = " eram";
Constant WAS2__TX       = "era ";
Constant WERE2__TX      = "eram ";

Array LanguagePronouns table

!   palavra  GNAs que podem                conectado
!            segui-la:                      a:
!              a     i
!              s  p  s  p
!              mfnmfnmfnmfn

    '-o'    $$101000100001                    NULL
    '-os'   $$000101000101                    NULL
    '-a'    $$010000010000                    NULL
    '-as'   $$000010000010                    NULL
    '-o'    $$110000110000                    NULL
    '-os'   $$000110000110                    NULL
    'ele'    $$100000100000                    NULL
    'ela'    $$010000010000                    NULL
    'eles'   $$000100000100                    NULL
    'elas'   $$000010000010                    NULL;

Array LanguageDescriptors table

    !palavra  GNAs que podem     tipo de   conectado
    !              segui-la:   descritor:       com:
    !          a     i
    !          s  p  s  p
    !          mfnmfnmfnmfn                 
    
    'meu'     $$110110110110    POSSESS_PK      0
    'este'    $$100000100000    POSSESS_PK      0
    'estes'   $$000100000100    POSSESS_PK      0
    'esta'    $$010000010000    POSSESS_PK      0
    'estas'   $$000010000010    POSSESS_PK      0
    'esse'    $$100000100000    POSSESS_PK      1
    'essa'    $$010000010000    POSSESS_PK      1
    'esses'   $$000100000100    POSSESS_PK      1
    'essas'   $$000010000010    POSSESS_PK      1
    'seu'     $$110000110000    POSSESS_PK      0
    'seus'    $$000110000110    POSSESS_PK      0
    'o//'     $$100000100000    DEFART_PK       NULL
    'a//'     $$010000010000    DEFART_PK       NULL
    'os'      $$000100000100    DEFART_PK       NULL
    'as'      $$000010000010    DEFART_PK       NULL
    'um'      $$100000100000    INDEFART_PK     NULL
    'uma'     $$010000010000    INDEFART_PK     NULL
    'uns'     $$000100000100    INDEFART_PK     NULL
    'umas'    $$000010000010    INDEFART_PK     NULL
    'algum'   $$100000100000    INDEFART_PK     NULL
    'alguns'  $$000100000100    INDEFART_PK     NULL
    'algumas' $$000010000010    INDEFART_PK     NULL
    'aceso'   $$100000100000    light             NULL
    'acesa'   $$010000010000    light             NULL
    'acesos'  $$000100000100    light             NULL
    'acesas'  $$000010000010    light             NULL
    'apagado' $$100000100000    (-light)          NULL
    'apagada' $$010000010000    (-light)          NULL
    'apagados' $$000100000100    (-light)          NULL
    'apagadas' $$000010000010    (-light)          NULL;

Array LanguageNumbers table
    'um' 1 'uma' 1 'dois' 2 'duas' 2 'tr@^es' 3 'tres' 3 
    'quatro' 4 'cinco' 5 'seis' 6 'sete' 7 'oito' 8 'nove' 9 
    'dez' 10 'onze' 11 'doze' 12 'treze' 13 'quatorze' 14 
    'quinze' 15 'dezesseis' 16 'dezessete' 17 'dezoito' 18 
    'dezenove' 19 'vinte' 20;

! ------------------------------------------------------------------------------
!   Part III.   Translation
! ------------------------------------------------------------------------------

[ LanguageToInformese x;
        for (x=2:x<2+buffer->1:x++) if (buffer->x == '-') LTI_Insert(x++, ' ');
];
   
! ------------------------------------------------------------------------------
!   Part IV.   Printing
! ------------------------------------------------------------------------------

Constant LanguageAnimateGender = male;
Constant LanguageInanimateGender = male;

Constant LanguageContractionForms = 1;

[ LanguageContraction ;
    return 0;
];


Array LanguageArticles -->
    ! Cdef   Def  Indef  
    "O " "o " "um "    
    "A " "a " "uma "   
    "Os " "os " "uns "  
    "As " "as " "umas ";

                   !             a           i
                   !             s     p     s     p
                   !             m f n m f n m f n m f n                 
Array LanguageGNAsToArticles --> 0 1 0 2 3 2 0 1 0 2 3 2;

[ LanguageDirection d;
    switch (d) {
      n_to:    print "norte";
      s_to:    print "sul";
      e_to:    print "leste";
      w_to:    print "oeste";
      ne_to:   print "nordeste";
      nw_to:   print "noroeste";
      se_to:   print "sudeste";
      sw_to:   print "sudoeste";
      u_to:    print "acima";
      d_to:    print "abaixo";
      in_to:   print "para dentro";
      out_to:  print "para fora";
      default: return RunTimeError(9,d);
    }
];

[ LanguageNumber n f;
    if (n == 0)    { print "zero"; rfalse; }
    if (n < 0)     { print "menos "; n = -n; }
    if (n >= 1000) { print (LanguageNumber) n/1000, " mil"; n = n%1000; f = 1; }
    if (n >= 100)  {
        if (f == 1) print ", ";
        print (LanguageNumber) n/100, " cem"; n = n%100; f = 1;
    }
    if (n == 0) rfalse;
    #Ifdef DIALECT_US;
    if (f == 1) print " ";
    #Ifnot;
    if (f == 1) print " e ";
    #Endif;
    switch (n) {
      1:    print "um";
      2:    print "dois";
      3:    print "tr�s";
      4:    print "quatro";
      5:    print "cinco";
      6:    print "seis";
      7:    print "sete";
      8:    print "oito";
      9:    print "nove";
      10:   print "dez";
      11:   print "onze";
      12:   print "doze";
      13:   print "treze";
      14:   print "quatorze";
      15:   print "quinze";
      16:   print "dezesseis";
      17:   print "dezessete";
      18:   print "dezoito";
      19:   print "dezenove";
      20 to 99: switch (n/10) {
        2:  print "vinte";
        3:  print "trinta";
        4:  print "quarenta";
        5:  print "cinquenta";
        6:  print "sessenta";
        7:  print "setenta";
        8:  print "oitenta";
        9:  print "noventa";
        }
        if (n%10 ~= 0) print "-", (LanguageNumber) n%10;
    }
];

[ LanguageTimeOfDay hours mins;
    print hours/10, hours%10, "h", mins/10, mins%10;
];

[ LanguageVerb i;
    switch (i) {
      'i//','inv','inventario','invent@'ario':
               print "ver o invent�rio";
      'x//':   print "examinar";
      'z//':   print "esperar";
      default: rfalse;
    }
    rtrue;
];

! ----------------------------------------------------------------------------
!  LanguageVerbIsDebugging is called by SearchScope.  It should return true 
!  if word w is a debugging verb which needs all objects to be in scope.
! ----------------------------------------------------------------------------

#Ifdef DEBUG;
[ LanguageVerbIsDebugging w;
    if (w == 'purloin' or 'tree' or 'abstract' or 'gonear' or 'scope' or 'showobj') rtrue;
    rfalse;
];
#Endif;

! ----------------------------------------------------------------------------
!  LanguageVerbLikesAdverb is called by PrintCommand when printing an UPTO_PE
!  error or an inference message.  Words which are intransitive verbs, i.e.,
!  which require a direction name as an adverb ('walk west'), not a noun
!  ('I only understood you as far as wanting to touch /the/ ground'), should
!  cause the routine to return true.
! ----------------------------------------------------------------------------

[ LanguageVerbLikesAdverb w;
    if (w == 'look' or 'go' or 'push' or 'walk') rtrue;
    rfalse;
];

! ----------------------------------------------------------------------------
!  LanguageVerbMayBeName is called by NounDomain when dealing with the 
!  player's reply to a "Which do you mean, the short stick or the long
!  stick?" prompt from the parser. If the reply is another verb (for example,
!  LOOK) then then previous ambiguous command is discarded /unless/
!  it is one of these words which could be both a verb /and/ an
!  adjective in a 'name' property.
! ----------------------------------------------------------------------------

[ LanguageVerbMayBeName w;
    if (w == 'long' or 'short' or 'normal'
                    or 'brief' or 'full' or 'verbose')
        rtrue;
    rfalse;
];

Constant NKEY__TX       = "P = pr�ximo     ";
Constant PKEY__TX       = "A = anterior";
Constant QKEY1__TX      = "V = volta ao jogo";
Constant QKEY2__TX      = "V = menu anterior";
Constant RKEY__TX       = "ENTER = para ler     ";

Constant NKEY1__KY      = 'P';
Constant NKEY2__KY      = 'p';
Constant PKEY1__KY      = 'A';
Constant PKEY2__KY      = 'a';
Constant QKEY1__KY      = 'V';
Constant QKEY2__KY      = 'v';

Constant SCORE__TX      = "Pontos: ";
Constant MOVES__TX      = "Turnos: ";
Constant TIME__TX       = "Tempo: ";
Constant CANTGO__TX     = "Voc� n�o pode seguir nessa dire��o.";
Constant FORMER__TX     = "seu antigo eu";
Constant YOURSELF__TX   = "voc� mesmo";
Constant YOU__TX        = "Voc�";
Constant DARKNESS__TX   = "Escurid�o";

Constant THOSET__TX     = "essas coisas";
Constant THAT__TX       = "isso";
Constant OR__TX         = " ou ";
Constant NOTHING__TX    = "nada";
Constant IS__TX         = " �";
Constant ARE__TX        = " est�o";
Constant IS2__TX        = "� ";
Constant ARE2__TX       = "est�o ";
Constant AND__TX        = " e ";
Constant WHOM__TX       = "quem ";
Constant WHICH__TX      = "qual ";
Constant COMMA__TX      = ", ";


[ ThatorThose obj;      ! Used in the accusative
    if (obj == player)            { print " voc� mesmo"; return; }
    if (obj has pluralname)       { print " esses"; return; }
    if (obj has animate) {
        if (obj has female)       { print "ela"; return; }
        else
            if (obj hasnt neuter) { print "ele"; return; }
    }
    print "esse";
];

[ ItorThem obj;
    if (obj == player)            { print "voc� mesmo"; return; }
    if (obj has pluralname)       { print "eles"; return; }
    if (obj has animate) {
        if (obj has female)       { print "ela"; return; }
        else
            if (obj hasnt neuter) { print "ele"; return; }
    }
    print "isso";
];

[ IsorAre obj;
    if (obj has pluralname || obj == player) print "s�o"; else print "�";
];

[ CThatorThose obj;     ! Used in the nominative
    if (obj == player)            { print "Voc�"; return; }
    if (obj has pluralname)       { print "Essas coisas"; return; }
    if (obj has animate) {
        if (obj has female)       { print "Ela"; return; }
        else
            if (obj hasnt neuter) { print "Ele"; return; }
    }
    print "Isso";
];

[ CTheyreorThats obj;
    if (obj == player)             { print "Voc�"; return; }
    if (obj has pluralname)        { print "Essas coisas"; return; }
    if (obj has animate) {
        if (obj has female)        { print "Ela"; return; }
        else if (obj hasnt neuter) { print "Ele"; return; }
    }
    print "Isso";
];

[ lo obj;
  if (obj == player) { print "lo"; return; }
  if (obj has pluralname) {
    if (obj has female) { print "las"; return; }
    else { print "los"; return; }
  } else {
    if (obj has female) { print "la"; return; }
    else { print "lo"; return; }
  }
  print "lo";
];

[ o obj;
  if (obj == player) { print "o"; return; }
  if (obj has pluralname) {
    if (obj has female) { print "as"; return; }
    else { print "os"; return; }
  } else {
    if (obj has female) { print "a"; return; }
    else { print "o"; return; }
  }
  print "o";
];

[ esta obj;
  if (obj has pluralname) { print "est�o"; return; }
  print "est�";
];

[ pode obj;
  if (obj has pluralname) { print "podem"; return; }
  print "pode";
];

! ----------------------------------------------------------------------------
! Tense is a little helper function to present the correct tense of a
! verb.  The first parameter is the verb in present tense.  The second
! parameter is the verb in past tense.  If the second parameter is
! omitted, then nothing will be printed if the appropriate tense is past.
! ----------------------------------------------------------------------------
[ Tense present past;
    if (player provides narrative_tense && player.narrative_tense == PAST_TENSE) {
        if (past == false) return;
        print (string) past;
    }
    else
        print (string) present;
];

#Ifdef TARGET_ZCODE;

[ LowerCase c;    ! for ZSCII matching ISO 8859-1
   switch (c) {
     'A' to 'Z':                            c = c + 32;
     202, 204, 212, 214, 221:               c--;
     217, 218:                              c = c - 2;
     158 to 160, 167, 168, 208 to 210:      c = c - 3;
     186 to 190, 196 to 200:                c = c - 5 ;
     175 to 180:                            c = c - 6;
   }
   return c;
];

[ UpperCase c;    ! for ZSCII matching ISO 8859-1
   switch (c) {
     'a' to 'z':                            c = c - 32;
     201, 203, 211, 213, 220:               c++;
     215, 216:                              c = c + 2;
     155 to 157, 164, 165, 205 to 207:      c = c + 3;
     181 to 185, 191 to 195:                c = c + 5 ;
     169 to 174:                            c = c + 6;
   }
   return c;
];

#Ifnot; ! TARGET_GLULX

[ LowerCase c; return glk_char_to_lower(c); ];
[ UpperCase c; return glk_char_to_upper(c); ];

#Endif; ! TARGET_

[ LanguageLM n x1;
  Answer,Ask:
            "N�o h� resposta.";
! Ask:      see Answer
  Attack:   "Viol�ncia n�o vai resolver neste caso.";
  Blow:     "Seria in�til sopr�-", (lo) x1, ".";
  Burn:     "Isso seria perigoso. E in�til.";
  Buy:      "N�o h� nada � venda.";
  Climb:    "Isso n�o vai dar resultado nenhum.";
  Close: switch (n) {
        1:  print_ret "Voc� n�o pode fech�-", (lo) x1, ".";
        2:  print_ret "J� ", (esta) x1, " fechad", (o) x1, ".";
        3:  "Voc� fecha ", (the) x1, ".";
    }
  CommandsOff: switch (n) {
        1: "[Grava��o de comandos desligada.]";
        #Ifdef TARGET_GLULX;
        2: "[Grava��o de comandos j� est� desligada.]";
        #Endif; ! TARGET_
    }
  CommandsOn: switch (n) {
        1: "[Grava��o de comandos ligada.]";
        #Ifdef TARGET_GLULX;
        2: "[Comandos est�o sendo repetidos.]";
        3: "[Grava��o de comandos j� est� ligada.]";
        4: "[A grava��o de comandos falhou.]";
        #Endif; ! TARGET_
    }
  CommandsRead: switch (n) {
        1: "[Repetindo comandos.]";
        #Ifdef TARGET_GLULX;
        2: "[Comandos j� est�o sendo repetidos.]";
        3: "[Repeti��o de comandos falhou.  Grava��o de comandos est� ligada.]";
        4: "[Repeti��o de comandos falhou.]";
        5: "[Repeti��o de comandos completa.]";
        #Endif; ! TARGET_
    }
  Consult:  "Voc� n�o descobre nada de interessante n", (the) x1, ".";
  Cut:      "Cort�-", (lo) x1, " n�o dar� grandes resultados.";
  Dig:      "Cavar n�o vai servir para nada aqui.";
  Disrobe: switch (n) {
        1:  "Voc� n�o est� usando ", (the) x1, ".";
        2:  "Voc� tira ", (the) x1, ".";
    }
  Drink:    "N�o h� nada bom para se beber por aqui.";
  Drop: switch (n) {
        1:  if (x1 has pluralname) print (The) x1, " j� est�o "; else print (The) x1, " j� est� ";
            "aqui.";
        2:  "Voc� n�o est� com ", (the) x1, ".";
        3:  "(primeiro tirando ", (the) x1, ")";
        4:  "Ok.";
    }
  Eat: switch (n) {
        1:  print_ret (The) x1, " � simplesmente intrag�vel.";
        2:  "Voc� come ", (the) x1, ". Nada mal.";
    }
  EmptyT: switch (n) {
        1:  print_ret (The) x1, " n�o ", (pode) x1, " conter outras coisas.";
        2:  print_ret (The) x1, " ", (esta) x1, " fechad", (o) x1, ".";
        3:  print_ret (The) x1, " j� ", (esta) x1, " vazi", (o) x1, ".";
        4:  "N�o d� para esvaziar isso...";
    }
  Enter: switch (n) {
        1:  print "Mas voc� j� est� ";
            if (x1 has supporter) print "sobre "; else print "dentro d";
            print_ret (the) x1, ".";
        2:  print "Isso n�o � algo em que voc� possa ";
            switch (verb_word) {
              'stand':  "ficar de p�.";
              'sit':    "sentar-se.";
              'lie':    "deitar-se.";
              default:  "entrar.";
            }
        3:  "Voc� n�o pode entrar n", (the) x1, " fechad", (o) x1, ".";
        4:  "Voc� s� pode entrar em algo independente.";
        5:  print "Voc� est� ";
            if (x1 has supporter) print "sobre "; else print "dentro d";
            print_ret (the) x1, ".";
        6:  print "(";
            if (x1 has supporter) print "descendo d"; else print "saindo d";
            print (the) x1; ")";
        7:  if (x1 has supporter) "(subindo n", (the) x1, ")^";
            if (x1 has container) "(entrando n", (the) x1, ")^";
            "(entrando n", (the) x1, ")^";
    }
  Examine: switch (n) {
        1:  "Escurid�o, substantivo.  A aus�ncia da luz com a qual voc� poderia enxergar.";
        2:  "Voc� n�o v� nada de especial n", (the) x1, ".";
        3:  print (The) x1, " ", (esta) x1, " ";
            if (x1 has on) print "ligad"; else "desligad";
            print_ret (o) x1;
    }
  Exit: switch (n) {
        1:  "Mas voc� n�o est� dentro de nada...";
        2:  "N�o d�: ", (the) x1, " ", (esta) x1, " fechad", (o) x1, ".";
        3:  print "Voc� ";
            if (x1 has supporter) print "desce d"; else print "sai d";
            print_ret (the) x1, ".";
        4:  print "Mas voc� n�o est� ";
            if (x1 has supporter) print "sobre "; else print "dentro d";
            print_ret (the) x1, ".";
    }
  Fill:     "Mas n�o h� �gua aqui...";
  FullScore: switch (n) {
        1:  if (deadflag) print "Sua pontua��o era "; else print "Sua pontua��o � ";
            "a seguinte:^";
        2:  "encontrar diversos itens";
        3:  "visitar diversos lugares";
        4:  print "at� agora (de um total de  ", MAX_SCORE; " poss�veis)";
    }
  GetOff:   "Mas voc� n�o est� sobre ", (the) x1, " agora...";
  Give: switch (n) {
        1:  "Voc� n�o est� com ", (the) x1, ".";
        2:  "Voc� brinca com ", (the) x1, " por um tempo, mas n�o consegue muita coisa.";
        3:  print (The) x1;
            if (x1 has pluralname) print " n�o demonstram"; else print " n�o demonstra";
            " nenhum interesse.";
    }
  Go: switch (n) {
        1:  print "Voc� vai ter que ";
            if (x1 has supporter) print "descer d"; else print "sair d";
            print_ret (the) x1, " primeiro.";
        2:  print_ret (string) CANTGO__TX;   ! "You can't go that way."
        3:  "Voc� n�o consegue subir pel", (the) x1, ".";
        4:  "Voc� n�o consegue descer pel", (the) x1, ".";
        5:  "N�o d�, porque ", (the) x1, " ", (esta) x1, " no caminho.";
        6:  print "Voc� n�o pode, porque ", (the) x1;
            if (x1 has pluralname) " n�o levam a lugar algum."; else " n�o leva a lugar algum.";
    }
  Insert: switch (n) {
        1:  "Voc� precisa estar segurando ", (the) x1, " antes de coloc�-l", (o) x1,
            " em alguma outra coisa.";
        2:  print_ret (The) x1, " n�o pode conter outras coisas.";
        3:  print_ret (The) x1, " ", (esta) x1, " fechad", (o) x1, ".";
        4:  "Voc� precisa tirar ", (the) x1, " antes.";
        5:  "Voc� n�o pode colocar uma coisa dentro dela mesma!";
        6:  "(tirando ", (the) x1, " antes)^";
        7:  "N�o h� mais espa�o n", (the) x1, ".";
        8:  "Feito.";
        9:  "Voc� coloca ", (the) x1, " n", (the) second, ".";
    }
  Inv: switch (n) {
        1:  "Voc� n�o est� carregando nada.";
        2:  print "Voc� est� carregando";
        3:  print ":^";
        4:  print ".^";
    }
  Jump:     "Voc� pula algumas vezes no mesmo lugar. Obviamente, sem resultados.";
  JumpOver,Tie:
            "Voc� n�o conseguir� nada fazendo isso.";
  Kiss:     "Ei, mantenha o foco, ok?";
  Listen:   "Voc� n�o ouve nada fora do comum.";
  ListMiscellany: switch (n) {
        1:  print " (provendo luz)";
        2:  print " (que ", (esta) x1, " fechad", (o) x1, ")";
        3:  print " (fechad", (o) x1, " e provendo luz)";
        4:  print " (que ", (esta) x1, " vazi", (o) x1, ")";
        5:  print " (vazi", (o) x1, " e provendo luz)";
        6:  print " (que ", (esta) x1, " fechad", (o) x1, " e vazi", (o) x1, ")";
        7:  print " (fechad", (o) x1, ", vazi", (o) x1, " e provendo luz)";
        8:  print " (provendo luz e sendo usad", (o) x1;
        9:  print " (provendo luz";
        10: print " (sendo usad", (o) x1;
        11: print " (que ", (esta) x1, " ";
        12: print "abert", (o) x1;
        13: print "abert", (o) x1, " mas vazi", (o) x1;
        14: print "fechad", (o) x1;
        15: print "fechad", (o) x1, " e trancad", (o) x1;
        16: print " e vazi", (o) x1;
        17: print " (que ", (esta) x1, " vazi", (o) x1, ")";
        18: print " contendo ";
        19: print " (sobre ";
        20: print ", sobre ";
        21: print " (dentro d";
        22: print ", dentro d";
    }
    ! TODO Continuar daqui
  LMode1:   " is now in its normal ~brief~ printing mode, which gives long descriptions
             of places never before visited and short descriptions otherwise.";
  LMode2:   " is now in its ~verbose~ mode, which always gives long descriptions
             of locations (even if you've been there before).";
  LMode3:   " is now in its ~superbrief~ mode, which always gives short descriptions
             of locations (even if you haven't been there before).";
  Lock: switch (n) {
        1:  if (x1 has pluralname) print "They don't "; else print "That doesn't ";
            "seem to be something you can lock.";
        2:  print_ret (ctheyreorthats) x1, " locked at the moment.";
        3:  "First you'll have to close ", (the) x1, ".";
        4:  if (x1 has pluralname) print "Those don't "; else print "That doesn't ";
            "seem to fit the lock.";
        5:  "You lock ", (the) x1, ".";
    }
  Look: switch (n) {
        1:  print " (sobre ", (the) x1, ")";
        2:  print " (dentro d", (the) x1, ")";
        3:  print " (como ", (object) x1, ")";
        4:  print "^Sobre ", (the) x1;
            WriteListFrom(child(x1),
              ENGLISH_BIT+RECURSE_BIT+PARTINV_BIT+TERSE_BIT+CONCEAL_BIT+ISARE_BIT);
            ".";
        5,6:
            if (x1 ~= location) {
                if (x1 has supporter) print "^Sobre "; else print "^Dentro d";
                print (the) x1, " voc�";
            }
            else print "^Voc�";
            if (n == 5) print "tamb�m ";
            print " pode ";
            print "ver ";
            WriteListFrom(child(x1),
              ENGLISH_BIT+RECURSE_BIT+PARTINV_BIT+TERSE_BIT+CONCEAL_BIT+WORKFLAG_BIT);
            if (x1 ~= location) "."; else " aqui.";
        7:  "Voc� n�o v� nada que n�o seria de se esperar nessa dire��o.";
    }
  LookUnder: switch (n) {
        1:  "Mas est� escuro.";
        2:  "Voc� n�o encontra nada que possa interessar.";
    }
  Mild:     "Ah, � mesmo.";
  Miscellany: switch (n) {
        1:  "(considerando apenas os dezesseis primeiros objetos)^";
        2:  "Nada a fazer!";
        3:  print " Voc� morreu ";
        4:  print " Voc� venceu ";
        5:  print "^Would you like to RESTART, RESTORE a saved game";
            #Ifdef DEATH_MENTION_UNDO;
            print ", UNDO your last move";
            #Endif;
            if (TASKS_PROVIDED == 0) print ", give the FULL score for that game";
            if (deadflag == 2 && AMUSING_PROVIDED == 0)
                print ", see some suggestions for AMUSING things to do";
            " or QUIT?";
        6:  "[Your interpreter does not provide ~undo~.  Sorry!]";
            #Ifdef TARGET_ZCODE;
        7:  "~Undo~ failed.  [Not all interpreters provide it.]";
            #Ifnot; ! TARGET_GLULX
        7:  "[You cannot ~undo~ any further.]";
            #Endif; ! TARGET_
        8:  "Please give one of the answers above.";
        9:  "^Agora est� completamente escuro aqui!";
        10: "N�o entendi. O que voc� quis dizer mesmo?";
        11: "[You can't ~undo~ what hasn't been done!]";
        12: "[Can't ~undo~ twice in succession. Sorry!]";
        13: "[Previous turn undone.]";
        14: "Sorry, that can't be corrected.";
        15: "Think nothing of it.";
        16: "~Oops~ can only correct a single word.";
        17: "It is pitch dark, and you can't see a thing.";
        18: print "yourself";
        19: "As good-looking as ever.";
        20: "To repeat a command like ~frog, jump~, just say ~again~, not ~frog, again~.";
        21: "You can hardly repeat that.";
        22: "You can't begin with a comma.";
        23: "You seem to want to talk to someone, but I can't see whom.";
        24: "You can't talk to ", (the) x1, ".";
        25: "To talk to someone, try ~someone, hello~ or some such.";
        26: "(first taking ", (the) not_holding, ")";
        27: "I didn't understand that sentence.";
        28: print "I only understood you as far as wanting to ";
        29: "I didn't understand that number.";
        30: "You can't see any such thing.";
        31: "You seem to have said too little!";
        32: "You aren't holding that!";
        33: "You can't use multiple objects with that verb.";
        34: "You can only use multiple objects once on a line.";
        35: "I'm not sure what ~", (address) pronoun_word, "~ refers to.";
        36: "You excepted something not included anyway!";
        37: "You can only do that to something animate.";
            #Ifdef DIALECT_US;
        38: "That's not a verb I recognize.";
            #Ifnot;
        38: "That's not a verb I recognise.";
            #Endif;
        39: "That's not something you need to refer to in the course of this game.";
        40: "You can't see ~", (address) pronoun_word, "~ (", (the) pronoun_obj,
            ") at the moment.";
        41: "I didn't understand the way that finished.";
        42: if (x1 == 0) print "None"; else print "Only ", (number) x1;
            print " of those ";
            if (x1 == 1) print "is"; else print "are";
            " available.";
        43: "Nothing to do!";
        44: "There are none at all available!";
        45: print "Who do you mean, ";
        46: print "Which do you mean, ";
        47: "Sorry, you can only have one item here. Which exactly?";
        48: print "Whom do you want";
            if (actor ~= player) print " ", (the) actor;
            print " to "; PrintCommand(); print "?^";
        49: print "What do you want";
            if (actor ~= player) print " ", (the) actor;
            print " to "; PrintCommand(); print "?^";
        50: print "Your score has just gone ";
            if (x1 > 0) print "up"; else { x1 = -x1; print "down"; }
            print " by ", (number) x1, " point";
            if (x1 > 1) print "s";
        51: "(Since something dramatic has happened, your list of commands has been cut short.)";
        52: "^Type a number from 1 to ", x1, ", 0 to redisplay or press ENTER.";
        53: "^[Please press SPACE.]";
        54: "[Comment recorded.]";
        55: "[Comment NOT recorded.]";
        56: print ".^";
        57: print "?^";
    }
  No,Yes:   "That was a rhetorical question.";
  NotifyOff:
            "Score notification off.";
  NotifyOn: "Score notification on.";
  Objects: switch (n) {
        1:  "Objects you have handled:^";
        2:  "None.";
        3:  print "   (worn)";
        4:  print "   (held)";
        5:  print "   (given away)";
        6:  print "   (in ", (name) x1, ")";
        7:  print "   (in ", (the) x1, ")";
        8:  print "   (inside ", (the) x1, ")";
        9:  print "   (on ", (the) x1, ")";
        10: print "   (lost)";
    }
  Open: switch (n) {
        1:  print_ret (ctheyreorthats) x1, " not something you can open.";
        2:  if (x1 has pluralname) print "They seem "; else print "It seems ";
            "to be locked.";
        3:  print_ret (ctheyreorthats) x1, " already open.";
        4:  print "You open ", (the) x1, ", revealing ";
            if (WriteListFrom(child(x1), ENGLISH_BIT+TERSE_BIT+CONCEAL_BIT) == 0) "nothing.";
            ".";
        5:  "You open ", (the) x1, ".";
    }
  Order:    print (The) x1;
            if (x1 has pluralname) print " have"; else print " has";
            " better things to do.";
  Places: switch (n) {
        1:  print "You have visited: ";
        2:  print ".^";
    }
  Pray:     "Nothing practical results from your prayer.";
  Prompt:   print "^>";
  Pronouns: switch (n) {
        1:  print "At the moment, ";
        2:  print "means ";
        3:  print "is unset";
        4:  "no pronouns are known to the game.";
        5:  ".";
    }
  Pull,Push,Turn: switch (n) {
        1:  if (x1 has pluralname) print "Those are "; else print "It is ";
            "fixed in place.";
        2:  "You are unable to.";
        3:  "Nothing obvious happens.";
        4:  "That would be less than courteous.";
    }
! Push: see Pull
  PushDir: switch (n) {
        1:  "Is that the best you can think of?";
        2:  "That's not a direction.";
        3:  "Not that way you can't.";
    }
  PutOn: switch (n) {
        1:  "You need to be holding ", (the) x1, " before you can put ",
                (itorthem) x1, " on top of something else.";
        2:  "You can't put something on top of itself.";
        3:  "Putting things on ", (the) x1, " would achieve nothing.";
        4:  "You lack the dexterity.";
        5:  "(first taking ", (itorthem) x1, " off)^";
        6:  "There is no more room on ", (the) x1, ".";
        7:  "Done.";
        8:  "You put ", (the) x1, " on ", (the) second, ".";
    }
  Quit: switch (n) {
        1:  print "Por favor, responda sim ou n�o.";
        2:  print "Tem certeza de que quer encerrar esta sess�o de jogo? ";
    }
  Remove: switch (n) {
        1:  if (x1 has pluralname) print "They are"; else print "It is";
            " unfortunately closed.";
        2:  if (x1 has pluralname) print "But they aren't"; else print "But it isn't";
            " there now.";
        3:  "Removed.";
    }
  Restart: switch (n) {
        1:  print "Tem certeza de que quer reiniciar? ";
        2:  "N�o foi poss�vel reiniciar.";
    }
  Restore: switch (n) {
        1:  "A restaura��o falhou.";
        2:  "Ok.";
    }
  Rub:      "N�o deu resultado nenhum.";
  Save: switch (n) {
        1:  "N�o foi poss�vel salvar o estado atual do jogo.";
        2:  "Ok.";
    }
  Score: switch (n) {
        1:  if (deadflag) print "In that game you scored "; else print "You have so far scored ";
            print score, " out of a possible ", MAX_SCORE, ", in ", turns, " turn";
            if (turns ~= 1) print "s";
            return;
        2:  "There is no score in this story.";
    }
  ScriptOff: switch (n) {
        1:  "Transcripting is already off.";
        2:  "^End of transcript.";
        3:  "Attempt to end transcript failed.";
    }
  ScriptOn: switch (n) {
        1:  "Transcripting is already on.";
        2:  "Start of a transcript of";
        3:  "Attempt to begin transcript failed.";
    }
  Search: switch (n) {
        1:  "But it's dark.";
        2:  "There is nothing on ", (the) x1, ".";
        3:  print "On ", (the) x1;
            WriteListFrom(child(x1), ENGLISH_BIT+TERSE_BIT+CONCEAL_BIT+ISARE_BIT);
            ".";
        4:  "Voc� n�o nota nada de importante n", (the) x1, ".";
        5:  "Voc� n�o pode olhar l� dentro, porque ", (the) x1, " ", (esta) x1, " fechad", (o) x1, ".";
        6:  print_ret (The) x1, " ", (esta) x1, " vazi", (o) x1, ".";
        7:  print "N", (the) x1;
            WriteListFrom(child(x1), ENGLISH_BIT+TERSE_BIT+CONCEAL_BIT+ISARE_BIT);
            ".";
    }
  Set:      "No, you can't set ", (thatorthose) x1, ".";
  SetTo:    "No, you can't set ", (thatorthose) x1, " to anything.";
  Show: switch (n) {
        1:  "Voc� n�o est� com ", (the) x1, ".";
        2:  print_ret (The) x1, " n�o ", (esta) x1, " impressionad", (o) x1, ".";
    }
  Sing:     "Voc� canta muito mal. S�rio.";
  Sleep:    "Voc� n�o est� com muito sono.";
  Smell:    "Voc� n�o sente nenhum cheiro incomum.";
  Sorry:    "Ah, n�o precisa se desculpar.";
  Squeeze: switch (n) {
        1:  "Hmm. Melhor n�o.";
        2:  "Voc� n�o vai conseguir nada fazendo isso.";
    }
  Strong:   "Ah, que coisa mais feia!";
  Swim:     "N�o h� �gua suficiente para nadar aqui.";
  Swing:    "N�o h� nada aqui que fa�a sentido balan�ar.";
  SwitchOff: switch (n) {
        1:  print_ret "Voc� n�o pode desligar ", (the) x1, ". Como poderia?";
        2:  print_ret (The) x1, " j� ", (esta) x1, " desligad", (o) x1, ".";
        3:  "Voc� desliga ", (the) x1, ".";
    }
  SwitchOn: switch (n) {
        1:  print_ret "Voc� n�o pode ligar ", (the) x1, ". Como poderia?";
        2:  print_ret (The) x1, " j� ", (esta) x1, " ligad", (o) x1, ".";
        3:  "Voc� liga ", (the) x1, ".";
    }
  Take: switch (n) {
        1:  "Peguei.";
        2:  "You are always self-possessed.";
        3:  "I don't suppose ", (the) x1, " would care for that.";
        4:  print "You'd have to get ";
            if (x1 has supporter) print "off "; else print "out of ";
            print_ret (the) x1, " first.";
        5:  "You already have ", (thatorthose) x1, ".";
        6:  if (noun has pluralname) print "Those seem "; else print "That seems ";
            "to belong to ", (the) x1, ".";
        7:  if (noun has pluralname) print "Those seem "; else print "That seems ";
            "to be a part of ", (the) x1, ".";
        8:  print_ret (Cthatorthose) x1, " ", (isorare) x1,
            "n't available.";
        9:  print_ret (The) x1, " ", (isorare) x1, "n't open.";
        10: if (x1 has pluralname) print "They're "; else print "That's ";
            "hardly portable.";
        11: if (x1 has pluralname) print "They're "; else print "That's ";
            "fixed in place.";
        12: "You're carrying too many things already.";
        13: "(putting ", (the) x1, " into ", (the) SACK_OBJECT, " to make room)";
    }
  Taste:    "Voc� n�o percebe nenhum sabor incomum.";
  Tell: switch (n) {
        1:  "Voc� fala sozinho por um tempo.";
        2:  "Voc� n�o obt�m nenhuma rea��o.";
    }
  Think:    "Que boa id�ia!";
  ThrowAt: switch (n) {
        1:  "In�til.";
        2:  "No �ltimo momento, voc� desiste.";
    }
! Tie:  see JumpOver.
  Touch: switch (n) {
        1:  "N�o, melhor n�o.";
        2:  "Voc� n�o sente nada incomum.";
        3:  "Se voc� acha que isso pode ajudar...";
    }
! Turn: see Pull.
  Unlock:  switch (n) {
        1:  if (x1 has pluralname) print "They don't "; else print "That doesn't ";
            "seem to be something you can unlock.";
        2:  print_ret (ctheyreorthats) x1, " unlocked at the moment.";
        3:  if (x1 has pluralname) print "Those don't "; else print "That doesn't ";
            "seem to fit the lock.";
        4:  "You unlock ", (the) x1, ".";
    }
  VagueGo:  "Voc� precisa dizer em que dire��o quer ir.";
  Verify: switch (n) {
        1:  "O arquivo do jogo foi verificado e est� intacto.";
        2:  "O arquivo do jogo foi verificado, mas n�o est� intacto. De fato, ele pode at� mesmo estar corrompido. Lament�vel.";
    }
  Wait:     "O tempo passa.";
  Wake:     "A terr�vel verdade � que isto n�o � um sonho.";
  WakeOther:"Isso n�o parece necess�rio.";
  Wave: switch (n) {
        1:  "Mas voc� n�o est� segurando ", (the) x1, ".";
        2:  "Voc� parece rid�culo acenando com ", (the) x1, ".";
    }
  WaveHands:"Voc� acena, sentindo-se tolo.";
  Wear: switch (n) {
        1:  "Voc� n�o pode usar ", (the) x1, "!";
        2:  "Voc� n�o est� com ", (the) x1, "!";
        3:  "Voc� j� est� usando ", (the) x1, "!";
        4:  "Voc� coloca ", (the) x1, ".";
    }
! Yes:  see No.
];

! ==============================================================================

Constant LIBRARY_ENGLISH;       ! for dependency checking.

! ==============================================================================
