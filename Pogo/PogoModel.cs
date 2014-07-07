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

	private void run() {

	}
}
