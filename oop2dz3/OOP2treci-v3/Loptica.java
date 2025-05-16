package igra;

import java.awt.Color;
import java.awt.Graphics;

public class Loptica extends AktivnaFigura {
	
	private int precnik;
	
	private double dx = 0, dy = 0;
	
	private int directionX = 1, directionY = 1;
	
	private int brojAzur = 0;

	public Loptica(Scena s, int xx, int yy, Color b, int t, int r) {
		super(s, xx, yy, b, t);
		precnik = r;
		nit.start();
	}
	
	public Loptica(Scena s, int xx, int yy, int t, int r) {
		this(s, xx, yy, Color.GREEN, t, r);
	}

	@Override
	protected void azurirajPolozaj() {
		novaBrzina();
		
		if (y >= scena.getHeight()) {
			unisti();
			return;
		} 
		
		sudari();
		
		if(++brojAzur == 100) {
			dx = 1.1 * dx;
			dy = 1.1 * dy;
			brojAzur = 0;
		}
	}
	
	private void sudari() {
		//ivice scene
		
		if(x <= 0) {
			directionX *= -1;
			dx *= -1;
			x = 1;
		}else if((x + precnik) >= scena.getWidth()) {
			directionX *= -1;
			dx *= -1;
			x = scena.getWidth() - precnik - 1;
		}
		if(y <= 0) {
			directionY *= -1;
			dy *= -1;
			y = 1;
		}
		//igrac i nepogodjene cigle
		synchronized(scena.figure) {
			for(int i = 0; i < scena.figure.size(); i++) {
				if(scena.dohvati(i).vrsta() == 'I') {
					Igrac igrac = (Igrac) scena.dohvati(i);
					udarioIgraca(igrac);
				}else if(scena.dohvati(i).vrsta() == 'C') {
					Cigla cigla = (Cigla) scena.dohvati(i);
					if(!cigla.pogodjena()) {
						if(udarioCiglu(cigla)) {
							cigla.pogodi();
							return;
						}
					}
				}
			}
		}
	}
	
	private void udarioIgraca(Igrac f) {
		if((Math.abs(x - f.x) <= f.dohvatiSirinu() / 2 + precnik/2) && (Math.abs(y - f.y) <= f.dohvatiVisinu()/2 + precnik/2)) {
			if (Math.abs(y - f.y) < f.dohvatiSirinu() / 2 + precnik/2) {
				directionY *= -1;
				dy *= -1;
				if (y < f.y) {
					y = f.y - f.dohvatiVisinu()/2 - precnik/2;
				}else y = f.y + f.dohvatiVisinu()/2 + precnik/2;
				
			}
			else {
				directionX *= -1;
				dx *= 1;
				if (x < f.x) {
					x = f.x - precnik/2 - f.dohvatiSirinu()/2;
				}else x = f.x + precnik/2 + f.dohvatiSirinu()/2;
			}		
		}
	}
	
	private boolean udarioCiglu(Cigla f) {
		if((Math.abs(x - f.x) <= f.dohvatiSirinu()/2 + precnik/2) && (Math.abs(y - f.y) <= f.dohvatiVisinu()/2 + precnik/2)) {
			if (Math.abs(y - f.y) < f.dohvatiSirinu()/2 + precnik/2) {
				directionY *= -1;
				dy *= -1;
				if (y < f.y) {
					y = f.y - f.dohvatiVisinu()/2 - precnik/2;
				}else y = f.y + f.dohvatiVisinu()/2 + precnik/2;
				
			}
			else {
				directionX *= -1;
				dx *= -1;
				if (x < f.x) {
					x = f.x - precnik/2 - f.dohvatiSirinu()/2;
				}else x = f.x + precnik/2 + f.dohvatiSirinu()/2;
			}
			return true;
		}
		return false;
	}
	
	
	public void novaBrzina() {
		dx += (-1 + Math.random() * 2) * directionX;
		dy += (-1*Math.random()) * directionY;
		while(Math.abs(dx) >= 1) {
			pomeri((dx > 0) ? 1 : -1, 0);
			dx -= ((dx > 0) ? 1 : -1);
		}
		while(Math.abs(dy) >= 1) {
			pomeri(0, (dy > 0) ? 1 : -1);
			dy -= ((dy > 0) ? 1 : -1);
		}
	}

	@Override
	public void nacrtaj(Graphics g) {
		g.setColor(boja);
		g.fillOval(x, y, precnik, precnik);
	}

	@Override
	public char vrsta() {
		return 'L';
	}

}
