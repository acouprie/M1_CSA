####################################################################################
#                                COMPILER FLAGS                                    #
####################################################################################
#                                                                                  #
# -DSTATS        : Display operation counts.                                       #
# -DDISPLAY_CUT  : Output includes the nodes in the source set of the minimum cut. #
# -DDISPLAY_FLOW : Displays flow values for each arc.                              #
#                                                                                  #
####################################################################################

CFLAGS=-O4 -Wall -DSTATS -DDISPLAY_CUT -DDISPLAY_FLOW
CC=gcc

all:  pseudo_lifo pseudo pseudo_lo_fifo pseudo_lo_lifo

pseudo_lifo:
	${CC} ${CFLAGS} -DLIFO_BUCKET pseudo.c -o pseudo_lifo

pseudo:
	${CC} ${CFLAGS} -DFIFO_BUCKET pseudo.c -o pseudo

pseudo_lo_fifo:
	${CC} ${CFLAGS} -DFIFO_BUCKET -DLOWEST_LABEL pseudo.c -o pseudo_lo_fifo

pseudo_lo_lifo:
	${CC} ${CFLAGS} -DLIFO_BUCKET -DLOWEST_LABEL pseudo.c -o pseudo_lo_lifo

clean:
	rm -f pseudo pseudo_lifo pseudo_lo_fifo pseudo_lo_lifo
