# Bomberman C++ clone

## How this project is structured?

The principal code base of the project is under the project folder,

There we have 3 separeted folders

- backend: Store code base relative to the game business logic;
- client-sdk: Provide a high-level API, to build client applications;
- client: Demo client app

To run this game you should start the backend service that will comunicate with the client app.

## How build this project?

### On Linux

You must have:

- `CMake 3.10.0` or higher.
- lib `SDL 2.0`
- lib `nlohmann_json`

Once you have all the dependencies, in a terminal type:

```
    mkdir build
    cd build
    cmake ..
    make
```
