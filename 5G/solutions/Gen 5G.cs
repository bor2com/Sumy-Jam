using System;

public class Program {

  static Random rnd = new Random();

  void Third() {
    Int32 n = 100, k = rnd.Next(100) + 1, i;
    Console.Write("{0} {1}", n, k);
    for (i = 0; i < n; ++i) {
      Console.Write(" {0} {1}", rnd.Next(100) + 1, rnd.Next(100) + 1);
    }
  }

  void Fourth() {
    Int32 n = 1000, k = rnd.Next(1000) + 1, i;
    Console.Write("{0} {1}", n, k);
    for (i = 0; i < n; ++i) {
      Console.Write(" {0} {1}", rnd.Next(1000) + 1, rnd.Next(1000) + 1);
    }
  }

  void Sixth() {
    Int32 n = 10000, k = 1, i;
    Console.Write("{0} {1}", n, k);
    for (i = 0; i < n; ++i) {
      Console.Write(" 2 {0}", i + 1);
    }
  }

  void Seventh() {
    Int32 n = rnd.Next(100000) + 1, k = 10, i;
    Console.Write("{0} {1}", n, k);
    for (i = 0; i < n; ++i) {
      Console.Write(" {1} {0}", rnd.Next(4) + 1, n - i);
    }
  }

  void Nineth() {
    Int32 n = 150000, k = rnd.Next(100) + 1, i;
    Console.Write("{0} {1}", n, k);
    for (i = 0; i < n; ++i) {
      Console.Write(" {1} {0}", 1, rnd.Next(1000) + 1);
    }
  }

  public Program() {
  }

  public static void Main() {
    var root = new Program();
    Console.Out.Flush();
  }

}
