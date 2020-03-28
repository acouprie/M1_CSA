mtype = { v }

chan mychan = [0] of { mtype };

active proctype p() {
T0_init:  
    if
    :: true -> goto T0_init;
    :: v -> goto accept_s16;
    fi;

accept_s16: 
    if
    :: !v -> goto T0_init;
    fi;
}