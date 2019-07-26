package com.ucheshang;

import java.util.Random;
import java.util.zip.CRC32;

public class lucky3
 {static
   {System.loadLibrary("lucky3"); 
    // Exception in thread "main" java.lang.UnsatisfiedLinkError: no hello in java.library.path
   }
  private native long lucky_3_connect(long i);
  private native double[] lucky_3_number(long v1,long v2,long v3);
    // Exception in thread "main" java.lang.UnsatisfiedLinkError: HelloWorld.sayHello()V
  private long getV(){return(0xE2E4467B81513395L);}
  private long getC(){return(0x8D74770D42365779L);}
  private long s=0;
  private byte[] i2b(int i)
   {byte[] b=new byte[4];
    b[0]=(byte)(i>>0);
    b[1]=(byte)(i>>8);
    b[2]=(byte)(i>>16);
    b[3]=(byte)(i>>24);
    return(b);
   }
  public lucky3()
   {long r1=(new Random()).nextInt();
    CRC32 crc1 = new CRC32();
    crc1.update(i2b((int)r1),0,4);
    r1&=0x00000000FFFFFFFFL;
    r1|=(crc1.getValue()<<32);
    long r2=getC()^lucky_3_connect(r1^getV());
    CRC32 crc2 = new CRC32();
    crc2.update(i2b((int)(r2>>32)),0,4);
    if(crc2.getValue()!=(0x00000000FFFFFFFFL&r2))
     s=0;
    else
     s=r1^r2;
   }
  private long getQ(boolean q)
   {long r=(new Random()).nextInt();
    if(q)
     {r|=0x00000008L;
     }
    else
     {r&=0xFFFFFFF7L;
     }
    CRC32 crc = new CRC32();
    crc.update(i2b((int)r),0,4);
    r&=0x00000000FFFFFFFFL;
    r|=(crc.getValue()<<32);
    return(r^s);
   }
  private long getA(int t,long x)
   {t/=67;
    long r=(new Random()).nextInt();
    r&=0xC0000000;
    r|=t;
    CRC32 crc = new CRC32();
    crc.update(i2b((int)r),0,4);
    r&=0x00000000FFFFFFFFL;
    r|=(crc.getValue()<<32);
    return(r^x);
   }
  private long getW(int t,long x)
   {t/=37;
    long r=(new Random()).nextInt();
    r&=0xE0000000;
    r|=t;
    CRC32 crc = new CRC32();
    crc.update(i2b((int)r),0,4);
    r&=0x00000000FFFFFFFFL;
    r|=(crc.getValue()<<32);
    return(r^x);
   }
  public double[] lucky_number(boolean v1,int v2,int v3)
   {if(0==s)
     {return(new double[0]);
     }
    else
     {long r1=getQ(v1);
      long r2=getA(v2,r1);
      long r3=getW(v3,r2);
      return(lucky_3_number(r1,r2,r3));
     }
   }
 }
