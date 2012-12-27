using System;
using System.Linq;
using System.Collections.Generic;
using System.IO;
using System.Text;

public class Program {

    static Random rnd = new Random();

    void Fourth() {
        Int32 n = 100000, i;
        Console.WriteLine(n);
        for (i = 0; i < n; ++i) {
            Console.WriteLine('0');
        }
    }

    void Fifth() {
        Int32 n = 100000, i;
        Console.WriteLine(n);
        for (i = 0; i < n; ++i) {
            Console.WriteLine("1 {0}", (i ^ 1) + 1);
        }
    }

    void Sixth() {
        Int32 n = 10000, i;
        Console.WriteLine(n);
        for (i = 0; i < n; ++i) {
            switch (i) {
                case 0 :
                    Console.WriteLine("1 2");
                    break;
                case 1 :
                    Console.WriteLine('0');
                    break;
                default :
                    if (i % 2 != 0) {
                        Console.WriteLine("3 {0} {2} {1}", i & ~1, (i & ~1) - 1, i);
                    } else {
                        Console.WriteLine("2 {0} {1}", i & ~1, (i & ~1) - 1);
                    }
                    break;
            }
        }
    }

    void Seventh() {
        Int32 n = 100000, i, m = 100000;
        SortedSet<Tuple<Int32, Int32> > set = new SortedSet<Tuple<Int32, Int32>>();
        Tuple<Int32, Int32> tmp;
        Console.WriteLine(n);
        while (--m >= 0) {
            do {
                tmp = Tuple.Create(rnd.Next(n / 2), rnd.Next(n / 2) + n / 2);
            } while (!set.Add(tmp));
        }
        var select =
            from one in set
            group one.Item2 by one.Item1;
        var iterator = select.GetEnumerator();
        Boolean hasNext = iterator.MoveNext();
        StringBuilder builder = new StringBuilder();
        for (i = 0; i < n; ++i) {
            if (hasNext && i == iterator.Current.Key) {
                m = 0;
                builder.Clear();
                foreach (var element in iterator.Current) {
                    builder.Append(' ');
                    builder.Append(element + 1);
                    ++m;
                }
                Console.Write(m);
                Console.WriteLine(builder);
                hasNext = iterator.MoveNext();
            } else {
                Console.WriteLine('0');
            }
        }
    }

    void Eighth() {
        Int32 n = 99699, i;
        Byte[] seed = new Byte[n];
        Int32[] order = new Int32[n], ptr = new Int32[n];
        for (i = 0; i < n; ++i) {
            order[i] = i;
        }
        rnd.NextBytes(seed);
        Array.Sort(seed, order);
        ptr[0] = -1;
        for (i = 1; i < n; ++i) {
            ptr[i] = order[i - 1];
        }
        Array.Sort(order, ptr);
        Console.WriteLine(n);
        for (i = 0; i < n; ++i) {
            if (ptr[i] < 0) {
                Console.WriteLine('0');
            } else {
                Console.WriteLine("1 {0}", ptr[i] + 1);
            }
        }
    }

    public Program() {
    }

    public static void Main() {
        var root = new Program();
        Console.Out.Flush();
    }

}
