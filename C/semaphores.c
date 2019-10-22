// Not real C, does not compile
// The purpose is only to give examples
// and a global overview

void exercise_1(void) {
    // Version 1
    // Tow threads write on a screen 10 messages ("Im process 0", "Im process 1") in an alternate manner
    Mutex m1, m2;
    init(m1, 1);
    init(m2, 0);

    fork();

    if(pid == 0) {
        for (int i = 0; i < 10; i++)
        {
            P(m1);
            printf("Im the son process");
            V(m2);
        }
    } else {
        for (int i = 0; i < 10; i++)
        {
            P(m2);
            printf("Im your father");
            V(m1);
        }
    }
}

void exercise_2(void) {
    // Version 2
    // Generalize the procedure with P threads
    int nbProcess = 10;
    Mutex m [nbProcess]
    init(m[0], 1);
    for (int i = 0; i < n; i++)
    {
        init(m[i], 0);
        fork();
    }

    Process(int i) {
        int j = 0;
        while (j < 10)
        {
            j++;
            P(m[i]);
            printf("I am Process" + i);
            V(m[(i+1) % nbProcess]);
        }
    }
}

/*
Paragliding with semaphores
We have NBW wings that are shared within paragliders.
A paraglider activity is:
    
    Forever:
        Take a wing
        Fly
        Take a shuttle to go up
        Give back the wing

1. Suppose there is only one shuttle
=> Synchronise the activities of paragliders
2.1 One shuttle leaves only when full
2.2 Suppose there are NBS shuttles wth NBP places
*/

// 1
void exercise_paraglider_1() {
    int nbOfWings = 25;
    Semaphore wings;
    Mutex shuttle;
    init(wings, nbOfWings);
    init(shuttle, 1);

    TakeAWing();
}

void TakeAWing() {
    P(wings);
    Fly();
}

void Fly() {
    wait(100);
    TakeShuttle();
}

void TakeShuttle() {
    P(shuttle);
    // go up
    V(shuttle);
    GivingBackWing();
}

void GiveBackWing() {
    V(wings);
}

// 2.1
void exercise_paraglider_2() {
    int nbOfSeats = 20;
    int nbOfWings = 25;
    Mutex m;
    Semaphore wings, shuttle, waiters;
    init(wings, nbOfWings);
    init(shuttle, nbOfSeats);
    init(waiters, 0);
    init(m, 1);
    nbOfOccupiedSeats = 0;    

    TakeAWing();
}

void TakeAWing() {
    P(wings);
    Fly();
}

void Fly() {
    wait(100);
    TakeShuttle();
}

void TakeShuttle() {
    P(m);
    // can be deleted, overcomplexify after adding the mutuex m
    // P(shuttle);
    nbOfOccupiedSeats++;
    if (nbOfOccupiedSeats == nbOfSeats)
    {
        nbOfOccupiedSeats =  0;
        /* for (int i = 0; i < nvOfSeats; i++)
        {
            V(shuttle);
        } */
        for (int i = 1; i < nvOfSeats; i++)
        {
            V(waiters);
        }
        V(m);
    } else {
        V(m)
        P(waiters)
    }
}

void GiveBackWing() {
    V(wings);
}

// 2.2
void exercise_paraglider_2() {
    int nbOfWings = 25;
    int nbOfSeats = 20;
    int nbOfShuttles = 10;
    int nbOfOccupiedSeats[nbOfSeats];
    Mutex m;
    Semaphore wings, shuttles, waiters;
    init(wings, nbOfWings);
    init(shuttles, nbOfShuttles);
    init(waiters, 0);

    TakeAWing();
}

void TakeAWing() {
    P(wings);
    Fly();
}

void Fly() {
    wait(100);
    TakeShuttle();
}

void TakeShuttle() {
    P(shuttles);
    // protect this part with a mutex
    P(m);
    for (int i = 0; i < nbOfShuttles; i++)
    {
        if(nbOfOccupiedSeats[i] < nbOfSeats) {
            s = i;
            break;
        }
    }
    nbOfOccupiedSeats[s]++;
    if(nbOfOccupiedSeats[s] == nbOfSeats) {
        // go up
        nbOfOccupiedSeats[s] = 0;
        V(shuttles);
        for (int i = 0; i < nbOfSeats; i++)
        {
            V(m);
            V(waiters[s]);
        } else {
            V(m);
            V(shutlles);
            P(waiters[s]);
        }
    }
}

void GiveBackWing() {
    V(wings);
}