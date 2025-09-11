! vim:ft=inform:
! ==============================================================================
!   GRAMMAR:  Grammar table entries for the standard verbs library.
!
!   Supplied for use with Inform 6 -- Release 6/11 -- Serial number 040227
!
!   Copyright Graham Nelson 1993-2004 but freely usable (see manuals)
!
!   In your game file, Include three library files in this order:
!       Include "Parser";
!       Include "VerbLib";
!       Include "Grammar";
! ==============================================================================

System_file;

! ------------------------------------------------------------------------------
!  The "meta-verbs", commands to the game rather than in the game, come first:
! ------------------------------------------------------------------------------

Verb meta 'breve' 'normal'
*                                   -> LMode1;
Verb meta 'verboso' 'longo'
*                                   -> LMode2;
Verb meta 'superbreve' 'curto'
*                                   -> LMode3;
Verb meta 'notifica@cc@~oes' 'notificacoes'
*                                   -> NotifyOn
* 'ligadas'                         -> NotifyOn
* 'desligadas'                      -> NotifyOff;
Verb meta 'pronomes' 'nomes'
*                                   -> Pronouns;
Verb meta 'encerrar' 'sair' 'fechar'
*                                   -> Quit;
Verb meta 'grava@cc@~ao' 'gravacao'
*                                   -> CommandsOn
* 'ligada'                          -> CommandsOn
* 'desligada'                       -> CommandsOff;
Verb meta 'replay'
*                                   -> CommandsRead;
Verb meta 'reiniciar'
*                                   -> Restart;
Verb meta 'restaurar'
*                                   -> Restore;
Verb meta 'salvar'
*                                   -> Save;
Verb meta 'pontos' 'pontua@cc@~ao' 'pontuacao'
*                                   -> Score
* 'completa'                        -> FullScore
* 'completos'                       -> FullScore;
Verb meta 'script' 'transcri@cc@~ao' 'transcricao'
*                                   -> ScriptOn
* 'ligada'                          -> ScriptOn
* 'ligado'                          -> ScriptOn
* 'desligada'                       -> ScriptOff
* 'desligado'                       -> ScriptOff;
Verb meta 'verificar'
*                                   -> Verify;
Verb meta 'vers@~ao' 'versao'
*                                   -> Version;

#Ifndef NO_PLACES;
Verb meta 'objetos'
*                                   -> Objects;
Verb meta 'lugares'
*                                   -> Places;
#Endif; ! NO_PLACES

! ------------------------------------------------------------------------------
!  Debugging grammar
! ------------------------------------------------------------------------------

#Ifdef DEBUG;
Verb meta 'actions'
*                                   -> ActionsOn
* 'on'                              -> ActionsOn
* 'off'                             -> ActionsOff;
Verb meta 'changes'
*                                   -> ChangesOn
* 'on'                              -> ChangesOn
* 'off'                             -> ChangesOff;
Verb meta 'gonear'
* noun                              -> Gonear;
Verb meta 'goto'
* number                            -> Goto;
Verb meta 'random'
*                                   -> Predictable;
Verb meta 'routines' 'messages'
*                                   -> RoutinesOn
* 'on'                              -> RoutinesOn
* 'off'                             -> RoutinesOff;
Verb meta 'scope'
*                                   -> Scope
* noun                              -> Scope;
Verb meta 'showobj'
*                                   -> Showobj
* number                            -> Showobj
* multi                             -> Showobj;
Verb meta 'showverb'
* special                           -> Showverb;
Verb meta 'timers' 'daemons'
*                                   -> TimersOn
* 'on'                              -> TimersOn
* 'off'                             -> TimersOff;
Verb meta 'trace'
*                                   -> TraceOn
* number                            -> TraceLevel
* 'on'                              -> TraceOn
* 'off'                             -> TraceOff;
Verb meta 'abstract'
* noun 'to' noun                    -> XAbstract;
Verb meta 'purloin'
* multi                             -> XPurloin;
Verb meta 'tree'
*                                   -> XTree
* noun                              -> XTree;

#Ifdef TARGET_GLULX;
Verb meta 'glklist'
*                                   -> Glklist;
#Endif; ! TARGET_

#Endif; ! DEBUG

! ------------------------------------------------------------------------------
!  And now the game verbs.
! ------------------------------------------------------------------------------

[ ADirection; if (noun in compass) rtrue; rfalse; ];

