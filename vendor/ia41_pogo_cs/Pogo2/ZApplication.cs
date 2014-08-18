using System;

public class ZApplication {
    public static void Main(string[] args) {
        Console.WriteLine("Hello World!");
//
//        Pawn pawnN = new Pawn(PawnColor.NULL);
//        Pawn pawnW = new Pawn(PawnColor.WHITE);
//        Pawn pawnB = new Pawn(PawnColor.BLACK);
//
//        Console.WriteLine(pawnN);
//        Console.WriteLine(pawnW);
//        Console.WriteLine(pawnB);
//
//        Case ca = new Case();
//        Console.WriteLine(ca.Push(pawnN));
//        Console.WriteLine(ca.Push(pawnW));
//        Console.WriteLine(ca.Push(pawnB));
//        Console.WriteLine(ca.Push(pawnB));
//        Console.WriteLine(ca);
//
//        PogoBoard boa = new PogoBoard();
//        Console.WriteLine(boa);
//        boa.move(9, 2, 5);
//        Console.WriteLine(boa);
//        boa.move(1, 2, 5);
//        Console.WriteLine(boa.move(9, 2, 5));
//        Console.WriteLine(boa);
//        boa.move(5, 3, 1);
//        Console.WriteLine(boa);
//        boa.move(2, 1, 1);
//        Console.WriteLine(boa);
//        boa.move(1, 3, 9);
//        Console.WriteLine(boa);
//        boa.move(1, 3, 9);
//        Console.WriteLine(boa);
//
//        Console.WriteLine("---------------------------------");
//        Console.WriteLine("---------------------------------");

        ZPogoModel pogo = new ZPogoModel();
        pogo.run();

        Console.WriteLine("Bye World!");
    }
}

