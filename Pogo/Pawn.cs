using System;

public class Pawn {
	private PawnValue value;

	public PawnValue Value {
		get {return value;}
	}

	public Pawn(PawnValue _value) {
		value = _value;
	}
}

public enum PawnValue {
	WHITE = 0,
	BLACK = 1
}
