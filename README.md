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

Das Spielfeld wird intern als 2-Dimensionales Array aus Signed Integern (Z. B. `Int[15][15]` für das schwere Spielfeld) repräsentiert:

| Zahl                 | Bedeutung der Zahl                               |
| -------------------- | ------------------------------------------------ |
| Alle negative Zahlen | Bombe                                            |
| 1-8                  | Feld grenzt an _n_ Bomben, Zahl auf Feld ist _n_ |
| 0                    | Freies Feld ohne angrenzende Bomben              |

Ebenfalls existiert ein zweites Array (Maske) der selben Größe, allerdings aus Booleans. Alle Booleans sind zuerst `false`, wenn ein Feld aufgedeckt wird, wird es auf `true` gesetzt. Nur der Inhalt Felder des Spielfelds, bei denen die Koordinaten der Maske auf `true` gesetzt ist, werden dem Spieler angezeigt.

### Nutzereingabe von Koordinaten

Der Nutzer wählt ein Feld aus, indem er Koordinaten angibt, die im Schema `Buchstabe-Zahl` angibt (Z. B. `N-16`). Zuallererst wird geprüft, ob die Nutzereingabe dem Schema entspricht. Der Buchstabe wird in eine Zahl konvertiert basierend auf der Position im Alphabet, dann wird bei beiden Zahlen 1 subtrahiert, damit der Nutzer keine 0-Koordinate eingeben muss.

Dann wird geprüft, ob die Nutzereingabe innerhalb des Spielfeldes ist (z. B. keine negativen Zahlen).

Dann erst wird die Koordinate genutzt.

### Spielfeld füllen

#### Mienen platzieren

Je nach Schwierigkeitsgrad, den der Nutzer ausgewählt hat, werden 10 / 40 / 99 Mienen platziert. Es wird eine zufällige Koordinate mithilfe von zwei Zufallszahlen, generiert von `rand()` aus der C Standard Library (`glibc` auf Linux), ausgewählt. Wenn an dieser Position schon eine Miene ist oder es sich um die erste vom Spieler ausgewählte Koordinate handelt, wird neu gewürfelt. Ansonsten wird auf dem Feld eine Miene platziert, und die Zahl auf dem Spielfeld wird negativ gesetzt.

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

Wenn ein zu überprüfendes Feld außerhalb des Spielfelds ist (z. B. negative Koordinate), wird es nicht überprüft.

<!-- ### Felder "flaggen"

Für Flaggen, die der Spieler verteilen kann, gibt es eine Flaggen-Maske. Beim rendern werden geflaggte Felder durch ein F markiert.

-->

## Quellcode /// Unsere Umsetzung von Minesweeper
