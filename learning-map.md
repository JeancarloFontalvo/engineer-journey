# Engineer Journey Map

An RPG-style view of the areas I want to explore. The star marks the current quest.

```mermaid
flowchart TB
    camp["🏕️ Base Camp<br/>Engineer Journey"]
    quest["⭐ CURRENT QUEST<br/>Graphics programming<br/>JavaScript + browser"]

    subgraph pixel["🌲 Pixel Forest"]
        canvas["Canvas<br/>pixels · shapes · colors"]
        motion["Animation Path<br/>loop · timing · input"]
        webgpu["WebGL / WebGPU<br/>later"]
    end

    subgraph forge["⚒️ Low-Level Forge"]
        electronics["Electronics<br/>Arduino · circuits"]
        lowlevel["C / Rust<br/>later"]
        solder["Wiring + soldering"]
        energy["Energy harvesting"]
    end

    subgraph workshop["🔧 Maker Workshop"]
        mechanics["Mechanics"]
        cad["CAD"]
        printing["3D printing + modeling"]
    end

    subgraph laboratory["🔬 Simulation Laboratory"]
        physics["Physics"]
        chemistry["Chemistry"]
        physim["Physics simulation"]
        chemsim["Chemistry simulation"]
    end

    subgraph agent["🤖 Agent Workshop"]
        agentic["Agentic coding"]
        harness["Coding harnesses<br/>and agentic patterns"]
    end

    camp --> quest
    quest --> canvas
    canvas --> motion
    motion --> webgpu
    motion -. "later" .-> lowlevel

    quest --> electronics
    electronics --> solder
    solder --> energy
    electronics -. "lower-level path" .-> lowlevel

    quest --> mechanics
    mechanics --> cad
    cad --> printing

    quest --> physics
    physics --> physim
    chemistry --> chemsim
    physics --- chemistry

    quest -. "future route" .-> agentic
    agentic --> harness

    classDef current fill:#ffe08a,stroke:#a66b00,stroke-width:3px,color:#241600;
    classDef camp fill:#d9ead3,stroke:#38761d,stroke-width:2px;
    class quest current;
    class camp camp;
```

The map is allowed to change. I am not trying to learn everything at once; the current route is JavaScript graphics in the browser.
