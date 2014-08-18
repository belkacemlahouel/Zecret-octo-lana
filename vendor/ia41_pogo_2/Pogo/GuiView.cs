using System;

public class GuiView : PogoView {
	private PogoController controller;

	public GuiView() : base() {
		controller = new PogoController();
	}

	// And we add every method using buttons etc.
}
