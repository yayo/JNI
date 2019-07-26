
import com.ucheshang.lucky2;

public class HelloWorld
 {
  public static void main(String[] args)
   {int t=1555340875;
    lucky2 l=new lucky2();
    long v1=l.getQ(true);
    long v2=l.getW((37*67)+t,v1);
    long v3=l.getA(t,v2);
    double result[]=l.sayHello(v1,v2,v3);
    System.out.println(""+result[0]+" "+result[1]+" "+result[2]+" "+result[3]);
   }
 }
