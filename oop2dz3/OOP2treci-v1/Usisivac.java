package simulacija;

import java.awt.*;

public class Usisivac extends Figura {
	
	private int r = 15;

	public Usisivac(int x, int y) {
		super(x, y);
	}

	@Override
	public int dohvatiPoluprecnik() {
		return r;
	}
	
	public int pomeraj() {
		return r/2;
	}

	@Override
	public void nacrtaj(Graphics g) {
		g.setColor(Color.RED);
		int[] xPoints = {x,(int)(x-Math.sqrt(3)*r/2),(int)(x+Math.sqrt(3)*r/2)};
		int[] yPoints = {(y - r), (y + r/2), (y + r/2)};
		g.fillPolygon(xPoints, yPoints, 3);
		
	}

}
