param capacite := 9;
do print "capacite : " , capacite;
set Objets := { 0 to 23 by 1 };
param size[Objets] := <0> 6, <1> 6, <2> 5, <3> 5, <4> 5, <5> 4, <6> 4, <7> 4, <8> 4, <9> 2, <10> 2, <11> 2, <12> 2, <13> 3, <14> 3, <15> 7, <16> 7, <17> 5, <18> 5, <19> 8, <20> 8, <21> 4, <22> 4, <23> 5;
var x[Objets] binary;

maximize valeur : sum<i> in Objets: valeurs[i] * x[i];
subto poids : sum<i> in Objets: poids[i] * x[i] <= capacite;