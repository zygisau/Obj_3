all: source_vektoriai.cpp
	g++ source_vektoriai.cpp -o testVector
	./testVector

masyvas: source_masyvai.cpp
	g++ source_masyvai.cpp -o testArray
	./testArray

clean:
	rm *.o testVector testArray

cleanAll: 
	rm *.o testVector testArray vargsiukai.txt kietuoliai.txt