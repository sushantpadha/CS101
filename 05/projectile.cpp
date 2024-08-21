#include <simplecpp>

main_program {
    double limit = 480;
    double dash = 5;                              // box size, dash length
    double ay = -9.8, ax = 0;                     // accelerations
    double damp_x = 0.8, damp_y = 0.75;           // damping after headon collision
    double sidedamp_x = 0.99, sidedamp_y = 0.99;  // damping on side collision
    double dt = .01;
    double eps = 1;

    turtleSim();
    hide(true);
    // go to the bottom-left
    penUp();
    forward(-limit / 2);
    right(90);
    forward(limit / 2);
    left(90);
    penDown();

    // draw a dashed box and stay at the bottom-left as the origin
    bool draw = true;
    for (int i = 1, nsteps = limit / dash; i <= 4 * nsteps; i++, draw = !draw) {
        if (draw)
            penDown();
        else
            penUp();
        forward(limit / nsteps);
        if (i % nsteps == 0)
            left(90);
    }
    penDown();

    double vx, vy;
    cout << "Enter velocity (in m/s) in x and y directions: ";
    cin >> vx >> vy;

    // the main loop, until it stops bouncing -- when "energy" is almost 0
    // add a term -(ax<0?x:(limit-x))*ax to account for potential energy from "wind"
    // force field
    for (double x = 0, y = 0; (vx * vx + vy * vy) / 2 - y * ay > eps;
         vx += dt * ax, vy += dt * ay) {
        double dx = vx * dt, dy = vy * dt;
        if (x + dx < 0 || x + dx > limit) {  // hitting a wall
            dx = -dx * damp_x;
            vx = -vx * damp_x;
            dy *= sidedamp_y;
            vy *= sidedamp_y;
        }
        if (y + dy < 0 || y + dy > limit) {  // hitting the floor or ceiling
            dy = -dy * damp_y;
            vy = -vy * damp_y;
            dx *= sidedamp_x;
            vx *= sidedamp_x;
        }
        x += dx;
        y += dy;                           // update position for next iteration
                                           //
        double deg = arctangent(vy / vx);  // arctangent in the range -90 to +90
        if (vx < 0)
            deg += 180;  // for negative vx, it should be 90 to 270
        double ds = dt * sqrt(vx * vx + vy * vy);
        left(deg);
        forward(ds);
        right(deg);  // keep angle at 0, when not moving
    }
    cout << "Finished. Click to exit!" << endl;
    getClick();
}