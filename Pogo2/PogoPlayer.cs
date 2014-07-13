using System;

// Default: HumanPlayer
// Future AiPlayer inheritates from PogoPlayer and overrides play() among others.
public class PogoPlayer {

    public virtual Move play() {
        Move mov = new Move(0, 0, 0);
        return mov;
    }
}
