mtype = { p, q }

chan mychan = [0] of { mtype };

active proctype x() {
T0_init:  
    if
    :: !p || q -> goto accept_s20;
    :: true -> goto T0_S27;
    fi;

accept_s20: 
    if
    :: !p || q -> goto T0_init;
    :: true -> goto T0_S27;
    fi;

accept_s27:
    if
    :: q -> goto T0_init;
    :: true -> goto T0_S27;
    fi;

T0_S27:
    if
    :: q -> goto accept_s20;
    :: true -> goto T0_S27;
    :: q -> goto accept_s27;
}