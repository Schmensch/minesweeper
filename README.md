# Minesweeper

## Problem /// Regeln von Minesweeper

Unser Problem besteht hauptsächlich aus den Regeln und dem Spielablauf von Minesweeper. Diese müssen zuallererst klar definiert sein, bevor wir weiter machen können.

Spielablauf:

- Es gibt einen "Gameloop":
  - Der / Die Spieler/in wird begrüßt und der Titel des Spiels wird angezeigt
  - Die / Der Spieler/in wählt eine Schwierigkeit aus: Normal, Schwer oder Experte.
  - Je nach Schwierigkeit werden unterschiedliche Felder generiert:
    - Normal: 8x8 Spielfeld mit 10 verborgenen Mienen
    - Schwer: 16x16 Spielfeld mit 40 verborgen Mienen
    - Experte: 30x16 Spielfeld mit 99 verborgen Mienen
  - Der Nutzer wählt ein Feld aus (z. B. mit Koordinaten)
  - Jetzt wird das Spielfeld generiert, und es wird sicher gestellt dass das Feld, das der Nutzer ausgewählt hat keine Miene enthält:
    - Das Feld das der Nutzer ausgewählt hat, wird aufgedeckt
    - Es werden weiter angrenzende Felder aufgedeckt, bis nur noch Felder angrenzen, die an eine Miene berühren (horizontal, vertikal oder diagonal)
    - Die Felder, die an Mienen grenzen werden mit einer Zahl ausgefüllt, die anzeigt, an wie viele Mienen sie grenzen.
    - Der Spieler deckt nun weiter Felder auf.
    - Wenn das Feld frei ist, wiederholen sich alle Schritte in diesem Absatz.
    - Wenn das Feld eine Miene enthält, hat der Spieler verloren und kann eine neue Runde starten.
    - Wenn alle verdeckten Felder nur noch Mienen enthalten, hat der Spieler gewonnen, und kann eine neue Runde starten.
    <!-- - Der Spieler kann nicht nur Felder aufdecken, sondern auch markieren, wenn er denkt, das es sich bei dem Feld um eine Miene handelt. Dies hat keinen Effekt auf das Spiel, sondern dient nur als Erinnerung für den Spieler. -->

## Algorithmus /// Wie unser Programm das Spiel umsetzt

### Spielfeldrepräsentation

Das Spielfeld wird als Struct repräsentiert, der 3 2-Dimensionale (geschachtelte) Vektoren enthält:

- Der erste enthält die Position aller Bomben, als Boolean (true = bombe)
- Der zweite enthält für jedes Feld die Menge an Bomben, die an das Feld angrenzt, als Integer (0-8 = 0-8 Bomben grenzen an das Feld an)
- Der dritte enthält booleans, die besagen, ob das Feld sichtbar ist (true = sichtbar)

### Nutzereingabe von Koordinaten

Der Nutzer wählt ein Feld aus, indem er zweimal Zahlen eingibt, einmal für die X- und einmal für die Y-Koordinate.

### Spielfeld füllen

#### Mienen platzieren

Je nach Schwierigkeitsgrad, den der Nutzer ausgewählt hat, werden 10 / 40 / 99 Mienen platziert. Es wird eine zufällige Koordinate mithilfe von zwei Zufallszahlen, generiert von `rand()` aus der C Standard Library (`glibc` auf Linux), ausgewählt. Wenn an dieser Position schon eine Miene ist oder es sich um das erste ausgewählte, wird neu gewürfelt. Ansonsten wird auf dem Feld eine Miene platziert, und im Spielfeld-Struct wird im 2D-Bomben-Vektor das Feld auf true gesetzt.

#### Anzahl an angrenzenden Mienen berechnen

Nachdem alle Mienen platziert wurden, wird für jedes Raster im Spielfeld, das keine Miene ist, gezählt, wie viele angrenzenden Mienen existieren, indem man die Koordinaten des Feldes nimmt und folgende Felder nach Mienen überprüft und diese zusammenzählt:

- X gleich, Y+1
- X gleich, Y-1
- X+1, Y+1
- X+1, Y gleich
- X+1, Y-1
- X-1, Y+1
- X-1, Y gleich
- X-1, Y-1

Wenn ein zu überprüfendes Feld außerhalb des Spielfelds ist (z. B. negative Koordinate, zu hohe Koordinate), wird es nicht überprüft.

### Automatisches Aufdecken angrenzender Zellen

Wenn der Nutzer eine Feld aufdeckt, werden automatisch alle Felder aufgedeckt, die durch eine ununterbrochene Linie an freien Feldern mit dem vom Nutzer ausgewählten Feld verbunden werden können, außer Mienen, sie werden nicht automatisch aufgedeckt.

Dies wird durch eine rekursive Funktion gelöst. Sie nimmt 2 Argumente:

- Ein Struct aus dem Spielfeld-Struct und einem 2D-Vektor aus Booleans mit allen Feldern, die die Funktion schon überprüft hat.
- Das Feld, von dem sie die Nachbarn frei machen soll.

Die Funktion überprüft alle Nachbarfelder und bearbeitet die Maske, die kontrolliert, welche Felder dem Spieler angezeigt werden. Sie setzt die Maske auf `true` (heißt Felder werden dem Spieler angezeigt) für alle Felder, auf denen sich keine Bombe befindet.

Alle Felder die die Funktion überprüft, werden einer anderen Maske hinzugefügt.

Hat das Feld keine Bomben um sich herum (Maske für Anzahl an Bomben ist `0`) und die Funktionsmaske ist nicht für das Feld gesetzt, ruft die Funktion sich selbst nochmal auf das Feld auf.

Dies führt dazu, das durch die Rekursion alle angrenzenden Felder Stück für Stück aufgedeckt werden, bis ein "Loch" entsteht, das einen Rand aus Zahlen hat.

### Spielzug

- Der Nutzer gibt mit Hilfe von zwei Zahlen ein Feld an
- Es wird überprüft ob es sich bei dem angegebenen Feld um eine Miene handelt, dies kann einfach aus dem Spielfeld Vector ausgelesen werden
- Handelt es sich bei dem Feld um eine Miene wird die Gameloop unterbrochen (Dieser Schritt ist beim ersten Spielzug nicht nötig, da das erste Feld keine Miene sein kann)
- Das vom Nutzer ausgewählte Feld wird nun aufgedeckt, indem das Feld im Masken-Vektor auf `true` gesetzt wird
- Der "Automatisches Aufdecken angrenzender Zellen" Algorithmus wird nun auf das vom Spieler ausgewählte Feld angewendet, und deckt umliegende Felder auf. (Siehe "Automatisches Aufdecken angrenzender Zellen)
- Der Spielzug wiederholt sich, bis der Spieler alle Felder bis auf Bomben aufgedeckt hat, oder eine Bombe aufgeckt hat.
- Der Spieler gewinnt oder verliert, und kann eine neue Runde anfangen.

## Quellcode /// Unsere Umsetzung von Minesweeper

# Quellen

- https://www.google.com/search?q=minesweeper
- https://www.minesweeper.info/wiki/Minesweeper_Official_Rules
- https://geeksforgeeks.org/
- https://w3schools.com/cpp/
- https://cplusplus.com/
- https://learncpp.com/
- https://cppreference.com
- https://stackoverflow.com/questions/
