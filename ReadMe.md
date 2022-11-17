

# Gameboy Light Light

Arduino Projekt für die Mikrocomputertechnik Vorlesung

## Ziel

Das Ziel ist es verschiedene, simple Spiele sowie die Möglichkeit zum Auswählen dieser mittels der beigefügten Fernbedienung auf dem Board zu implementieren.
Zur Darstellung werden die mitgelieferten 8x8 Matrizen benutzt.


## Menu

Der User soll die Möglichkeit haben, zwischen verschiedenen Spielen zu wählen indem er sie mit der IR-Fernbedienung auswählt.

### Steps

- [ ] Spielname oder ID auf Segmentanzeige ausgeben

- [ ] IR-Fernebdienungs Inputs auslesen und verwerten

- [ ] Spielauswahl programmieren

- [ ] Nach Spielende zurück ins Menu gehen


## Game 1: Pong

Mittels zwei 8x8 Marixen, einer 4-Stellen 7-Segment Anzeige und einem Potentiometer  soll das klassiche Spiel Pong nachgestellt werden.

### Steps

- [X] Poti Inputs auslesen und verwerten

- [ ] Das Spiel auf der Matrix darstellen

- [X] Das Spiel programmieren

- [ ] Punkte Counter mittels Anzeige umsetzen

## Other Game Ideas
- Chrome Dino Game
- Flappy Bird
- Snake

## Layout of the Board
Hier können die einzelnen Verbindungen zwischen den LED-Matrizen, dem Potentiometer und dem Buzzer und dem Board selbst gesehen werden.

<img width="513" alt="Screenshot 2022-11-17 at 15 12 44" src="https://user-images.githubusercontent.com/58913260/202468950-7dc98c56-93bf-4060-bfe6-947465b9d195.png">
