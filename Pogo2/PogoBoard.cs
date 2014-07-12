using System;
using System.Collections.Generic;

public class Case {
    private Stack<Pawn> pawns;

    public Stack<Pawn> Pawns {
        get { return pawns; }
    }

    public Case() {
        pawns = new Stack<Pawn>();
    }

    public bool Push(Pawn p) {
        if (p.Color != PawnColor.NULL && !pawns.Contains(p)) {
            pawns.Push(p);
            return true;
        }

        return false;
    }

    public void Push(Queue<Pawn> qp) {
        while (qp.Count > 0) {
            Push(qp.Dequeue());
        }
    }

    // Printing all Pawns in this Case, stack order style (TOP -> BOT)
    public override string ToString() {
        string rep = ""; // = "Case containing:";

        foreach (Pawn p in pawns) {
            rep += p;
        }

        for (int i = pawns.Count; i < 12; ++i) {
            rep += " ";
        }

        rep += " |";

        return rep;
    }
}

public class PogoBoard {
    private Case[,] board;

    public Case[,] Board {
        get { return board; }
    }

    public PogoBoard() {
        board = new Case[3, 3];

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i, j] = new Case();
            }
        }

        for (int i = 0; i < 3; ++i) {
            board[0, i].Push(new Pawn(PawnColor.BLACK));
            board[0, i].Push(new Pawn(PawnColor.BLACK));

            board[2, i].Push(new Pawn(PawnColor.WHITE));
            board[2, i].Push(new Pawn(PawnColor.WHITE));
        }
    }

    public void move() {

    }

    public override string ToString() {
        string rep = "------------------------------------------\n";

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                rep += board[i, j] + " ";
            }
            rep += "\n";
        }

        rep += "------------------------------------------\n";

        return rep;
    }
}

