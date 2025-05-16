package simulacija;

import java.awt.*;

public class Scena extends Canvas implements Runnable{
	
	private Simulacija glavniProzor;
	
	private Usisivac usisivac;
	
	private SkupFigura figure = new SkupFigura();
	
	private Thread nit = null;
	
	private boolean radi = false;
	
	public Scena(Simulacija vlasnik) {
		glavniProzor = vlasnik;
		setBackground(Color.GRAY);
		usisivac = new Usisivac(vlasnik.getWidth()/2, vlasnik.getHeight()/2);
	}

	@Override
	public void run() {
		try {
			while(!nit.isInterrupted()) {
				synchronized(this) {
					while(!radi) {
						wait();
					}
				}
				Figura najbliza = najblizaFigura();
				if(najbliza != null) {
					pomeriUsisivac(najbliza);
				}
				repaint();
				if(figure.brojFigura() == 0) pauziraj();
				Thread.sleep(50);
			}
		} catch (InterruptedException e) {}
	}
	
	private Figura najblizaFigura() {
		double max = Double.MAX_VALUE;
		Figura najbliza = null;
		synchronized(figure) {
			figure.postaviPrvuZaTekucu();
			Figura f = figure.tekuca();
			while(f != null) {
				if(f.rastojanje(usisivac) <= max) {
					najbliza = f;
					max = f.rastojanje(usisivac);
				}
				try {
					figure.sledeca();
					f = figure.tekuca();
				} catch (GreskaNemaSledece e) {break;}
			}
		}
		return najbliza;
	}

	private void pomeriUsisivac(Figura f) {
		if(Math.abs(usisivac.dohvatiX() - f.dohvatiX()) < usisivac.pomeraj()) {
			synchronized(figure) {
				if(usisivac.preklapaDeoFigure(f) || usisivac.obuhvataFiguru(f)) {
					figure.izbaci(f);
					return;
				}
			}
			if(usisivac.dohvatiY() - f.dohvatiY() > 0) { // usisivac je nize od f
				usisivac.postaviY(usisivac.dohvatiY() - usisivac.pomeraj());
			}else {
				usisivac.postaviY(usisivac.dohvatiY() + usisivac.pomeraj());
			}
		}else {
			if(usisivac.dohvatiX() - f.dohvatiX() > 0) { // usisivac je desnije od f
				usisivac.postaviX(usisivac.dohvatiX() - usisivac.pomeraj());
			}else {
				usisivac.postaviX(usisivac.dohvatiX() + usisivac.pomeraj());
			}
		}
	}

	@Override
	public void paint(Graphics g) {
		usisivac.nacrtaj(g);
		synchronized(figure) {
			figure.postaviPrvuZaTekucu();
			Figura f = figure.tekuca();
			while(f != null) {
				f.nacrtaj(g);
				try {
					figure.sledeca();
					f = figure.tekuca();
				} catch (GreskaNemaSledece e) {break;}
			}
		}
		if(nit == null) {
			nit = new Thread(this);
			nit.start();
		}
	}
	
	public boolean radi() {
		return radi;
	}
	
	public void dodaj(Figura f) {
		int x = f.dohvatiX();
		int y = f.dohvatiY();
		int r = f.dohvatiPoluprecnik();
		int sirina = getWidth();
		int visina = getHeight();
		if(x - r < 0 || x + r > sirina || y - r < 0 || y + r > visina) return;
		synchronized(figure) {
			figure.postaviPrvuZaTekucu();
			Figura fi = figure.tekuca();
			while(fi != null) {
				if(fi.preklapaDeoFigure(f) || fi.obuhvataFiguru(f)) return;
				try {
					figure.sledeca();
					fi = figure.tekuca();
				} catch (GreskaNemaSledece e) {break;}
			}
			
			try {
				figure.dodaj(f);
			} catch (GreskaVecPostoji e) {}
		}
		if(!radi) nastavi();
	}
	
	public void pauziraj() {
		radi = false;
	}
	
	public synchronized void nastavi() {
		radi = true;
		notify();
	}
	
	public void zavrsi() {
		radi = false;
		nit.interrupt();
	}
}
