# Learning tracker

This is the control panel for the journey. Keep the active work small, write down new ideas instead of immediately switching to them, and use the diary for the details of each session.

## Current focus

> Keep this section to one main thread. If it changes, write the reason in `diary.md` and move the old work to **Next up** or **Backlog**.

- [ ] **First motorized mechanism** — connect the L298N experiment and holder design into one safe, repeatable build.
  - [ ] Confirm the wiring and pin map, including a shared ground.
  - [ ] Test forward, reverse, stop, and independent motor behavior.
  - [ ] Add and verify PWM speed control; remove or explain unused settings in the sketch.
  - [ ] Review `cad/02-holder.FCStd`, and record its purpose, dimensions, and next design change.
  - [ ] Record the motor supply, driver behavior, and any problems in `diary.md`.

## Next up

These are worthwhile follow-ups, but they should wait until the current focus has a useful stopping point.

- [ ] Revisit the OLED cursor experiment and test whether one potentiometer can select/control both axes without making the input ambiguous.
- [ ] Add a short README or wiring note to the more hardware-dependent Arduino experiments.
- [ ] Build a small end-to-end project that combines a CAD part, an Arduino controller, and a motor or servo.
- [ ] Practice diagnosing button inputs, pull resistors, floating signals, and electrical noise with deliberate tests.

## Backlog

- [ ] Improve FreeCAD constraint and modeling workflow through another small, dimensioned part.
- [ ] Compare motor-driver behavior at different loads and speeds, including power and heat considerations.
- [ ] Review old sketches for clearer names, setup notes, and consistent comments.
- [ ] Add photos or diagrams to experiments when they explain the physical setup better than code can.

## Ideas parking lot

Capture ideas here so they are not lost, but do not let them interrupt the current focus. Promote an idea to **Current focus** only when there is a concrete next action.

- A more durable/useful motor project using a better motor and mechanical structure.
- A richer OLED interface using the existing bitmap cursor and face assets.
- More basic circuit studies, such as the NOT-gate schematic and resistor behavior.

## Session note template

Copy this into [`diary.md`](diary.md) after a meaningful session:

```markdown
## [YYYY-MM-DD]

- **Focus**:
- **Done**:
- **What I learned**:
- **Blockers or questions**:
- **Next action**:
```

## Tracking rules

1. Start a session by choosing one concrete next action.
2. Keep new ideas in the parking lot instead of switching immediately.
3. Mark work done only when it has been tested or documented.
4. End with one next action, even if the experiment is blocked.
5. Periodically archive completed items and promote only the most useful next thread.
