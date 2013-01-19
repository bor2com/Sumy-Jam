using System;

public class Program {

  static Random rnd = new Random();
  
  static Int32 GetCoordinate(Int32 n) {
    return rnd.Next(n * 2 + 1) - n;
  }
  
  struct Rectangle {
    public Int32 X1, Y1, X2, Y2;
    public override String ToString() {
      return String.Format("{0} {1} {2} {3}", X1, Y1, X2, Y2);
    }
  }
  
  static Rectangle GetRandom(Int32 n) {
    Rectangle r;
    do {
      r.X1 = GetCoordinate(n);
      r.Y1 = GetCoordinate(n);
      r.X2 = GetCoordinate(n);
      r.Y2 = GetCoordinate(n);
      if (r.X1 > r.X2) {
        Swap(ref r.X1, ref r.X2);
      }
      if (r.Y1 > r.Y2) {
        Swap(ref r.Y1, ref r.Y2);
      }
    } while (r.X1 == r.X2 || r.Y1 == r.Y2);
    return r;
  }
  
  static void GenRandom(Int32 n, Int32 q) {
    Console.WriteLine(GetRandom(n));
    Console.WriteLine(q);
    while (--q >= 0) {
      Console.WriteLine(GetRandom(n));
    }
  }

  void Fourth() {
    GenRandom(50, 50);
  }

  void Fifth() {
    Int32 n = 10, i;
    Rectangle[] r = new Rectangle[n * 2];
    for (i = 0; i < n; ++i) {
      r[i * 2] = r[i * 2 + 1] = new Rectangle() { X1 = -(i + 1), Y1 = -(i + 1), X2 = i + 1, Y2 = i + 1 };
    }
    RandomShuffle(r);
    Console.WriteLine("{0} {1} {2} {3}", -n, -n, n, n);
    Console.WriteLine(r.Length);
    for (i = 0; i < r.Length; ++i) {
      Console.WriteLine(r[i]);
    }
  }

  void Sixth() {
    Int32 n = 100000, i;
    Rectangle[] r = new Rectangle[n];
    for (i = 0; i < n; ++i) {
      r[i] = new Rectangle() { X1 = -(i + 1), Y1 = -(i + 1), X2 = i + 1, Y2 = i + 1 };
    }
    RandomShuffle(r);
    Console.WriteLine("{0} {1} {2} {3}", -n, -n, n, n);
    Console.WriteLine(r.Length);
    for (i = 0; i < r.Length; ++i) {
      Console.WriteLine(r[i]);
    }
  }

  void Seventh() {
    Int32 n = 99999, i;
    Rectangle[] r = new Rectangle[n];
    for (i = 0; i < n; ++i) {
      r[i] = new Rectangle() { X1 = -(i + 1), Y1 = -(i + 1), X2 = i + 1, Y2 = i + 1 };
    }
    RandomShuffle(r);
    Console.WriteLine("{0} {1} {2} {3}", -(n + 1), -(n + 1), n + 1, n + 1);
    Console.WriteLine(r.Length);
    for (i = 0; i < r.Length; ++i) {
      Console.WriteLine(r[i]);
    }
  }
  
  void Eighth() {
    Int32 n = (Int32)1e5, q = (Int32)1e5;
    Console.WriteLine("-3 -2 4 8");
    Console.WriteLine(q);
    Rectangle r;
    while (--q >= 0) {
      do {
        r.X1 = rnd.Next(n) + 1;
        r.Y1 = rnd.Next(n) + 1;
        r.X2 = rnd.Next(n) + 1;
        r.Y2 = rnd.Next(n) + 1;
        if (r.X1 > r.X2) {
          Swap(ref r.X1, ref r.X2);
        }
        if (r.Y1 > r.Y2) {
          Swap(ref r.Y1, ref r.Y2);
        }
      } while (r.X1 == r.X2 || r.Y1 == r.Y2);
      if (rnd.Next(2) == 0) {
        r.X1 = -r.X1;
        r.X2 = -r.X2;
        Swap(ref r.X1, ref r.X2);
      }
      if (rnd.Next(2) == 0) {
        r.Y1 = -r.Y1;
        r.Y2 = -r.Y2;
        Swap(ref r.Y1, ref r.Y2);
      }
      Console.WriteLine(r);
    }
  }

  void Nineth() {
    GenRandom((Int32)1e5, (Int32)1e5);
  }

  public Program() {
  }
  
  static void RandomShuffle<T>(T[] a) {
    Byte[] seed = new Byte[a.Length];
    rnd.NextBytes(seed);
    Array.Sort(seed, a);
  }
  
  static void Swap<T>(ref T a, ref T b) {
    T t = a;
    a = b;
    b = t;
  }

  public static void Main() {
    Console.SetOut(new System.IO.StreamWriter("../plus/in"));
    var root = new Program();
    Console.Out.Flush();
  }

}
