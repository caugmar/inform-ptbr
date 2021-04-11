! ===========================================================================
!   Inform Language Definition File: Italian 020825
!
!   (c) Ilario Nardinocchi 1998,1999,2000,2001,2002
! ---------------------------------------------------------------------------
System_file;
! ---------------------------------------------------------------------------
!   Parte I.   Preliminari
! ---------------------------------------------------------------------------
Constant LanguageVersion = "ILDF ~Italiano~ 020825 (c) Ilario Nardinocchi.";

Class CompassDirection with article "il", number 0 has scenery;

Object Compass "bussola" has female concealed;

IFNDEF WITHOUT_DIRECTIONS;
CompassDirection -> n_obj "muro nord" with
                    name 'n//' 'nord' 'muro',           door_dir n_to;
CompassDirection -> s_obj "muro sud" with
                    name 's//' 'sud' 'muro',            door_dir s_to;
CompassDirection -> e_obj "muro est" with
                    name 'e//' 'est' 'muro',            door_dir e_to;
CompassDirection -> w_obj "muro ovest" with
                    name 'w//' 'o//' 'ovest' 'muro',    door_dir w_to;
CompassDirection -> ne_obj "muro nordest" with
                    name 'ne' 'nordest' 'muro',         door_dir ne_to;
CompassDirection -> nw_obj "muro nordovest" with
                    name 'no' 'nordovest' 'muro',       door_dir nw_to;
CompassDirection -> se_obj "muro sudest" with
                    name 'se' 'sudest' 'muro',          door_dir se_to;
CompassDirection -> sw_obj "muro sudovest" with
                    name 'so' 'sudovest' 'muro',        door_dir sw_to;
CompassDirection -> u_obj "soffitto" with
                    name 'su' 'soffitto',               door_dir u_to;
CompassDirection -> d_obj "pavimento" with
                    name 'giu' 'gi@`u' 'pavimento',     door_dir d_to;
ENDIF;
CompassDirection -> out_obj "fuori" with
                                                        door_dir out_to;
CompassDirection -> in_obj "dentro" with
                                                        door_dir in_to;
! ---------------------------------------------------------------------------
!   Parte II.   Vocabolario
! ---------------------------------------------------------------------------
Constant AGAIN1__WD   = 'ancora';
Constant AGAIN2__WD   = 'g//';
Constant AGAIN3__WD   = 'ancora';
Constant OOPS1__WD    = 'oops';
Constant OOPS2__WD    = 'oops';
Constant OOPS3__WD    = 'oops';
Constant UNDO1__WD    = 'rifai';
Constant UNDO2__WD    = 'rifai';
Constant UNDO3__WD    = 'rifai';

Constant ALL1__WD     = 'tutto';
Constant ALL2__WD     = 'ogni';
Constant ALL3__WD     = 'ciascun';
Constant ALL4__WD     = 'tutti';
Constant ALL5__WD     = 'entrambi';
Constant AND1__WD     = 'e//';
Constant AND2__WD     = 'e//';
Constant AND3__WD     = 'e//';
Constant BUT1__WD     = 'eccetto';
Constant BUT2__WD     = 'tranne';
Constant BUT3__WD     = 'senza';
Constant ME1__WD      = 'io';
Constant ME2__WD      = 'me';
Constant ME3__WD      = 'me';
Constant OF1__WD      = 'di';
Constant OF2__WD      = 'di';
Constant OF3__WD      = 'di';
Constant OF4__WD      = 'di';
Constant OTHER1__WD   = 'altro';
Constant OTHER2__WD   = 'altro';
Constant OTHER3__WD   = 'altro';
Constant THEN1__WD    = 'poi';
Constant THEN2__WD    = 'quindi';
Constant THEN3__WD    = 'quindi';

Constant NO1__WD      = 'no';
Constant NO2__WD      = 'no';
Constant NO3__WD      = 'no';
Constant YES1__WD     = 's@`i';
Constant YES2__WD     = 'si';
Constant YES3__WD     = 'si';

Constant AMUSING__WD  = 'divertenti';
Constant FULLSCORE1__WD = 'punteggio';
Constant FULLSCORE2__WD = 'totale';
Constant QUIT1__WD    = 'q//';
Constant QUIT2__WD    = 'uscire';
Constant RESTART__WD  = 'ricominciare';
Constant RESTORE__WD  = 'caricare';

Array LanguagePronouns table

   !  word       possible GNAs                   connected
   !             to follow:                      to:
   !             a     i
   !             s  p  s  p
   !             mfnmfnmfnmfn                 

      'lui'    $$100000100000                    NULL
      'lei'    $$010000010000                    NULL
      'essi'   $$000100000100                    NULL
      'esse'   $$000010000010                    NULL;
      
Array LanguageDescriptors table

   !  word       possible GNAs   descriptor      connected
   !             to follow:      type:           to:
   !             a     i
   !             s  p  s  p
   !             mfnmfnmfnmfn                 

      'mio'    $$100000100000    POSSESS_PK      0
      'mia'    $$010000010000    POSSESS_PK              0
      'miei'   $$000100000100    POSSESS_PK              0
      'mie'    $$000010000010    POSSESS_PK              0
      'questo' $$100000100000    POSSESS_PK      0
      'questa' $$010000010000    POSSESS_PK              0
      'questi' $$000100000100    POSSESS_PK              0
      'queste' $$000010000010    POSSESS_PK      0
      'quello' $$100000100000    POSSESS_PK              1
      'quella' $$010000010000    POSSESS_PK              1
      'quegli' $$000100000100    POSSESS_PK              1
      'quelle' $$000010000010    POSSESS_PK      1
