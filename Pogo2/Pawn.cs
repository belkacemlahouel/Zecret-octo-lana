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
        if (color == PawnColor.NULL) return "N";
        else if (color == PawnColor.WHITE) return "W";
        else return "B";
    }
}

public enum PawnColor {
    NULL = -1,
    WHITE,
    BLACK
}

