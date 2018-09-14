CC      = gcc
CXX     = g++
LINK    = g++
CFLAGS  = -g -Wall -O2
LDFLAGS = -lm
TARGET  = magcalibrate
SRCS    = $(wildcard *.cpp)
SRCS    += $(wildcard *.c)

CXX_OBJS    = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
C_OBJS  = $(patsubst %.c, %.o, $(wildcard *.c))

all:$(TARGET)

$(TARGET):$(CXX_OBJS) $(C_OBJS)
	$(LINK) $(CFLAGS) $(LDFLAGS) -o $@ $^
%.o:%.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<
%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY:clean
clean:
	rm -rf *.o $(TARGET) $(CXX_OBJS) $(C_OBJS)