
#include <jni.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include "HelloWorld.h"
 
JNIEXPORT jlongArray JNICALL Java_HelloWorld_sayHello (JNIEnv *env, jobject thisObj,jlong i1,jlong i2,jlong i3)
 {
  printf("Hello, Wor2d\n");
  const size_t n=4;
  assert(8==sizeof(uint64_t) && 8==sizeof(jlong));
  jlongArray out = (*env)->NewLongArray(env, n);
  if(NULL==out)
   {
    fprintf(stderr,"Out of Memory!");
   }
  else
   {jlong buf[n];
    int i;
    for(i=0;i<n;i++)
     {uint64_t t;
      assert(1==RAND_bytes(&t,sizeof(t)));
      buf[i]=t;
     }
    (*env)->SetLongArrayRegion(env, out, 0, n, buf);
   }
  return(out);
 }
