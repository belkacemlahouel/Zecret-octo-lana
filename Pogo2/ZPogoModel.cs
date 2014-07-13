using System;

public class ZPogoModel {
    private PogoBoard board;
    private PogoPlayer white;
    private PogoPlayer black;

    public PogoBoard Board {
        get { return board; }
    }

    public PogoPlayer White {
        get { return white; }
    }

    public PogoPlayer Black {
        get { return black; }
    }

    public ZPogoModel() {
        board = new PogoBoard();
        white = new PogoPlayer();
        black = new PogoPlayer();
    }

    public void run() {

    }
}
