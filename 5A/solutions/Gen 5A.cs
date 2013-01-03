using System;
using System.IO;
using System.Text;

public sealed class Program {

    const Int32 N = (Int32)1e5;

    static readonly Random rnd = new Random();

    void Swap<T>(ref T a, ref T b) {
        T t = a;
        a = b;
        b = t;
    }

    Int32[] GenerateSequence(Int32 numberCount, Int32 numberSpan) {
        Int32[] result = new Int32[numberCount];
        for (Int32 i = 0; i < numberCount; ++i) {
            result[i] = rnd.Next(numberSpan) - numberSpan / 2;
        }
        return result;
    }

    void Print(Int32[] sequence) {
        for (Int32 i = 0; i < sequence.Length; Console.Write(++i == sequence.Length ? Environment.NewLine : " ")) {
            Console.Write(sequence[i]);
        }
    }

    void PrintRandomQuery(Int32 elements, Int32 queries) {
        Int32 a, b;
        while (--queries >= 0) {
            a = rnd.Next(elements) + 1;
            b = rnd.Next(elements) + 1;
            if (a > b) {
                Swap(ref a, ref b);
            }
            Console.WriteLine("{0} {1}", a, b);
        }
    }

    void Second() {
        Int32 n = 200, q = 100;
        Console.WriteLine("{0} {1}", n, q);
        Print(GenerateSequence(n, 100));
        PrintRandomQuery(n, q);
    }

    void Fifth() {
        Int32 n = 1000, q = 1000;
        Console.WriteLine("{0} {1}", n, q);
        Print(GenerateSequence(n, 1000));
        PrintRandomQuery(n, q);
    }

    void Sixth() {
        Int32 n = 100000 - rnd.Next(1000), q = 100000 - rnd.Next(1000);
        Console.WriteLine("{0} {1}", n, q);
        Print(GenerateSequence(n, (Int32)2e9));
        PrintRandomQuery(n, q);
    }

    void Tenth() {
        Int32 n = 100000, q = 100000, i;
        Console.WriteLine("{0} {1}", n, q);
        Int32[] seq = new Int32[n];
        for (i = 0; i < n; ++i) {
            seq[i] = (Int32)(-1e9);
        }
        Print(seq);
        while (--q >= 0) {
            Console.WriteLine("1 {0}", n);
        }
    }

    public Program() {
    }
     
    public static void Main() {
        var root = new Program();
        Console.Out.Flush();
    }

}
