using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Beep(10000,1000);
            Console.WriteLine("{0}+{1}={2} نمره شما:",10,10,10+10);
            Console.BackgroundColor = ConsoleColor.DarkMagenta;
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("┌──┬──┬──┬──┬──┬──┬──┬──┬──┬───┬─┐");
            Console.WriteLine("│*1│*2│*3│*4│*5│*6│*7│*8│*9│*10│A│");
            Console.WriteLine("├──┼──┼──┼──┼──┼──┼──┼──┼──┼───┼─┤");
            Console.WriteLine("│ 1│ 2│ 3│ 4│ 5│ 6│ 7│ 8│ 9│ 10│A│");
            Console.WriteLine("├──┼──┼──┼──┼──┼──┼──┼──┼──┼───┼─┤");
            Console.WriteLine("│ 2│ 4│ 6│ 8│10│12│14│16│18│ 20│R│");
            Console.WriteLine("├──┼──┼──┼──┼──┼──┼──┼──┼──┼───┼─┤");
            Console.WriteLine("│ 3│ 6│ 9│12│15│18│21│24│27│ 30│A│");
            Console.WriteLine("├──┼──┼──┼──┼──┼──┼──┼──┼──┼───┼─┤");
            Console.WriteLine("│ 4│ 8│12│16│20│24│28│32│36│ 40│B│");
            Console.WriteLine("├──┼──┼──┼──┼──┼──┼──┼──┼──┼───┼─┤");
            Console.WriteLine("│ 5│10│15│20│25│30│35│40│45│ 50│I│");
            Console.WriteLine("├──┼──┼──┼──┼──┼──┼──┼──┼──┼───┼─┤");
            Console.WriteLine("│ 6│12│18│24│30│36│42│48│54│ 60│.│");
            Console.WriteLine("├──┼──┼──┼──┼──┼──┼──┼──┼──┼───┼─┤");
            Console.WriteLine("│ 7│14│21│28│35│42│49│56│63│ 70│A│");
            Console.WriteLine("├──┼──┼──┼──┼──┼──┼──┼──┼──┼───┼─┤");
            Console.WriteLine("│ 8│16│24│32│40│48│56│64│72│ 80│C│");
            Console.WriteLine("├──┼──┼──┼──┼──┼──┼──┼──┼──┼───┼─┤");
            Console.WriteLine("│ 9│18│27│36│45│54│63│72│81│ 90│H│");
            Console.WriteLine("├──┼──┼──┼──┼──┼──┼──┼──┼──┼───┼─┤");
            Console.WriteLine("│10│20│30│40│50│60│70│80│90│100│.│");
            Console.WriteLine("└──┴──┴──┴──┴──┴──┴──┴──┴──┴───┴─┘");
            

           
                                          

            
            Console.ReadKey();
        }
    }
}
