package racunari;


public abstract class RacunarskiDeo implements Cloneable{
	protected String naziv;
	protected double ocena;
	protected double masa;
	
	public RacunarskiDeo(String naziv) {
		this.naziv = naziv;
	}
	
	public RacunarskiDeo clone() throws CloneNotSupportedException{
		RacunarskiDeo deo = (RacunarskiDeo)super.clone();
		deo.naziv = naziv;
		deo.masa = masa;
		deo.ocena = ocena;
		return deo;
	}

	public double dohvatiOcenuKvaliteta() {
		return ocena;
	}

	public double dohvatiMasu() {
		return masa;
	}
	
	@Override
	public boolean equals(Object deo) {
		if(!(deo instanceof RacunarskiDeo)) return false;
		RacunarskiDeo rdeo = (RacunarskiDeo) deo;
		if(naziv.equals(rdeo.naziv) && (ocena == rdeo.ocena) && (masa == rdeo.masa)) return true;
		return false;
	}

	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append(naziv).append(" (").append(String.format("%.2f", masa)).append("g) ");
		sb.append(String.format("%.1f", ocena));
		return sb.toString();
	}

	
}