Verb 'responda' 'diga' 'grite' 'fale'
* topic 'para' creature             -> Answer;
Verb 'pergunte' 'pe@cca' 'peca'
* creature 'sobre' topic            -> Ask
* noun 'para' creature              -> AskFor
* creature 'para' topic             -> AskTo
* 'desculpas'/'desculpa'            -> Sorry;
Verb 'ataque' 'quebre' 'rache' 'destrua'
'lute' 'mate' 'assassine' 'soque'
'chute' 'torture'
* noun                              -> Attack
* 'com' noun                        -> Attack;
Verb 'sopre'
* held                              -> Blow;
Verb 'droga' 'porcaria'
*                                   -> Mild
* 'de' topic                        -> Mild;
Verb 'queime' 'acenda'
* noun                              -> Burn
* noun 'com' held                   -> Burn;
Verb 'compre'
* noun                              -> Buy;
Verb 'suba' 'escale'
* noun                              -> Climb
* 'em'/'no'/'na'/'nos'/'nas' noun   -> Enter;
Verb 'feche' 'cubra' 'tampe'
* noun                              -> Close;
Verb 'corte' 'pique' 'pode' 'fatie'
* noun                              -> Cut;
Verb 'cave'
* noun                              -> Dig
* noun 'com' held                   -> Dig;
Verb 'beba' 'engula' 'tome'
* noun                              -> Drink;
Verb 'solte' 'descarte' 'largue'
* multiheld                         -> Drop;
Verb 'coloque' 'ponha'
* multiexcept 'em'/'no'/'na'/'nos'/'nas' noun -> Insert
* multiexcept 'sobre' noun          -> PutOn
* held                              -> Wear
* held 'no' 'chao'/'ch@~ao'         -> Drop
* multiheld 'no' 'chao'/'ch@~ao'    -> Drop;
Verb 'jogue' 'arremesse' 'atire'
* held 'em'/'no'/'na'/'nos'/'nas' noun -> ThrowAt;
Verb 'coma'
* held                              -> Eat;
Verb 'esvazie'
* noun                              -> Empty
* noun 'no'/'na'/'nos'/'nas' noun   -> EmptyT;
Verb 'entre' 'cruze'
*                                   -> GoIn
* 'em'/'no'/'na'/'nos'/'nas' noun   -> Enter;
Verb 'vasculhe' 
* noun                              -> Search;
Verb 'x//' 'examine' 'cheque' 'descreva' 'observe' 'olhe' 'veja' 
*                                   -> Look
* noun                              -> Examine
* 'em'/'no'/'na'/'nos'/'nas' noun   -> Search
* 'dentro' 'de'/'do'/'da'/'dos'/'das' noun -> Search
* 'debaixo' 'de'/'do'/'da'/'dos'/'das' noun -> LookUnder
* 'em' 'baixo' 'de'/'do'/'da'/'dos'/'das' noun -> LookUnder
* noun=ADirection                   -> Examine;
Verb 'pesquise' 'consulte' 'procure'
* topic 'em'/'no'/'na'/'nos'/'nas' noun -> Consult
* noun 'sobre' topic                -> Consult
* noun 'no' topic                   -> Consult;
Verb 'saia'
*                                   -> Exit
* 'de'/'do'/'da'/'dos'/'das' noun   -> Exit;
Verb 'va' 'v@'a' 'corra' 'caminhe'
*                                   -> VagueGo
* 'para' noun=ADirection            -> Go
* 'para' noun                       -> Enter;
Verb 'encha' 'preencha'
* noun                              -> Fill;
Verb 'pegue' 'obtenha' 'tire' 'retire' 'carregue' 'segure'
* multi                             -> Take
* multiinside 'de'/'do'/'da'/'dos'/'das' noun -> Remove
* multiinside 'de dentro' 'de'/'do'/'da'/'dos'/'das' noun -> Remove;
Verb 'levante'
*                                   -> Exit
* 'de'/'do'/'da'/'dos'/'das' noun   -> GetOff;
Verb 'de' 'd@^e' 'alimente' 'ofereca' 'ofere@cca' 'pague'
* held 'para' creature              -> Give
* 'a//'/'ao' creature held          -> Give reverse;
Verb 'insira'
* multiexcept 'em'/'no'/'na'/'nos'/'nas' noun -> Insert;
Verb 'inventario' 'invent@'ario' 'inv' 'i//'
*                                   -> Inv
* 'alto'                            -> InvTall
* 'largo'                           -> InvWide;
Verb 'pule' 'salte'
*                                   -> Jump
* 'sobre' noun                      -> JumpOver;
Verb 'beije' 'abrace'
* creature                          -> Kiss;
Verb 'ouca' 'ou@cca' 'escute'
*                                   -> Listen
* noun                              -> Listen;
Verb 'tranque' 'trave'
* noun 'com' held                   -> Lock;
Verb 'nao' 'n@~ao'
*                                   -> No;
Verb 'abra' 'descubra' 'desembrulhe'
* noun                              -> Open
* noun 'com' held                   -> Unlock;
Verb 'reze' 'ore'
*                                   -> Pray;
Verb 'force'
* noun 'com' held                   -> Unlock;
Verb 'puxe' 'arraste'
* noun                              -> Pull;
Verb 'empurre' 'mova' 'desloque'
* noun                              -> Push
* noun 'para' noun                  -> PushDir;
Verb 'leia'
* noun                              -> Examine
* 'sobre' topic 'em'/'no'/'na'/'nos'/'nas' noun -> Consult;
Verb 'esfregue' 'limpe' 'varra' 
* noun                              -> Rub;
Verb 'ajuste' 'regule'
* noun                              -> Set
* noun 'para' special               -> SetTo;
Verb 'dispa'
* held                              -> Disrobe;
Verb 'mostre' 'exiba' 'apresente'
* held 'para' creature              -> Show reverse
* held 'a//'/'ao' creature          -> Show;
Verb 'merda' 'porra' 'foda'
*                                   -> Strong
* 'de' topic                        -> Strong;
Verb 'cante'
*                                   -> Sing;
Verb 'sente' 'deite' 'sente-se' 'deite-se'
* 'sobre' noun                      -> Enter
* 'em'/'no'/'na'/'nos'/'nas' noun   -> Enter;
Verb 'durma' 'cochile'
*                                   -> Sleep;
Verb 'cheire' 'fareje'
*                                   -> Smell
* noun                              -> Smell;
Verb 'desculpe'
*                                   -> Sorry;
Verb 'esprema' 'esmague' 'achate'
* noun                              -> Squeeze;
Verb 'nade' 'mergulhe'
*                                   -> Swim;
Verb 'balance'
* noun                              -> Swing
* 'em'/'no'/'na'/'nos'/'nas' noun   -> Swing;
Verb 'remova'
* worn                              -> Disrobe;
Verb 'prove' 'saboreie'
* noun                              -> Taste;
Verb 'conte'
* 'a//'/'ao' creature 'sobre' topic -> Tell;
Verb 'pense'
*                                   -> Think;
Verb 'amarre' 'junte' 'prenda' 'fixe'
* noun                              -> Tie
* noun 'a//'/'ao' noun              -> Tie
* noun 'em'/'no'/'na'/'nos'/'nas' noun -> Tie;
Verb 'toque' 'sinta'
* noun                              -> Touch;
Verb 'transfira'
* noun 'para' noun                  -> Transfer;
Verb 'gire' 'rode' 'parafuse' 'tor@cca' 'desparafuse'
* noun                              -> Turn;
Verb 'ligue' 'ative'
* noun                              -> Switchon;
Verb 'desligue' 'desative'
* noun                              -> Switchoff;
Verb 'acene'
*                                   -> WaveHands
* 'com' noun                        -> Wave;
Verb 'vista' 'use'
* held                              -> Wear;
Verb 'sim'
*                                   -> Yes;
Verb 'destranque'
* noun 'com' held                   -> Unlock;
Verb 'espere' 'aguarde' 'z//'
*                                   -> Wait;
Verb 'acorde' 'desperte'
*                                   -> Wake
* creature                          -> WakeOther;

