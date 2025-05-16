package simulacija;

import java.util.LinkedList;

public class SkupFigura {
	
	private Figura tekuca = null;
	
	LinkedList<Figura> figure = new LinkedList<>();
	
	public void dodaj(Figura f) throws GreskaVecPostoji {
		if(figure.contains(f)) throw new GreskaVecPostoji();
		figure.add(f);
	}
	
	public void postaviPrvuZaTekucu() {
		if(figure.isEmpty()) {
			tekuca = null;
			return;
		}
		tekuca = figure.getFirst();
	}
	
	public void sledeca() throws GreskaNemaSledece {
		if(tekuca == null) return;
		int i = figure.indexOf(tekuca) + 1;
		if(figure.isEmpty() || (i == figure.size())) {
			tekuca = null;
			throw new GreskaNemaSledece();
		}
		tekuca = figure.get(i);
	}
	
	public Figura tekuca() {
		return tekuca;
	}
	
	public boolean postojiSledeca() {
		if(tekuca == null) return false;
		if(figure.isEmpty() || ((figure.indexOf(tekuca) + 1) == figure.size())) return false;
		return true;
	}
	
	public void isprazni() {
		figure.clear();
		tekuca = null;
	}
	
	public boolean postoji(Figura f) {
		if(figure.contains(f)) return true;
		return false;
	}
	
	public void izbaci(Figura f) {
		/*if(tekuca == f) {
			if(postojiSledeca()) {
				try {
					sledeca();
				} catch (GreskaNemaSledece e) {}
			}else{
				tekuca = null;
			}
		}*/
		figure.remove(f);
	}
	
	public int brojFigura() {
		return figure.size();
	}
}
