
public class HelloWorld
 {
  static String s="Hello, Wor1d";
  static
   {
    System.loadLibrary("hello"); 
   }
  private native void sayHello();
   // Exception in thread "main" java.lang.UnsatisfiedLinkError: no hello in java.library.path
   // Exception in thread "main" java.lang.UnsatisfiedLinkError: HelloWorld.sayHello()V
  public static void main(String[] args)
   {
    System.out.println(s);
    new HelloWorld().sayHello();
   }
 }
