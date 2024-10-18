CXX = g++
CXXFLAGS = -std=c++11 -I include
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRCS = src/main.cpp src/Game.cpp
OBJS = $(SRCS:.cpp=.o)

TIC_TAC_TOE = TicTacToe

all: $(TIC_TAC_TOE)

$(TIC_TAC_TOE): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TIC_TAC_TOE)
