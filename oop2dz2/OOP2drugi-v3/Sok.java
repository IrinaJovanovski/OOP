package kafic;

public class Sok extends Pice {
	public enum Vrsta {GAZIRAN, NEGAZIRAN}
	private Vrsta vrsta;
	
	
	public Sok(String naziv,float zapremina, int cena, Vrsta vrsta) {
		this.naziv = naziv;
		this.zapremina = zapremina;
		this.cena = cena;
		this.vrsta = vrsta;
		switch(vrsta) {
			case GAZIRAN:
				this.oznaka = 'G';
				break;
			case NEGAZIRAN:
				this.oznaka = 'N';
				break;
		}
	}
	
	public Vrsta getVrsta() {
		return vrsta;
	}
	
}
