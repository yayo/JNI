
#include <jni.h>
#include <stdio.h>
#include "HelloWorld.h"
 
JNIEXPORT void JNICALL Java_HelloWorld_sayHello(JNIEnv *env, jobject thisObj)
 {
  printf("Hello, Wor2d\n");
  return;
 }
