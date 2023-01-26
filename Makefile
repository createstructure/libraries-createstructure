all:
	make precompile

precompile:
	g++ -Wall -lcurl -c ./bin/cryptation.cpp -o ./bin/cryptation.o
	g++ -Wall -lcurl -c ./bin/emoji.cpp -o ./bin/emoji.o
	g++ -Wall -lcurl -c ./bin/inputs.cpp -o ./bin/inputs.o
	g++ -Wall -lcurl -c ./bin/positive.cpp -o ./bin/positive.o
	g++ -Wall -lcurl -c ./bin/rest.cpp -o ./bin/rest.o
	g++ -Wall -lcurl -c ./bin/sleep.cpp -o ./bin/sleep.o