!      'suo'    $$100000100000    POSSESS_PK      'lui'
!      'sua'    $$010000010000    POSSESS_PK      'lui'
!      'suoi'   $$000100000100    POSSESS_PK             'lui'
!      'sue'    $$000010000010   POSSESS_PK      'lui'
!      'loro'   $$110110110110    POSSESS_PK      'essi'
      'il'     $$100000100000    DEFART_PK               NULL
      'lo'     $$100000100000    DEFART_PK               NULL
      'la'     $$010000010000    DEFART_PK               NULL
      'l^'     $$110000110000    DEFART_PK               NULL
      'i//'    $$000100000100    DEFART_PK               NULL
      'gli'    $$000100000100    DEFART_PK               NULL
      'le'     $$000010000010    DEFART_PK               NULL
      'un'     $$100000100000    INDEFART_PK     NULL
      'uno'    $$100000100000    INDEFART_PK     NULL
      'un^'    $$010000010000    INDEFART_PK     NULL
      'una'    $$010000010000    INDEFART_PK     NULL
!  'qualcuno'   $$000100000100    INDEFART_PK    NULL
!  'qualcuna'   $$000010000010    INDEFART_PK     NULL
  'alcuni'     $$000100000100    INDEFART_PK     NULL    
  'alcune'     $$000010000010    INDEFART_PK     NULL
  'illuminato' $$100000100000    light                   NULL
  'illuminata' $$010000010000    light                   NULL
  'illuminati' $$000100000100    light               NULL
  'illuminate' $$000010000010    light                   NULL
  'buio'       $$100000100000    (-light)                NULL
  'buia'       $$010000010000    (-light)                NULL
  'bui'        $$000100000100    (-light)            NULL
  'buie'       $$000010000010    (-light)                NULL;

Array LanguageNumbers table
    'uno' 1 'due' 2 'tre' 3 'quattro' 4 'cinque' 5
    'sei' 6 'sette' 7 'otto' 8 'nove' 9 'dieci' 10
    'undici' 11 'dodici' 12 'tredici' 13 'quattordici' 14 'quindici' 15
    'sedici' 16 'diciassette' 17 'diciotto' 18 'diciannove' 19 'venti' 20;

! ---------------------------------------------------------------------------
!   Parte III.   Traduzione.
! ---------------------------------------------------------------------------

! Tabelle per l'espansione delle preposizioni articolate.
Array prep_di_il        string "di il";
Array prep_di_lo        string "di lo";
Array prep_di_la        string "di la";
Array prep_di_i         string "di i";
Array prep_di_gli       string "di gli";
Array prep_di_le        string "di le";
Array prep_a_il         string "a il";
Array prep_a_lo         string "a lo";
Array prep_a_la         string "a la";
Array prep_a_i          string "a i";
Array prep_a_gli        string "a gli";
Array prep_a_le         string "a le";
Array prep_da_il        string "da il";
Array prep_da_lo        string "da lo";
Array prep_da_la        string "da la";
Array prep_da_i         string "da i";
Array prep_da_gli       string "da gli";
Array prep_da_le        string "da le";
Array prep_in_il        string "in il";
Array prep_in_lo        string "in lo";
Array prep_in_la        string "in la";
Array prep_in_i         string "in i";
Array prep_in_gli       string "in gli";
Array prep_in_le        string "in le";
Array prep_su_il        string "su il";
Array prep_su_lo        string "su lo";
Array prep_su_la        string "su la";
Array prep_su_i         string "su i";
Array prep_su_gli       string "su gli";
Array prep_su_le        string "su le";

! Subst(x,y) sostituisce ogni occorrenza della parola del dizionario x con
! la stringa y nel buffer del parser.

[ Subst x y l c1 c2 word at;

        for (c1 = 0: c1 < parse->1: c1++) {
                word = parse-->(c1 * 2 + 1);
                at = parse->(c1 * 4 + 5);
                if (word == x) {
                        l = parse->(c1 * 4 + 4); 
                        if (l < y->0) {
                                for (c2 = 0: c2 < (y->0 - l): c2++)
                                        LTI_Insert(at, ' ');
                        } else {
                                for (c2 = 0: c2 < (l - y->0): c2++)
                                        buffer->(at + c2) = ' ';
                                at = at + c2;
                        }
                        for (c2 = 0: c2 < y->0: c2++)
                                buffer->(at + c2) = y->(c2 + 1);
                        tokenise__(buffer,parse);
                        c1 = 0;
                }
        }
];

! DeContract() trasforma un verbo in forma contratta in un verbo
! in forma espansa (es. prendile -> prendi esse)

[ DeContract at x;

        for (   x = 0: 
                        x < parse->1 && ~~(parse->(x*4+4) == 1 && buffer->(parse->(x*4+5)) == ','):
                        x++);
        if (x == parse->1)
                x = 0;
        else
                x++;
        if ( parse-->(x*2+1) == 0 or 'dallo' or 'dalla' or 'dagli' or 'dalle' && 
             parse->(x*4+4) > 3) {
                at = parse->(x*4+5) + parse->(x*4+4) - 2;
                if (buffer->at == 'm' && buffer->(at+1) == 'i') {
                        if (buffer->(at-1) == 'm')
                                buffer->(at-1) = ' ';
                        LTI_Insert(at, ' ');
                        buffer->(at+1) = 'm';
                        buffer->(at+2) = 'e';
                        tokenise__(buffer,parse);
                }
                else if (buffer->at == 'l' && buffer->(at+1) == 'o' or 'a' or 'i' or 'e') {
                        x = buffer->(at+1);
                        if (buffer->(at-1) == 'l')
                                buffer->(at-1) = ' ';
                        else if (buffer->(at-1) == 'g' && x == 'i') {
                                buffer->(at-1) = ' ';
                                x = 'o';
                        }
                        LTI_Insert(at, ' ');
                        LTI_Insert(at, ' ');
                        switch (x) {
                                'o':
                                        buffer->(at+1) = 'l';
                                        buffer->(at+2) = 'u';
                                        buffer->(at+3) = 'i';
                                'a':
                                        buffer->(at+1) = 'l';
                                        buffer->(at+2) = 'e';
                                        buffer->(at+3) = 'i';
                                'i':
                                        LTI_Insert(at, ' ');
                                        buffer->(at+1) = 'e';
                                        buffer->(at+2) = 's';
                                        buffer->(at+3) = 's';
                                        buffer->(at+4) = 'i';
                                'e':
                                        LTI_Insert(at, ' ');
                                        buffer->(at+1) = 'e';
                                        buffer->(at+2) = 's';
                                        buffer->(at+3) = 's';
                                        buffer->(at+4) = 'e';
                        }
                        tokenise__(buffer,parse);
                }
        }
];