! ------------------------------------------------------------------------------
!  Final task: provide trivial routines if the user hasn't already:
! ------------------------------------------------------------------------------

Stub AfterLife         0;
Stub AfterPrompt       0;
Stub Amusing           0;
Stub BeforeParsing     0;
Stub ChooseObjects     2;
Stub DarkToDark        0;
Stub DeathMessage      0;
Stub Epilogue 0;
Stub GamePostRoutine   0;
Stub GamePreRoutine    0;
Stub InScope           1;
Stub LookRoutine       0;
Stub NewRoom           0;
Stub ObjectDoesNotFit  2;
Stub ParseNumber       2;
Stub ParserError       1;
Stub PrintTaskName     1;
Stub PrintVerb         1;
Stub TimePasses        0;
Stub UnknownVerb       1;

#Ifdef TARGET_GLULX;
#Stub HandleGlkEvent    2;
#Stub IdentifyGlkObject 4;
#Stub InitGlkWindow     1;
#Endif; ! TARGET_GLULX

#Ifndef PrintRank;
! Constant Make__PR;
! #Endif;
! #Ifdef Make__PR;
[ PrintRank; "."; ];
#Endif;

#Ifndef ParseNoun;
! Constant Make__PN;
! #Endif;
! #Ifdef Make__PN;
[ ParseNoun obj; obj = obj; return -1; ];
#Endif;

#Default Story 0;
#Default Headline 0;

#Ifdef INFIX;
#Include "infix";
#Endif;

! ==============================================================================

Constant LIBRARY_GRAMMAR;       ! for dependency checking

! ==============================================================================
