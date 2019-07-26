
# gmake JAVA_HOME=/usr/java/jdk1.8.0_171-amd64 test

JAVA_HOME=/usr/java/jdk1.8.0_171-amd64

.PHONY: clean test

test : HelloWorld.class
	java -cp . -Djava.library.path=. HelloWorld
clean :
	rm -f HelloWorld.class liblucky3.so lucky3.o com/ucheshang/lucky3.class com_ucheshang_lucky3.h

com_ucheshang_lucky3.h : com/ucheshang/lucky3.java
	javac -h . com/ucheshang/lucky3.java
lucky3.o : crc32tab.h expectations.h lucky3.c com_ucheshang_lucky3.h
	gcc -Wall -Wextra -Werror -O3 -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux -fPIC -c lucky3.c
liblucky3.so : lucky3.o
	gcc -Wall -Wextra -Werror -O3 -s -shared -o liblucky3.so lucky3.o -lssl -lcrypto
com/ucheshang/lucky3.class : com/ucheshang/lucky3.java liblucky3.so
	javac com/ucheshang/lucky3.java
HelloWorld.class : HelloWorld.java com/ucheshang/lucky3.class
	javac HelloWorld.java