[ LanguageToInformese x;

! passo 1: separazione degli apostrofi (l'acqua -> l' acqua)

        for (x = 2: x < 2 + buffer->1: x++) {
                if (buffer->x == ''') LTI_Insert(x+1, ' ');
        }
        
        tokenise__(buffer,parse);

! Passo 2: espansione delle forme contratte dei verbi
! (es: gettala -> getta lei ATTENZIONE:
!                      gettale: getta loro o getta a lei? ACH! ENTRAMBE!)

        DeContract();

! Passo 3: espansione delle preposizioni articolate (del -> di il)

        Subst('del', prep_di_il);
        Subst('dell^', prep_di_lo);
        Subst('dello', prep_di_lo);
        Subst('della', prep_di_la);
        Subst('dei', prep_di_i);
        Subst('degli', prep_di_gli);
        Subst('delle', prep_di_le);
        
        Subst('al', prep_a_il);
        Subst('all^', prep_a_lo);
        Subst('allo', prep_a_lo);
        Subst('alla', prep_a_la);
        Subst('ai', prep_a_i);
        Subst('agli', prep_a_gli);
        Subst('alle', prep_a_le);

        Subst('dal', prep_da_il);
        Subst('dall^', prep_da_lo);
        Subst('dallo', prep_da_lo);
        Subst('dalla', prep_da_la);
        Subst('dai', prep_da_i);
        Subst('dagli', prep_da_gli);
        Subst('dalle', prep_da_le);

        Subst('nel', prep_in_il);
        Subst('nell^', prep_in_lo);
        Subst('nello', prep_in_lo);
        Subst('nella', prep_in_la);
        Subst('nei', prep_in_i);
        Subst('negli', prep_in_gli);
        Subst('nelle', prep_in_le);

        Subst('sul', prep_su_il);
        Subst('sull^', prep_su_lo);
        Subst('sullo', prep_su_lo);
        Subst('sulla', prep_su_la);
        Subst('sui', prep_su_i);
        Subst('sugli', prep_su_gli);
        Subst('sulle', prep_su_le);

        if (parser_trace) {
                print "^[LanguageToInformese: ~";
                for (x = 2: x < 2 + buffer->1: x++)
                        print (char) buffer->x;
                print "~]^";
        }
];

! ---------------------------------------------------------------------------
!   Parte IV.   Stampa
! ---------------------------------------------------------------------------

Constant LanguageAnimateGender   = male;
Constant LanguageInanimateGender = male;

Constant LanguageContractionForms = 3;     ! L'italiano ne ha tre:
                                           ! 0 = consonante
                                           ! 1 = vocale
                                           ! 2 = z,x,j,y o s + cons

[ LanguageContraction text;

        if (text->0 ==  'a' or 'e' or 'i' or 'o' or 'u' or
                        'A' or 'E' or 'I' or 'O' or 'U' )
                return 1;
        if (text->0 == 'z' or 'Z' or 'x' or 'X' or 'j' or 'J' or 'y' or 'Y')
                return 2;
        if (text->0 ~= 's' or 'S')
                return 0;
        if (text->1 ~=  'a' or 'e' or 'i' or 'o' or 'u' or
                                        'A' or 'E' or 'I' or 'O' or 'U' )
                return 2;
  return 0;
];

Array LanguageArticles -->

 !      Contraction form 0:                     Contraction form 1:                     Contraction form 2:
 !      Cdef    Def             Indef           Cdef    Def             Indef           Cdef    Def             Indef

        "Il "   "il "   "un "           "L'"    "l'"    "un "           "Lo "   "lo "   "uno " ! 0:Masc Sing.
        "I "    "i "    "dei "          "Gli "  "gli "  "degli "        "Gli "  "gli "  "degli " ! 1:Masc Plur.
        "La "   "la "   "una "          "L'"    "l'"    "un'"           "La "   "la "   "una " ! 2:Fem  Sing.
        "Le "   "le "   "delle "        "Le "   "le "   "delle "        "Le "   "le "   "delle "; ! 3:Fem  Plur. 

                   !             a           i
                   !             s     p     s     p
                   !             m f n m f n m f n m f n                 

Array LanguageGNAsToArticles --> 0 2 0 1 3 0 0 2 0 1 3 0;

[ LanguageDirection d;
   switch(d)
   {   n_to: print "nord";
       s_to: print "sud";
       e_to: print "est";
       w_to: print "ovest";
       ne_to: print "nordest";
       nw_to: print "nordovest";
       se_to: print "sudest";
       sw_to: print "sudovest";
       u_to: print "su";
       d_to: print "gi@`u";
       in_to: print "dentro";
       out_to: print "fuori";
       default: return RunTimeError(9,d);
   }
];

[ LanguageNumber n f;
  if (n==0)    { print "zero"; rfalse; }
  if (n<0)     { print "meno "; n=-n; }
  if (n>=1000) { if (n/1000 == 1) print "mille"; else print (LanguageNumber) n/1000, "mila"; n=n%1000; f=1; }
  if (n>=100)  { if (f==1) print " ";
                 if (n/100 > 1) print (LanguageNumber) n/100; print "cento"; n=n%100; f=1; }
  if (n==0) rfalse;
  switch(n)
  {   1:  print "uno";
      2:  print "due";
      3:  print "tre";
      4:  print "quattro";
      5:  print "cinque";
      6:  print "sei";
      7:  print "sette";
      8:  print "otto";
      9:  print "nove";
      10: print "dieci";
      11: print "undici";
      12: print "dodici";
      13: print "tredici";
      14: print "quattordici";
      15: print "quindici";
      16: print "sedici";
      17: print "diciassette";
      18: print "diciotto";
      19: print "diciannove";
      20 to 99:
          switch(n/10)
          {  2: print "vent";
             3: print "trent";
             4: print "quarant";
             5: print "cinquant";
             6: print "sessant";
             7: print "settant";
             8: print "ottant";
             9: print "novant";
          }
          if ((n%10) ~= 1 or 8) {
                          if (n/10==2)
                                  print "i";
                          else
                                  print "a";
                  }
          if ((n%10) ~= 0) print (LanguageNumber) n%10;
  }
];

[ LanguageTimeOfDay hours mins i;
   i=hours%12;
   if (i==0) i=12;
   if (i<10) print " ";
   print i, ":", mins/10, mins%10;
   if ((hours/12) > 0) print " pm"; else print " am";
];

[ LanguageVerb i;
   if (i==#n$l)        { print "guarda";          rtrue; }
   if (i==#n$z)        { print "aspetta";         rtrue; }
   if (i==#n$x)        { print "esamina";         rtrue; }
   if (i==#n$i or 'inv' or 'inventario')
                       { print "inventario";        rtrue; }
   rfalse;
];

Constant NKEY__TX     = "A = avanti";
Constant PKEY__TX     = "I = indietro";
Constant QKEY1__TX    = "     Q = esci";
Constant QKEY2__TX    = "  Q = menu precedente";
Constant RKEY__TX     = "RETURN = leggi l'argomento";

Constant NKEY1__KY    = 'S';
Constant NKEY2__KY    = 's';
Constant PKEY1__KY    = 'P';
Constant PKEY2__KY    = 'p';
Constant QKEY1__KY    = 'Q';
Constant QKEY2__KY    = 'q';

Constant SCORE__TX    = "Punti: ";
Constant MOVES__TX    = "Mosse: ";
Constant TIME__TX     = "Tempo: ";
Constant CANTGO__TX   = "Non puoi andare l@`a.";
Constant FORMER__TX   = "ci@`o che tu eri";
Constant YOURSELF__TX = "te stesso";
Constant DARKNESS__TX = "Oscurit@`a";

Constant THOSET__TX   = "quelle cose";
Constant THAT__TX     = "quello";
Constant OR__TX       = " oppure ";
Constant NOTHING__TX  = "niente";
Constant IS__TX       = " c'@`e";
Constant ARE__TX      = " ci sono";
Constant IS2__TX      = "c'@`e ";
Constant ARE2__TX     = "ci sono ";
Constant AND__TX      = " e ";
Constant WHOM__TX     = "cui ";
Constant WHICH__TX    = "cui ";

[ GetMode obj x;
        x = GetGNAOfObject(obj);
        if (x == 0 or 6)
                return 1;
        if (x == 1 or 7)
                return 2;
        if (x == 3 or 9)
                return 3;
        if (x == 4 or 10)
                return 4;
        return 0;
];

[ LioLa obj; 
        switch(GetMode(obj)) {
                1:
                        print "lo";
                2:
                        print "l'";
                3:
                        print "li";
                4:
                        print "le";
        }
];

[ CLioLa obj; 
        switch(GetMode(obj)) {
                1:
                        print "Lo";
                2:
                        print "L'";
                3:
                        print "Li";
                4:
                        print "Le";
        }
];

[ ThatorThose obj;
        if (obj == player) { print "tu"; return; }
        if (obj hasnt pluralname && obj has animate) {
                if (obj has female)
                        print "sua";
                print "suo";
                return;
        }
        switch(GetMode(obj)) {
                1:
                        print "quel";
                2:
                        print "quella";
                3:
                        print "quei";
                4:
                        print "quelle";
        }
];

[ CThatorThose obj;
        if (obj == player) { print "Tu"; return; }
        if (obj hasnt pluralname && obj has animate) {
                if (obj has female)
                        print "Lei";
                print "Lui";
                return;
        }
        switch(GetMode(obj)) {
                1:
                        print "Quel";
                2:
                        print "Quella";
                3:
                        print "Quei";
                4:
                        print "Quelle";
        }
];

[ IsorAre obj; if (obj has pluralname) print "sono"; else print "@`e";
];

[ CIsOrAre obj; if (obj has pluralname) print "Sono";
  else print "@`E";
];

[ VerbInf obj;
        switch(GetMode(obj)) {
                1:                       
                        print "o";
                2:
                        print "a";
                3:
                        print "i";
                4:
                        print "e";
        }
];

[ IsClosed obj; print "chius", (verbinf) obj; ];
[ IsOpen obj; print "apert", (verbinf) obj; ];
[ IsLit obj; print "luminos", (verbinf) obj; ];
[ IsEmpty obj; print "vuot", (verbinf) obj; ];
[ IsWorn obj; print "indossat", (verbinf) obj; ];
[ IsLocked obj; print (isclosed) obj, " a chiave"; ];


[ LanguageLM n x1;
  Prompt:  print "^>";
  Miscellany:
           switch(n)
           {   1: "(considero solo i primi sedici oggetti)^";
               2: "Non ho nulla da fare!";
               3: print " Sei morto ";
               4: print " Hai vinto ";
               5: print "^Vuoi RICOMINCIARE, CARICARE un gioco salvato";
                  #IFDEF DEATH_MENTION_UNDO;
                  print ", RIFARE la mossa precedente";
                  #ENDIF;
                  if (TASKS_PROVIDED==0)
                      print ", vedere il tuo punteggio TOTALE";
                  if (deadflag==2 && AMUSING_PROVIDED==0)
                      print ", vedere alcuni suggerimenti sulle cose DIVERTENTI da fare";
                  " o USCIRE?";
               6: "[Il tuo interprete non ha il ~rifai~, spiacente.]";
               7: "~Rifai~ non funziona.  [Non tutti gli interpreti lo forniscono.]";
               8: "Per favore, dai una delle risposte elencate.";
               9: "^Adesso @`e buio pesto qui!";
              10: "Prego?";
              11: "[Non puoi rifare ci@`o che non hai fatto!]";
              12: "[Non puoi rifare due volte di seguito. Spiacente!]";
              13: "[Torno al turno precedente.]";
              14: "Spiacente, non si pu@`o correggere.";
              15: "Non c'@`e di che.";
              16: "~Oops~ pu@`o correggere solo una parola.";
              17: "@`E buio pesto, e non riesci a vedere un bel niente.";
              18: print "tu";
              19: "Bell", (verbinf)actor, " come sempre.";           
              20: "Per ripetere un comando come ~rana, salta~, d@`i solo
                   ~ancora~, non ~rana, ancora~.";
              21: "Sar@`a difficile ripeterlo.";
              22: "Non puoi iniziare con una virgola.";
              23: "Mi sembra che tu voglia parlare con qualcuno, ma non riesco a capire chi.";
              24: "Non puoi parlare con ", (the) x1, ".";
              25: "Per parlare con qualcuno, prova ~qualcuno, ciao~ o qualcosa del genere.";
              26: "(prima prendi ", (the) not_holding, ")";
              27: "Non ho capito la frase.";
              28: print "Ho capito la frase almeno fino a: ";
              29: "Non ho capito quel numero.";
              30: "Non vedi nulla del genere.";
              31: "Hai detto troppo poco!";
              32: "Non ce l'hai!";
              33: "Non puoi usare oggetti multipli con quel verbo.";
              34: "Puoi usare oggetti multipli solo una volta per linea.";
              35: "Non so a chi o cosa tu ti stia riferendo.";
              36: "Ti aspetti qualcosa che non @`e stato incluso!";
              37: "Puoi farlo solo con esseri viventi.";
              38: "Non @`e uno dei verbi che conosco.";
              39: "Non @`e affatto importante.";
              40: "Non riesci a vedere ~", (address) pronoun_word,
                  "~ (", (the) pronoun_obj, ") ora.";
              41: "Non ho capito la fine.";
              42: if (x1==0) "Non ce ne sono.";
                  print "Ce ";
                  if (x1 > 1) print "ne sono"; else print "n'@`e";
                  print_ret " solo ", (number) x1, ".";
              43: "Niente da fare!";
              44: "Non ce ne sono!";
              45: print "Vuoi dire "; ! esseri viventi
              46: print "Vuoi dire ";
              47: "Spiacente, puoi avere solo un oggetto qui. Quale esattamente?";
              48: if (actor~=player) {
                                          print "~", actor, ", ";
                                          PrintCommand();
                                          print "~";
                                  }
                                  else
                                        PrintCommand();
                                  print " chi?^";
              49: if (actor~=player) {
                                          print "~", actor, ", ";
                                          PrintCommand();
                                          print "~";
                                  }
                                  else
                                        PrintCommand();
                                  print " che cosa?^";
              50: print "Il tuo punteggio @`e appena ";
                  if (x1 > 0) print "salito"; else { x1 = -x1; print "sceso"; }
                  print " di ", (number) x1, " punt";
                  if (x1 > 1) print "i"; else print "o";
              51: "(@`E accaduto qualcosa di drammatico, e i tuoi
                   comandi disponibili sono stati ridotti.)";
              52: "^Scrivi un numero da 1 a ", x1,
                  ", 0 per rivedere o premi INVIO.";
              53: "^[Premi SPAZIO.]";
           }

  ListMiscellany:
           switch(n)
           {   1: print " (luminos", (verbinf) x1, ")";
               2: print " (che ", (isorare) x1, " ", (isclosed) x1, ")";
               3: print " (", (isclosed) x1, " e ", (islit) x1, ")";
               4: print " (che ", (isorare) x1, " ", (isempty) x1, ")";
               5: print " (", (isempty) x1, " e ", (islit) x1, ")";
               6: print " (che ", (isorare) x1, " ", (isclosed) x1, " e ", (isempty) x1, ")";
               7: print " (", (isclosed) x1, ", ", (isempty) x1, " e ", (islit) x1, ")";
               8: print " (", (islit) x1, " e ", (isworn) x1, ")";
               9: print " (", (islit) x1;
              10: print " (", (isworn) x1;
              11: print " (che ", (isorare) x1, " ";
              12: print (isopen) x1;
              13: print (isopen) x1, " ma ", (isempty) x1;
              14: print (isclosed) x1;
              15: print (islocked) x1;
              16: print " e ", (isempty) x1;
              17: print " (che ", (isorare) x1, " ", (isempty) x1, ")";
              18: print " contenente ";
              19: print " (sopra ";
              20: print ", sopra ";
              21: print " (dentro ";
              22: print ", dentro ";
           }

  Pronouns: switch(n)
           {   1: print "Al momento, ";
               2: print "indica ";
               3: print "non @`e impostato";
               4: "non ci sono pronomi conosciuti.";
           }
  Order:          print (The) x1;
                  if (x1 has pluralname) print " hanno"; else print " ha";
                  " cose migliori da fare.";
  Quit:    switch(n)
           {   1: print "Rispondi s@`i o no, per favore";
               2: print "Sicuro di voler uscire? ";
           }
  Restart: switch(n)
           {   1: print "Sicuro di voler ricominciare? ";
               2: "Non ci riesco.";
           }
  Restore: switch(n)
           {   1: "Non riesco a caricare.";
               2: "Fatto.";
           }
  Save:    switch(n)
           {   1: "Non riesco a salvare.";
               2: "Fatto.";
           }
  Verify:  switch(n)
           {   1: "Il gioco salvato @`e intatto.";
               2: "Il gioco salvato non sembra intatto, e potrebbe essere rovinato.";
           }
  ScriptOn: switch(n)
           {   1: "La trascrizione @`e gi@`a attiva.";
               2: "Inizio la trascrizione: ";
               3: "Il tentativo di iniziare la trascrizione @`e fallito.";
           }
  ScriptOff: switch(n)
           {   1: "La trascrizione non @`e attiva.";
               2: "^Fine trascrizione.";
               3: "Il tentativo di terminare la trascrizione @`e fallito.";
           }
  NotifyOn:       "Notifica del punteggio attivata.";
  NotifyOff:      "Notifica del punteggio disattivata.";
  Places:         print "Hai visitato: ";
  Objects: switch(n)
           {   1: "Oggetti che hai utilizzato:^";
               2: "Nessuno.";
               3: print "   (addosso)";
               4: print "   (in mano)";
               5: print "   (ad altri)";
               6: print "   (", (name) x1, ")";
               7: print "   (dentro ", (the) x1, ")";
               8: print "   (dentro ", (the) x1, ")";
               9: print "   (sopra ", (the) x1, ")";
              10: print "   (chissa' dove)";
           }
  Score:          if (deadflag) print "In questo gioco hai ottenuto ";
                  else print "Fin'ora hai ottenuto ";
                  print score, " punt";
                                  if (score == 1) print "o"; else print "i";
                                  print " da un massimo di ", MAX_SCORE,
                  ", in ", turns, " turn";
                  if (turns == 1) print "o"; else print "i";
                  return;
  FullScore: switch(n)
           {   1: if (deadflag) print "Il punteggio @`e stato ";
                  else          print "Il punteggio viene ";
                  "conseguito cos@`i:^";
               2: "scoprendo oggetti preziosi";
               3: "visitando posti interessanti";
               4: print "totale (su ", MAX_SCORE; ")";
           }
  Inv:     switch(n)
           {   1: "Non stai portando nulla.";
               2: print "Stai portando";
           }
  Take:    switch(n)
           {   1: "Fatto.";
               2: "Sei gi@`a abbastanza in te.";
               3: "Non credo che ", (the)x1, " sia interessat", (verbinf)x1, ".";
               4: print "Dovresti ";
                  if (x1 has supporter) print "scendere da sopra ";
                                   else print "uscire da dentro ";
                  print_ret (the) x1, " prima.";
               5: print_ret (cliola) x1, " hai gi@`a.";
               6: "Sembra che il proprietario sia ", (the) x1, ".";
               7: if (noun has pluralname) print "Sembrano ";
                                      else print "Sembra ";
                  "esser parte di ", (the) x1, ".";
               8: print_ret (Cthatorthose)x1, " non ",
                            (isorare)x1, " disponibili.";
               9: print "Non ", (isorare) x1, " ", (isopen) x1, ".";
              10: print_ret (cisorare) x1, " impossibil", (verbinf) x1, " da trasportare.";
              11: print (cisorare) x1, " fissat", (verbinf) x1;
                  " al suolo.";
              12: "Stai gi@`a trasportando troppe cose.";
              13: "(metti ", (the) x1, " dentro ", (the) SACK_OBJECT,
                  " per far spazio)";
           }


  Drop:    switch(n)
           {   1: print (The) x1, " ", (isorare) x1;
                  " gi@`a a terra.";
               2: "Non ce ", (liola) x1, " hai.";
               3: "(prima ti togli ", (the) x1, ")";
               4: "Fatto.";
           }
  Remove:  switch(n)
           {   1: print "Purtroppo ", (isorare) x1, " chius", (verbinf) x1;
                  ".";
               2: print "Ma non ", (isorare) x1;
                  " l@`i ora.";
               3: "Fatto.";
           }
  PutOn:   switch(n)
           {   1: print "Devi prenderl", (verbinf) x1, ", ", (the) x1,
                  ", prima di poterl", (verbinf) x1;
                  " mettere sopra qualcos'altro.";
               2: "Non puoi mettere qualcosa sopra se stessa.";
               3: "Mettere cose sopra ", (the) x1, " @`e inutile.";
               4: "Non sei un acrobata.";
               5: "(prima l", (verbinf)x1, " togli)^";
               6: "Non c'@`e abbastanza spazio per ", (the) x1, ".";
               7: "Fatto.";
               8: "Ora ", (the) x1, " ", (isorare) x1, " sopra ", (the) second, ".";
           }
  Insert:  switch(n)
           {   1: print "Devi prenderl", (verbinf) x1, ", ", (the) x1,
                  ", prima di poterl", (verbinf) x1;
                  " mettere dentro qualcos'altro.";
               2: print "Non ";
                  if (x1 has pluralname) print "possono "; else print "pu@`o ";
                  "contenere cose.";
               3: print_ret (The) x1, " ", (isorare) x1, " ", (isclosed) x1, ".";
               4: "Prima devi prenderl", (verbinf) x1, ".";
               5: "Non puoi mettere qualcosa dentro se stessa.";
               6: "(prima l", (verbinf) x1, " togli)^";
               7: "Non c'@`e pi@`u spazio dentro ", (the) x1, ".";
               8: "Fatto.";
               9: "Ora ", (the) x1, " ", (isorare) x1, " dentro ", (the) second, ".";
           }
  EmptyT:  switch(n)
           {   1: print_ret (The) x1, " non pu@`o contenere cose.";
               2: print_ret (The) x1, " ", (isorare) x1, " chius", (verbinf) x1, ".";
               3: print_ret (The) x1, " ", (isorare) x1, " gi@`a vuot", (verbinf) x1, ".";
               4: "Non @`e cos@`i che si vuotano le cose!";
           }
  Give:    switch(n)
           {   1: "Non ce l'hai, ", (the) x1, ".";
               2: "Ti gingilli con ", (the) x1,
                  " per un po', ma non ottieni granch@'e.";
               3: print (The) x1, " non";
                  if (x1 has pluralname) print " sembrano";
                  else print " sembra";
                  " interessat", (verbinf) x1, ".";
           }
  Show:    switch(n)
           {   1: "Non ce l'hai, ", (the) x1, ".";
               2: print_ret (The) x1, " non ", (isorare) x1, " rimast", (verbinf)x1, " impressionat", (verbinf) x1, ".";
           }
  Enter:   switch(n)
           {   1: print "Ma sei gi@`a ";
                  if (x1 has supporter) print "sopra "; else print "dentro ";
                  print_ret (the) x1, ".";
               2: print "Non ";
                  if (x1 has pluralname)
                        print "sono delle cose ";
                  else
                        print "@`e qualcosa ";
                  switch (verb_word) {
                        'stand': "su cui puoi stare.";
                        'sit': "su cui puoi sederti.";
                        'lie': "su cui puoi stenderti.";
                        default: "in cui puoi entrare.";
                  }
               3: "Non puoi entrare dentro ", (the) x1, " chius", (verbinf) x1, ".";
               4: "Puoi entrare solo dentro qualcosa di libero.";
               5: print "Ora sei ";
                  if (x1 has supporter) print "sopra "; else print "dentro ";
                  print_ret (the) x1, ".";
               6: print "(l", (verbinf) noun, " togli da ";
                  if (x1 has supporter) print "sopra "; else print "dentro ";
                  print (the) x1; ")";
               7: if (x1 has supporter) "(sali sopra ", (the) x1, ")^";
                  if (x1 has container) "(entri dentro ", (the) x1, ")^";
                  "(entri dentro ", (the) x1, ")^";
           }
  GetOff:         "Ma non sei sopra ", (the) x1, " adesso.";
  Exit:    switch(n)
           {   1: "Non sei dentro nulla.";
               2: print_ret (The) x1, " ", (isorare) x1, " chius", (verbinf) x1, ", non puoi uscire.";
               3: print "Ora sei ";
                  if (x1 has supporter) "sceso."; else "uscito.";
           }
  VagueGo: "Devi dire in che direzione vuoi dirigerti.";

  Go:      switch(n)
           {   1: print "Prima dovrai ";
                  if (x1 has supporter) print "scendere da sopra "; else print "uscire da dentro ";
                  print_ret (the) x1, ".";
               2: "Non puoi andare di l@`a.";
               3: "Non riesci a salire ", (the) x1, ".";
               4: "Non riesci a scendere ", (the) x1, ".";
               5: print "Non puoi, poich@'e ", (the) x1, " ti ";
                  if (x1 has pluralname) "ostacolano."; else "ostacola.";
               6: print "Non puoi, poich@'e ", (the) x1, " non ";
                  if (x1 has pluralname) print "portano "; else print "porta ";
                  "a nulla.";
           }

  LMode1:         " @`e ora in modalit@`a  ~breve~, che fornisce le descrizioni
                   estese dei luoghi mai visitati e le descrizioni brevi altrimenti.";
  LMode2:         " @`e ora in modalit@`a ~prolissa~, che fornisce sempre le
                   descrizioni estese dei luoghi (anche se ci sei gi@`a stato).";
  LMode3:         " @`e ora in modalit@`a ~brevissima~, che fornisce sempre le
                   descrizioni brevi dei luoghi (anche se non ci sei mai stato).";

  Look:    switch(n)
           {   1: print " (sopra ", (the) x1, ")";
               2: print " (dentro", (the) x1, ")";
               3: print " (come "; @print_obj x1; print ")";
               4: print "^Sopra ", (the) x1;
                  WriteListFrom(child(x1),
                      ENGLISH_BIT + RECURSE_BIT + PARTINV_BIT
                      + TERSE_BIT + ISARE_BIT + CONCEAL_BIT);
                  ".";
         default: if (x1~=location)
                  {   if (x1 has supporter) print "^Sopra "; else print "^Dentro ";
                      print (the) x1, " puoi ";
                  }
                  else print "Puoi ";
                  if (n==5) print "anche "; print "vedere ";
                  WriteListFrom(child(x1),
                      ENGLISH_BIT + WORKFLAG_BIT + RECURSE_BIT
                      + PARTINV_BIT + TERSE_BIT + CONCEAL_BIT);
                  if (x1~=location) ".";
                  " qui.";
           }

  Examine: switch(n)
           {   1: "Oscurit@`a - sost. femm. - Assenza di luce, buio, tenebre.";
               2: "Non noti nulla di speciale guardando ", (the) x1, ".";
               3: print "In questo momento ", (the) x1, " ", (isorare) x1;
                  if (x1 has on) print " acces"; else print " spent";
                  print_ret (verbinf) x1, ".";
           }
  LookUnder: switch(n)
           {   1: "Ma @`e buio.";
               2: "Non trovi nulla di interessante.";
           }

  Search:  switch(n)
           {   1: "Ma @`e buio.";
               2: "Non c'@`e nulla sopra ", (the) x1, ".";
               3: print "Sopra ", (the) x1;
                  WriteListFrom(child(x1),
                      TERSE_BIT + ENGLISH_BIT + ISARE_BIT + CONCEAL_BIT);
                  ".";
               4: "Non trovi nulla di interessante.";
               5: "Non puoi vederne l'interno, poich@'e ", (the) x1, " ",
                  (isorare) x1, " ", (isclosed) x1, ".";
               6: print_ret (The) x1, " ", (isorare) x1, " ", (isempty) x1, ".";
               7: print "Dentro ", (the) x1;
                  WriteListFrom(child(x1),
                      TERSE_BIT + ENGLISH_BIT + ISARE_BIT + CONCEAL_BIT);
                  ".";
           }

  Unlock:  switch(n)
           {   1: "Sembra che tu non sia in grado di aprirl", (verbinf) x1, ".";
               2: "Non ", (cisorare) x1, " ", (islocked) x1, " al momento.";
               3: print "Sembra che ", (the) x1, " non entri";
                  if (x1 has pluralname) print "no";
                  " nella serratura.";
               4: "Ora ", (the) x1, " ", (isorare) x1, " apert", (verbinf) x1, ".";
           }
  Lock:    switch(n)
           {   1: print "Non ";
                  if (x1 has pluralname) print "sembrano "; else print "sembra ";
                  "essere qualcosa che si possa chiudere a chiave.";
               2: print_ret (cisorare) x1, " ", (islocked) x1, " al momento.";
               3: "Prima devi chiudere ", (the) x1, ".";
               4: print "Sembra che ", (the) x1, " non entri";
                  if (x1 has pluralname) print "no";
                  " nella serratura.";
               5: "Hai chiuso a chiave ", (the) x1, ".";
           }

  SwitchOn: switch(n)
           {   1: print_ret "Non @`e possibile accenderl", (verbinf) x1, "."; 
               2: print_ret (cisorare) x1, "gi@`a acces", (verbinf) x1, ".";
               3: "Hai acceso ", (the) x1, ".";
           }
  SwitchOff: switch(n)
           {   1: print_ret "Non @`e possibile spegnerl", (verbinf) x1, "."; 
               2: print_ret (cisorare) x1,
                  " gi@`a spent", (verbinf) x1, ".";
               3: "Hai spento ", (the) x1, ".";
           }

  Open:    switch(n)
           {   1: print_ret "Non @`e possibile aprirl", (verbinf) x1, ".";
               2: if (x1 has pluralname) print "Sembrano ";
                  else print "Sembra ";
                  print_ret (islocked) x1, ".";
               3: print_ret (cisorare) x1, " gi@`a ", (isopen) x1, ".";
               4: print "Apri ", (the) x1, ", trovando ";
                  if (WriteListFrom(child(x1),
                      ENGLISH_BIT + TERSE_BIT + CONCEAL_BIT)==0) " un bel nulla.";
                  ".";
               5: "Ora ", (the) x1, " ", (isorare) x1, " ", (isopen) x1, ".";
           }

  Close:   switch(n)
           {   1: print_ret "Non @`e possibile chiuderl", (verbinf) x1, ".";
               2: print_ret (cisorare) x1,
                  " gi@`a ", (isclosed) x1, ".";
               3: "Ora ", (the) x1, " ", (isorare) x1, " chius", (verbinf) x1, ".";
           }
  Disrobe: switch(n)
           {   1: "Non l", (verbinf) x1, " stai indossando.";
               2: "Ti togli ", (the) x1, ".";
           }
  Wear:    switch(n)
           {   1: "Non puoi indossarl", (verbinf) x1, "!";
               2: "Non ce ", (liola) x1, " hai!";
               3: "Stai gi@`a indossandol", (verbinf) x1, "!";
               4: "Ti sei mess", (verbinf)actor, " ", (the) x1, ".";
           }
  Eat:     switch(n)
           {   1: print_ret (cisorare) x1,
                  " semplicemente immangiabile.";
               2: "Mangi ", (the) x1, ". Niente male...";
           }
  Yes, No:        "Era una domanda retorica.";
  Burn:           "Questa azione pericolosa ti frutterebbe solo guai.";
  Pray:           "Le tue preghiere non vengono esaudite.";
  Wake:           "La terribile verit@`a @`e che questo non @`e un sogno.";
  WakeOther:      "Non sembra necessario.";
  Kiss:           "Concentrati sul gioco.";
  Think:          "Bell'idea.";
  Smell:          "Non senti nulla di particolare.";
  Listen:         "Non senti nulla di particolare.";
  Taste:          "Non senti nulla di particolare.";
  Touch:   switch(n)
           {   1: "Tieni a posto quelle mani!";
               2: "Non senti nulla di particolare.";
               3: "Se pensi che sia utile...";
           }
  Dig:            "Scavando qui non otterrai nulla.";
  Cut:            "Tagliandol", (verbinf) x1, " non otterresti nulla.";
  Jump:           "Salti da fermo, inutilmente.";
  JumpOver, Tie:  "Lascia perdere.";
  Drink:          "Non c'@`e nulla da bere qui.";
  Fill:           "Ma qui non c'@`e acqua.";
  Sorry:          "Oh, non scusarti.";
  Strong:         "I veri avventurieri non utilizzano un s@'i scurrile linguaggio.";
  Mild:           "Gi@`a.";
  Attack:         "La violenza @`e deprecabile.";
  Swim:           "Non c'@`e abbastanza acqua per nuotarci.";
  Swing:          "Non c'@`e nulla da scuotere qui.";
  Blow:           "Spero che tu davvero non voglia bruciarl", (verbinf) x1, ".";
  Rub:            "Non ne otterrai nulla.";
  Set:            "No, non puoi.";
  SetTo:          "No, non puoi.";
  WaveHands:      "Muovi le braccia, sentendoti stupido.";
  Wave:    switch(n)
           {   1: "Ma non ce ", (liola) x1, " hai.";
               2: "Ti senti stupido mentre muovi ", (the) x1, " su e gi@`u.";
           }
  Pull, Push, Turn:
           switch(n)
           {   1: print_ret (cisorare) x1, " fissat", (verbinf) x1, " al suolo.";
               2: "Non ci riesci.";
               3: "Non succede nulla.";
               4: "Non sarebbe molto cortese da parte tua.";
           }
  PushDir: switch(n)
           {   1: "@`E forse questo il meglio a cui riesci a pensare?";
               2: "Non @`e una direzione.";
               3: "Non puoi da quella parte.";
           }
  Squeeze: switch(n)
           {   1: "Tieni a posto le mani.";
               2: "Non ottieni nulla facendolo.";
           }
  ThrowAt: switch(n)
           {   1: "Inutile.";
               2: "Ti manca il coraggio proprio all'ultimo momento.";
           }
  Tell:    switch(n)
           {   1: "Parli da solo per un po'.";
               2: "Non ottieni alcuna reazione.";
           }
  Answer, Ask:    "Non c'@`e risposta.";
  Buy:            "Sembra che non ci sia nulla da comprare.";
  Sing:           "Canti come una cornacchia.";
  Climb:          "Bah, tempo sprecato.";
  Wait:           "Il tempo passa.";
  Sleep:          "Non hai molto sonno.";
  Consult:        "Non trovi niente di interessante consultando ", (the) x1, ".";
];

! ---------------------------------------------------------------------------
