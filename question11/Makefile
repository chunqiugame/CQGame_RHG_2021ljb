CC=gcc
OUTPUT_DID=bin
SOURCR_DIR=src
CFLAGS=-fstack-protector-all -m32 -std=c99 -g
LD=-static -z execstack -m32 -fstack-protector-all
LD_D=-z execstack -m32
OBJ=main.o unit.o 
VPATH = ${SOURCR_DIR}:${OUTPUT_DID}

.PHONY: clean
all: dir bin

debug: dir bin-dbg

dyn: dir bin-dyn

bin: ${OBJ}
	${CC}  ${OBJ:%.o=${OUTPUT_DID}/%.o} -o ${OUTPUT_DID}/$@ ${LD}
	strip -s ${OUTPUT_DID}/$@

bin-dbg: ${OBJ}
	${CC}  ${OBJ:%.o=${OUTPUT_DID}/%.o} -o ${OUTPUT_DID}/$@ ${LD}

bin-dyn: ${OBJ}
	${CC}  ${OBJ:%.o=${OUTPUT_DID}/%.o} -o ${OUTPUT_DID}/$@ ${LD_D}
	strip -s ${OUTPUT_DID}/$@

dir:
	-mkdir bin

${OBJ}: %.o: %.c
	${CC} ${CFLAGS} -c $< -o ${OUTPUT_DID}/$@ 

clean:
	-rm ${OUTPUT_DID}/*.o
	-rm ${OUTPUT_DID}/.gdb_history
	-rm ${OUTPUT_DID}/*.idb
	-rm */peda-session-bin.txt
	-rm peda-session-bin.txt
	-rm */*~
	-rm *~
