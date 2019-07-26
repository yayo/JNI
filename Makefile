
# gmake JAVA_HOME=/usr/java/jdk1.8.0_171-amd64 test

JAVA_HOME=/usr/java/jdk1.8.0_171-amd64

.PHONY: clean test

test : HelloWorld.class
	java -cp . -Djava.library.path=. HelloWorld
clean :
	rm -f HelloWorld.class liblucky.so lucky.o lucky.class lucky.h

lucky.class : lucky.java
	javac lucky.java
lucky.h : lucky.java
	javac -h . lucky.java
lucky.o : lucky.c lucky.h
	gcc -Wall -Wextra -Werror -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux -fPIC -c lucky.c
liblucky.so : lucky.o
	gcc -Wall -Wextra -Werror -shared -o liblucky.so lucky.o -lcrypto

HelloWorld.class : HelloWorld.java liblucky.so
	javac HelloWorld.java
