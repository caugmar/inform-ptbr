! ----------------------------------------------------------------------------
!  GRAMMAR:  Grammatica per la lingua italiana (vedere Italian.h)
!            Grammar for the italian language (see also Italian.h)
!
!  Utilizzabile con Inform v6                           Numero di serie 020825
!                                                            Revisione    6/10
!  (c) Ilario Nardinocchi 1998,1999,2000,2001,2002
!      ma liberamente distribuibile
! ----------------------------------------------------------------------------

System_file;

Verb meta 'punteggio'
                *                                -> Score
                * 'totale'			 -> FullScore;
Verb meta 'punteggione' 'totale'
                *                                -> FullScore;
Verb meta 'q//' 'uscire' 'muori' 'fine' 'basta'
                *                                -> Quit;
Verb meta 'load' 'restore' 'carica' 'caricare'
                *                                -> Restore;
Verb meta 'ricomincia' 'ricominciare'
                *                                -> Restart;
Verb meta 'verifica'
                *                                -> Verify;
Verb meta 'save' 'salva'
                *                                -> Save;
Verb meta 'trascrivi'
                *                                -> ScriptOn;
Verb meta 'non'
		* 'trascrivere'			 -> ScriptOff
		* 'notificare'			 -> NotifyOff;
Verb meta 'brevissimo' 'corto'
                *                                -> LMode3;
Verb meta 'prolisso' 'lungo' 'esteso'
                *                                -> LMode2;
Verb meta 'breve' 'normale'
                *                                -> LMode1;
Verb meta 'pronomi' 'nomi'
                *                                -> Pronouns;
Verb meta 'notifica'
                *				 -> NotifyOn;
Verb meta 'versione'
                *                                -> Version;
#IFNDEF NO_PLACES;
Verb meta 'luoghi'
                *                                -> Places;
Verb meta 'oggetti'
                *                                -> Objects;
#ENDIF;

! ----------------------------------------------------------------------------
!  Grammatica per il debugging... volutamente lasciata in inglese.
! ----------------------------------------------------------------------------

#ifdef DEBUG;
Verb meta 'trace'
                *                                -> TraceOn
                * number                         -> TraceLevel
                * 'on'                           -> TraceOn
                * 'off'                          -> TraceOff;
Verb meta 'actions'
                *                                -> ActionsOn
                * 'on'                           -> ActionsOn
                * 'off'                          -> ActionsOff;
Verb meta 'routines' 'messages'
                *                                -> RoutinesOn
                * 'on'                           -> RoutinesOn
                * 'off'                          -> RoutinesOff;
Verb meta 'timers' 'daemons'
                *                                -> TimersOn
                * 'on'                           -> TimersOn
                * 'off'                          -> TimersOff;
Verb meta 'changes'
                *                                -> ChangesOn
                * 'on'                           -> ChangesOn
                * 'off'                          -> ChangesOff;
Verb meta 'recording'
                *                                -> CommandsOn
                * 'on'                           -> CommandsOn
                * 'off'                          -> CommandsOff;
Verb meta 'replay'
                *                                -> CommandsRead;
Verb meta 'random'
                *                                -> Predictable;
Verb meta 'purloin'
                * multi                          -> XPurloin;
Verb meta 'abstract'
                * noun 'to' noun                 -> XAbstract;
Verb meta 'tree'
                *                                -> XTree
                * noun                           -> XTree;
Verb meta 'goto'
                * number                         -> Goto;
Verb meta 'gonear'
                * noun                           -> Gonear;
Verb meta 'scope'
                *                                -> Scope
                * noun                           -> Scope;
Verb meta 'showverb'
                * special                        -> Showverb;
Verb meta 'showobj'
                *                                -> Showobj
                * multi                          -> Showobj;
#endif;

! ----------------------------------------------------------------------------
!  Verbi principali.
! ----------------------------------------------------------------------------

Verb 'prendi' 'raccogli' 'piglia' 'afferra' 'acchiappa'
                * multi                          -> Take
                * multiinside 'da' noun          -> Remove;
