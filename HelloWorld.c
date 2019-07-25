
#include <jni.h>
#include <stdio.h>
#include "HelloWorld.h"
 
JNIEXPORT jlong JNICALL Java_HelloWorld_sayHello (JNIEnv *env, jobject thisObj)
 {
  printf("Hello, Wor2d\n");
  return(1);
 }
