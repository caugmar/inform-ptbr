# Tutorial de vitória: Ruínas

Este tutorial conduz a uma partida completa de **Ruínas**, desde um jogo novo
até a vitória com 30 pontos. Ele reproduz a sequência de
`transcrição-vitoria.txt`, mas explica o que está acontecendo e por que cada
ação é necessária.

## Regras essenciais

Você precisa recuperar cinco artefatos: a estatueta, a máscara, a pedra
funerária, o osso entalhado e o favo de mel. Para cada um, a ordem correta é:

1. Fotografá-lo enquanto ainda está no local original.
2. Pegá-lo.
3. Levá-lo ao caixote da Grande Plaza.
4. Colocá-lo no caixote.

Sem a fotografia, o jogo não permite remover um artefato. A lanterna também
precisa ser transportada com cuidado: ela deve estar no chão para ser ligada e
não pode ser recolhida enquanto estiver acesa.

Os comandos abaixo pressupõem um jogo novo. Linhas em blocos de código são
comandos para digitar; os parágrafos explicam o resultado esperado.

## 1. Abrir o acesso à Estrutura 10

Você começa na Grande Plaza. A câmera está no caixote, e o cogumelo bloqueia
indiretamente o caminho para os degraus. O mapa, o dicionário e a lanterna
estão no inventário, mas será preciso reorganizá-los para explorar.

```text
pegue a câmera
pegue o cogumelo
coma o cogumelo
desça
```

Comer o cogumelo provoca uma alteração estranha na floresta e remove os
escombros que bloqueavam os degraus. Agora você chega à Câmara Quadrada.

Na câmara, deixe de lado os objetos que não serão necessários imediatamente e
posicione a lanterna para iluminar o caminho. A lanterna não pode ser acesa
enquanto estiver sendo carregada.

```text
solte o mapa
solte o dicionário
solte a lanterna
ligue a lanterna
empurre a lanterna para o sul
```

O último comando empurra a lanterna para dentro do Corredor Inclinado. Ela
continua iluminando o percurso, enquanto você fica com as mãos livres para
operar a câmera e recolher artefatos.

## 2. Recuperar a estatueta

### Corredor Inclinado

A estatueta está no corredor. Ela vale 5 pontos, mas só conta para a pontuação
depois de ser guardada no caixote. Primeiro registre o contexto arqueológico;
depois remova a peça e leve a lanterna de volta para poder retornar à plaza.

```text
fotografe a estatueta
pegue a estatueta
empurre a lanterna para o norte
suba
coloque a estatueta no caixote
```

Você volta à Grande Plaza e recebe 5 pontos. Fotografar antes de pegar é
obrigatório: a aventura trata a remoção sem registro como saque arqueológico.

## 3. Obter a chave e abrir a porta

Volte à Câmara Quadrada e entre no Ninho dos Vermes pelo leste. O saco de ovos
brilhante parece perigoso, mas ele é o mecanismo que produz a chave de pedra.
Leve-o até o raio de sol da câmara; não o leve até a luz natural da saída, pois
isso provoca uma morte imediata.

```text
desça
empurre a lanterna para o leste
pegue o saco de ovos
empurre a lanterna para o oeste
coloque o saco de ovos no raio de sol
pegue a chave de pedra
```

O saco explode em pequenos insetos e deixa uma chave amarela no chão. A
lanterna é reposicionada para que você possa atravessar a câmara e alcançar a
porta sem perder a iluminação.

```text
empurre a lanterna para o sul
destranque a porta com a chave de pedra
abra a porta
solte a chave de pedra
empurre a lanterna para o sul
```

A porta de pedra amarela leva ao Santuário. Soltar a chave não é necessário
para a pontuação, mas libera espaço no inventário, que tem capacidade limitada.

## 4. Recuperar a máscara e revelar Xibalbá

### Santuário

A máscara de jade está sobre o altar. Fotografe-a antes de pegá-la. Depois,
vista-a: a máscara revela o sacerdote mumificado, que fornece a pista que
desbloqueia a passagem para Xibalbá.

```text
fotografe a máscara
pegue a máscara
vista a máscara
pergunte sacerdote sobre Xibalbá
remova a máscara
```

O sacerdote aponta para sudoeste e faz as estalactites que bloqueavam a
passagem derreterem. Remova a máscara antes de sair; assim ela permanece no
inventário e pode ser levada ao caixote.

```text
empurre a lanterna para o norte
empurre a lanterna para o norte
suba
coloque a máscara no caixote
```

