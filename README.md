# Reaction Timer

A two-player reaction time game on an Arduino Uno. Both players watch a green → yellow → red light sequence, then race to press their button the instant the red light goes out. First one to press wins the round.

![Demo](demo.gif)

## How It Works

The board runs a traffic-light countdown:

1. Green LED blinks with a short buzz
2. Yellow LED blinks with another buzz
3. Red LED holds on — for somewhere between 0.9 and 4.9 seconds, randomly — while both players sit there waiting
4. Red goes out — that's the signal
5. Both button LEDs light up; whoever presses first turns off the other player's LED and triggers the win buzz

After the beep, the board resets and runs again. The random delay on the red light means you can't just count and anticipate it — you actually have to react.

## Hardware

| Component | Qty |
|---|---|
| Arduino Uno | 1 |
| Push button | 2 |
| Red LED | 1 |
| Yellow LED | 1 |
| Green LED | 1 |
| White LED (button indicators) | 2 |
| Passive buzzer | 1 |
| 220Ω resistor | 3 (for the traffic LEDs) |
| Breadboard + jumper wires | — |

## Pin Connections

| Arduino Pin | Component |
|---|---|
| 4 | Button 2 |
| 6 | Button LED 2 |
| 7 | Buzzer |
| 9 | Red LED |
| 10 | Yellow LED |
| 11 | Green LED |
| 12 | Button LED 1 |
| 13 | Button 1 |

Buttons use `INPUT_PULLUP` — wire one leg to the pin and the other to GND.

## Wiring

See `WiringDiagram.png` for the full breadboard layout.

## Code

The sketch is `Project_2.ino`. Open it in the Arduino IDE, select **Arduino Uno** as the board, and upload. No libraries needed beyond the standard Arduino core.

## How to Play

1. Upload the sketch and power the board
2. Both players rest a finger near their button
3. Watch the lights: green, then yellow, then red
4. React the moment red turns off
5. The board beeps once to confirm the winner, then resets for the next round

## Notes

- `randomSeed(analogRead(A0))` seeds the RNG from floating analog noise on an unconnected pin, so each round's delay is unpredictable
- The buzzer fires a quick beep on each light change as an audio heads-up, then a longer beep on a confirmed press
- Both button LEDs stay on during the reaction window so it's obvious at a glance who pressed first
