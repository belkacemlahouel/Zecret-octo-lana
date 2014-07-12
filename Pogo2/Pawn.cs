using System;

public class Pawn {
    private PawnColor color;

    public PawnColor Color {
        get { return color; }
    }

    public Pawn(PawnColor _color) {
        color = _color;
    }

    public override string ToString() {
        if (color == PawnColor.NULL) return "NULL Pawn";
        else if (color == PawnColor.WHITE) return "WHITE Pawn";
        else return "BLACK Pawn";
    }
}

public enum PawnColor {
    NULL = -1,
    WHITE,
    BLACK
}

