
public class HelloWorld
 {
  static String s="Hello, Wor1d";
  static
   {
    System.loadLibrary("hello"); 
   }
  private native long[] sayHello(long i1,long i2,long i3);
   // Exception in thread "main" java.lang.UnsatisfiedLinkError: no hello in java.library.path
   // Exception in thread "main" java.lang.UnsatisfiedLinkError: HelloWorld.sayHello()V
  public static void main(String[] args)
   {
    System.out.println(s);
    long result[]=new HelloWorld().sayHello(2,3,4);
    System.out.println(""+result[0]+" "+result[1]+" "+result[2]+" "+result[3]);
   }
 }
