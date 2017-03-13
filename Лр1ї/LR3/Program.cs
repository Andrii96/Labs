using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LR3
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] array1 = new int[10000];
            int[] array2 = new int[10000];

            Console.WriteLine("Input number of elements\n");
            int number = int.Parse(Console.ReadLine());
            Random rand = new Random();
            for (int i = 0; i < number; i++)
            {
                array1[i] = rand.Next(100);
                array2[i] = array1[i];
            }

            Stopwatch watch = new Stopwatch();
            watch.Start();

            SelectionSort(array1,number);

            watch.Stop();
            Console.WriteLine(string.Format("Execution time in one thread:{0}",watch.ElapsedMilliseconds));


            Stopwatch watch1 = new Stopwatch();
            watch1.Start();

            SelectionSortParallel(array2,number);

            watch1.Stop();
            Console.WriteLine(string.Format("Execution time in two thread:{0}", watch1.ElapsedMilliseconds));

            Console.ReadLine();

        }

        public static void SelectionSortParallel(int[] array,int number)
        {
            Parallel.For(0, number - 1, i =>
            {
                int min = i;
                for (int j = i + 1; j < number; j++)
                {
                    if (array[j] < array[min])
                    {
                        min = j;
                    }
                }

                var tmp = array[i];
                array[i] = array[min];
                array[min] = tmp;
            });                           
        }

        public static void SelectionSort(int[] array, int number)
        {
            for (int i = 0; i < number - 1; i++)
            {
                int min = i;
                for (int j = i + 1; j < number; j++)
                {
                    if (array[j] < array[min])
                    {
                        min = j;
                    }
                }

                var tmp = array[i];
                array[i] = array[min];
                array[min] = tmp;
            }          

        }
    }
}
