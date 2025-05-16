package kafic;

abstract public class Pice {
	protected String naziv;
	protected float zapremina; // u litrima
	protected int cena; // cena po litru
	protected char oznaka;
	
	public String getNaziv() {
		return naziv;
	}
	
	public float getZapremina() {
		return zapremina;
	}
	
	public float getCena() {
		return cena*zapremina;
	}
	
	public char getOznaka() {
		return oznaka;
	}

	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append(naziv).append(" (").append(String.format("%.2f", zapremina)).append("L) : ");
		sb.append(String.format("%.2f", cena*zapremina)).append(" RSD\n");
		return sb.toString();
		
	}

	@Override
	public boolean equals(Object obj) {
		if(obj instanceof Pice) {
			Pice pice = (Pice) obj;
			if(naziv.equals(pice.naziv) && (zapremina == pice.zapremina)) return true;
		}
		return false;
	}
	
	
	
}
