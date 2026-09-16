# Curses: tutorial para 554 pontos

Este e um roteiro completo para `curses.z8` (Release 16). Ele leva a vitoria
com a pontuacao maxima conhecida: **554/550**. Os comandos estao em ingles
porque sao os nomes mais seguros para o parser desta recriacao; o texto do
jogo pode aparecer em portugues.

## Como usar

- Digite um comando por vez. `n`, `s`, `e`, `w`, `u` e `d` significam norte,
  sul, leste, oeste, subir e descer.
- Para economizar espaco, algumas linhas juntam movimentos, como `e e e`.
  Digite-os separadamente: `e`, depois `e`, depois `e`.
- `z` significa esperar. Quando este roteiro diz `z` varias vezes, repita-o
  ate o evento indicado acontecer.
- Nao pule os comandos `examine`, `read`, `look`, `smell` e `wave`: muitos
  deles sao tarefas que valem pontos, nao apenas dicas.
- Use `save` nos checkpoints se quiser poder voltar. Os numeros abaixo sao a
  pontuacao esperada depois de cada trecho; pequenas diferencas significam
  que alguma tarefa foi pulada.
- Se o inventario ficar cheio, deixe objetos apenas quando o roteiro mandar
  `drop all`; recupere-os com `get all` depois.

Texto entre parenteses nos blocos e uma instrucao de controle, nao deve ser
digitado literalmente. Por exemplo, `z (ate Austin aparecer)` significa
repetir `z` ate Austin aparecer.

## 1. Sótão e preparação (19 pontos)

Digite:

```text
n
w
s
examine sheets
push radio n
turn it on
w
z (repita ate a radio tocar musica)
get gloves
wear gloves
e
e
open demijohn
s
s
se
e
examine rolls
get battery
open torch
empty it
put new battery in torch
close torch
s
get rucksack
```

O ultimo comando conclui a preparacao. A lanterna precisa da bateria nova antes
de qualquer excursao no escuro.

## 2. Rato, premonicao e Tia Jemima (28 pontos)

```text
n
open cupboard
n
get painting
get mask
s
w
nw
n
n
get red battery
get map
e
get wrench
enter dumbwaiter
get wishbone
pull rope
get out
get mouse
s
drop mouse
mouse, w
hole, w
hole, w
hole, w
hole, n
hole, w
hole, n
hole, s
hole, e
hole, s
hole, e
hole, e
hole, e
hole, e
get key
n
enter dumbwaiter
pull rope
get out
wear mask
n
unlock door with brass key
open door
s
enter dumbwaiter
pull rope
get out
w
s
examine teachest
look inside it
e
lie down
sleep
e
n
get mascot
drop mascot
s
w
sw
e
get up
get all
w
s
get all from cupboard
open parcel
n
n
w
examine calendar
turn calendar (ate fevereiro e encontrar Merlyn's Hat daisies)
w
give chocolate to jemima
remove mask
say yellow
e
e
s
s
se
w
pull cord
examine postcard
get flash
open flash
put nasty battery in flash
close flash
examine photograph
read about roger in history book
```

Ao examinar o calendario, anote a cor de *Merlyn's Hat daisies*. Nesta
versao ela e `yellow`; a resposta correta para Jemima e `say yellow`.

## 3. Fantasma, chaminé e garrafa (54 pontos)

```text
e
e
n
turn crank
u
nw
get key
give wishbone to ghost
se
d
put torch in fireplace
put brass key in fireplace
drop all
enter fireplace
d
get all
unlock hatch with brass key
open hatch
d
e
turn off wheel
turn wheel
enter dumbwaiter
pull rope
pull rope
get out
w
s
s
se
e
n
drop all
get rucksack
get all
s
w
nw
n
n
w
w
e
e
e
turn off wheel
turn wheel
drop medicine bottle in shaft
turn wheel
enter dumbwaiter
get tablet
get out
w
s
s
se
d
clean glass ball
w
get wrench
fix pipe
get books
read romance novel
```

## 4. Cidade irreal, labirinto e navio (83 pontos)

```text
read poetry book
n
u
push bell
say even
n
u
get tarot cards
d
e
examine mural
w
s
w
get handkerchief
wave it
board boat
say time
nw
climb tree
examine maze
d
w
w
get all
board roller
turn it on
e e e w n n w w n n n n w w w
get off
get miniature
board roller
e e e s s s s e e s s
turn off roller
get off
wear mask
se
s
s
d
turn wheel
enter dumbwaiter
pull rope
pull rope
get out
w
s
s
se
s
s
turn on projector
turn dial
put ace of cups in slot
s
search crates
get mounted bottle
pull anchor
put stick ship into mounted bottle
examine ship
climb mast
get flag
go port
get all
go fore
get green branch
go aft
go aft
turn wheel
d
```

## 5. Alison e identificação dos bastões (144 pontos)

