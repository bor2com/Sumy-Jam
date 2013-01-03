using System;
using System.IO;
using System.Text;

public class Program {

    const Int32 N = 500;

    #region Generators

    static Random rnd = new Random();

    static Char GetCharacter() {
        Int32 n = rnd.Next(26 * 2 + 10);
        if (n < 26) {
            return (Char)(n + 'a');
        } else if ((n -= 26) < 26) {
            return (Char)(n + 'A');
        } else {
            return (Char)((n -= 26) | 0x30);
        }
    }

    static String GetBlock(Int32 length) {
        return new String(GetCharacter(), rnd.Next(length) + 1);
    }

    static String GetString(Int32 length) {
        Int32 i;
        Char[] result = new Char[length];
        for (i = 0; i < length; ++i) {
            result[i] = GetCharacter();
        }
        return new String(result);
    }

    static String GetShrapnel(Int32 parts) {
        StringBuilder sb = new StringBuilder();
        for (Int32 i = 0, stock = N, a; i < parts; ++i) {
            stock -= a = rnd.Next(stock);
            sb.Append(GetBlock(a));
        }
        return sb.ToString();
    }

    #endregion

    void Fourth() {
        String s = new String('x', N);
        Console.WriteLine(s);
        Console.WriteLine(s);
    }

    void Fifth() {
        String a = new String('a', N / 2);
        String b = new String('b', N / 2);
        Console.WriteLine(a + b);
        Console.WriteLine(b + a);
    }

    void Sixth() {
        Console.WriteLine(GetString(N - rnd.Next(400)));
        Console.WriteLine(GetString(N - rnd.Next(100)));
    }

    void Seventh() {
        Console.WriteLine(GetString(N - rnd.Next(100)));
        Console.WriteLine(GetString(N - rnd.Next(400)));
    }

    void Eighth() {
        Console.WriteLine(GetShrapnel(5));
        Console.WriteLine(GetShrapnel(10));
    }

    void Nineth() {
        Console.WriteLine(GetShrapnel(100));
        Console.WriteLine(GetShrapnel(3));
    }

    void Tenth() {
        Console.WriteLine(GetString(N - rnd.Next(10)));
        Console.WriteLine(GetString(N - rnd.Next(10)));
    }

    public Program() {
    }
     
    public static void Main() {
        var root = new Program();
        Console.Out.Flush();
    }

}
