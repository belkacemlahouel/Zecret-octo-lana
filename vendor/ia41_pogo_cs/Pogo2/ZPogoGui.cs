using System;

public class ZPogoGui {
    private ZPogoModel model;

    public ZPogoGui(ZPogoModel _model) {
        model = _model;
    }

    public virtual void update() {
        Console.WriteLine("#MOVES: " + (model.Moves));

        if (model.LastPlayerColor == PawnColor.BLACK || model.LastPlayerColor == PawnColor.NULL) {
            Console.Write("WHITE");
        } else {
            Console.Write("BLACK");
        }

        Console.WriteLine("'s TURN");

        Console.WriteLine("Last MOVE: (" + model.LastPlayerColor + ") " + model.LastMove);

        Console.WriteLine(model.Board);
    }
}
