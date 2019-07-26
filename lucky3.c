#include <assert.h>
#include <openssl/rand.h>
#include <openssl/ssl.h>
#include "com_ucheshang_lucky3.h"
#include "crc32tab.h"
#include "expectations.h"

static uint32_t crc32(const uint8_t *buf, size_t size)
{uint32_t i, crc;
 crc=0xFFFFFFFF;
 for(i=0;i<size;i++) crc=crc32tab[(crc^buf[i])&0xff]^(crc>>8);
 return(crc^0xFFFFFFFF);
}

static uint64_t s=0;

JNIEXPORT jlong JNICALL Java_com_ucheshang_lucky3_lucky_13_1connect (__attribute__((unused)) JNIEnv *env, __attribute__((unused)) jobject o, jlong i)
 {assert(8==sizeof(uint64_t)&&8==sizeof(jlong));
  uint32_t *e=alloca(sizeof(e[0]));
#ifndef OPENSSL_VERSION_NUMBER
#error OPENSSL_VERSION_NUMBER NOT DEFINED
#else
#if (0x10100000UL>OPENSSL_VERSION_NUMBER)
  OpenSSL_add_all_digests();
  OpenSSL_add_all_algorithms();
  OpenSSL_add_all_ciphers();
  *e=OpenSSL_add_ssl_algorithms();
  assert(1==*e);
  *e=SSLeay();
#else
  *e=OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_DIGESTS|OPENSSL_INIT_ADD_ALL_CIPHERS,NULL);
  assert(1==*e);
  *e=OPENSSL_init_ssl(OPENSSL_INIT_LOAD_SSL_STRINGS,NULL);
  assert(1==*e);
  *e=OpenSSL_version_num();
#endif
#endif
  if(0x000000000000000FULL!=(0x000000000000000FULL&*e))
   {fprintf(stderr,"ERR1\n");
    return(0);
   }
  else
   {
    const uint64_t v=0xE2E4467B81513395ULL;
    const uint64_t c=0x8D74770D42365779ULL;
    *e=RAND_bytes((unsigned char *)&s,sizeof(s));
    assert(1==*e);
    i^=v;
    if((*(1+(uint32_t*)&i))!=crc32((uint8_t*)&i,sizeof(uint32_t)))
     {return(0);
     }
    else
     {uint64_t *t=alloca(sizeof(t[0]));
      *e=RAND_bytes((unsigned char *)(1+(uint32_t*)t),sizeof(uint32_t));
      assert(1==*e);
      *((uint32_t*)t)=crc32((uint8_t*)(1+(uint32_t*)t),sizeof(uint32_t));
      s=*t^i;
      //fprintf(stderr,"%016lX\n",s);
      return(*t^c);
     }
   }
 }

JNIEXPORT jdoubleArray JNICALL Java_com_ucheshang_lucky3_lucky_13_1number (JNIEnv *env, __attribute__((unused)) jobject thisObj,jlong qualified,jlong auctionBeginTime,jlong winTime)
 {const size_t n=4;
  //assert(13*n*2*sizeof(map1[0])==sizeof(map1));
  //assert(22*n*2*sizeof(map0[0])==sizeof(map0));
  jdoubleArray out=(*env)->NewDoubleArray(env,n);
  if(NULL==out)
   {fprintf(stderr,"ERR2\n");
   }
  else
   {
    //fprintf(stderr,"%016lX %016lX %016lX\n",*((uint64_t*)&qualified),*((uint64_t*)&winTime ),*((uint64_t*)&auctionBeginTime));
    winTime^=auctionBeginTime;
    if((*(1+(uint32_t*)&winTime))!=crc32((uint8_t*)&winTime,sizeof(uint32_t)))
     {fprintf(stderr,"ERR3\n");
     }
    else
     {auctionBeginTime^=qualified;
      if((*(1+(uint32_t*)&auctionBeginTime))!=crc32((uint8_t*)&auctionBeginTime,sizeof(uint32_t)))
       {fprintf(stderr,"ERR4\n");
       }
      else
       {qualified^=s;
        if((*(1+(uint32_t*)&qualified))!=crc32((uint8_t*)&qualified,sizeof(uint32_t)))
         {fprintf(stderr,"ERR5\n");
         }
        else
         {auctionBeginTime=((0x3FFFFFFFUL&auctionBeginTime)/37)*67*37;
          winTime=((0x1FFFFFFFUL&winTime)/67)*37*67;
          //fprintf(stderr,"%08lX %08lX %ld %ld %ld\n",auctionBeginTime,winTime,auctionBeginTime,winTime,winTime-auctionBeginTime);
          //if((37*67+auctionBeginTime)!=winTime)
          if(auctionBeginTime>winTime)
           {fprintf(stderr,"ERR6\n");
           }
          else
           {uint32_t *v=alloca(sizeof(v[0]));
            *v=time(NULL);
            if(*v<(uint64_t)auctionBeginTime)
             {fprintf(stderr,"ERR7\n");
             }
            else
             {qualified&=0x0000000000000008ULL;
              uint8_t m=0;
              const uint64_t *p;
              switch(qualified)
               {case 0:
                 p=map0;
                 m=sizeof(map0)/(sizeof(map0[0])*n*2);
                 *v-=auctionBeginTime;
                 break;
                case 8:
                 p=map1;
                 m=sizeof(map1)/(sizeof(map1[0])*n*2);
                 *v-=winTime;
                 break;
                default:
                 assert(0!=m);
               }
              *v/=60*60*24*30;
              if(m<=1+*v) *v=m-1;
              uint8_t i;
              jdouble j[n];
              assert(sizeof(uint64_t)<=sizeof(j[0]));
              uint32_t *e=alloca(sizeof(e[0]));
              for(i=0;i<n;i++)
               {*e=RAND_bytes((unsigned char *)(j+i),sizeof(j[i]));
                assert(1==*e);
                // 0ULL; // 0.0
                // 1ULL; // 5.421010862427522E-20
                // 18446744073709550591ULL; // 0.9999999999999999
                // 18446744073709550592ULL; // 1.0
                // 18446744073709551615ULL; // 1.0
                // assert(p[(i*m+*v)*2+0]<p[(i*m+*v)*2+1]);
                j[i]=((double)*(uint64_t*)(j+i)/UINT64_MAX*(p[(i*m+*v)*2+1]-p[(i*m+*v)*2+0])+p[(i*m+*v)*2+0])/UINT64_MAX;
                // fprintf(stderr,"%lu %d %lf %lf %lf\n",(uint64_t)qualified,*v,100*(double)p[(i*m+*v)*2+0]/UINT64_MAX,100*j[i],100*(double)p[(i*m+*v)*2+1]/UINT64_MAX);
                // make 2>&1 | grep -e '^8 ' -e '^0 ' | cut -d' ' -f1,2,3,5 | md5sum | grep 4925e73b68358fb0089540a5e6957198
               }
              (*env)->SetDoubleArrayRegion(env,out,0,n,j);
             }
           }
         }
       }
     }
   }
  return(out);
 }
