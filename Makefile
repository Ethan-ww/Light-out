CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD 
EXEC = LightOut
OBJECTS = main.o grid.o cell.o graphicsdisplay.o subject.o observer.o info.o subscriptions.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean


