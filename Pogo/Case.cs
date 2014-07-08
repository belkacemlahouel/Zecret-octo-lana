using System;
using System.Collections.Generic;

public class Case {
	private Stack<Pawn> pawns;

	public Stack<Pawn> Pawns {
		get {return pawns;}
	}

	public Case() {
		pawns = new Stack<Pawn>();
	}

	public void Push(Pawn p) {
		pawns.Push(p);
	}

	public PawnColor controller() {
		if (pawns.Count == 0)
			return PawnColor.EMPTY;

		return pawns.Peek().Color;
	}

	// Returns and removes all pawns until the i-th pawn.
	// We use stack order style.
	public Queue<Pawn> remove(int i) {
		Queue<Pawn> rep = new Queue<Pawn>();

		if (i < pawns.Count && i > 0) {
			for (int j = 0; j < i; ++j) {
				rep.Enqueue(pawns.Pop());
			}
		}
	}
}
