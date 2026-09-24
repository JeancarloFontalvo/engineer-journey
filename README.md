# Engineer Journey

A personal, hands-on learning lab for engineering—currently focused on **electronics, Arduino, and mechanical design with FreeCAD**. This repository contains experiments, sketches, schematics, CAD files, and the notes that explain what I learned along the way.

The goal is progress through small, practical builds rather than polished production projects. Some experiments are intentionally incomplete or rough; that is part of the learning record.

## Current focus

The active thread is bringing together simple Arduino motor control and mechanical design. The working checklist and ideas that are intentionally being deferred live in [`TODO.md`](TODO.md).

## Repository map

| Directory | Contents |
| --- | --- |
| [`electronics/arduino/`](electronics/arduino/) | Arduino exercises, from LED timing and buttons to servos, OLEDs, and motors |
| [`electronics/schematics/`](electronics/schematics/) | Circuit notes and schematics |
| [`cad/`](cad/) | FreeCAD designs and saved iterations |
| [`graphics/`](graphics/) | Bitmap assets used by electronics experiments |
| [`diary.md`](diary.md) | Dated learning notes, challenges, and reflections |
| [`TODO.md`](TODO.md) | Current focus, next actions, backlog, and ideas parking lot |

## Learning path so far

- Arduino fundamentals: blinking LEDs, loops, arrays, and non-blocking timing
- Digital inputs: push buttons, pull-up/pull-down resistors, and floating signals
- Servos: position control and button-driven movement
- OLED display: text, bitmap graphics, and a cursor controlled by inputs
- Motor control: first experiments with an L298N motor driver
- CAD: constrained sketches and early mechanical parts in FreeCAD

The experiments are available in the numbered sketches under [`electronics/arduino/`](electronics/arduino/). The diary provides the context behind them and records questions to revisit.

## How to use this repository

1. Choose one item from [`TODO.md`](TODO.md), preferably from **Current focus**.
2. Open the relevant Arduino sketch in the Arduino IDE, or the CAD file in FreeCAD.
3. Record the wiring, hardware, assumptions, and result—not just the final code or model.
4. Add a short dated entry to [`diary.md`](diary.md), including what worked, what was confusing, and the next action.
5. Update [`TODO.md`](TODO.md) before changing focus so unfinished work and new ideas do not get lost.

Arduino sketches are hardware-specific experiments. Check the pin assignments and power requirements before connecting a circuit; motor projects in particular need a suitable external supply and a shared ground with the controller.

## Documentation habits

Each experiment should aim to leave behind:

- a small, understandable sketch or model;
- a wiring diagram, schematic, or useful photo when applicable;
- the important hardware and library assumptions;
- a short reflection in the diary; and
- one clear next step.

This keeps the repository useful as both a reference and a record of how the understanding developed.

## License

No license has been selected yet. Treat the contents as personal learning material unless a license is added.
