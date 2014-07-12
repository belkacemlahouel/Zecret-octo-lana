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

    public void Push(Stack<Pawn> qp) {
        while (qp.Count > 0) {
            Push(qp.Pop());
        }
    }

    public Stack<Pawn> Pop(int i) {
        Stack<Pawn> rep = new Stack<Pawn>();
//        int borne = Math.Min(i, pawns.Count);
        int borne = i;

        for (int j = 0; j < borne; ++j) {
            rep.Push(pawns.Pop());
        }

        return rep;
    }

    // Printing all Pawns in this Case, stack order style (TOP -> BOT)
    public override string ToString() {
        string rep = "";

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

    public void move(Case c1, int i, Case c2) {
        c2.Push(c1.Pop(i));
    }

    // Parameters i1 and i2: number of the cases
    // 1 2 3 | 0,0  0,1  0,2
    // 4 5 6 | 1,0  1,1  1,2
    // 7 8 9 | 2,0  2,1  2,2
    public void move(int i1, int i, int i2) {
        move(board[(i1-1)/3, (i1-1)%3], i, board[(i2-1)/3, (i2-1)%3]);
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

