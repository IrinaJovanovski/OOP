package igra;

import java.awt.*;
import java.util.ArrayList;

public class Scena extends Canvas{
	
	ArrayList<Figura> figure = new ArrayList<>();
	
	public Scena() {
		setPreferredSize(new Dimension(500, 700));
	}
	
	@Override
	public void paint(Graphics g) {
		synchronized(figure) {
			for(int i = 0; i < figure.size(); i++) {
				dohvati(i).nacrtaj(g);
			}
		}
	}
	
	public void dodaj(Figura f) {
		synchronized(figure) {
			figure.add(f);
		}
	}
	
	public Figura dohvati(int indeks) {
		if(indeks >= figure.size() || indeks < 0) return null;
		synchronized(figure) {
			return figure.get(indeks);
		}
	}
	
	public void izbaci(Figura f) {
		synchronized(figure) {
			figure.remove(f);
		}
	}

	public void kreni() {
		synchronized(figure) {
			for(int i = 0; i < figure.size(); i++) {
				if(dohvati(i) instanceof AktivnaFigura) {
					((AktivnaFigura)dohvati(i)).kreni();
				}
			}
		}
	}
	
	public void zavrsi() {
		synchronized(figure) {
			while(figure.size()>0) dohvati(0).unisti();
		}
	}
}