Verb 'scendi'
                *                                -> Exit
		* 'da' noun                      -> GetOff
		* noun                           -> GetOff;
Verb 'alzati'
                *                                -> Exit
                * 'in' 'piedi'                   -> Exit
                * 'su' noun                      -> Enter;
Verb 'togli' 'rimuovi' 'leva'
                * multi                          -> Take
                * multiinside 'da' noun          -> Remove;
Verb 'togliti' 'levati'
                * held                           -> Disrobe; 
Verb 'indossa' 'mettiti'
                * held                           -> Wear;
Verb 'metti' 
                * 'giu'/'gi@`u' multiheld        -> Drop
                * multiexcept 'in'/'dentro' noun -> Insert
                * multiexcept 'su'/'sopra' noun  -> PutOn
		* noun 'a//' special             -> SetTo
		* noun 'su' special              -> SetTo;
Verb 'inserisci' 'infila'
                * multiexcept 'in'/'dentro' noun -> Insert;
Verb 'vuota'
                * noun                           -> Empty
                * noun 'in'/'dentro' noun        -> EmptyT;
Verb 'trasferisci'
                * noun 'in'/'dentro'/'su'/'sopra'/'verso' noun -> Transfer;

Verb 'getta' 'butta' 'lancia' 'scaglia'
                * multiheld                      -> Drop
                * 'via' multiheld		 		 -> Drop
                * multiexcept 'in'/'dentro' noun -> Insert
                * multiexcept 'su'/'sopra' noun  -> PutOn
                * held 'a//'/'contro'/'verso' noun
                                                 -> ThrowAt;
Verb 'lascia' 'posa' 'riponi' 'appoggia'
                * multiheld                      -> Drop
                * multiexcept 'in'/'dentro' noun -> Insert
                * multiexcept 'su'/'sopra' noun  -> PutOn;

Verb 'd@`a' 'da' 'offri' 'porgi' 'dona'

! La terza voce (dai <creatura> <oggetto>) e' scorretta grammaticalmente,
! ma torna molto utile quando nella frase "x, dammi la chiave" il
! parser espande il tutto a "x, da me la chiave".

                * held 'a//' creature            -> Give
		* 'a//' creature held		 -> Give reverse
		* creature held			 -> Give reverse;

Verb 'fai'
		* 'vedere' held 'a//' creature	 -> Show;

Verb 'mostra'
! Vedi il commento in 'dai' per la seconda voce.
                * held 'a//' creature            -> Show
		* 'a//' creature held		 -> Show reverse;

[ ADirection; if (noun in compass) rtrue; rfalse; ];
Verb 'vai' 'cammina' 'corri' 'dirigiti' 'recati'
                *                                -> VagueGo
                * 'a//'/'verso' noun=ADirection	 -> Go
                * 'via'/'fuori' 	    		 -> Exit
                * 'via'/'fuori' 'da' noun 		 -> Exit
                * 'in'/'dentro'/'verso'/'attraverso' noun
                                                 -> Enter;
Verb 'abbandona'
                * noun                           -> Exit;

Verb 'inventario' 'inv' 'i//'
                *                                 -> Inv
                * 'lungo'                         -> InvTall
                * 'largo'                         -> InvWide;

Verb 'guardati'
		* 'intorno'/'attorno'			 -> Look;

Verb 'guarda' 'osserva' 'l//'
                *                                -> Look
                * noun                           -> Examine
                * 'in'/'dentro'/'attraverso' noun
                                                 -> Search
                * 'sotto' noun                   -> LookUnder;

Verb 'apri' 'scopri' 'disfai' 'spalanca' 'scarta'
                * noun                           -> Open
                * noun 'con' held                -> Unlock;

Verb 'chiudi' 'serra' 'copri'
                * noun                           -> Close
                * 'a//' 'chiave' noun 'con' held   -> Lock
		* noun 'a//' 'chiave' 'con' held   -> Lock;

Verb 'entra' 'attraversa'
                *                                -> GoIn
                * noun                           -> Enter
		* 'in'/'dentro' noun		 -> Enter;

