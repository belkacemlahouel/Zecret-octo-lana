using System;

public class PogoModel {
	private Board board;
	private Player whitePlayer;
	private Player blackPlayer;
	private PawnColor turn;

	public Board Board {
		get {return board;}
	}

	public Player WhitePlayer {
		get {return whitePlayer;}
	}

	public Player BlackPlayer {
		get {return blackPlayer;}
	}

	public PawnColor Turn {
		get {return turn;}
	}

	public PogoModel() {
		board = new Board();

		// Creation of both players: default is two "HumanPlayer"
		whitePlayer = new HumanPlayer(PawnColor.WHITE);
		blackPlayer = new HumanPlayer(PawnColor.BLACK);

		turn = PawnColor.WHITE;

		run();
	}

	public PogoModel(bool whitePlayerHuman, bool blackPlayerHuman) {
		board = new Board();

		if (whitePlayerHuman)
			whitePlayer = new HumanPlayer(PawnColor.WHITE);
		// else: creation of an artifical player

		if (blackPlayerHuman)
			blackPlayer = new HumanPlayer(PawnColor.BLACK);
		// else: creation of an artificial player

		turn = PawnColor.WHITE;

		run();
	}

	private PawnColor winner() {
		PawnColor tmp = PawnColor.EMPTY;

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (tmp != PawnColor.EMPTY && tmp != board.Cases[i, j].controller()) {
						return PawnColor.EMPTY;
				} else {
					tmp = board.Cases[i, j].controller();
				}
			}
		}

		return tmp;
	}

	// Moving i-th first Pawns from Case d to Case a.
	private void move(Case d, int i, Case a) {

	}

	private void run() {

	}
}
