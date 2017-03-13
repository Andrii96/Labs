using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ЛР4
{
    class Program
    {
        static void Main(string[] args)
        {
            const int N = 80000;
	        int[]mas = new int[N];
            int[]sum = new int[N];

            Random rand = new Random();

            for (int i = 0; i < N; i++)
                mas[i] = rand.Next(1000);

	        sum[0] = mas[0];

            //1 thread
            Stopwatch watch = new Stopwatch();
            watch.Start();
	        for (int i = 1; i < N; i++) {
                for (int j = 1; j < i; j++)
                    sum[j] = sum[j - 1] + mas[i];
	        }

            watch.Stop();
            Console.WriteLine("Execution time in one thread:{0}",watch.ElapsedMilliseconds);

	        //parallel for
            Stopwatch watch1 = new Stopwatch();
            watch1.Start();
            Parallel.For(0, N, i =>
            {
                for (int j = 1; j < i; j++)
                    sum[j] = sum[j - 1] + mas[i];
            });
            watch1.Stop();
            Console.WriteLine("Parallel execution time :{0}", watch1.ElapsedMilliseconds);
            Console.ReadLine();
        }

        
    }
}
