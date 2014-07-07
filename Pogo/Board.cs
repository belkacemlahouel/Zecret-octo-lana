using System;

public class Board {
	private Case[,] cases;

	public Case[,] Cases {
		get {return cases;}
	}

	public Board() {
		cases = new Case[3, 3];

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				cases[i, j] = new Case();
			}
		}

		for (int i = 0; i < 3; ++i) {
			cases[0, i].Push(new Pawn(PawnColor.BLACK));
			cases[0, i].Push(new Pawn(PawnColor.BLACK));

			cases[2, i].Push(new Pawn(PawnColor.WHITE));
			cases[2, i].Push(new Pawn(PawnColor.WHITE));
		}
	}
}
