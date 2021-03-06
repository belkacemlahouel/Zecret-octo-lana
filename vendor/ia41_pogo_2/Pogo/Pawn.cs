using System;

public class Pawn {
	private PawnColor color;

	public PawnColor Color {
		get {return color;}
	}

	public Pawn(PawnColor _color) {
		color = _color;
	}
}

public enum PawnColor {
	EMPTY = -1,
	WHITE = 0,
	BLACK = 1,
}
