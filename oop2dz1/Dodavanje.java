package masina;

public class Dodavanje extends Operacija {
	private int broj;
	
	public Dodavanje(int br) {
		broj = br;
	}
	public void izvrsi(Stek stek) {
		stek.dodaj(broj);
	}
}
