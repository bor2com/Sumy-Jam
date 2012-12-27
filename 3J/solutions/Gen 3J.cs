using System;
using System.Collections.Generic;
using System.IO;

public class Program {

    static Random rnd = new Random();

    void Fourth() {
        const Int32 N = 1;
        Console.WriteLine((2 * N + 1) * (2 * N + 1));
        for (Int32 y, x = -N; x <= N; ++x) {
            for (y = -N; y <= N; ++y) {
                Console.WriteLine("{0} {1}", x + y, x - y);
            }
        }
    }

    void Fifth() {
        const Int32 N = 10;
        Console.WriteLine((2 * N + 1) * (2 * N + 1));
        for (Int32 y, x = -N; x <= N; ++x) {
            for (y = -N; y <= N; ++y) {
                Console.WriteLine("{0} {1}", x, y);
            }
        }
    }

    void Sixth() {
        const int N = 500;
        int i, x, y;
        var used = new SortedSet<Tuple<Int32, Int32>>();
        Console.WriteLine(N);
        for (i = 0; i < N; ++i) {
            do {
                x = rnd.Next(201) - 100;
                y = rnd.Next(201) - 100;
            } while (!used.Add(Tuple.Create(x, y)));
            Console.WriteLine("{0} {1}", x, y);
        }
    }

    public Program() {
    }

    public static void Main() {
        var root = new Program();
        Console.Out.Flush();
    }

}
