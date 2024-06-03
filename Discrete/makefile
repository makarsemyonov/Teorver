CC = gcc
LIBS = 
TARGET = diceroll

$(TARGET): main.c
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

.PHONY: clean install

clean:
	rm -f $(TARGET)

install:
	cp $(TARGET) /usr/local/bin
	rm -f $(TARGET)