Você volta à Grande Plaza e recebe mais 10 pontos, totalizando 15. Os dois
empurrões levam a lanterna de volta pelo corredor e pela Câmara Quadrada; subir
retorna à plaza.

## 5. Recuperar a pedra funerária e o osso entalhado

### Xibalbá

Depois de guardar a máscara, desça novamente até o santuário e siga até a nova
passagem sudoeste. A pedra funerária está em Xibalbá. Como os demais artefatos,
ela deve ser fotografada antes da remoção.

```text
desça
empurre a lanterna para o sul
empurre a lanterna para o sul
sudoeste
fotografe a pedra funerária
pegue a pedra funerária
solte a pedra funerária
```

A pedra precisa ser deixada temporariamente em Xibalbá porque a próxima tarefa
é empurrar a enorme bola de pedra-pomes. Soltá-la também evita sobrecarregar o
inventário e permite executar o quebra-cabeça com as mãos livres.

```text
norte
empurre a bola de pedra-pomes para o sul
empurre a bola de pedra-pomes para o sul
empurre a bola de pedra-pomes para o sul
sul
```

Os três empurrões fazem a bola descer pela ravina. Ela fica presa no abismo e
forma uma saliência improvisada, permitindo alcançar uma área que antes era
inacessível.

### Saliência de Pedra-Pomes

O osso entalhado está preso no lodo da nova saliência. Fotografe-o ainda no
local e pegue-o. Depois, retorne a Xibalbá para recuperar a pedra funerária.

```text
fotografe o osso entalhado
pegue o osso entalhado
norte
norte
pegue a pedra funerária
```

Agora os dois artefatos estão com você. Siga para nordeste, atravesse de volta
ao santuário e suba até a Grande Plaza.

```text
nordeste
empurre a lanterna para o norte
empurre a lanterna para o norte
suba
coloque a pedra funerária no caixote
coloque o osso entalhado no caixote
```

A pedra funerária e o osso valem 5 pontos cada. A pontuação chega a 25. Os
artefatos já fotografados podem ser armazenados sem nenhuma ação adicional.

## 6. Transformar-se em javali

Ainda falta o favo de mel, que está no Poço Funerário. O acesso exige passar
por túneis estreitos demais para um ser humano. A gaiola da Antecâmara é o
mecanismo de transformação: entrar nela desencadeia a cena com os esqueletos e
faz você assumir o controle de um javali.

```text
desça
empurre a lanterna para o sul
empurre a lanterna para o sul
empurre a lanterna para o sudeste
entre na gaiola
```

Depois da transformação, você está na Antecâmara como javali. A lanterna fica
para trás; a visão noturna do animal permite continuar sem ela.

```text
noroeste
norte
norte
leste
norte
```

Essas direções levam ao Ninho dos Vermes. Como javali, você consegue atravessar
os túneis que eram estreitos demais para o arqueólogo.

## 7. Recuperar o favo de mel

### Ninho dos Vermes e Poço Funerário

No Ninho dos Vermes, o comando `norte` não encontra uma saída comum. Como você
é um javali, a tentativa de continuar força a passagem pelo túnel e leva ao
Poço Funerário.

```text
norte
norte
```

No poço, pule contra o tampão de barro. A transformação se desfaz e você volta
a controlar o arqueólogo dentro da cripta. O favo de mel está ali, mas ainda
deve ser registrado antes de ser recolhido.

```text
pule
fotografe o favo de mel
pegue o favo de mel
suba
```

Subir pelo tampão aberto retorna à gaiola. A lanterna está acesa no caminho de
volta, e uma lanterna acesa não pode ser carregada; desligue-a antes de pegá-la.

```text
desligue a lanterna
pegue a lanterna
noroeste
norte
norte
suba
```

Você retorna à Grande Plaza com o favo e a lanterna. O favo foi fotografado no
poço, portanto agora pode ser armazenado.

```text
coloque o favo de mel no caixote
```

O favo completa os cinco artefatos e acrescenta os 5 pontos finais. A expedição
termina automaticamente com **30 pontos**, e o posto obtido é **Diretor da
Carnegie Institution**.

## Resultado esperado

Ao final, a mensagem descreve o empacotamento cuidadoso do favo, a arara que
desce da copa das árvores e a lua crescente sobre a selva. Esse texto confirma
que os cinco artefatos foram fotografados, recuperados e guardados na ordem
correta, e que a partida terminou em vitória.
