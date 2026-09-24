# Learning tracker

## Current quest: graphics programming

Start small and get something moving in a browser before worrying about engines or advanced APIs.

- [ ] Create a tiny JavaScript project that opens a canvas in a browser.
- [ ] Draw pixels, rectangles, lines, and simple shapes.
- [ ] Learn the animation loop and frame timing.
- [ ] Add keyboard and mouse input.
- [ ] Make one small 2D experiment or toy.
- [ ] Write down what I understand and what I still do not understand in `diary.md`.

### Suggested path

1. JavaScript basics needed for the experiment
2. HTML canvas and a render loop
3. Coordinates, vectors, colors, and transforms
4. Input and simple animation
5. A small game-like or simulation-like project
6. WebGL/WebGPU only when Canvas becomes limiting
7. C or Rust later, if lower-level control or performance becomes useful

## Next up

- [ ] Return to the L298N motor experiment and make the setup safe and repeatable.
  - [ ] Confirm the wiring and pin map, including a shared ground.
  - [ ] Test forward, reverse, stop, and independent motor behavior.
  - [ ] Add and verify PWM speed control.
  - [ ] Review `cad/02-holder.FCStd` and record its purpose, dimensions, and next design change.
- [ ] Revisit the OLED cursor experiment and test one potentiometer controlling both axes.
- [ ] Add short wiring notes to the hardware-dependent Arduino experiments.

## Backlog

- [ ] Build a small project combining a CAD part, an Arduino controller, and a motor or servo.
- [ ] Improve FreeCAD constraint and modeling workflow with another dimensioned part.
- [ ] Learn more about 3D printing and design a part for printing.
- [ ] Practice wiring and soldering on a small, documented circuit.
- [ ] Explore energy harvesting with a simple measurable experiment.
- [ ] Study physics simulation after getting a basic graphics loop working.
- [ ] Study chemistry simulation after building enough math and modeling background.
- [ ] Explore agentic coding through a small harness or repeatable coding workflow.
- [ ] Review C and Rust when JavaScript experiments expose a useful reason to go lower level.

## Ideas parking lot

Ideas go here so they are not lost without becoming the next distraction.

- A richer OLED interface using the existing cursor and face assets.
- A more durable motor project with a better motor and mechanical structure.
- Basic circuit studies, including the NOT-gate schematic and resistor behavior.
- A browser-based physics toy.
- A browser-based chemistry or particle visualization.
- Build an **Engineer Journey RPG** as a graphics/web project: JavaScript in the browser with Canvas, SVG, or HTML; dynamically generate skills and mastery stars from repository data. Try building it myself before delegating implementation.
- A small coding agent harness for one narrow development task.

## Session note template

```markdown
## [YYYY-MM-DD]

- **Focus**:
- **Done**:
- **What I learned**:
- **Blockers or questions**:
- **Next action**:
```

## Rules for staying focused

- Keep one current quest.
- Put new ideas in the parking lot instead of switching immediately.
- Mark work done only when it has been tested or documented.
- End a session with one clear next action.
- Move the current quest when the next step is no longer useful, not just because a new idea appeared.
