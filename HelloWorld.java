
import com.ucheshang.lucky3;

public class HelloWorld
 {
  public static void main(String[] args)
   {int t;
    long v1,v2,v3;
    double result[];
    lucky3 l=new lucky3();
    t=1552748875;
    result=l.lucky_number(true,t,(37*67)+t);
    System.out.println(""+result.length+": "+result[0]+" "+result[1]+" "+result[2]+" "+result[3]);
    t=1544972986;
    result=l.lucky_number(false,t,(37*67)+t);
    System.out.println(""+result.length+": "+result[0]+" "+result[1]+" "+result[2]+" "+result[3]);
   }
 }
