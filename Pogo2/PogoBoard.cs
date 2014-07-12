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

    // Printing all Pawns in this Case, STACK order
    public override string ToString() {
        string rep = "Case containing:";

        foreach (Pawn p in pawns) {
            rep += " " + p.ToString();
        }

        return rep;
    }
}

public class PogoBoard {
    private Case[,] board;

    public Case[,] Board {
        get { return board; }
    }
}

