# Rig3D

Game Engine Design and Development
Fall 2015

Gabriel Ortega
Henrique Silva Chaltein de Almeida
Lucas Vasconcelos
Tiago Martines


# Running the Samples

1. Set the Working Directory of the Sample Project to $(OutDir).
2. Set the proto-03-remix project as Startup Project.

# Mono [Author: Lucas Vasconcelos]

On this sample, the class Game defined in C# is hooked up to the main engine. The Start method is called during initalization phase and the Update method is called every frame.

* The blue square can be controlled by pressing the arrow keys.
* Space reactivates and reactivates the C# hook.

# Relevant code is located at:

## C++

### MonoEngine.{h, cpp}

Code related to mono binding is located here.

### Input.{h, cpp}

Code related to keyboard input is located here.

### main.cpp (VInitialize, VUpdate)

Initialization code and hooks are called here.

## C# projects

### Rig3DEngine

Engine C# interface

### Rig3DGame

Game logic
