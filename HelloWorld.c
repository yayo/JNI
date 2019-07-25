
#include <jni.h>
#include <stdio.h>
#include <assert.h>
#include "HelloWorld.h"
 
JNIEXPORT jlongArray JNICALL Java_HelloWorld_sayHello (JNIEnv *env, jobject thisObj,jlong i1,jlong i2,jlong i3)
 {
  printf("Hello, Wor2d\n");
  const size_t n=4;
  assert(8==sizeof(i1));
  jlongArray out = (*env)->NewLongArray(env, n);
  if(NULL==out)
   {
    fprintf(stderr,"Out of Memory!");
   }
  else
   {jlong buf[n];
    int i;
    for(i=0;i<n;i++)
     {
      buf[i]=70+i;
     }
    (*env)->SetLongArrayRegion(env, out, 0, n, buf);
   }
  return(out);
 }