```text
get ace of cups
put fool in slot
n n e s e ne n
examine cross
read about alison in history book
s sw w
push south wall
s
lie down
put flag on bed
sleep
z
e e
turn wheel
pinch me
get out
get stick
look in mirror
wave stick
wave timber spar
break window
s
look under window
get gold key
n n n w nw n
close door
get box
open door
unlock box with gold key
open box
get four leaf clover
wave clover
n e
enter dumbwaiter
pull rope
pull rope
get out
n e e
get charcoal sketch
break frame
get letter
get sketch
open coffin
wear gloves
read inscription
read letter
put a mahogany rod into coffin
close coffin
open coffin
get named rod
put next mahogany rod into coffin (repita para cada um)
close coffin
open coffin
get scroll
se
hang painting on hook
search umbrella stand
get sceptre
```

Cada bastao de mogno deve ser convertido no caixao: coloque-o, feche,
abra e pegue o bastao identificado. Isso inclui os bastoes encontrados mais
tarde.

## 6. Hamburgo e o segundo labirinto (176 pontos)

```text
u u
read about 1420 in map
turn door
ne
push ball sw
push ball s
get tarot box
open it
e
remove mask
break cabinet
get all from cabinet
get tablet
get rod of returning
strike rod of returning
z (ate os druidas levarem voce)
eat tablet
get shepherd's crook
point rod of returning at me
```

Ao usar o Rod of Returning, escolha o retorno para a sala do souvenir. Em
seguida, recupere o Fool, coloque a miniatura no slot, golpeie o bastao e
continue:

```text
s
e e e e e s e s e e s s
w
squeeze weed killer bottle
e n n w w n w n w w w w w
get bean pole
point rod of returning at me
s w
get poetry book
e n nw n n e
turn wheel
enter dumbwaiter
pull rope
pull rope
get out
n n nw
board roller
turn on roller
n n e e e
get off
get marble rose
```

## 7. Cidade irreal, manutenção e bastões (232 pontos)

```text
d
examine mural
read poetry book
get tarot cards from tarot box
n u
put 8 of wands on deck
put maiden on deck
put star on deck
push bell
n u
get tarot cards
d s w
board boat
say time
s e e
convert quarterstaff
convert crook
convert bean pole
convert 8 of wands
se
painting, lagach
get poetry book
get bronze rod
strike bronze rod
point it at mural
d
get key
e e
read tombstone
w w s
smell
smell
d
turn off switch
u w
examine panel
examine bronze wall
strike bronze rod
point it at bronze wall
n
slide i
slide k
slide c
slide a
slide n
slide e
slide l
slide o
slide s
slide t
s
slide k
slide k
e u u u
board roller
w w w s s e
turn off roller
get off
```

## 8. Grecia antiga (270 pontos)

```text
get golden orb
w se s e e se u u w s se s s
get miniature
put maiden in slot
s u e s
strike rod of fire
point it at wall
strike rod of luck
point it at me
s s
get copper coin
se
get inscribed stone
examine inscribed stone
sw
wake homer
say agamemnon
say ptolemy
say yellow
d sw
push statue ne
push dionysus se
push dionysus sw
ne ne
push demeter sw
push demeter nw
se
push poseidon ne
sw
put inscribed stone in opening
d
get amber gem
u u ne nw n n n
strike rod of husbandry
point it at goats
e
get fig
s
give coin to bartender
get dessert
n w w d
give dessert to andromeda
u sw
play pan-pipes
put fig in urn
priestess, tell me about fig
```

Anote os dois numeros dados pela sacerdotisa. Eles sao as coordenadas do
strongbox e serao usados na secao 10. Retorne usando o Rod of Returning.

## 9. Castelo, bomba e grade (362 pontos)

```text
s s
get castle
put castle card in slot
s
look under table
examine scarf
pull blue wire
pull green wire
pull black wire
pull red wire
z (ate o temporizador terminar)
strike rod of returning
point it at me
s s
get star
put star in slot
s d
examine frieze
u
open flash
set timer
put timer in flash
close flash
put flash in device
z (ate disparar)
e e
mosaic, lagach
mural, lagach
mural, lagach
painting, lagach
painting, lagach
u
get all
strike rod of returning
point it at me
s s
get sketch
put charcoal sketch in slot
n
z (ate Austin aparecer)
push austin s
jump
s n
get smooth round stone
drop stone in grating
s se sw s
examine writings
n
blow bird whistle
get cloak
wear cloak
ne ne se s
anoint me
n se
get spindle
nw
z (ate o mensageiro chegar)
get tubes
look in alpha
look in kappa
get short poem
get epic poem
put short poem in alpha
put epic poem in kappa
e
give kappa tube to callimachus
s
give alpha tube to apollonius
get all
n w nw n w
get stone
get key
e s sw nw n
unlock grating with key
open grating
d
get heart
board skiff
sail (ate chegar ao Garden Stream)
```

