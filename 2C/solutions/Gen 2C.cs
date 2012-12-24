using System;
using System.IO;
using System.Collections.Generic;

public class MapGenerator {

    #region Settings

    const String testFolder = @"C:\Users\anonymous\Ordnance\Plus\tests\";
    const Int32 testNumber = 10;
    const Int32 N = 1000, M = 1000;
    const Double part = 0.4;

    #endregion

    static Random rnd = new Random();

    static Int32[,] shift = new Int32[4, 2] { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };

    Int32 ShortestDistance(Char[,] map) {
        Int32 i, j, sh, shi, shj, n = map.GetLength(0), m = map.GetLength(1);
        Int32[,] dist = new Int32[n, m];
        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                dist[i, j] = -1;
            }
        }
        dist[0, 0] = 0;
        Queue<Int32> qu = new Queue<Int32>();
        qu.Enqueue(0);
        qu.Enqueue(0);
        while (qu.Count != 0) {
            i = qu.Dequeue();
            j = qu.Dequeue();
            if (map[i, j] == 'x') {
                return dist[i, j];
            }
            for (sh = 0; sh < 4; ++sh) {
                shi = i + shift[sh, 0];
                shj = j + shift[sh, 1];
                if (shi >= 0 && shj >= 0 && shi < n && shj < m && map[shi, shj] != '#' && dist[shi, shj] < 0) {
                    dist[shi, shj] = dist[i, j] + 1;
                    qu.Enqueue(shi);
                    qu.Enqueue(shj);
                }
            }
        }
        return -1;
    }

    public MapGenerator() {
        Int32 i, j, s;
        Char[,] map = new Char[N, M];
        do {
            for (i = 0; i < N; ++i) {
                for (j = 0; j < M; ++j) {
                    map[i, j] = '.';
                }
            }
            Int32 all = N * M, put = (Int32)(part * all);
            map[0, 0] = '#';
            while (--put >= 0) {
                do {
                    i = rnd.Next(N);
                    j = rnd.Next(M);
                } while (map[i, j] == '#');
                map[i, j] = put == 0 ? 'x' : '#';
            }
            map[0, 0] = '.';
            s = ShortestDistance(map);
        } while (s < 0);
        String testName = testNumber.ToString("000");
        using (var input = new StreamWriter(testFolder + testName + ".dat")) {
            input.WriteLine("{0} {1}", N, M);
            for (i = 0; i < N; ++i) {
                for (j = 0; j < M; ++j) {
                    input.Write(' ');
                    input.Write(map[i, j]);
                    input.Write(' ');
                }
                input.WriteLine();
            }
        }
        using (var ans = new StreamWriter(testFolder + testName + ".ans")) {
            ans.WriteLine(s);
        }
    }

    public static void Main() {
        var root = new MapGenerator();
    }

}
