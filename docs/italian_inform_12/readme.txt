------------------------------------------------------------------------------
Questo archivio (italian_inform_12.tgz) contiene i seguenti file:
Italian.h
ItalianG.h

Il primo definisce gli aspetti linguistici dell'italiano, e
viene automaticamente caricato da Inform utilizzando
l'opzione "+language_name=Italian" durante la compilazione.
Il secondo contiene la grammatica italiana (non completamente :)
e deve essere incluso al posto di grammar.h

La versione di entrambi i file e' 1.2. La grammatica italiana si basa
sulla versione inglese (Grammar.h) delle librerie 6/10

Modifiche:
020825 - 1.2	Ilario Nardinocchi (illo@CS.UniBO.IT)
Allineamento dei file alla libreria 6/10 di Inform.

990710 - 1.1	Ilario Nardinocchi (illo@CS.UniBO.IT)
Le modifiche (principalmente stilistiche) sono ispirate ai numerosi
suggerimenti che Matteo De Luigi mi forni' circa un anno fa.
Ringrazio inoltre Umberto Michelucci per il suo lavoro nella versione 1.01.

990416 - 1.01	Umberto Michelucci (umich@physik.uni-augsburg.de)
Cambiato il verbo chiedi. Prima bisognava chiedere informazioni ai
personaggi con frasi del tipo

	chiedi dottore di libro

e frasi come 

	chiedi dottore del libro

non funzionavano. 
Una precisazione. In italiano la frase 

	chiedi del te al commesso

puo' volere dire

1) chiedi un po' di te al commesso
2) chiedi informazioni sul te al commesso.

Bisogna decidere quindi una convenzione. Pensavo di fare cosi':

Per chiedere qualcosa (per ottenerla) si usera' la sintassi

	chiedi 'il'/'la'/'lo' oggetto 'a' persona

per chiedere informazioni su qualcosa si puo' usare la sintassi

	chiedi 'di'/'del'/... oggetto 'a' persona
	chiedi 'a' persona 'di'/'del'... oggetto

quindi per ottenere qualcosa andranno bene le seguenti frasi

	chiedi il te al commesso
	chiedi te al commesso
	chiedi te commesso
	chiedi te a commesso
	chiedi al commesso il te
	ecc...

per chiedere informazioni andranno bene le seguenti frasi

	chiedi del te al commesso
	chiedi di te al commesso
	chiedi al commesso del te
	chiedi al commesso di te
	chiedi commesso di te
	chiedi commeso te
	ecc...

Spero tutto questo sia chiaro e sia accettabile. Fatemi sapere cosa ne pensate.

971207 - 1.0	Ilario Nardinocchi (illo@CS.UniBO.IT)

Versione iniziale.

------------------------------------------------------------------------------
