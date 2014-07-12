using System;

public class ZApplication {
    public static void Main(string[] args) {
        Console.WriteLine("Hello World!");

        Pawn pawnN = new Pawn(PawnColor.NULL);
        Pawn pawnW = new Pawn(PawnColor.WHITE);
        Pawn pawnB = new Pawn(PawnColor.BLACK);

        Console.WriteLine(pawnN.ToString());
        Console.WriteLine(pawnW.ToString());
        Console.WriteLine(pawnB.ToString());

        Console.WriteLine("bye World!");
    }
}

