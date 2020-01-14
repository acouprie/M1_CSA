CPP = g++
CFLAGS = -Wall -g
CPPFLAGS =  -DTRACE -DDELAY
# Sur Mac, ajouter -DMACOS
# TRACE_SOUHAIT : trace des depots/retraits
# TRACE_THD : creation/desctrution des thread
LDFLAGS = -lpthread
RM = rm -f
REPMH = MONITEURS_HOARE/
HM = HoareMonitor
HC = HoareCondition
SEM = sem
ER = error
LI = List

# TODO : CHANGE
# Nom de l'executable
EX = orderProcessing-v1
# Nom du fichier contenant le main
APP = orderProcessing-v1
# Nom du fichier declarant la classe moniteur
APPM = xmasMonitor
# END OF TODO

$(EX) : $(APP).o
	$(CPP) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(APP).o -o $(EX) $(APPM).o $(REPMH)$(HC).o $(REPMH)$(HM).o $(REPMH)sem.o $(REPMH)$(LI).o $(REPMH)$(ER).o -lpthread

$(APP).o : $(APP).cpp $(APPM).o
	$(CPP) $(CFLAGS) $(CPPFLAGS) $(APP).cpp -c

$(APPM).o : $(APPM).cpp $(REPMH)$(HM).o $(REPMH)$(HC).o
	$(CPP) $(CFLAGS) $(CPPFLAGS) $(APPM).cpp -c

$(REPMH)$(HM).o : $(REPMH)$(HM).cpp $(REPMH)$(HC).o $(REPMH)$(ER).o $(REPMH)$(SEM).o $(REPMH)$(LI).o
	$(CPP) $(CFLAGS) $(CPPFLAGS)  $(REPMH)$(HM).cpp -c -o $(REPMH)$(HM).o

$(REPMH)$(HC).o : $(REPMH)$(HC).cpp $(REPMH)$(HM).o $(REPMH)$(ER).o
	$(CPP) $(CFLAGS) $(CPPFLAGS) $(REPMH)$(HC).cpp -c -o $(REPMH)$(HC).o

$(REPMH)$(ER).o : $(REPMH)$(ER).cpp
	$(CPP) $(CFLAGS) $(CPPFLAGS) $(REPMH)$(ER).cpp -c -o $(REPMH)$(ER).o

$(REPMH)sem.o : $(REPMH)$(SEM).cpp $(REPMH)$(ER).o
	$(CPP) $(CFLAGS) $(REPMH)sem.cpp -c -o $(REPMH)sem.o

$(REPMH)$(LI).o : $(REPMH)$(LI).cpp
	$(CPP) $(CFLAGS) $(REPMH)$(LI).cpp -c -o $(REPMH)$(LI).o

clean :
	$(RM) $(REPMH)*.o *.o $(EX)

