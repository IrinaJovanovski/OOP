package racunari;

public class ProstDeo extends RacunarskiDeo implements Cloneable{

	public ProstDeo(String naziv, double masa, double ocena) throws GPogresnaSpecifikacija {
		super(naziv);
		if(masa <= 0) throw new GPogresnaSpecifikacija();
		this.masa = masa;
		if(ocena < 1 || ocena > 5) throw new GPogresnaSpecifikacija();
		this.ocena = ocena;
	}

	@Override
	public ProstDeo clone() throws CloneNotSupportedException {
		ProstDeo deo = (ProstDeo) super.clone();
		return deo;
	}

}
