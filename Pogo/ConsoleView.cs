using System;

public class ConsoleView : PogoView {
	public ConsoleView() : base() {

	}

	// Printing every information about the current game
	public override void update() {
		Console.Write("Turn: ");
		printTurn(model.Turn);
		Console.WriteLine();

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				printCase(model.Board.Cases[i, j]);
			}
		}
	}

	private void printTurn(PawnColor color) {
		if (color == PawnColor.BLACK) {
			Console.Write("BLACK");
		} else if (color == PawnColor.WHITE) {
			Console.Write("WHITE");
		}
	}

	private void printCase(Case c) {
		int tmp = 0;

		foreach (Pawn p in c.Pawns) { // Need to check the ordre of printing
			printPawn(p);
			++tmp;
		}

		while (tmp < 13) { // Maximum number of pawns in the same case: 12
			Console.Write(" ");
			++tmp;
		}
	}

	private void printPawn(Pawn p) {
		if (p.Color == PawnColor.BLACK) {
			Console.Write("B");
		} else if (p.Color == PawnColor.WHITE) {
			Console.Write("W");
		}
	}
}

