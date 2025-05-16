package racunari;

import java.util.ArrayList;

public class SlozenDeo extends RacunarskiDeo implements Cloneable{
	
	private ArrayList<ProstDeo> delovi;

	
	public SlozenDeo(String naziv) {
		super(naziv);
		delovi = new ArrayList<ProstDeo>();
		masa = 0;
		ocena = 0;
	}

	public int brojProstihDelova() {
		return delovi.size();
	}

	public void dodaj(ProstDeo pdeo) throws CloneNotSupportedException {
		if(!delovi.add(pdeo.clone())) return;
		masa += pdeo.dohvatiMasu();
		ocena = (ocena*(delovi.size()-1) + pdeo.dohvatiOcenuKvaliteta())/delovi.size();
	}
	
	public boolean ukloni(ProstDeo pdeo) {
		if(delovi.remove(pdeo)) {
			masa -= pdeo.dohvatiMasu();
			if(delovi.isEmpty()) { ocena = 0; return true;} 
			ocena = (ocena*(delovi.size()+1) - pdeo.dohvatiOcenuKvaliteta())/delovi.size();
			return true;
		}
		return false;
	}

	public boolean sadrzi(ProstDeo pdeo) {
		return delovi.contains(pdeo);
	}
	
	public ProstDeo dohvati(int indeks) throws GPozicijaVanOpsega {
		if(indeks >= delovi.size() || indeks < 0) throw new GPozicijaVanOpsega();
		return delovi.get(indeks);
	}
	
	
	
	@Override
	public SlozenDeo clone() throws CloneNotSupportedException {
		SlozenDeo deo = (SlozenDeo)super.clone();
		deo.delovi = new ArrayList<ProstDeo>();
		for(ProstDeo pd : delovi) {
			ProstDeo p = pd.clone();
			deo.delovi.add(p);
		}
		return deo;
		//deo.delovi = (ArrayList<ProstDeo>)delovi.clone();
	}
	
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append(super.toString());
		for(ProstDeo pd : delovi) {
			sb.append("\n\t").append(pd);
		}
		return sb.toString();
	}

}
