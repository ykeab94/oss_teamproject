CC= gcc
CFLAGS = -W -Wall
TARGET = scoreMain
DTARGET = scoreMain_debug
OBJECT = score.c file.o manager.o

$(TARGET) :$(OBJECTS)
		$(CC) $(CFLAGS) -o $@ $^

$(DTARGET) : $(OBJECTS)
		$(CC) $(CFLAGS) -DDEBUG -o $@ $^

clean :
		rm *.o $(TARGET) $(DTARGET)
