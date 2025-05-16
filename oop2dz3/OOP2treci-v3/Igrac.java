package igra;

import java.awt.Color;
import java.awt.Graphics;

public class Igrac extends Figura {
	
	private int sirina, visina;

	public Igrac(Scena s, int si, int v) {
		super(s, s.getWidth()/2 - si/2,( s.getHeight() - 20) - v, Color.BLUE);
		sirina = si;
		visina = v;
	}
	
	public void ispaliLopticu(Color b) {
		int rr = visina;
		(new Loptica(scena, (x + sirina/2 - rr/2), (y - rr - 10), Color.GREEN, 10, rr)).kreni();
	}
	
	public int dohvatiSirinu() {
		return sirina;
	}
	
	public int dohvatiVisinu() {
		return visina;
	}

	@Override
	public void nacrtaj(Graphics g) {
		g.setColor(boja);
		g.fillRect(x, y, sirina, visina);
	}
	
	@Override
	public synchronized void pomeri(int xx, int yy) {
		if((x + sirina) + xx >= scena.getWidth()) {
			xx = (scena.getWidth() - 1) - (x + sirina);
		}else if(x + xx <= 0) {
			xx = -x + 1;
		}else if((y + visina) + yy >= scena.getHeight()) {
			yy = (scena.getHeight() - 1) - (y + visina);
		}else if(y + yy <= 0) {
			yy = y + visina;
		}
		super.pomeri(xx, yy);
	}

	@Override
	public char vrsta() {
		return 'I';
	}
	
}
