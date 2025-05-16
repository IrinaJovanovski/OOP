package kafic;

import java.util.ArrayList;

public class KartaPica {
	private ArrayList<Pice> pica;
	
	public KartaPica() {
		pica = new ArrayList<Pice>();
	}
	
	public void dodajPice(Pice pice) throws GPostoji {
		if(pica.contains(pice)) throw new GPostoji();
		pica.add(pice);
	}
	
	public int getBrojPica() {
		return pica.size();
	}
	
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append("GAZIRANI SOKOVI\n");
		for(Pice p : pica) {
			if(p.getOznaka() == 'G') sb.append(p);
		}
		sb.append("NEGAZIRANI SOKOVI\n");
		for(Pice p : pica) {
			if(p.getOznaka() == 'N') sb.append(p);
		}
		return sb.toString();
	}
}
