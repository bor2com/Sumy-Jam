using System;
using System.IO;

public class Fffuuuu {

    Random rnd = new Random();

    public Fffuuuu() {
        Int32 n = 10000, m = 50000, i;
        Console.Write("{0} {1}", n, m);
        Console.WriteLine(" {0} {1}", rnd.Next(n) + 1, rnd.Next(n) + 1);
        for (i = 0; i < m; ++i) {
            Console.WriteLine("{0} {1}", rnd.Next(n) + 1, rnd.Next(n) + 1);
        }
    }

    public static void Main() {
#if DEBUG
        Console.SetIn(new StreamReader(@"..\..\in.txt"));
        Console.SetOut(new StreamWriter(@"C:\Users\anonymous\Ordnance\Plus\Plus\in.txt"));
#endif
        Fffuuuu root = new Fffuuuu();
        Console.Out.Flush();
    }

}
