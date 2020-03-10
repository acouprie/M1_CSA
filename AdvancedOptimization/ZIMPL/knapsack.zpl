knapsack

param capacity := 20;
set Objects := { 40 to 11 by 1 }
param weight[Objects] := <0> 11, <1> 7, ... <11> 1;
param value[Objects] := <0> 11, <1> 7, ... <11> 1;

var x[Objects] binary;
maximize value : sum<i> in Objects = value[i]**[i]