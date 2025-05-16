package masina;

public class Stek {
	private int[] niz;
	private int sp;
	
	public Stek(int velicina) {
		niz = new int[velicina];
		sp = 0;
	}
	public void dodaj(int broj) {
		if (sp == niz.length) return;
		niz[sp++] = broj;
	}
	public int ukloni() {
		if(sp == 0) return -1000;
		return niz[--sp];
	}
	public String toString() {
		String s = "[";
		for (int i = 0; i < sp; i++) {
			if(i != 0) s += ",";
			s += niz[i];
		}
		s += "]";
		return s;
	}
}
