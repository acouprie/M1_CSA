mtype = { v }

chan mychan = [0] of { mtype };

active proctype p() {
T0_init:  
    if
    :: true -> goto T0_init;
    :: v -> goto accept_s9;
    fi;

accept_s9: 
    if
    :: true -> goto T0_init;
    fi;
}