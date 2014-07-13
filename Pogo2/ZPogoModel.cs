using System;

public class ZPogoModel {
    private PogoBoard board;
    private PogoPlayer white;
    private PogoPlayer black;
    private ZPogoGui gui;
    private PawnColor lastPlayerColor;
    private int moves;
    private Move lastMove;

    public PogoBoard Board {
        get { return board; }
    }

    public PogoPlayer White {
        get { return white; }
    }

    public PogoPlayer Black {
        get { return black; }
    }

    public int Moves {
        get { return moves; }
    }

    public PawnColor LastPlayerColor {
        get { return lastPlayerColor; }
    }

    public Move LastMove {
        get { return lastMove; }
    }

    public ZPogoModel() {
        board = new PogoBoard();
        white = new PogoPlayer();
        black = new PogoPlayer();
        moves = 0;
        lastPlayerColor = PawnColor.NULL;

        gui = new ZPogoGui(this);
    }

    private PawnColor winner() {
        PawnColor rep = PawnColor.NULL;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (rep == PawnColor.NULL) {
                    rep = board.Board[i, j].Color;
                } else if (rep != board.Board[i, j].Color) {
                    return PawnColor.NULL;
                }
            }
        }

        return rep;
    }

    public void run() {
        Move tmp;

        while (winner() == PawnColor.NULL) {
            tmp = white.play();
            board.move(tmp);
            gui.update();
            lastPlayerColor = PawnColor.WHITE;
            lastMove = tmp;
            ++moves;

            if (winner() != PawnColor.NULL)
                break;

            tmp = black.play();
            board.move(tmp);
            gui.update();
            lastPlayerColor = PawnColor.BLACK;
            lastMove = tmp;
            ++moves;

            Console.WriteLine("SHIT");
            break;
        }
    }
}
