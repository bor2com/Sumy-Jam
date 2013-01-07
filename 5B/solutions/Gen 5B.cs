using System;
using System.IO;

public class Fffuuuu {

  static Random rnd = new Random();

  const Int32 N = 500;
  
  void Swap<T>(ref T a, ref T b) {
    T t = a;
    a = b;
    b = t;
  }
  
  void WriteRandomRectangles(Int32 times, Int32 r, Int32 c) {
    Int32 i1, i2, j1, j2;
    Console.WriteLine(times);
    while (--times >= 0) {
      i1 = rnd.Next(r) + 1;
      i2 = rnd.Next(r) + 1;
      j1 = rnd.Next(c) + 1;
      j2 = rnd.Next(c) + 1;
      if (i1 > i2) {
        Swap(ref i1, ref i2);
      }
      if (j1 > j2) {
        Swap(ref j1, ref j2);
      }
      Console.WriteLine("{0} {1} {2} {3}", i1, j1, i2, j2);
    }
  }
  
  void Second() {
    Int32 n = 10, m = 10, q = 100, i, j;
    Console.WriteLine("{0} {1}", n, m);
    for (i = 0; i < n; ++i) {
      for (j = 0; j < m; Console.Write(++j == m ? Environment.NewLine : " ")) {
        Console.Write('1');
      }
    }
    WriteRandomRectangles(q, n, m);
  }
  
  void Third() {
    Int32 n = 10, m = 30, q = 50, i, j;
    Console.WriteLine("{0} {1}", n, m);
    for (i = 0; i < n; ++i) {
      for (j = 0; j < m; Console.Write(++j == m ? Environment.NewLine : " ")) {
        Console.Write(rnd.Next(200) - 99);
      }
    }
    WriteRandomRectangles(q, n, m);
  }
  
  void Fourth() {
    Int32 n = 100, m = 1, q = 666, i, j;
    Console.WriteLine("{0} {1}", n, m);
    for (i = 0; i < n; ++i) {
      for (j = 0; j < m; Console.Write(++j == m ? Environment.NewLine : " ")) {
        Console.Write(rnd.Next((Int32)2e9 + 1) - (Int32)1e9);
      }
    }
    WriteRandomRectangles(q, n, m);
  }
  
  void Sixth() {
    Int32 n = 500, m = 500, q = 100000, i, j;
    Console.WriteLine("{0} {1}", n, m);
    for (i = 0; i < n; ++i) {
      for (j = 0; j < m; Console.Write(++j == m ? Environment.NewLine : " ")) {
        Console.Write('1');
      }
    }
    WriteRandomRectangles(q, n, m);
  }
  
  void Seventh() {
    Int32 n = 500, m = 500, q = 100000, i, j;
    Console.WriteLine("{0} {1}", n, m);
    for (i = 0; i < n; ++i) {
      for (j = 0; j < m; Console.Write(++j == m ? Environment.NewLine : " ")) {
        Console.Write(rnd.Next((Int32)2e9 + 1) - (Int32)1e9);
      }
    }
    while (--q >= 0) {
      Console.WriteLine("1 1 {0} {1}", n, m);
    }
  }
  
  void Eighth() {
    Int32 n = 500, m = 500, q = 100000, i, j;
    Console.WriteLine("{0} {1}", n, m);
    for (i = 0; i < n; ++i) {
      for (j = 0; j < m; Console.Write(++j == m ? Environment.NewLine : " ")) {
        Console.Write(rnd.Next((Int32)2e9 + 1) - (Int32)1e9);
      }
    }
    WriteRandomRectangles(q, n, m);
  }
  
  void Tenth() {
    Int32 n = 500, m = 500, q = 100000, i, j;
    Console.WriteLine("{0} {1}", n, m);
    for (i = 0; i < n; ++i) {
      for (j = 0; j < m; Console.Write(++j == m ? Environment.NewLine : " ")) {
        Console.Write(-(Int32)1e9);
      }
    }
    WriteRandomRectangles(q - 1, n, m);
    Console.WriteLine("1 1 {0} {1}", n, m);
  }

  public Fffuuuu() {
  }

  public static void Main() {
    Fffuuuu root = new Fffuuuu();
    Console.Out.Flush();
  }

}
