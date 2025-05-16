package simulacija;

import java.awt.Color;
import java.awt.Graphics;

public class Kamencic extends Figura {
	
	private int r = 5;
	
	public Kamencic(int x, int y) {
		super(x,y);
	}

	@Override
	public int dohvatiPoluprecnik() {
		return r;
	}

	@Override
	public void nacrtaj(Graphics g) {
		g.setColor(Color.BLACK);
		g.fillOval(x, y, r, r); 
	}

}
