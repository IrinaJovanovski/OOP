package kanalizacija;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.ArrayList;

public class Kanalizacija {
	
	ArrayList<Kvadrat> kvadrati = new ArrayList<>();
	
	Kvadrat oznacenKvadrat = null;
	
	private int redovi, kolone;
	
	public Kanalizacija(int r, int c) {
		redovi = r;
		kolone = c;
		for(int i = 0; i < r*c; i++) {
			Zid z = new Zid();
			z.addMouseListener(new MouseAdapter() {
				@Override
				public void mouseClicked(MouseEvent e) {
					promeniOznaku(((Kvadrat)e.getComponent()));
				}
			});
			kvadrati.add(z);
		}
	}
	
	public void promeniOznaku(Kvadrat k) {
		try {
			if(oznacenKvadrat != null) {
				if(oznacenKvadrat.equals(k)) { // oznacenom se menja oznaka
					oznacenKvadrat.postaviOznaku(false);
					oznacenKvadrat = null;
				}
				// inace drugi kvadrat trazi da bude oznacen - ne moze jer vec postoji jedan
			}else {
				k.postaviOznaku(true); // neoznacenom se menja oznaka
				oznacenKvadrat = k;	
			}
		} catch (GOznaka e) {System.out.println(e.getMessage());}
	}
	
	public int dodajCev(Cev c) {
		if(oznacenKvadrat != null) {
			int indeks = kvadrati.indexOf(oznacenKvadrat);
			oznacenKvadrat.removeMouseListener(oznacenKvadrat.getMouseListeners()[0]);
			kvadrati.set(indeks, c);
			c.addMouseListener(new MouseAdapter() {
				@Override
				public void mouseClicked(MouseEvent e) {
					promeniOznaku(((Kvadrat)e.getComponent()));
				}
			});
			c.repaint();
			oznacenKvadrat = c;
			promeniOznaku(c);
			return indeks;
		}
		return -1;
	}
	
}
