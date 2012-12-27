using System;
using System.Diagnostics;
using System.IO;

public class Program {

    struct Point {
        public Int64 x, y;
        public Point(Int64 x, Int64 y) {
            this.x = x;
            this.y = y;
        }
        public override string ToString() {
            return String.Format("{0} {1}", x, y);
        }
    }

    const Int32 Lim = 1000000000;

    static Random rnd = new Random();

    void Swap<T>(ref T a, ref T b) {
        T c = a;
        a = b;
        b = c;
    }

    Point GenPoint() {
        return new Point(rnd.Next(2 * Lim + 1) - Lim, rnd.Next(2 * Lim + 1) - Lim);
    }

    void Balance(ref Point a, ref Point b) {
        if (a.x > b.x) {
            Swap(ref a.x, ref b.x);
        }
        if (a.y > b.y) {
            Swap(ref a.y, ref b.y);
        }
    }

    Tuple<Point, Point> GenRectangle() {
        Point one, two;
        do {
            one = GenPoint();
            two = GenPoint();
            Balance(ref one, ref two);
        } while (one.x == two.x || one.y == two.y);
        Debug.Assert(one.x < two.x && one.y < two.y);
        if (rnd.Next(2) == 0) {
            Swap(ref one.x, ref two.x);
        }
        return Tuple.Create(one, two);
    }

    void Print(Tuple<Point, Point> rectangle) {
        Console.WriteLine("{0} {1}", rectangle.Item1, rectangle.Item2);
    }

    void Sixth() {
        Print(GenRectangle());
        Print(GenRectangle());
    }

    public Program() {
    }

    public static void Main() {
        var root = new Program();
        Console.Out.Flush();
    }

}
