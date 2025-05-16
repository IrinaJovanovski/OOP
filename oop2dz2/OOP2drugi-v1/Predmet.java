package fakultet;

import java.util.ArrayList;


public class Predmet implements Uporediv {
	
	private String naziv;
	private ArrayList<Student> studenti;
	
	
	public Predmet(String naziv) {
		this.naziv = naziv;
		studenti = new ArrayList<Student>();
	}
	
	public int brojPrijavljenih() {
		return studenti.size();
	}
	
	public String dohvatiNaziv() {
		return naziv;
	}

	public void prijavi(Student s) throws GStudentVecPostoji {
		if( studenti.contains(s)) throw new GStudentVecPostoji();
		studenti.add(s);
	}
	
	public boolean odjavi(Student s) {
		return studenti.remove(s);
	}

	public boolean prati(Student s) {
		return studenti.contains(s);
	}
	
	@Override
	public int uporedi(Uporediv u) throws GRazlicitiTipovi {
		if(u instanceof Predmet) {
			return naziv.compareTo(((Predmet)u).naziv);
		}else {
			throw new GRazlicitiTipovi();
		}
	}
	
	public void sortirajStudente() {
		if(studenti.isEmpty()) return;
		studenti.sort(((s1,s2) -> {
			try {
				return s1.uporedi(s2);
			} catch (GRazlicitiTipovi e) { return 0;}
		}));
	}
	
	public String toString(){ 
		StringBuilder sb = new StringBuilder();
		sb.append(naziv);
		sortirajStudente();
		for(Student s:studenti) {
			sb.append("\n").append(s);
		}
		return sb.toString();
	}

}
