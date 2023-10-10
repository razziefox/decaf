## decaf framework
decaf is an experimental minimal game framework for C. Entirely software-rendered, depending on sdl2 for the backend handling and is designed to be replaced with any other additional backends. Due to the experimental nature of this framework, its not recommended for use in commercial products.

## dependencies
* sdl2
* sdl_image
* sdl_mixer
* sdl_ttf


## example

`main.c`

```c

#include "main.h"

int main(int argc, char **argv) {

    // initializes decaf with additional window information
    decaf_init("decaf framework", 256, 144, 3);

    // initializes decaf audio
    decaf_audio_init();

    // calls load function
    load();

    // runs update and draw functions provided in decad_update
    decaf_update(update, draw);

    // clears anything left over
    decaf_quit(destroy);

    return 0;

}

```

`main.h`
```c
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "game.h"
#include "decaf/decaf.h"
#include "decaf/audio.h"

#endif
```

`game.c`
```c
#include "game.h"

void load() {

}

void update(float dt) {

}

void draw() {

}

void destroy() {

}
```

`game.h`
```c
#ifndef GAME_H
#define GAME_H

#include "decaf/graphics.h"
#include "decaf/input.h"
#include "decaf/audio.h"

void load();
void update(float dt);
void draw();
void destroy();

#endif
```