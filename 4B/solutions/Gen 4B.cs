using System;
using System.IO;
using System.Collections.Generic;

public class Program {

  static Random rnd = new Random();

  Int32[] GenerateSequence(Int32 n) {
    SortedSet<Int32> s = new SortedSet<Int32>();
    while (s.Count < n) {
      s.Add(rnd.Next((Int32)2e9) - (Int32)1e9);
    }
    Int32[] result = new Int32[n];
    s.CopyTo(result);
    return result;
  }

  void Print(Int32[] seq) {
    for (Int32 i = 0; i < seq.Length; Console.Write(++i == seq.Length ? Environment.NewLine : " ")) {
      Console.Write(seq[i]);
    }
  }

  void Second() {
    Int32 n = 100, q = 100;
    Console.WriteLine("{0} {1}", n, q);
    Print(GenerateSequence(n));
    Print(GenerateSequence(q));
  }

  void Nineth() {
    Int32 n = 100000, q = 100000;
    Console.WriteLine("{0} {1}", n, q);
    Print(GenerateSequence(n));
    Print(GenerateSequence(q));
  }

  public Program() {
  }

  public static void Main() {
    var root = new Program();
    Console.Out.Flush();
  }

}
