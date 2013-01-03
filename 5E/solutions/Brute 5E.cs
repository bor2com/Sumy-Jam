using System;
using System.IO;

public class Program {

    const int N = 18;

    public Program() {
        Int64 n = Int64.Parse(Console.ReadLine()), i;
        Int32[] happy = new Int32[N];
        Int32 cnt;
        for (i = 0; i <= n; ++i) {
            cnt = 0;
            foreach (Char c in i.ToString()) {
                if (c == '4' || c == '7') {
                    ++cnt;
                }
            }
            ++happy[cnt];
        }
        for (i = 0; i < N; ++i) {
            Console.Write(happy[i]);
            Console.Write(' ');
        }
    }

    public static void Main() {
        var root = new Program();
        Console.Out.Flush();
    }

}