Verb 'siedi' 'siediti' 'sdraiati' 'coricati' 'stenditi'
                * 'su'/'sopra' noun              -> Enter
                * 'in'/'dentro' noun             -> Enter;

Verb 'esci' 'fuori'
                *                                -> Exit
                * 'da' noun			 -> Exit;

Verb 'esamina' 'x//' 'controlla' 'descrivi'
                * noun                           -> Examine;
Verb 'leggi'
                * noun                         	-> Examine
                * 'circa'/'su'/'riguardo' topic 'in' noun   -> Consult;
Verb 'spiacente' 'scusa' 'scusami'
                *                                -> Sorry;
Verb 'merda' 'cazzo' 'fanculo' 'vaffanculo' 'stronzo'
                *                                -> Strong
                * topic                          -> Strong;
Verb 'uffa' 'cavoli' 'diavolo' 'dannazione'
                *                                -> Mild
                * topic                          -> Mild;
Verb 'cerca'
                * 'sotto' noun                   -> LookUnder
				* 'in' 'mezzo' 'a//' noun        -> Search
				* 'fra'/'tra'/'per'/'in'/'dentro'/'sopra'
				                                 -> Search
                * topic 'in'/'su' noun			 -> Consult;

Verb 'rovista'
                * 'sotto' noun                   -> LookUnder
				* 'fra'/'tra'/'per'              -> Search
				* 'in' 'mezzo' 'a//' noun        -> Search
				* 'in'/'dentro'/'sopra' noun     -> Search;

Verb 'ondeggia' 'saluta' 'sventola' 'agita'
                *                                -> WaveHands
                * noun                           -> Wave;

Verb 'imposta' 'aggiusta' 'regola'
                * noun                           -> Set
                * noun 'a//'/'su' special              -> SetTo;
Verb 'tira' 'trascina'
                * noun                           -> Pull;
Verb 'premi' 'muovi' 'sposta' 'spingi' 'schiaccia'
                * noun                           -> Push
                * noun noun                      -> PushDir
                * noun 'a//'/'verso' noun        -> Transfer;
Verb 'gira' 'ruota' 'avvita' 'svita'
                * noun                           -> Turn;
Verb 'accendi' 'attiva'
                * noun                           -> Switchon;
Verb 'spegni' 'disattiva'
		* noun				 -> Switchoff;

Verb 'attacca' 'rompi' 'colpisci' 'distruggi'
     'uccidi' 'tortura' 'smembra' 'squarta'
		* noun				 -> Attack;

Verb 'aspetta' 'attendi' 'z//'
                *                                -> Wait;
Verb 'rispondi' 'grida' 'urla'
                * topic 'a//' creature            -> Answer
                * 'si'/'s@`i'                     -> Yes
                * 'no'                            -> No;
Verb 'd@`i' 'di'
                * 'a//' creature 'che' topic         -> Tell
                * 'a//' creature topic   -> Tell
                * creature 'che' topic			   -> Tell
                * creature topic		   -> Tell
                * topic 'a//' creature		   -> Tell reverse;

[Articolo w;
w = NextWord();
if (w=='il' or 'lo' or 'la') return 0;
return -1;
];

Verb 'chiedi' 'interroga' 'domanda'
	* noun 'a//' creature			-> AskFor reverse
	* 'a//' creature noun			-> AskFor
        * 'a//' creature 'di' Articolo topic	-> Ask
	* creature 'di' Articolo topic		-> Ask
	* 'a//' creature 'di' topic		-> Ask
        * 'a//' creature topic			-> Ask
        * creature 'di' topic			-> Ask
        * creature topic			-> Ask
	* 'di' Articolo topic 'a//' creature	-> Ask reverse;

Verb 'informa'
        * creature 'di'/'su'/'circa' topic	-> Tell;

Verb 'mangia' 'ingoia' 'ingurgita'
                * held                           -> Eat;
Verb 'dormi' 'pisola' 'addormentati' 'appisolati' 
                *                                -> Sleep;
