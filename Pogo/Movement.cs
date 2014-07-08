using System;

public class Movement {
	private Case dep;
	private int i;
	private Case arr;

	public Movement(Case _dep, int _i, Case _arr) {
		dep = _dep;
		i = _i;
		arr = _arr;
	}

	public Case Dep {
		get {return dep;}
	}

	public int I {
		get {return i;}
	}

	public Case Arr {
		get {return arr;}
	}
}