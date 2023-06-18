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
    - Wenn das Feld eine Miene enthält, hat der Spieler verloren
    - Wenn alle verdeckten Felder nur noch Mienen enthalten, hat der Spieler gewonnen, und kann eine neue Runde starten.
    - Der Spieler kann nicht nur Felder aufdecken, sondern auch markieren, wenn er denkt, das es sich bei dem Feld um eine Miene handelt. Dies hat keinen Effekt auf das Spiel, sondern dient nur als Erinnerung für den Spieler.

## Algorithmus /// Wie unser Programm das Spiel umsetzt

## Quellcode /// Unsere Umsetzung von Minesweeper
