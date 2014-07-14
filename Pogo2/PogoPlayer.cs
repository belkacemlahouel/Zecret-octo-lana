using System;
using System.Collections.Generic;

// Default Player is a HumanPlayer.
// Future AiPlayer inheritates from PogoPlayer and overrides play() among others.
public class PogoPlayer {
    private ZPogoModel model;

    public ZPogoModel Model {
        get { return model; }
    }

    public PogoPlayer(ZPogoModel _model) {
        model = _model;
    }

    // Minimax implementation.
    protected virtual List<Move> possibilities(PogoBoard board, PawnColor turn) {
        return null;
    }

    // Evaluation function for Minimax implementation.
    protected virtual double evaluation(PogoBoard PogoBoard, PawnColor turn) {
        return 0;
    }

    // Public interface towards Model.
    public virtual Move play() {
        return model.getNextMove();
//        return null;
    }
}
