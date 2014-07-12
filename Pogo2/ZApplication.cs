using System;

public class ZApplication {
    public static void Main(string[] args) {
        Console.WriteLine("Hello World!");

        Pawn pawnN = new Pawn(PawnColor.NULL);
        Pawn pawnW = new Pawn(PawnColor.WHITE);
        Pawn pawnB = new Pawn(PawnColor.BLACK);

        Console.WriteLine(pawnN);
        Console.WriteLine(pawnW);
        Console.WriteLine(pawnB);

        Case ca = new Case();
        Console.WriteLine(ca.Push(pawnN));
        Console.WriteLine(ca.Push(pawnW));
        Console.WriteLine(ca.Push(pawnB));
        Console.WriteLine(ca.Push(pawnB));
        Console.WriteLine(ca);

        Console.WriteLine("bye World!");
    }
}

