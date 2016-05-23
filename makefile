pokemon: trainer.o emulator.o poketmon.o item.o
	g++ -std=c++11 -o pokemon trainer.o emulator.o poketmon.o item.o

trainer.o: trainer.h trainer.cpp
	g++ -std=c++11 -c trainer.cpp trainer.h

poketmon.o: poketmon.h skill.h poketmon.cpp
	g++ -std=c++11 -c poketmon.cpp poketmon.h

emulator.o: emulator.h trainer.h emulator.cpp
	g++ -std=c++11 -c emulator.cpp emulator.h trainer.h

item.o: item.h item.cpp
	g++ -std=c++11 -c item.cpp item.h

clean:
	rm *.o
	rm *.gch
