mtype = { enter, exit }

chan mychan = [0] of { mtype };

active [2] proctype p() {
ncs:  
    if
    :: true -> goto wait;
    fi;

wait:
    if
    :: mychan?enter -> goto cs;
    fi;

cs: 
    if
    :: mychan?exit -> goto ncs;
    fi;
}

active proctype c() {
idle:    
    if
    :: mychan!enter -> goto busy;
    fi;

busy:    
    if
    :: mychan!exit -> goto idle;
    fi;
}

ltl excl0 { [] !(p[0]@cs && p[1]@cs) }
ltl excl1 { [] !(p[0]@cs) }
ltl excl2 { [] <> (p[0]@cs || p[1]@cs) }