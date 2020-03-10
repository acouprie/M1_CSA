param capacite := 9;
param N := 24;

do print "capacite : " , capacite;
set Objects := { 0 to N-1 by 1 };
set Boxes := { 0 to N-1 by 1 };
param size[Objects] := <0> 6, <1> 6, <2> 5, <3> 5, <4> 5, <5> 4, <6> 4, <7> 4, <8> 4, <9> 2, <10> 2, <11> 2, <12> 2, <13> 3, <14> 3, <15> 7, <16> 7, <17> 5, <18> 5, <19> 8, <20> 8, <21> 4, <22> 4, <23> 5;

var x[Objects*Boxes] binary;
var y[Boxes] binary;

minimize boxes: sum<j> in Boxes: y[j];
subto capacite : forall <j> in Boxes: sum<i> in Objects: size[i] * x[i,j] <= capacite;
subto inonebox : forall<i> in Objects : sum<j> in Boxes: x[i,j] == 1;
subto used : forall<i,j> in Objects*Boxes : x[i,j] <= y[j];