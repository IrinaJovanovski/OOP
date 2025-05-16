package simulacija;

import java.awt.*;

public abstract class Figura {
	
	protected int x, y;
	
	public Figura(int xx, int yy) {
		x = xx;
		y = yy;
	}

	public int dohvatiX() {
		return x;
	}

	public void postaviX(int x) {
		this.x = x;
	}

	public int dohvatiY() {
		return y;
	}

	public void postaviY(int y) {
		this.y = y;
	}
	
	public abstract int dohvatiPoluprecnik();
	
	public abstract void nacrtaj(Graphics g);
	
	public double rastojanje(Figura f2) {
		return Math.sqrt(Math.pow((f2.dohvatiX()-x), 2) + Math.pow((f2.dohvatiY()-y), 2));
	}
	
	public boolean preklapaDeoFigure(Figura f2) {
		if(Math.abs(rastojanje(f2)) < (dohvatiPoluprecnik()+f2.dohvatiPoluprecnik()) && 
		   Math.abs(rastojanje(f2)) > (dohvatiPoluprecnik()-f2.dohvatiPoluprecnik())) return true;
		return false;
	}
	
	public boolean obuhvataFiguru(Figura f2) {
		if((rastojanje(f2) <= (dohvatiPoluprecnik()-f2.dohvatiPoluprecnik())) || (rastojanje(f2) == 0)) return true;
		return false;
	}
	
	
}
