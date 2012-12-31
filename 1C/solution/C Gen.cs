using System;
using System.IO;
using System.Collections.Generic;

public class Fffuuuu {

    Random rnd = new Random();

    public Fffuuuu() {
        Int32 n = 100000, m = 100000, i, a, b, sa, sb;
        var used = new SortedSet<Tuple<Int32, Int32>>();
        Console.WriteLine("{0} {1}", n, m);
        for (i = 0; i < m; ++i) {
            do {
                a = rnd.Next(n) + 1;
                b = rnd.Next(n) + 1;
                sa = Math.Min(a, b);
                sb = Math.Max(a, b);
            } while (sa == sb || !used.Add(Tuple.Create(sa, sb)));
            Console.WriteLine("{0} {1}", a, b);
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