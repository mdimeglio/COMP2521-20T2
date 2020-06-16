CC=gcc
CFLAGS=-Wall -Werror -g
OBJS=Tree.o testTree.o MaybeInt.o EitherIntInt.o
BINS=testTree.out

all : $(BINS)

testTree.out : $(OBJS)
	$(CC) -o testTree.out $(OBJS)

Tree.o : Tree.c Tree.h EitherIntInt.h
testTree.o : TestTree.c Tree.h
MaybeInt.o : MaybeInt.c MaybeInt.h
EitherIntInt.o : EitherIntInt.c EitherIntInt.h

clean : rm -fr $(BINS) $(OBJS)