Verb 'canta'
                *                                -> Sing;
Verb 'sali' 'scala' 'scavalca'
                * noun                           -> Climb
                * 'su'/'sopra' noun              -> Climb;
Verb 'arrampicati'
		* 'su'/'sopra' noun		-> Climb;
Verb 'compra' 'acquista'
                * noun                           -> Buy;
Verb 'spremi'
                * noun                           -> Squeeze;
Verb 'nuota' 'tuffati'
                *                                -> Swim;
Verb 'scuoti' 'dondola'
                * noun                           -> Swing;
Verb 'soffia'
                * held                           -> Blow;
Verb 'prega'
                *                                -> Pray;
Verb 'sveglia' 'svegliati' 'risveglia' 'risvegliati'
                *                                -> Wake
                * creature                       -> WakeOther;
Verb 'bacia' 'abbraccia'
                * creature                       -> Kiss;
Verb 'pensa'
                *                                -> Think;
Verb 'odora' 'annusa'
                *                                -> Smell
                * noun                           -> Smell;
Verb 'senti' 'ascolta'
                *                                -> Listen
                * noun                           -> Listen;

Verb 'gusta' 'assapora'
                * noun                           -> Taste;
Verb 'tocca' 'accarezza'
                * noun                           -> Touch;
Verb 'pulisci' 'spolvera' 'spazza' 'scrosta'
                * noun                           -> Rub;
Verb 'lega' 'allaccia' 'aggancia'
                * noun                           -> Tie
                * noun 'a//' noun                 -> Tie;
Verb 'brucia' 'infiamma'
                * noun                           -> Burn
                * noun 'con' held               -> Burn;
Verb 'bevi' 'ingolla' 'succhia'
                * noun                           -> Drink;
Verb 'riempi'
                * noun                           -> Fill;
Verb 'taglia' 'affetta' 'spezza' 'sbriciola'
                * noun                           -> Cut;
Verb 'salta' 'saltella'
                *                                -> Jump
                * 'su' noun                    -> JumpOver;
Verb 'scava'    
				* noun                           -> Dig
                * noun 'con' held               -> Dig;
! ----------------------------------------------------------------------------
!  This routine is no longer used here, but provided to help existing games
!  which use it as a general parsing routine:

[ ConTopic w; consult_from = wn;
  do w=NextWordStopped();
  until (w==-1 || (w=='to' && action_to_be==##Answer));
  wn--;
  consult_words = wn-consult_from;
  if (consult_words==0) return -1;
  if (action_to_be==##Ask or ##Answer or ##Tell)
  {   w=wn; wn=consult_from; parsed_number=NextWord();
      if (parsed_number=='the' && consult_words>1) parsed_number=NextWord();
      wn=w; return 1;
  }
  return 0;
];
! ----------------------------------------------------------------------------
!  Procedure banali se non fornite dall'utente:
! ----------------------------------------------------------------------------

#Stub TimePasses      0;
#Stub Amusing         0;
#Stub DeathMessage    0;
#Stub DarkToDark      0;
#Stub NewRoom         0;
#Stub LookRoutine     0;
#Stub AfterLife       0;
#Stub GamePreRoutine  0;
#Stub GamePostRoutine 0;
#Stub AfterPrompt     0;
#Stub BeforeParsing   0;
#Stub PrintTaskName   1;
#Stub InScope         1;
#Stub UnknownVerb     1;
#Stub PrintVerb       1;
#Stub ParserError     1;
#Stub ParseNumber     2;
#Stub ChooseObjects   2;
#IFNDEF PrintRank;
Constant Make__PR;
#ENDIF;
#IFDEF Make__PR;
[ PrintRank; "."; ];
#ENDIF;
#IFNDEF ParseNoun;
Constant Make__PN;
#ENDIF;
#IFDEF Make__PN;
[ ParseNoun obj; obj=obj; return -1; ];
#ENDIF;
#Default Story 0;
#Default Headline 0;
#IFDEF INFIX;
#Include "infix";
#ENDIF;
! ----------------------------------------------------------------------------
