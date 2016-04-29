CXX = g++
CXXFLAGS = -Wall
CXXFLAGS += -std=c++0x
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = character.o barbarian.o goblin.o reptile.o bluemen.o shadow.o assignment4.o damage.o fifo.o filo.o battle.o lineup.o tournament.o

SRCS = Character.cpp Barbarian.cpp Goblin.cpp Reptile.cpp BlueMen.cpp Shadow.cpp assignment4.cpp Damage.cpp FIFO.cpp FILO.cpp Battle.cpp LineUp.cpp Tournament.cpp

HEADERS = Character.hpp Barbarian.hpp Goblin.hpp Reptile.hpp BlueMen.hpp Shadow.hpp Damage.hpp FIFO.hpp FILO.hpp Battle.hpp LineUp.hpp Tournament.hpp

PROGS = assignment4

all: ${PROGS}

assignment4: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o $@

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f ${PROGS} *.o


