package igra;

import java.awt.Color;
import java.awt.Graphics;

public class Cigla extends AktivnaFigura {
	
	private int sirina, visina;
	
	private boolean pogodjena = false;

	public Cigla(Scena s, int xx, int yy, int si, int v, int t) {
		super(s, xx, yy, Color.RED, t);
		sirina = si;
		visina = v;
		nit.start();
	}

	@Override
	protected void azurirajPolozaj() {
		if(pogodjena) {
			pomeri(0, 5);
			if((y + visina) >= scena.getHeight()) {
				unisti();
			}
		}
	}

	@Override
	public void nacrtaj(Graphics g) {
		g.setColor(boja);
		g.fillRect(x, y, sirina, visina);
	}
	
	public void pogodi() {
		boja = Color.GRAY;
		scena.repaint();
		pogodjena = true;
	}
	
	public boolean pogodjena() {
		return pogodjena;
	}
	
	public int dohvatiSirinu() {
		return sirina;
	}
	
	public int dohvatiVisinu() {
		return visina;
	}

	@Override
	public char vrsta() {
		return 'C';
	}

}
