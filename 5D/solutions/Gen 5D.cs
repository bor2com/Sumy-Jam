using System;
using System.IO;
using System.Text;

public sealed class Program {

    const Int32 N = 100, maxCost = (Int32)1e9;

    static readonly Random rnd = new Random();

    delegate Int32 GenNum();

    void Generate(GenNum g, Int32 n) {
        for (Int32 i = 0; i < n; Console.Write(++i == n ? Environment.NewLine : " ")) {
            Console.Write(g());
        }
    }

    void Seventh() {
        Int32 n = rnd.Next(N) + 1, w = rnd.Next(N * N) + 1, i;
        Console.WriteLine("{0} {1}", n, w);
        Generate(() => rnd.Next(100) + 1, n);
        Generate(() => rnd.Next(maxCost) + 1, n);
    }

    void Eighth() {
        Int32 n = N - rnd.Next(5), w = N * N - rnd.Next(10), i;
        Console.WriteLine("{0} {1}", n, w);
        Generate(() => rnd.Next(100) + 1, n);
        Generate(() => maxCost - rnd.Next(1000), n);
    }

    public Program() {
    }
     
    public static void Main() {
        var root = new Program();
        Console.Out.Flush();
    }

}
