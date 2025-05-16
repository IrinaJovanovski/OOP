package fakultet;


public class Student implements Uporediv {
	private String ime;
	private int godinaUpisa;
	private int brojIndeksa;
	
	
	
	public Student(String ime, int godinaUpisa, int brojIndeksa) throws GPogresanIndeks {
		this.ime = ime;
		if(godinaUpisa > 2024 || godinaUpisa < 1970) throw new GPogresanIndeks();
		this.godinaUpisa = godinaUpisa;
		if(brojIndeksa > 799 || brojIndeksa < 1) throw new GPogresanIndeks();
		this.brojIndeksa = brojIndeksa;
	}

	

	@Override
	public int uporedi(Uporediv u) throws GRazlicitiTipovi {
		if(u instanceof Student) {
			if (godinaUpisa - ((Student)u).godinaUpisa == 0) {
				return (brojIndeksa - ((Student)u).brojIndeksa);
			}else {
				return (godinaUpisa - ((Student)u).godinaUpisa);
			}
		}else {
			throw new GRazlicitiTipovi();
		}
	}
	
	public String toString(){ 
		StringBuilder sb = new StringBuilder();
		sb.append(ime).append(" ").append(godinaUpisa).append("/")
		.append(String.format("%04d", brojIndeksa));
		return sb.toString();
	}

}
