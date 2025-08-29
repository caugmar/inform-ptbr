! vim:ft=inform:
! ==============================================================================
!   Português: Arquivo de definição de linguagem
!
!   Para uso com Inform 6 -- Release 6/11 -- Serial number 040227
!
!   Copyright Guto Marcicano 2012. Pode ser usado gratuitamente.
! ==============================================================================

System_file;

! ------------------------------------------------------------------------------
!   Part I.   Preliminaries
! ------------------------------------------------------------------------------

Constant LanguageVersion = "Tradução portuguesa por Guto Marcicano";

#ifdef TARGET_ZCODE;
Zcharacter 'á';
Zcharacter 'é';
Zcharacter 'í';
Zcharacter 'ó';
Zcharacter 'ú';
Zcharacter 'ã';
Zcharacter 'õ';
Zcharacter 'â';
Zcharacter 'ê';
Zcharacter 'ô';
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
Constant ALL3__WD       = 'tudo';
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
    3:    print "três";
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
    print "ver o inventário";
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

Constant NKEY__TX       = "P = próximo     ";
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
Constant CANTGO__TX     = "Você não pode seguir nessa direção.";
Constant FORMER__TX     = "seu antigo eu";
Constant YOURSELF__TX   = "você mesmo";
Constant YOU__TX        = "Você";
Constant DARKNESS__TX   = "Escuridão";

Constant THOSET__TX     = "essas coisas";
Constant THAT__TX       = "isso";
Constant OR__TX         = " ou ";
Constant NOTHING__TX    = "nada";
Constant IS__TX         = " é";
Constant ARE__TX        = " estão";
Constant IS2__TX        = "é ";
Constant ARE2__TX       = "estão ";
Constant AND__TX        = " e ";
Constant WHOM__TX       = "quem ";
Constant WHICH__TX      = "qual ";
Constant COMMA__TX      = ", ";


[ ThatorThose obj;      ! Used in the accusative
if (obj == player)            { print " você mesmo"; return; }
if (obj has pluralname)       { print " esses"; return; }
if (obj has animate) {
    if (obj has female)       { print "ela"; return; }
    else
        if (obj hasnt neuter) { print "ele"; return; }
}
print "esse";
];

[ ItorThem obj;
if (obj == player)            { print "você mesmo"; return; }
if (obj has pluralname)       { print "eles"; return; }
if (obj has animate) {
    if (obj has female)       { print "ela"; return; }
    else
        if (obj hasnt neuter) { print "ele"; return; }
}
print "isso";
];

[ IsorAre obj;
if (obj has pluralname || obj == player) print "são"; else print "é";
];

[ CThatorThose obj;     ! Used in the nominative
if (obj == player)            { print "Você"; return; }
if (obj has pluralname)       { print "Essas coisas"; return; }
if (obj has animate) {
    if (obj has female)       { print "Ela"; return; }
    else
        if (obj hasnt neuter) { print "Ele"; return; }
}
print "Isso";
];

[ CTheyreorThats obj;
if (obj == player)             { print "Você"; return; }
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
];

