package masina;

public class Sabiranje extends Operacija {
	
	public void izvrsi(Stek stek) {
		int a = stek.ukloni();
		int b = stek.ukloni();
		stek.dodaj(a+b);
	}
}
