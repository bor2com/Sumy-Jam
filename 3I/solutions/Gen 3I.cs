using System;
using System.IO;
using Point = System.Tuple<int, int>;

public class Program {

    static Random rnd = new Random();

    Int32 Cross(Point a, Point b) {
        return a.Item1 * b.Item2 - a.Item2 * b.Item1;
    }

    Point Gen() {
        return new Point(rnd.Next(201) - 100, rnd.Next(201) - 100);
    }

    Point Vector(Point a, Point b) {
        return new Point(b.Item1 - a.Item1, b.Item2 - a.Item2);
    }

    void Seventh() {
        Point a = Gen(), b = Gen(), m, s, ab = Vector(a, b);
        do {
            m = Gen();
            s = Gen();
        } while (Cross(ab, Vector(a, m)) * Cross(ab, Vector(a, s)) <= 0);
        Console.WriteLine("{0} {1}", m.Item1, m.Item2);
        Console.WriteLine("{0} {1}", s.Item1, s.Item2);
        Console.WriteLine("{0} {1}", a.Item1, a.Item2);
        Console.WriteLine("{0} {1}", b.Item1, b.Item2);
    }

    public Program() {
    }

    public static void Main() {
        var root = new Program();
        Console.Out.Flush();
    }

}
