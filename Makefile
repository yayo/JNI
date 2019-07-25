
# gmake JAVA_HOME=/usr/java/jdk1.8.0_171-amd64 test

JAVA_HOME=/usr/java/jdk1.8.0_171-amd64

.PHONY: clean test

test : HelloWorld.class libhello.so
	java -Djava.library.path=. HelloWorld
clean :
	rm -f libhello.so HelloWorld.o HelloWorld.class HelloWorld.h

HelloWorld.class : HelloWorld.java
	javac HelloWorld.java
HelloWorld.h : HelloWorld.java
	javac -h . HelloWorld.java
HelloWorld.o : HelloWorld.c HelloWorld.h
	gcc -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux -fPIC -c HelloWorld.c
libhello.so : HelloWorld.o
	gcc -shared -o libhello.so HelloWorld.o
