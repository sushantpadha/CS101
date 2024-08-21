#include <simplecpp>

// pattern to draw: .png

main_program {
    turtleSim();
    for (int i = 0; i < 36; i++) {
        for (int j = 0; j < 4; j++) {
            forward(160);
            right(90);
        }

        right(10);
    }
    hide();
    wait(10);
}
