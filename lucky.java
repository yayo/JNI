
import java.util.Random;
import java.util.zip.CRC32;

public class lucky
 {static
   {System.loadLibrary("lucky"); 
   }
  public native double[] sayHello(long v1,long v2,long v3);
   // Exception in thread "main" java.lang.UnsatisfiedLinkError: no hello in java.library.path
   // Exception in thread "main" java.lang.UnsatisfiedLinkError: HelloWorld.sayHello()V
  static byte[] i2b(int i)
   {byte[] b=new byte[4];
    b[0]=(byte)(i>>0);
    b[1]=(byte)(i>>8);
    b[2]=(byte)(i>>16);
    b[3]=(byte)(i>>24);
    return(b);
   }
  public static long getQ(boolean q)
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
    return(r);
   }
  public static long getW(int w,long x)
   {w/=37;
    long r=(new Random()).nextInt();
    r&=0xE0000000;
    r|=w;
    CRC32 crc = new CRC32();
    crc.update(i2b((int)r),0,4);
    r&=0x00000000FFFFFFFFL;
    r|=(crc.getValue()<<32);
    return(r^x);
   }
  public static long getA(int a,long x)
   {a/=67;
    long r=(new Random()).nextInt();
    r&=0xC0000000;
    r|=a;
    CRC32 crc = new CRC32();
    crc.update(i2b((int)r),0,4);
    r&=0x00000000FFFFFFFFL;
    r|=(crc.getValue()<<32);
    return(r^x);
   }
 }
