using System;

// Default Controller is a Console Controller.
public class ZPogoController {
    private int start;
    private int index;
    private int end;

    public ZPogoController() {

    }

    public virtual Move nextMove() {
        Console.WriteLine(" -------\n| 1 2 3 |\n| 4 5 6 |\n| 7 8 9 |\n -------");

        Console.WriteLine("Enter starting case number: ");
        int s = readInt();

        Console.WriteLine("Enter pawn number to move: ");
        int i = readInt();

        Console.WriteLine("Enter ending case number: ");
        int e = readInt();

        return new Move(s, i, e);
    }

    private int readInt() {
        int rep;

        string tmp = Console.ReadLine();
        while (int.TryParse(tmp, out rep)) {
            Console.WriteLine("Try again, we need an integer!");
            tmp = Console.ReadLine();
        }

        return rep;
    }
}
