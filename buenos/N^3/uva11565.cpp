// simple equations. p84 libro IOC.
// buen ejemplo para el tema de la k

bool sol = false; int x, y, x;
for (x = -100; x <= 100; x++)
    for (y = -100; y <= 100; y++)
        for (z = -100; z <= 100; z++)
            if ( y != x && z !=x && z != y &&
                x+y+z == A && x*y*z== B && x*x + y*y +z*z == C){
                    if (! sol) printf("%d %d %d\n", x, y, z);
                    sol = true;
                }