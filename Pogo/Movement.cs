using System;

public class Movement {
	private int dep;
	private int i;
	private int arr;

	public Movement(int _dep, int _i, int _arr) {
		dep = _dep;
		i = _i;
		arr = _arr;
	}

	public int Dep {
		get {return dep;}
	}

	public int I {
		get {return i;}
	}

	public int Arr {
		get {return arr;}
	}
}