Pegue a pedra lisa **antes** de deixa-la cair na grade e pegue-a novamente
depois da passagem. O jogo limpa por engano o atributo `moved` durante a
travessia e concede os mesmos 4 pontos duas vezes. Esse e o excedente que
transforma 550 em 554.

## 10. Croquete e strongbox (402 pontos)

```text
s e
wear gloves
get spindle
convert spindle
get hairband
convert hairband
se u u w s se e s e ne d
wave green branch
get nuts
nw
examine mosaic
get wooden ball
lagach ate White Hallway
ne e n
get croquet mallet
s e
walk X paces (use o primeiro numero da sacerdotisa, na direcao indicada)
walk Y paces (use o segundo numero, na direcao indicada)
get gardening implement
examine it
dig
unlock strongbox with gothic key
open it
get astrolabe
fill hole
drop wooden ball
hit it with croquet mallet
nw
put nuts in crack
s
blow bird whistle
get gold watch
```

Se `dig` nao encontrar a caixa, os numeros estao certos mas a combinacao de
direcoes pode ser uma das quatro: oeste/sul, leste/sul, leste/norte ou
oeste/norte. Tente as quatro, sem andar aleatoriamente fora do jardim.

## 11. Submundo e Alexandria (475 pontos)

```text
lagach ate XIIth Dynasty Pyramid
n
get amber gem
put amber gem in socket
d
lie down on couch
sleep
lie down on couch
sleep
lie down on couch
sleep
lie down on couch
sleep
z (ate os soldados franceses sairem)
w
get up
w
get up
w
get up
w
get up
twist sphinx's nose
w
get model
w
n (mova-se ate soltar o greenish oak)
get oak
get sceptre
put sceptre in first socket
turn it ate ficar em si
put sceptre in second socket
turn it ate ficar em huth
put sceptre in third socket
turn it ate ficar em thu
enter coffin
close lid
close lid
u
w w u
lagach ate XIIth Dynasty Pyramid
n ne se
remove cloak
turn cloak
wear cloak
open door
u
put green oak timber on table
nw
remove cloak
turn cloak
wear cloak
n n n
remove cloak
wear purple sash
n ne e s
anoppe
put astrolabe on mounting
look in eyepiece
get hand
d d
```

## 12. Igreja e o cavaleiro (498 pontos)

```text
w
put hand on statue
tighten hand
get skull
put skull on statue
tighten skull
get heart
put heart in statue
strike rod of fire
point it at statue
point e
e
point e
e
give marble rose to knight
show keepsake to knight
point w
w
knight, open moonstone
point d
strike rod of ice
point it at rod of love
get rod of love
get rod of love
s
get gold watch
hypnotize evans
evans, give me mascot
s sw w s
get model of ugly animal
look in mirror
n e ne n
```

## 13. Orb dourado e infinito (498 pontos)

```text
get golden orb
clean it
strike rod of sacrifice
point it on black
s sw w n w nw n n e
turn wheel
enter dumbwaiter
pull rope
get out
w
unlock door with wrought iron key
open door
nw
put rod of sacrifice in lemniscus
put rod of ice in lemniscus
put rod of love in lemniscus
put rod of fire in lemniscus
put rod of returning in lemniscus
put rod of husbandry in lemniscus
put rod of luck in lemniscus
put rod of bronze in lemniscus
put rod of stalking in lemniscus
put orb in opening
strike rod of infinity
point it at lemniscus
```

Nao coloque o Rod of Eternity no lemniscus; ele fica fora. O jogo deve estar
em 498 pontos antes do trecho final.

## 14. Master Game e limpeza final (554 pontos)

```text
get torch
w d
swing rope
get daisy
wear daisy
u e ne e s
get horn
s e
get sandals
wear sandals
w w
open cover
put torch in well
d e
blow horn
wave horn
strike rod of language
point it at me
z (ate os druidas terminarem de falar)
w u
z (ate o espiao saxao ser jogado na tenda)
get pole
e
get blue stone
wave tent pole
strike rod of returning
point it at me
read poetry book
e d
wave blue stone
give fifty-franc note to man
say carte
u w w
board boat
say time
se e
enter dumbwaiter
pull rope
pull rope
get out
w w w
kiss jemima
e e s d
```

A mensagem final deve ser equivalente a:

```text
Congratulations! You've scored 554 out of 550 points!
```

## De onde vem o máximo

O placar normal soma 550 pontos: tarefas, bastoes, itens e locais visitados.
O roteiro tambem executa uma das oito acoes do bonus temporario (o beijo em
Jemima no fim e uma delas). A pontuacao extra de 4 nao e um truque externo:
`smooth round stone` recebe pontos ao ser encontrada no museu e novamente
apos atravessar a grade porque a implementacao limpa seu atributo de objeto.

Assim, `554/550` e o resultado correto para esta versao de `curses.z8`.