[ esta obj;
if (obj has pluralname) { print "estão"; return; }
print "está";
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
"Não há resposta.";
! Ask:      see Answer
Attack:   "Violência não vai resolver neste caso.";
Blow:     "Seria inútil soprá-", (lo) x1, ".";
Burn:     "Isso seria perigoso. E inútil.";
Buy:      "Não há nada à venda.";
Climb:    "Isso não vai dar resultado nenhum.";
Close: switch (n) {
    1:  print_ret "Você não pode fechá-", (lo) x1, ".";
    2:  print_ret "Já ", (esta) x1, " fechad", (o) x1, ".";
    3:  "Você fecha ", (the) x1, ".";
}
CommandsOff: switch (n) {
    1: "[Gravação de comandos desligada.]";
    #Ifdef TARGET_GLULX;
    2: "[Gravação de comandos já está desligada.]";
    #Endif; ! TARGET_
}
CommandsOn: switch (n) {
    1: "[Gravação de comandos ligada.]";
    #Ifdef TARGET_GLULX;
    2: "[Comandos estão sendo repetidos.]";
    3: "[Gravação de comandos já está ligada.]";
    4: "[A gravação de comandos falhou.]";
    #Endif; ! TARGET_
}
CommandsRead: switch (n) {
    1: "[Repetindo comandos.]";
    #Ifdef TARGET_GLULX;
    2: "[Comandos já estão sendo repetidos.]";
    3: "[Repetição de comandos falhou.  Gravação de comandos está ligada.]";
    4: "[Repetição de comandos falhou.]";
    5: "[Repetição de comandos completa.]";
    #Endif; ! TARGET_
}
Consult:  "Você não descobre nada de interessante n", (the) x1, ".";
Cut:      "Cortá-", (lo) x1, " não dará grandes resultados.";
Dig:      "Cavar não vai servir para nada aqui.";
Disrobe: switch (n) {
    1:  "Você não está usando ", (the) x1, ".";
    2:  "Você tira ", (the) x1, ".";
}
Drink:    "Não há nada bom para se beber por aqui.";
Drop: switch (n) {
    1:  if (x1 has pluralname) print (The) x1, " já estão "; else print (The) x1, " já está ";
    "aqui.";
    2:  "Você não está com ", (the) x1, ".";
    3:  "(primeiro tirando ", (the) x1, ")";
    4:  "Ok.";
}
Eat: switch (n) {
    1:  print_ret (The) x1, " é simplesmente intragável.";
    2:  "Você come ", (the) x1, ". Nada mal.";
}
EmptyT: switch (n) {
    1:  print_ret (The) x1, " não ", (pode) x1, " conter outras coisas.";
    2:  print_ret (The) x1, " ", (esta) x1, " fechad", (o) x1, ".";
    3:  print_ret (The) x1, " já ", (esta) x1, " vazi", (o) x1, ".";
    4:  "Não dá para esvaziar isso...";
}
Enter: switch (n) {
    1:  print "Mas você já está ";
    if (x1 has supporter) print "sobre "; else print "dentro d";
    print_ret (the) x1, ".";
    2:  print "Isso não é algo em que você possa ";
    switch (verb_word) {
        'stand':  "ficar de pé.";
        'sit':    "sentar-se.";
        'lie':    "deitar-se.";
        default:  "entrar.";
    }
    3:  "Você não pode entrar n", (the) x1, " fechad", (o) x1, ".";
    4:  "Você só pode entrar em algo independente.";
    5:  print "Você está ";
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
    1:  "Escuridão, substantivo.  A ausência da luz com a qual você poderia enxergar.";
    2:  "Você não vê nada de especial n", (the) x1, ".";
    3:  print (The) x1, " ", (esta) x1, " ";
    if (x1 has on) print "ligad"; else "desligad";
    print_ret (o) x1;
}
Exit: switch (n) {
    1:  "Mas você não está dentro de nada...";
    2:  "Não dá: ", (the) x1, " ", (esta) x1, " fechad", (o) x1, ".";
    3:  print "Você ";
    if (x1 has supporter) print "desce d"; else print "sai d";
    print_ret (the) x1, ".";
    4:  print "Mas você não está ";
    if (x1 has supporter) print "sobre "; else print "dentro d";
    print_ret (the) x1, ".";
}
Fill:     "Mas não há água aqui...";
FullScore: switch (n) {
    1:  if (deadflag) print "Sua pontuação era "; else print "Sua pontuação é ";
    "a seguinte:^";
2:  "encontrar diversos itens";
3:  "visitar diversos lugares";
4:  print "até agora (de um total de  ", MAX_SCORE; " possíveis)";
}
GetOff:   "Mas você não está sobre ", (the) x1, " agora...";
Give: switch (n) {
    1:  "Você não está com ", (the) x1, ".";
    2:  "Você brinca com ", (the) x1, " por um tempo, mas não consegue muita coisa.";
    3:  print (The) x1;
    if (x1 has pluralname) print " não demonstram"; else print " não demonstra";
    " nenhum interesse.";
}
Go: switch (n) {
    1:  print "Você vai ter que ";
    if (x1 has supporter) print "descer d"; else print "sair d";
    print_ret (the) x1, " primeiro.";
    2:  print_ret (string) CANTGO__TX;   ! "You can't go that way."
    3:  "Você não consegue subir pel", (the) x1, ".";
    4:  "Você não consegue descer pel", (the) x1, ".";
    5:  "Não dá, porque ", (the) x1, " ", (esta) x1, " no caminho.";
    6:  print "Você não pode, porque ", (the) x1;
    if (x1 has pluralname) " não levam a lugar algum."; else " não leva a lugar algum.";
}
Insert: switch (n) {
    1:  "Você precisa estar segurando ", (the) x1, " antes de colocá-l", (o) x1,
    " em alguma outra coisa.";
    2:  print_ret (The) x1, " não pode conter outras coisas.";
    3:  print_ret (The) x1, " ", (esta) x1, " fechad", (o) x1, ".";
    4:  "Você precisa tirar ", (the) x1, " antes.";
    5:  "Você não pode colocar uma coisa dentro dela mesma!";
    6:  "(tirando ", (the) x1, " antes)^";
    7:  "Não há mais espaço n", (the) x1, ".";
    8:  "Feito.";
    9:  "Você coloca ", (the) x1, " n", (the) second, ".";
}
Inv: switch (n) {
    1:  "Você não está carregando nada.";
    2:  print "Você está carregando";
    3:  print ":^";
    4:  print ".^";
}
Jump:     "Você pula algumas vezes no mesmo lugar. Obviamente, sem resultados.";
JumpOver,Tie:
"Você não conseguirá nada fazendo isso.";
Kiss:     "Ei, mantenha o foco, ok?";
Listen:   "Você não ouve nada fora do comum.";
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
LMode1:   " agora está no seu modo de impressão ~breve~ normal, que dá descrições longas
de lugares nunca antes visitados e descrições curtas em outros casos.";
LMode2:   " agora está no seu modo ~detalhado~, que sempre dá descrições longas
de lugares (mesmo se você já esteve lá antes).";
LMode3:   " agora está no seu modo ~super-breve~, que sempre dá descrições curtas
de lugares (mesmo se você nunca esteve lá antes).";
Lock: switch (n) {
    1:  if (x1 has pluralname) print "Eles não parecem ";
    else print "Isso não parece ";
    " ser algo que você possa trancar.";
    2:  print_ret (ctheyreorthats) x1, " trancados no momento.";
    3:  "Primeiro você terá que fechar ", (the) x1, ".";
    4:  if (x1 has pluralname) print "Eles não parecem ";
    else print "Ele não parece ";
    "caber na fechadura.";
    5:  "Você tranca ", (the) x1, ".";
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
    print (the) x1, " você";
}
else print "^Você";
if (n == 5) print "também ";
print " pode ";
print "ver ";
WriteListFrom(child(x1),
              ENGLISH_BIT+RECURSE_BIT+PARTINV_BIT+TERSE_BIT+CONCEAL_BIT+WORKFLAG_BIT);
if (x1 ~= location) "."; else " aqui.";
7:  "Você não vê nada que não seria de se esperar nessa direção.";
}
LookUnder: switch (n) {
    1:  "Mas está escuro.";
    2:  "Você não encontra nada que possa interessar.";
}
Mild:     "Ah, é mesmo.";
Miscellany: switch (n) {
    1:  "(considerando apenas os dezesseis primeiros objetos)^";
    2:  "Nada a fazer!";
    3:  print " Você morreu ";
    4:  print " Você venceu ";

    5:  print "^Você gostaria de REINICIAR, RESTAURAR um jogo salvo";
    #Ifdef DEATH_MENTION_UNDO;
    print ", DESFAZER sua última jogada";
    #Endif;
    if (TASKS_PROVIDED == 0) print ", ver a pontuação TOTAL do jogo";
    if (deadflag == 2 && AMUSING_PROVIDED == 0)
        print ", ver algumas sugestões de coisas DIVERTIDAS para fazer";
    " ou SAIR?";
    6:  "[Seu interpretador não fornece ~desfazer~. Desculpe!]";
    #Ifdef TARGET_ZCODE;
    7:  "O ~desfazer~ falhou. [Nem todos os interpretadores o fornecem.]";
    #Ifnot; ! TARGET_GLULX
    7:  "[Você não pode ~desfazer~ mais.]";
    #Endif; ! TARGET_
    8:  "Por favor, dê uma das respostas acima.";
    9:  "^Agora está completamente escuro aqui!";
    10: "Não entendi. O que você quis dizer mesmo?";
    11: "[Você não pode ~desfazer~ o que não foi feito!]";
    12: "[Não é possível ~desfazer~ duas vezes seguidas. Desculpe!]";
    13: "[Turno anterior desfeito.]";
    14: "Desculpe, isso não pode ser corrigido.";
    15: "Não foi nada.";
    16: "~Oops~ só pode corrigir uma única palavra.";
    17: "Está muito escuro, e você não consegue ver nada.";
    18: print "você mesmo";
    19: "Tão bonito(a) como sempre.";
    20: "Para repetir um comando como ~sapo, pule~, diga apenas ~novamente~, não ~sapo, novamente~.";
    21: "Você dificilmente pode repetir isso.";
    22: "Você não pode começar com uma vírgula.";
    23: "Você parece querer falar com alguém, mas não consigo ver quem.";
    24: "Você não pode falar com ", (the) x1, ".";
    25: "Para falar com alguém, tente ~alguém, olá~ ou algo parecido.";
    26: "(primeiro pegando ", (the) not_holding, ")";
    27: "Eu não entendi essa frase.";
    28: print "Eu só entendi que você queria ";
    29: "Eu não entendi esse número.";
    30: "Você não pode ver tal coisa.";
    31: "Parece que você disse muito pouco!";
    32: "Você não está segurando isso!";
    33: "Você não pode usar múltiplos objetos com esse verbo.";
    34: "Você só pode usar múltiplos objetos uma vez por linha.";
    35: "Não tenho certeza a que ~", (address) pronoun_word, "~ se refere.";
    36: "Você excluiu algo que nem estava incluído!";
    37: "Você só pode fazer isso com algo animado.";
    38: "Eu não reconheço esse verbo.";
    39: "Isso não é algo a que você precise se referir durante este jogo.";
    40: "Você não consegue ver ~", (address) pronoun_word, "~ (", (the) pronoun_obj,
    ") no momento.";
    41: "Eu não entendi como isso terminou.";
    42: if (x1 == 0) print "Nenhum"; else print "Apenas ", (number) x1;
    print " desses ";
    if (x1 == 1) print "é"; else print "são";
    " disponível.";
    43: "Nada a fazer!";
    44: "Não há nenhum disponível!";
    45: print "Quem você quer dizer, ";
    46: print "Qual você quer dizer, ";
    47: "Desculpe, você só pode ter um item aqui. Qual exatamente você quer?";
    48: print "Quem você quer";
    if (actor ~= player) print " ", (the) actor;
    print " para "; PrintCommand(); print "?^";
    49: print "O que você quer";
    if (actor ~= player) print " ", (the) actor;
    print " para "; PrintCommand(); print "?^";
    50: print "Sua pontuação acabou de ";
    if (x1 > 0) print "aumentar"; else { x1 = -x1; print "diminuir"; }
    print " em ", (number) x1, " ponto";
    if (x1 > 1) print "s";
    51: "(Como algo dramático aconteceu, sua lista de comandos foi encurtada.)";
    52: "^Digite um número de 1 a ", x1, ", 0 para reexibir ou pressione ENTER.";
    53: "^[Por favor, pressione ESPAÇO.]";
    54: "[Comentário gravado.]";
    55: "[Comentário NÃO gravado.]";
    56: print ".^";
    57: print "?^";
}
No,Yes:   "Essa foi uma pergunta retórica.";
NotifyOff:
"Notificação de pontuação desativada.";
NotifyOn: "Notificação de pontuação ativada.";
Objects: switch (n) {
    1:  "Objetos que você manipulou:^";
    2:  "Nenhum.";
    3:  print "   (usado)";
    4:  print "   (segurando)";
    5:  print "   (dado)";
    6:  print "   (em ", (name) x1, ")";
    7:  print "   (em ", (the) x1, ")";
    8:  print "   (dentro ", (the) x1, ")";
    9:  print "   (sobre ", (the) x1, ")";
    10: print "   (perdido)";
}
Open: switch (n) {
    1:  print_ret (ctheyreorthats) x1, " não é algo que você pode abrir.";
    2:  if (x1 has pluralname) print "Eles parecem "; else print "Parece ";
    "estar trancado.";
    3:  print_ret (ctheyreorthats) x1, " já está aberto.";
    4:  print "Você abre ", (the) x1, ", revelando ";
    if (WriteListFrom(child(x1), ENGLISH_BIT+TERSE_BIT+CONCEAL_BIT) == 0) "nada.";
    ".";
    5:  "Você abre ", (the) x1, ".";
}
Order:    print (The) x1;
if (x1 has pluralname) print " têm"; else print " tem";
" coisas melhores para fazer.";
    Places: switch (n) {
        1:  print "Você visitou: ";
        2:  print ".^";
    }
    Pray:     "Nada prático resulta da sua oração.";
    Prompt:   print "^>";
    Pronouns: switch (n) {
        1:  print "No momento, ";
        2:  print "significa ";
        3:  print "não está definido";
        4:  "nenhum pronome é conhecido pelo jogo.";
        5:  ".";
    }
    Pull,Push,Turn: switch (n) {
        1:  if (x1 has pluralname) print "Esses são "; else print "É ";
        "fixo no lugar.";
        2:  "Você não pode.";
        3:  "Nada óbvio acontece.";
        4:  "Isso seria menos do que cortês.";
    }
    ! Push: see Pull
    PushDir: switch (n) {
        1:  "Isso é o melhor que você consegue pensar?";
        2:  "Isso não é uma direção.";
        3:  "Por esse caminho você não pode.";
    }
    PutOn: switch (n) {
        1:  "Você precisa estar segurando ", (the) x1, " antes de poder colocar ",
        (itorthem) x1, " em cima de algo mais.";
        2:  "Você não pode colocar algo em cima de si mesmo.";
        3:  "Colocar coisas em ", (the) x1, " não alcançaria nada.";
        4:  "Você não tem a destreza.";
        5:  "(primeiro tirando ", (itorthem) x1, ")^";
        6:  "Não há mais espaço em ", (the) x1, ".";
        7:  "Feito.";
        8:  "Você coloca ", (the) x1, " em ", (the) second, ".";
    }  Quit: switch (n) {
        1:  print "Por favor, responda sim ou não.";
        2:  print "Tem certeza de que quer encerrar esta sessão de jogo? ";
    }
    Restart: switch (n) {
        1:  print "Tem certeza de que quer reiniciar? ";
        2:  "Não foi possível reiniciar.";
    }
    Restore: switch (n) {
        1:  "A restauração falhou.";
        2:  "Ok.";
    }
    Rub:      "Não deu resultado nenhum.";
    Save: switch (n) {
        1:  "Não foi possível salvar o estado atual do jogo.";
        2:  "Ok.";
    }
    Score: switch (n) {
        1:  if (deadflag) print "Nesse jogo você marcou "; else print "Você marcou até agora ";
        print score, " de um total de ", MAX_SCORE, ", em ", turns, " jogada";
        if (turns ~= 1) print "s";
        return;
        2:  "Não há pontuação nesta história.";
    }
    ScriptOff: switch (n) {
        1:  "A transcrição já está desligada.";
        2:  "^Fim da transcrição.";
        3:  "A tentativa de terminar a transcrição falhou.";
    }
    ScriptOn: switch (n) {
        1:  "A transcrição já está ligada.";
        2:  "Início de uma transcrição de";
        3:  "A tentativa de iniciar a transcrição falhou.";
    }
    Search: switch (n) {
        1:  "Mas está escuro.";
        2:  "Não há nada em ", (the) x1, ".";
        3:  print "Em ", (the) x1;
        WriteListFrom(child(x1), ENGLISH_BIT+TERSE_BIT+CONCEAL_BIT+ISARE_BIT);
        ".";
    4:  "Você não nota nada de importante n", (the) x1, ".";
    5:  "Você não pode olhar lá dentro, porque ", (the) x1, " ", (esta) x1, " fechad", (o) x1, ".";
    6:  print_ret (The) x1, " ", (esta) x1, " vazi", (o) x1, ".";
    7:  print "N", (the) x1;
    WriteListFrom(child(x1), ENGLISH_BIT+TERSE_BIT+CONCEAL_BIT+ISARE_BIT);
    ".";
    }
    Set:      "Não, você não pode definir ", (thatorthose) x1, ".";
    SetTo:    "Não, você não pode definir ", (thatorthose) x1, " para nada.";
    Show: switch (n) {
        1:  "Você não está com ", (the) x1, ".";
        2:  print_ret (The) x1, " não ", (esta) x1, " impressionad", (o) x1, ".";
    }
    Sing:     "Você canta muito mal. Sério.";
    Sleep:    "Você não está com muito sono.";
    Smell:    "Você não sente nenhum cheiro incomum.";
    Sorry:    "Ah, não precisa se desculpar.";
    Squeeze: switch (n) {
        1:  "Hmm. Melhor não.";
        2:  "Você não vai conseguir nada fazendo isso.";
    }
    Strong:   "Ah, que coisa mais feia!";
    Swim:     "Não há água suficiente para nadar aqui.";
    Swing:    "Não há nada aqui que faça sentido balançar.";
    SwitchOff: switch (n) {
        1:  print_ret "Você não pode desligar ", (the) x1, ". Como poderia?";
        2:  print_ret (The) x1, " já ", (esta) x1, " desligad", (o) x1, ".";
        3:  "Você desliga ", (the) x1, ".";
    }
    SwitchOn: switch (n) {
        1:  print_ret "Você não pode ligar ", (the) x1, ". Como poderia?";
        2:  print_ret (The) x1, " já ", (esta) x1, " ligad", (o) x1, ".";
        3:  "Você liga ", (the) x1, ".";
    }
    Take: switch (n) {
        1:  "Peguei.";
        2:  "Você está sempre em controle de si mesmo.";
        3:  "Eu não suponho que ", (the) x1, " se importaria com isso.";
        4:  print "Você teria que sair ";
        if (x1 has supporter) print "de cima de "; else print "de dentro de ";
        print_ret (the) x1, " primeiro.";
        5:  "Você já tem ", (thatorthose) x1, ".";
        6:  if (noun has pluralname) print "Parecem "; else print "Parece ";
        "pertencer a ", (the) x1, ".";
        7:  if (noun has pluralname) print "Parecem "; else print "Parece ";
        "fazer parte de ", (the) x1, ".";
        8:  print_ret (Cthatorthose) x1, " ", (isorare) x1,
        " não estão disponíveis.";
        9:  print_ret (The) x1, " não ", (isorare) x1, " abertos.";
        10: if (x1 has pluralname) print "Eles são "; else print "Isso é ";
        " dificilmente portátil.";
        11: if (x1 has pluralname) print "Eles estão "; else print "Isso está ";
        "fixo no lugar.";
        12: "Você já está carregando coisas demais.";
        13: "(colocando ", (the) x1, " em ", (the) SACK_OBJECT, " para abrir espaço)";
    }
    Taste:    "Você não percebe nenhum sabor incomum.";
    Tell: switch (n) {
        1:  "Você fala sozinho por um tempo.";
        2:  "Você não obtém nenhuma reação.";
    }
    Think:    "Que boa idéia!";
    ThrowAt: switch (n) {
        1:  "Inútil.";
        2:  "No último momento, você desiste.";
    }
    ! Tie:  see JumpOver.
    Touch: switch (n) {
        1:  "Não, melhor não.";
        2:  "Você não sente nada incomum.";
        3:  "Se você acha que isso pode ajudar...";
    }
    ! Turn: see Pull.
    ! TODO Continuar daqui
    Unlock:  switch (n) {
        1:  if (x1 has pluralname) print "Eles não "; else print "Isso não ";
        "parece ser algo que você possa destrancar.";
        2:  print_ret (ctheyreorthats) x1, " destrancados no momento.";
        3:  if (x1 has pluralname) print "Esses não "; else print "Esse não ";
        "parecem caber na fechadura.";
        4:  "Você destranca ", (the) x1, ".";
    }
    VagueGo:  "Você precisa dizer em que direção quer ir.";
    Verify: switch (n) {
        1:  "O arquivo do jogo foi verificado e está intacto.";
        2:  "O arquivo do jogo foi verificado, mas não está intacto. De fato, ele pode até mesmo estar corrompido. Lamentável.";
    }
    Wait:     "O tempo passa.";
    Wake:     "A terrível verdade é que isto não é um sonho.";
    WakeOther:"Isso não parece necessário.";
    Wave: switch (n) {
        1:  "Mas você não está segurando ", (the) x1, ".";
        2:  "Você parece ridículo acenando com ", (the) x1, ".";
    }
    WaveHands:"Você acena, sentindo-se tolo.";
    Wear: switch (n) {
        1:  "Você não pode usar ", (the) x1, "!";
        2:  "Você não está com ", (the) x1, "!";
        3:  "Você já está usando ", (the) x1, "!";
        4:  "Você coloca ", (the) x1, ".";
    }
    ! Yes:  see No.
];

! ==============================================================================

Constant LIBRARY_ENGLISH;       ! for dependency checking.

! ==============================================================================
