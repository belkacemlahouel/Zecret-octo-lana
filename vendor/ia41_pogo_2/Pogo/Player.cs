using System;

public abstract class Player {
	private PawnColor color;

	public PawnColor Color {
		get {return color;}
	}

	public Player(PawnColor _color) {
		color = _color;
	}

	public abstract void play();
}
