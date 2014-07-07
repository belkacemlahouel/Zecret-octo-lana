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
}
