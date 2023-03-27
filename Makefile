CC = g++
CFLAGS = -std=c++20 -Wall -Wextra
FILES := $(wildcard *.cpp)
HEADERS := $(wildcard *.h)
BINARY = f1_simulator

all: $(FILES) $(HEADERS)
	$(CC) $(CFLAGS) $(FILES) -o $(BINARY)
clean:
	rm -f $(BINARY)