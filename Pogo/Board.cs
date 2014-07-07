using System;

public class Board {
	private Case[,] cases;

	public Case[,] Cases {
		get {return cases;}
	}

	public Board() {
		cases = new Case[3, 3];
	}
}
