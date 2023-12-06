#include "main.h"

int main(int argc, char **argv) {

    // initializes decaf with additional window information
    decaf_init("hello, decaf!", 256, 144, 3);

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
