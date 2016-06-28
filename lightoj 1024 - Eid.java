import java.math.BigInteger ;
import java.util.Scanner;

class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        int tcase ;
        tcase = cin.nextInt();

        for(int i=1 ; i<=tcase ; i++)
        {
            int n ;
            n = cin.nextInt();
            BigInteger result , a , b ;
            result = BigInteger.ONE ;

            for(int j=0 ; j<n ; j++)
            {
                b =  cin.nextBigInteger();
                result = result.divide(result.gcd(b)).multiply(b);
            }
            System.out.println("Case "+i+": "+result);
            System.gc();
        }
    }
}
