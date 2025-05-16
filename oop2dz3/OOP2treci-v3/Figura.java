package igra;

import java.awt.*;

public abstract class Figura {
	protected Scena scena;
	protected int x, y;
	protected Color boja;
	protected Figura(Scena s, int xx, int yy, Color b) {
		scena = s;
		x = xx;
		y = yy;
		boja = b;
		scena.dodaj(this);
	}
	
	public void unisti() {
		scena.izbaci(this);
	}
	
	public abstract void nacrtaj(Graphics g);
	
	public synchronized void pomeri(int xx, int yy) {
		x = x + xx;
		y = y + yy;
	}
	
	public abstract char vrsta();
}
