package main;

import fakultet.*;

public class MainDomaci {
	public static void main(String[] args) {
		try {
		Student s1 = new Student("Aleksa Aleksic", 2022, 150);
		Uporediv u = new Student("Ana Anic", 2021, 165);
		if (s1.uporedi(u) > 0) { System.out.println(s1 + " je kasnije upisao fakultet"); }
		else if (s1.uporedi(u) < 0) { System.out.println(s1 + " je ranije upisao fakultet"); }
		else { System.out.println(s1 + " i " + u + " imaju isti indeks"); }
		Student s2 = new Student("Bojana Bojanic", 2022, 2);
		Student s3 = new Student("Cveta Cvetanovic", 2021, 120);
		Predmet p = new Predmet("Objektno orijentisano programiranje 2");
		p.prijavi(s1); p.prijavi(s2); p.prijavi(s3);
		System.out.println("Broj prijavljenih studenata: " + p.brojPrijavljenih());
		System.out.println(p);
		p.odjavi(s2);
		if (p.prati(s2)) { System.out.println(s2 + " prati predmet " + p.dohvatiNaziv()); }
		else { System.out.println(s2 + " ne prati predmet " + p.dohvatiNaziv()); }
		}
		catch(GStudentVecPostoji | GPogresanIndeks | GRazlicitiTipovi g) {
		System.out.println(g.getMessage());
		}
		}
}
