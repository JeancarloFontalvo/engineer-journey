# Learning backlog

These are long-term topics captured from a conversation about connecting my software engineering background with graphics, physics simulation, and biomechanics. They are reference notes, not a replacement for the current quest: JavaScript graphics in the browser.

## Mathematics and physics foundations

- **Linear algebra**: vector spaces, matrix transformations, dot products, cross products, and quaternions for 3D rotations without gimbal lock.
- **Calculus and numerical integration**: derivatives and integrals for motion; Euler, Verlet, and Runge–Kutta methods for advancing a simulation through time.
- **Continuum mechanics**: how continuous materials deform under stress, including Young's modulus for elasticity and Poisson's ratio.

## Graphics programming and GPU architecture

- **Modern graphics APIs**: WebGPU, Vulkan, or Metal, with the goal of understanding how GPUs process data in parallel.
- **Shaders and GPGPU**: vertex, fragment, and compute shaders using GLSL, HLSL, or WGSL; eventually use compute shaders for heavy physics calculations.
- **Spatial data structures**: bounding volume hierarchies (BVH), octrees, and uniform grids for efficient collision detection between flexible limbs and other objects.

## Physics simulation and soft-body dynamics

- **Position-Based Dynamics (PBD)** and **Extended Position-Based Dynamics (XPBD)**: stable approaches for cloth, ropes, and soft bodies.
- **Mass-spring-damper systems**: a practical introduction to modeling flesh and muscle tissue with connected masses and springs.
- **Cosserat rod theory**: a mathematical framework for bendable and twistable structures such as tentacles, trunks, and hair.
- **Constraint solvers**: algorithms that enforce physical limits, including a distance constraint that can change from soft to rigid when a hypothetical “chemical locking state” is activated.

## Applied, bio-inspired robotics

- **Soft robotics kinematics**: forward and inverse kinematics for continuum arms and robots without conventional joints.
- **Multi-appendage control**: distributed neural networks or reinforcement learning for coordinating several limbs while avoiding collisions.

## Possible progression

1. Continue with JavaScript, Canvas, vectors, transforms, timing, and simple motion.
2. Implement a small 2D integrator and a mass-spring-damper experiment.
3. Strengthen linear algebra and numerical methods, then compare Euler, Verlet, and Runge–Kutta.
4. Explore WebGPU and compute shaders when Canvas and ordinary JavaScript become limiting.
5. Build toward collision detection, PBD/XPBD, and constraint solvers.
6. Study continuum mechanics and Cosserat rods before attempting realistic soft-body or tentacle simulations.
7. Connect the simulation work to continuum-robot kinematics and multi-appendage control.

## Decisions and future references

- **Initial sandbox**: JavaScript in the browser, starting with Canvas. C or Rust can come later when lower-level control or performance gives a concrete reason to switch.
- **References**: add a curated list of repositories and textbooks when choosing the first focused topic, rather than collecting resources without a project to apply them to.
