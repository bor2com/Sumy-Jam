using System;
using System.IO;

public class Program {

  static Random rnd = new Random();

  struct Line {
    public Int32 x1, y1, x2, y2;
    public Line(Int32 x1, Int32 y1, Int32 x2, Int32 y2) {
      this.x1 = x1;
      this.y1 = y1;
      this.x2 = x2;
      this.y2 = y2;
    }
    public static Int32 RandomCoordinate {
      get {
        return rnd.Next(201) - 100;
      }
    }
    public static Line RandomLine {
      get {
        Int32 x1, y1, x2, y2;
        do {
          x1 = RandomCoordinate;
          y1 = RandomCoordinate;
          x2 = RandomCoordinate;
          y2 = RandomCoordinate;
        } while (x1 == x2 && y1 == y2);
        return new Line(x1, y1, x2, y2);
      }
    }
    public override string ToString() {
      return String.Format("{0} {1} {2} {3}", x1, y1, x2, y2);
    }
  }

  void WriteRandomLines(Int32 count) {
    Console.WriteLine(count);
    while (--count >= 0) {
      Console.WriteLine(Line.RandomLine);
    }
  }

  void Fifth() {
    WriteRandomLines(500);
  }

  void Sixth() {
    WriteRandomLines(2000);
  }

  void Seventh() {
    Int32 n = 100000;
    Line line = new Line(-100, 0, 100, 0);
    Console.WriteLine(n);
    while (--n >= 0) {
      Console.WriteLine(line);
    }
  }

  void Eighth() {
    Int32 n = 100000;
    Line line = new Line(0, -100, 0, 100);
    Console.WriteLine(n);
    while (--n >= 0) {
      Console.WriteLine(line);
    }
  }

  void Nineth() {
    WriteRandomLines(100000);
  }

  public Program() {
  }

  public static void Main() {
    var root = new Program();
    Console.Out.Flush();
  }

}
