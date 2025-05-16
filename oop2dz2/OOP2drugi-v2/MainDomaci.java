package main;

import racunari.*;

public class MainDomaci {
	public static void main(String[] args) {
		try {
			RacunarskiDeo p0 = new ProstDeo("Prost deo 0", 2.25, 3.5);
			RacunarskiDeo pk = p0.clone();
			ProstDeo p1 = new ProstDeo("Prost deo 1", 3.75, 4);
			ProstDeo p2 = new ProstDeo("Prost deo 2", 2.5, 4.5);
			if (p0.equals(pk)) { System.out.println(p0 + " i " + pk + " su jednaki delovi"); }
			else { System.out.println(p0 + " i " + pk + " nisu jednaki delovi"); }
			SlozenDeo s = new SlozenDeo("Slozen deo");
			s.dodaj((ProstDeo) p0); s.dodaj(p1); s.dodaj(p2);
			System.out.println("Broj prostih delova: " + s.brojProstihDelova());
			System.out.println(s);
			s.ukloni(p1);
			if (s.sadrzi(p1)) { System.out.println(p1 + " jeste deo slozenog dela"); }
			else { System.out.println(p1 + " nije deo slozenog dela"); }
			System.out.println("Na poziciji 1 se nalazi deo: " + s.dohvati(1));
			System.out.println("Masa slozenog dela je: " + s.dohvatiMasu());
			System.out.println("Ocena kvaliteta slozenog dela je: " + s.dohvatiOcenuKvaliteta());
		}
		catch(GPogresnaSpecifikacija | GPozicijaVanOpsega | CloneNotSupportedException g) {
			System.out.println(g.getMessage());
		}
	}
}