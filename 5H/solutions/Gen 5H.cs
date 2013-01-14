using System;
using System.IO;
using System.Collections.Generic;

public class Program {

  static Random rnd = new Random();

  void Print(Int32[] seq) {
    Console.Write(seq.Length / 2);
    for (Int32 i = 0; i < seq.Length; ++i) {
      Console.Write(" {0}", seq[i]);
    }
  }

  void Permute(Int32[] seq) {
    Byte[] seed = new Byte[seq.Length];
    rnd.NextBytes(seed);
    Array.Sort(seed, seq);
  }

  void MakeRandom(Int32 n) {
    Int32[] seq = new Int32[n * 2];
    for (Int32 i = 0; i < n; ++i) {
      seq[i] = seq[i + n] = i + 1;
    }
    Permute(seq);
    Print(seq);
  }

  void Ordered(Int32 n) {
    Int32[] seq = new Int32[n * 2];
    for (Int32 i = 0; i < n; ++i) {
      seq[i] = seq[i + n] = i + 1;
    }
    Print(seq);
  }

  // stuff cutline

  void Fourth() {
    Ordered(100);
  }

  void Fifth() {
    MakeRandom(500);
  }

  void Sixth() {
    MakeRandom(100000);
  }

  void Seventh() {
    Ordered(99699);
  }

  void Eighth() {
    Int32 n = rnd.Next(100000) + 1;
    Int32[] seq = new Int32[n * 2];
    for (Int32 i = 0; i < n; ++i) {
      seq[i] = seq[n * 2 - i - 1] = i + 1;
    }
    Print(seq);
  }

  void Nineth() {
    MakeRandom(rnd.Next(100000) + 1);
  }

  public Program() {
  }

  public static void Main() {
    var root = new Program();
    Console.Out.Flush();
  }

}
