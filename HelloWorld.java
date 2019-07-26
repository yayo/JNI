
import java.util.Random;
import java.util.zip.CRC32;

public class HelloWorld
 {static
   {System.loadLibrary("hello"); 
   }
  private native double[] sayHello(long v1,long v2,long v3);
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
  static long getQ(boolean q)
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
  static long getW(int w,long x)
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
  static long getA(int a,long x)
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
  public static void main(String[] args)
   {int t=1555340875;
    long v1=getQ(true);
    long v2=getW((37*67)+t,v1);
    long v3=getA(t,v2);
    double result[]=new HelloWorld().sayHello(v1,v2,v3);
    System.out.println(""+result[0]+" "+result[1]+" "+result[2]+" "+result[3]);
   }
 }
