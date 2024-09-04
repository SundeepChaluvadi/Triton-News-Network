# Makefile for P1
# Sharlee Climer


CC      = g++
CFLAGS  = -g
TARGET  = P2
OBJS    = P2.o

$(TARGET):	$(OBJS)
		$(CC) -o $(TARGET) $(OBJS)

P2.o:	P2.cpp P2.h Timer.h
		$(CC) $(CFLAGS) -c P2.cpp

clean:
		/bin/rm -f *.o $(TARGET)
