using System;

public abstract class PogoView {
	protected PogoModel model;

	public PogoView() {
		model = new PogoModel();
	}

	public abstract void update();
}
