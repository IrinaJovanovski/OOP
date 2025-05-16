package igra;

import java.awt.Color;
import java.awt.Graphics;

public abstract class AktivnaFigura extends Figura implements Runnable{
	
	protected Thread nit = null;
	
	private int vreme;
	
	private boolean radi = false;

	protected AktivnaFigura(Scena s, int xx, int yy, Color b, int t) {
		super(s, xx, yy, b);
		vreme = t;
		nit = new Thread(this);
	}
	
	@Override
	public void run() {
		try{
			 while (!nit.isInterrupted()) {
				 synchronized (this) {
					 if (!radi) wait();
				 }
				 azurirajPolozaj();
				 scena.repaint();
				 Thread.sleep(vreme);
			 }
		}catch (InterruptedException e) {}
	}

	protected abstract void azurirajPolozaj();

	public synchronized void kreni() {
		radi = true;
		notify();
	}
	
	public void zavrsi() {
		if(nit != null) {
			radi = false;
			nit.interrupt();
		}
	}
	
	@Override
	public void unisti() {
		zavrsi();
		super.unisti();
	}
	
}
