
# gmake JAVA_HOME=/usr/java/jdk1.8.0_171-amd64 test

JAVA_HOME=/usr/java/jdk1.8.0_171-amd64

.PHONY: clean test

test : HelloWorld.class
	java -cp . -Djava.library.path=. HelloWorld
clean :
	rm -f HelloWorld.class liblucky2.so lucky.o com/ucheshang/lucky2.class com_ucheshang_lucky2.h

com/ucheshang/lucky2.class : com/ucheshang/lucky2.java
	javac com/ucheshang/lucky2.java
com_ucheshang_lucky2.h : com/ucheshang/lucky2.java
	javac -h . com/ucheshang/lucky2.java
lucky.o : lucky.c com_ucheshang_lucky2.h
	gcc -Wall -Wextra -Werror -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux -fPIC -c lucky.c
liblucky2.so : lucky.o
	gcc -Wall -Wextra -Werror -O3 -s -shared -o liblucky2.so lucky.o -lcrypto

HelloWorld.class : HelloWorld.java liblucky2.so
	javac HelloWorld.java
